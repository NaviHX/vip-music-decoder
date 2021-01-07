# vip-music-decoder

.qmc/.ncm格式解码器

## 构建

### For Linux

```bash
git clone https://github.com/NaviHX/vip-music-decoder.git
cd ./vip-music-decoder
chmod +x ./build.sh
./build.sh
```

### For Win10

使用PowerShell,请安装MSVC编译器和git,并且设置环境变量  
或者使用VS自带的命令行

```bash
git clone https://github.com/NaviHX/vip-music-decoder.git
cd ./vip-music-decoder
mkdir build
cd build
cmake -G "NMake Makefiles"
nmake
```

## 项目进度

qmc解码 :heavy_check_mark:  
自动确定输出文件名 :heavy_multiplication_x:
