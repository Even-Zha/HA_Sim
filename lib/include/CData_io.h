#pragma once
#include "reg.h"



// 本类不属于硬件操作的一部分
// 模拟硬件的数据输入和输出功能
class CData_io
{
public:

    CData_io(char fileIn[], char fileOut[]);                // 初始化
    int getData_1Frame(CReg RAx, int frameLen);     // 取一帧数据
    void outData_1Frame(CReg RAx, int frameLen);    // 输出一帧数据

private:
    int* inBuf;                                             // 输入数据缓存
    char fileInPath[256];                                   // 输入文件路径
    char fileOutPath[256];                                  // 输出文件路径
    int inBufNum;                                           // 输入数据个数
    int inBufIndex;                                         // 输入数据缓存当前位置

    int readFile(char file[]);
    int readFileBin(char file[]);
    int readFileBin2(char file[]);
    int writeFile(char file[], int* buf, int len);
    int writeFileBin(char file[], int* buf, int len);

    int writeFileBin2(char file[], int* buf, int len);

    short limit(int data);
    void createFile(char file[]);
};

