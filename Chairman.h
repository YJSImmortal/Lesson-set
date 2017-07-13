#pragma once

#include "Staff.h"
#include "Engineer.h"
#include "Leader.h"

class Chairman : public Engineer, public Leader  
{
private:
	Chairman *next;
	Chairman* InitLinkChairman();   // ��������
	void PrintLinkChairman(Chairman *head);  // ��������е�Engineer����
	bool InitfileChairman(Chairman *head);   // �������е�Engineer���ݴ����ļ�
public:
	Chairman();
	Chairman(string x, string y, int z, string prof, string jobt, string posit, string depart);
	int InitChairman();   // ��������
	int UpdataChairman();  //��������
	int SearchChairman(); ////��ѯ����
	int DelChairman();  //ɾ������
	~Chairman();
};

