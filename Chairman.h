#pragma once

#include "Staff.h"
#include "Engineer.h"
#include "Leader.h"

class Chairman : public Engineer, public Leader  
{
private:
	Chairman *next;
	Chairman* InitLinkChairman();   // 创建链表
	void PrintLinkChairman(Chairman *head);  // 输出链表中的Engineer数据
	bool InitfileChairman(Chairman *head);   // 将链表中的Engineer数据存入文件
public:
	Chairman();
	Chairman(string x, string y, int z, string prof, string jobt, string posit, string depart);
	int InitChairman();   // 增加数据
	int UpdataChairman();  //更新数据
	int SearchChairman(); ////查询数据
	int DelChairman();  //删除数据
	~Chairman();
};

