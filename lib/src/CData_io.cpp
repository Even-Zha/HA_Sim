#include "CData_io.h"
#include <iostream>
#include "memory.h"

int CData_io::* inBuf = NULL;

CData_io::CData_io(char fileIn[], char fileOut[])
{
    inBufIndex = 0;

    strcpy(fileInPath, fileIn);
    strcpy(fileOutPath, fileOut);
    readFile(fileInPath);
    createFile(fileOutPath);
}

// ��inBufȡһ֡���ݣ����ȡ���ʧ�ܷ���0����ȷ�������ݸ���
int CData_io::getData_1Frame(CReg RAx, int frameLen)
{
    int* frame = new int[frameLen];
    if (frame == NULL)
    {
        return 0;
    }

    if (inBufNum < (inBufIndex + frameLen))
    {
        delete[] frame;
        return 0;
    }

    for (int i = 0; i < frameLen; i++)
    {
        frame[i] = inBuf[inBufIndex + i];
    }
    inBufIndex += frameLen;

    // frame -> RAx
    for (int i = 0; i < frameLen; i++)
    {
        SET_M(RAx + i * MMU_BASE, frame[i]);
    }


    delete[] frame;
    return frameLen;
}


// ��RAxȡһ֡���ݣ�д�뵽����ļ���
void CData_io::outData_1Frame(CReg RAx, int frameLen)
{
    int* frame = new int[frameLen];
    if (frame == NULL)
    {
        return;
    }    

    // frame <- RAx
    for (int i = 0; i < frameLen; i++)
    {
        CReg tempRD = GET_M(RAx + i * MMU_BASE);
        frame[i] = tempRD.m_data;
    }

    // д���ļ�
    writeFile(fileOutPath, frame, frameLen);

    delete[] frame;
    return;
}

// ��ȡ�ļ����������ݵ�inBuf
int CData_io::readFile(char file[])
{
    // ��ȡ�ļ���׺, .bin .txt .wav��
    char* pTail = strrchr(file, '.');
    if (strcmp(pTail, ".bin") == 0)
    {
        return readFileBin(file);
    }
    else
    {
        return 0;
    }


    

    return 0;
}

// ��ȡ.bin�ļ�, ���ݸ�ʽΪ��Ƶ���ݽ������У�ÿ��������Ϊ2�ֽڣ���˸�ʽ
// ���ض�ȡ��
int CData_io::readFileBin(char file[])
{
    int len = 0;

    // ȡ�ļ���С
    struct _stat info;
    _stat(file, &info);
    int size = info.st_size;

    // ���ļ�
    FILE* fp = fopen(file, "rb");
    if (fp == NULL)
    {
        return len;
    }
    
    // inBuf����ռ�
    int num = size / 2;
    inBuf = new int[num];
    if (inBuf == NULL)
    {
        return len;
    }
    inBufNum = num;

    // ���ļ����ݵ�inbuf
    unsigned char byte2[2];
    while (!feof(fp))
    {
        fread(byte2, 1, 2, fp);        
        unsigned char tempByte = byte2[0];
        byte2[0] = byte2[1];
        byte2[1] = tempByte;
        short tempShort = *(short*)byte2;
        inBuf[len++] = (int)tempShort;
    }
    fclose(fp);


    return len;
}

// ��bufд���ļ���д�뷽ʽ��append
int CData_io::writeFile(char file[], int *buf, int len)
{
    // ��ȡ�ļ���׺, .bin .txt .wav��
    char* pTail = strrchr(file, '.');
    if (strcmp(pTail, ".bin") == 0)
    {
        return writeFileBin(file, buf, len);
    }
    else
    {
        return 0;
    }

    return 0;
}

// ��bufд���ļ���д�뷽ʽ��append, ���ݸ�ʽΪ��Ƶ���ݽ������У�ÿ��������Ϊ2�ֽڣ���˸�ʽ
int CData_io::writeFileBin(char file[], int* buf, int len)
{
    int retlen = 0;
    short temp;
    unsigned char tempByte[2];

    // ���ļ�
    FILE* fp = fopen(file, "ab");
    if (fp == NULL)
    {
        return retlen;
    }

    for (int i = 0; i < len; i++)
    {
        temp = limit(buf[i]);
        tempByte[0] = *((unsigned char*)(&temp) + 1);
        tempByte[1] = *((unsigned char*)(&temp) + 0);

        fwrite(tempByte, 1, 2, fp);
        retlen += 2;
    }
    

    fclose(fp);

    return retlen;
}

// intתshort�����ҽ���ֵ��Χ������ -32767��32767
short CData_io::limit(int data)
{
    short rst;

    if (data > 32767)
    {
        rst = 32767;
    }
    else if (data < -32767)
    {
        rst = -32767;
    }
    else
    {
        rst = (short)data;
    }
    return rst;
}

void CData_io::createFile(char file[])
{
    if (strlen(file) <= 0)
    {
        return;
    }

    FILE* fp = fopen(file, "wb");
    if (fp == NULL)
    {
        return;
    }
    fclose(fp);

}