mkdir build
cd ./build

cmake -G "MinGW Makefiles" .. -DFIND=true
mingw32-make 

cd ..
mv ./build/*dump.exe .
rm -r ./build
