#pragma once

#include "Staff.h"

using namespace std;
class Engineer : virtual public Staff  //工程师类
{
private:
	string profession;   //专业
	string jobtitle;      //职称
	Engineer *next;
	Engineer* InitLinkEngineer();   // 创建链表
	void PrintLinkEngineer(Engineer *head);  // 输出链表中的Engineer数据
	bool InitfileEngineer(Engineer *head);   // 将链表中的Engineer数据存入文件
public:
	Engineer();
	Engineer(string x, string y, int z, string prof, string jobt);
	string Output_prof();
	string Output_jobt();
	void Change_prof(string a);
	void Change_jobt(string a);

	int InitEngineer();   // 增加数据
	int UpdataEngineer();  //更新数据
	int SearchEngineer(); ////查询数据
	int DelEngineer();  //删除数据
	~Engineer();
};

