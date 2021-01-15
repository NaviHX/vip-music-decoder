#include "decoder.hpp"
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc,char** argv)
{
    if(argc==1)
    {
        std::string fn;
        while(std::cin>>fn)
        {
            //dec::decoder decoder_(fn,dec::fileNameWithoutExt(fn)+".mp3");
            //decoder_.get();
            dec::decoder decoder_(fn);
            decoder_.dump();
        }
    }
    else
    {
        std::string in="",out="";
        for(int i=1;i<argc;i++)
        {
            std::string arg(argv[i]);
            if(arg[0]=='-')
            {
                if(arg=="-h" || arg=="--help")
                {
                std::cout << "Usage          : qcmdump [options] file_path" << std::endl
                          << "-h, --help     : help information" << std::endl;
                }
                else
                    std::cout<<"Invalid argu : "<<arg<<std::endl;
            }
            else
                in=std::string(arg);   
        }
        if(in=="")
        {
            std::cout<<"Input Path Needed\n";
            return 0;
        }   
        dec::decoder decoder_(in);
        decoder_.dump();
    }
    return 0;
}
