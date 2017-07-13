#pragma once

#include "Staff.h"
class Leader : virtual public Staff  //领导
{
private:
	string position;  // 职务
	string department; // 部门
	Leader *next;
	Leader* InitLinkLeader();   // 创建链表
	void PrintLinkLeader(Leader *head);  // 输出链表中的Engineer数据
	bool InitfileLeader(Leader *head);   // 将链表中的Engineer数据存入文件
public:
	Leader();
	Leader(string x, string y, int z, string posit, string depart);
	string Output_posit();
	void Change_posit(string a);
	string Output_depart();
	void Change_depart(string a);

	int InitLeader();  // 增加数据
	int UpdataLeader();  //更新数据

	int SearchLeader(); ////查询数据
	int DelLeader();  //删除数据
	~Leader();
};

