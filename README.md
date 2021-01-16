# vip-music-decoder

.qmc/.ncm格式解码器

## 构建

ncmdump依赖于[taglib](https://github.com/taglib/taglib)  
如需使用ncm转换功能,请自行安装

### For Linux

```bash
git clone https://github.com/NaviHX/vip-music-decoder.git
cd ./vip-music-decoder
chmod +x ./build.sh
./build.sh
```

### For Win10

**请使用WSL/WSL2,然后跳转至 For Linux** ,或者按照如下步骤

> 旧版 : 使用PowerShell,请安装MSVC编译器和git,并且设置环境变量  
或者使用VS自带的命令行  
git clone https://github.com/NaviHX/vip-music-decoder.git  
cd ./vip-music-decoder  
mkdir build  
cd build  
cmake -G "NMake Makefiles" ..  
nmake  
尚未完善  

## 如何使用

输入`./qmcdump`后，在`stdin`中输入qmc*文件名，这些文件将会批量转换成mp3格式.  
也可以在命令行参数中加入文件名指定待转换的文件名

### 使用例

仅以qmcdump为例, .ncm文件的解码同理

1. 批量转换当前目录下的qmc*文件  

```bash
ls | grep ".qmc" | ./qmcdump
```

2. 转换当前目录下的test.qmc0文件

```bash
./qmcdump ./test.qmc0
```

## 项目进度

qmc解码 :heavy_check_mark:  
自动确定输出文件名 :heavy_check_mark:  
ncm解码 :heavy_check_mark: 

已知BUG :  
.ncm无法将封面图片写入文件
