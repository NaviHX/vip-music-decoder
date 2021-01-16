mkdir build
cd ./build

FIND=$(ldconfig -p | grep libtag)
if [ "$FIND" = "" ];
then
    say="CANNOT find taglib. Only build qmcdump."
    cmake ..
else
    say="Taglib Found. Build both qmcdump and ncmdump."
    cmake .. -DFIND=true
fi

make

cd ..
mv ./build/*dump .
rm -r ./build
echo "$say"