#pragma once

#include "Staff.h"

using namespace std;
class Engineer : virtual public Staff  //����ʦ��
{
private:
	string profession;   //רҵ
	string jobtitle;      //ְ��
	Engineer *next;
	Engineer* InitLinkEngineer();   // ��������
	void PrintLinkEngineer(Engineer *head);  // ��������е�Engineer����
	bool InitfileEngineer(Engineer *head);   // �������е�Engineer���ݴ����ļ�
public:
	Engineer();
	Engineer(string x, string y, int z, string prof, string jobt);
	string Output_prof();
	string Output_jobt();
	void Change_prof(string a);
	void Change_jobt(string a);

	int InitEngineer();   // ��������
	int UpdataEngineer();  //��������
	int SearchEngineer(); ////��ѯ����
	int DelEngineer();  //ɾ������
	~Engineer();
};

