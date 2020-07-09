#pragma once

#define FRAME_DWORD 32                                     // һ֡32��


// ����




// RN_GRAMx RN_XRAMx������ȫ�ֿռ䣬�������룬��д����ͨ��memcpy_gx
#define RN_GRAM0                BASERAM_SIZE_DWORD*MMU_BASE                     // 1024Byte
#define RN_GRAM1                (RN_GRAM0+1024)                                 // 1024Byte
#define RN_GRAM2                (RN_GRAM1+1024)                                 // 1024Byte
#define RN_GRAM3                (RN_GRAM2+1024)                                 // 1024Byte
#define RN_GRAM4                (RN_GRAM3+1024)                                 // 1024Byte
#define RN_GRAM5                (RN_GRAM4+1024)                                 // 1024Byte
#define RN_GRAM6                (RN_GRAM5+1024)                                 // 1024Byte
#define RN_GRAM7                (RN_GRAM6+1024)                                 // 1024Byte
#define RN_GRAM8                (RN_GRAM7+1024)                                 // 1024Byte
#define RN_GRAM9                (RN_GRAM8+1024)                                 // 1024Byte
#define RN_GRAM10               (RN_GRAM9+1024)                                 // 1024Byte
#define RN_GRAM11               (RN_GRAM10+1024)                                // 1024Byte
#define RN_GRAM12               (RN_GRAM11+1024)                                // 1024Byte
#define RN_GRAM13               (RN_GRAM12+1024)                                // 1024Byte
#define RN_GRAM14               (RN_GRAM13+1024)                                // 1024Byte
#define RN_GRAM15               (RN_GRAM14+1024)                                // 1024Byte
#define RN_XRAM0                (RN_GRAM15+1024)                                // 1024Byte
#define RN_XRAM1                (RN_XRAM0+1024)                                 // 1024Byte
#define RN_XRAM2                (RN_XRAM1+1024)                                 // 1024Byte
#define RN_XRAM3                (RN_XRAM2+1024)                                 // 1024Byte
#define RN_XRAM4                (RN_XRAM3+1024)                                 // 1024Byte
#define RN_XRAM5                (RN_XRAM4+1024)                                 // 1024Byte
#define RN_XRAM6                (RN_XRAM5+1024)                                 // 1024Byte
#define RN_XRAM7                (RN_XRAM6+1024)                                 // 1024Byte

// ��GRAM��ʹ�ö�������
// ============================ GRAM0 ============================
#define RN_GRAM_IN              RN_GRAM0                                        // 512Byte
#define RN_GRAM_OUT             RN_GRAM0                                        // 512Byte