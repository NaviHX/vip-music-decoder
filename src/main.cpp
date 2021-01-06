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
            dec::decoder decoder_(fn,fn+".mp3");
            decoder_.get();
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
                          << "-h, --help     : help information" << std::endl
                          << "-o <file_path> : place the output file in <file_path>\n";
                }
                else if(arg=="-o")
                {
                    if(i+1>=argc)
                    {
                        std::cout<<"Output Path Needed\n";
                        return 0;
                    }
                    else
                        out=std::string(argv[++i]);
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
        if(out=="")
            out=in+".mp3";
        dec::decoder decoder_(in,out);
        decoder_.get();
    }
    return 0;
}
