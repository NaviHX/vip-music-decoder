#ifndef __DECODER_HPP__
#define __DECODER_HPP__

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <string>

namespace dec
{
    class seed_map
    {
    private:
        int x;
        int y;
        int dx;
        int index;
        std::array<std::array<uint8_t, 7>, 8> seedMap;

    public:
        seed_map()
        {
            seedMap = {{{0x4a, 0xd6, 0xca, 0x90, 0x67, 0xf7, 0x52},
                        {0x5e, 0x95, 0x23, 0x9f, 0x13, 0x11, 0x7e},
                        {0x47, 0x74, 0x3d, 0x90, 0xaa, 0x3f, 0x51},
                        {0xc6, 0x09, 0xd5, 0x9f, 0xfa, 0x66, 0xf9},
                        {0xf3, 0xd6, 0xa1, 0x90, 0xa0, 0xf7, 0xf0},
                        {0x1d, 0x95, 0xde, 0x9f, 0x84, 0x11, 0xf4},
                        {0x0e, 0x74, 0xbb, 0x90, 0xbc, 0x3f, 0x92},
                        {0x00, 0x09, 0x5b, 0x9f, 0x62, 0x66, 0xa1}}};
            x = -1;
            y = 8;
            dx = 1;
            index = -1;
        }
        ~seed_map() = default;
        uint8_t get_mask()
        {
            uint8_t ret;
            index++;
            if (x < 0)
            {
                ret = 0xc3;
                dx = 1;
                y = (8 - y) % 8;
            }
            else if (x > 6)
            {
                ret = 0xd8;
                dx = -1;
                y = 7 - y;
            }
            else
                ret = seedMap[y][x];
            x += dx;
            if (index == 0x8000 || (index > 0x8000 && (index + 1) % 0x8000 == 0))
                return get_mask();
            return ret;
        }
    };
    class decoder
    {
    private:
        seed_map seedMap;
        FILE *ipath;
        FILE *opath;

    public:
        decoder(std::string in, std::string out)
        {
            ipath = fopen(in.c_str(), "rb");
            if (ipath == nullptr)
                std::cerr << "Read File Failed : " << in << std::endl;

            opath = fopen(out.c_str(), "wb");
            if (opath == nullptr)
                std::cerr << "Write File Failed : " << out << std::endl;
        }
        ~decoder()
        {
            fclose(ipath);
            fclose(opath);
        }
        void get()
        {
            fseek(ipath,0,SEEK_END);
            auto len = ftell(ipath);
            fseek(ipath,0,SEEK_SET);
            char *buffer = (char *)malloc(len * sizeof(char));
            if (buffer == NULL)
                std::cerr << "Create Buffer Failed" << std::endl;
            if (fread(buffer, 1, len, ipath) != len)
                std::cerr << "Read File Error" << std::endl;

            for (int i = 0; i < len; i++)
                buffer[i] = (buffer[i] ^ seedMap.get_mask());

            if (fwrite(buffer, 1, len, opath) != len)
                std::cerr << "Write File Error" << std::endl;
        }
    };
} // namespace dec

#endif