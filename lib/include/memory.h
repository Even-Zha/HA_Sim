#pragma once
#include "cpu.h"
#include "fifo.h"

#define sub void
#define Sub void
#define Sub_AutoField void
#define call            send_para(RD0);
#define call_AutoField  push_AutoField;
#define Return(x)       RSP += (x+MMU_BASE);\
                        return
#define Return_AutoField(x)       RSP += x;\
                        pop_AutoField;\
                        return


//#define RSP_MINUS(x)    CMemBase::malloc_local(x)
//#define RSP_ADD(x)      CMemBase::release_local(x)
#define GET_M(x)        CMemBase::M_R(x)
#define SET_M(x,y)      CMemBase::M_W(x,y)
#define MEMCPY(x,y,z)   CMemBase::memcpy(x, y, z)
#define push(x)         CMemBase::PUSH(x)
#define pop(x)          CMemBase::POP(x)
#define send_para(x)    push(x)

#define BASERAM_SIZE_DWORD      (1 * 1024)
#define GRAM_SIZE_DWORD         (4 * 1024)
#define XRAM_SIZE_DWORD         (2 * 1024)

class CMemBase :
    public CCpu
{
public:
    //static const int BASERAM_SIZE_DWORD = 1 * 1024;                     // BASE_RAM�ߴ�
    //static int pRam[RAM_SIZE_DWORD];
    //static const int GRAM_SIZE_DWORD = 4 * 1024;                    // GRAM�ߴ�
    //static int pGRam[GRAM_SIZE_DWORD];
    //static const int XRAM_SIZE_DWORD = 2 * 1024;                     // XRAM�ߴ�
    //static int pXRam[XRAM_SIZE_DWORD];

    // ��BASE_RAM GRAM XRAM ��Ϊһ����������ַ���ڴ�
    static int pTotalRam[BASERAM_SIZE_DWORD + GRAM_SIZE_DWORD + XRAM_SIZE_DWORD];

    static void init();
    static void  malloc_local(int len);                             // BASE_RAM�оֲ������ռ����룬ÿ������RSP���Сlen���൱��RSP-=len
    static void  release_local(int len);                            // BASE_RAM�оֲ������ռ��ͷţ�ÿ���ͷ�RSP������len���൱��RSP+=len
    //static void malloc_global(int len);                // BASE_RAM��ȫ�ֱ����������룬��0��ַ��ʼ�ü���

    static CReg M_R(CReg addr);                                     // ȡ��ַ��ָ�����ݣ��൱��RDx = M[RAx]
    static void M_W(CReg addr, CReg data);                          // ���ַ��ָ�����ݣ��൱��M[RAx] = RDx
    static void PUSH(CReg rdx);                                     // �Ĵ���ѹջ���൱��push RDx
    static void POP(CReg &rdx);                                     // �Ĵ���ѹջ���൱��push RDx

    static void memcpy(CReg len, CReg src, CReg dst);
};

