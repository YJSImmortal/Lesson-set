#pragma once

#include "Staff.h"
class Leader : virtual public Staff  //�쵼
{
private:
	string position;  // ְ��
	string department; // ����
	Leader *next;
	Leader* InitLinkLeader();   // ��������
	void PrintLinkLeader(Leader *head);  // ��������е�Engineer����
	bool InitfileLeader(Leader *head);   // �������е�Engineer���ݴ����ļ�
public:
	Leader();
	Leader(string x, string y, int z, string posit, string depart);
	string Output_posit();
	void Change_posit(string a);
	string Output_depart();
	void Change_depart(string a);

	int InitLeader();  // ��������
	int UpdataLeader();  //��������

	int SearchLeader(); ////��ѯ����
	int DelLeader();  //ɾ������
	~Leader();
};

