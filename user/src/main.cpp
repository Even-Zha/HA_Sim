#include "main.h"




using namespace std;

// ȫ�ֱ���
char File_In[] = "./user/data/data_in.bin";		// ������Ƶ����·��
char File_Out[] = "./user/data/data_in.bin";	// �����Ƶ����·��

CData_io data_io = CData_io("./user/data/data_in.bin", "./user/data/data_out.bin");     // ����IO���ʼ��




int main()
{

	// ϵͳ��ʼ��
	sys_init();

	cout << "start prj" << endl;

	// ===================��ʱ����===================
	//test_mem_oper();
	//test_simple_oper();
	//test_conditional();
	test_float_model();


	// ===================�û�������====================
	// �㷨��������(��ʱ��˥��һ��Ϊ�������޸�)
	while (1)
	{
		// ��ADCȡһ֡���ݴ���RN_GRAM_IN
		RD0 = RN_GRAM_IN;
		RA0 = RD0;
		if (data_io.getData_1Frame(RA0, FRAME_LEN_Word) != FRAME_LEN_Word)
		{
			cout << "end prj" << endl;
			break;
		}


		// ���ݴ���
		// ���*0.5
		RD0 = 0x40004000;
		RD1 = FRAME_LEN_Word;
		send_para(RA0);
		send_para(RD0);
		send_para(RA0);
		send_para(RD1);
		call_AutoField MAC_MultiConst16;


		// RN_GRAM_OUT���һ֡���ݵ�DAC
		RD0 = RN_GRAM_OUT;
		RA0 = RD0;
		data_io.outData_1Frame(RA0, FRAME_LEN_Word);


	}


	return 0;
}

void sys_init()
{
	// �������������޸�
	CVersion ver111;		// ��ʾ��汾��Ϣ
	CMemBase::init();		// �ڴ��ʼ��
}


