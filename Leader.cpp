#include "stdafx.h"
#include "Leader.h"


Leader::Leader()
{
	//cout << "Leader" << endl;
}

Leader::Leader(string x, string y, int z, string posit, string depart) :Staff(x, y, z)
{
	//Staff(x, y, z);
	next = NULL;
	position = posit;
	department = depart;
	//cout << "Leader_2" << endl;
}
string Leader::Output_depart()
{
	//cout << department << endl;
	return department;
}

void Leader::Change_depart(string a)
{
	department = a;
	//cout << department << endl;
}

string Leader::Output_posit()
{
	//cout << position << endl;
	return position;
}
void Leader::Change_posit(string a)
{
	position = a;
	//cout << position << endl;
}
// 增加数据
int Leader::InitLeader()
{
	ofstream outfile;
	outfile.open("D:/C++代码/019-课设封装/TestLeader.txt", ios::out | ios::app);  // 文件不存在则新建
	if (outfile.is_open())
	{
		cout << "打开成功" << endl;
		//outfile << "\n";
		outfile << Output_Num() << "\t";
		outfile << Output_Name() << "\t";
		outfile << Output_Birday() << "\t";
		outfile << Output_posit() << "\t";
		outfile << Output_depart() << endl;
	}
	else
	{
		cout << "打开失败" << endl;
		outfile.close();
	}
	outfile.close();
	return 0;
}

// 创建链表
Leader* Leader::InitLinkLeader()  //// 创建链表
{
	string x;
	string y;
	int z;
	string posit;
	string depart;

	fstream outinfile;
	outinfile.open("D:/C++代码/019-课设封装/TestLeader.txt");
	Leader *head = NULL;
	Leader *p = NULL;
	if (outinfile.is_open())
	{
		cout << "打开成功" << endl;
		//cout << "编号\t姓名\t年龄\t职务\t部门\t" << endl;
		while (!outinfile.eof())  //链表
		{
			string ch;
			if (outinfile >> x >> y >> z >> posit >> depart)
			{
				Leader *r = new Leader(x, y, z, posit, depart);
				r->next = NULL;
				if (head == NULL)
				{
					head = r;
					p = r;
				}
				else
				{
					p->next = r;
					p = r;
				}
			}
		}
	}
	else
	{
		cout << "打开失败" << endl;
		outinfile.close();
	}
	outinfile.close();
	return head;
}

//// 输出链表中的Leader数据
void Leader::PrintLinkLeader(Leader *head)
{
	for (Leader *q = head; q != NULL; q = q->next)//循环输出链表文件中的所有数据
	{
		cout << q->Output_Num() << "\t";
		cout << q->Output_Name() << "\t";
		cout << q->Output_Birday() << "\t";
		cout << q->Output_posit() << "\t";
		cout << q->Output_depart() << endl;
	}
}

// 将链表中的Leader数据存入文件
bool Leader::InitfileLeader(Leader *head)
{
	ofstream outfiles;
	bool ifrenew = false;
	outfiles.open("D:/C++代码/019-课设封装/TestLeader.txt", ios::out);
	if (outfiles.is_open())
	{
		for (Leader *q = head; q != NULL; q = q->next)  //当更新不存在时
		{
			outfiles << q->Output_Num() << "\t";
			outfiles << q->Output_Name() << "\t";
			outfiles << q->Output_Birday() << "\t";
			outfiles << q->Output_posit() << "\t";
			outfiles << q->Output_depart() << endl;
			ifrenew = true;
		}
		outfiles.close();
	}
	else
	{
		cout << "打开失败" << endl;
		outfiles.close();
		return false;
	}
	return ifrenew;
}

//更新数据
int Leader::UpdataLeader()
{
	string x;
	string y;
	int z;
	string posit;
	string depart;
	bool ifexist = false;
	bool ifrenew = false;

	string changeof_Engineer;
	Leader *head = InitLinkLeader();
	PrintLinkLeader(head);

	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++代码/019-课设封装/TestLeader.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "请输入需要更改信息的工程师编号" << endl;
			cin >> changeof_Engineer;
			cout << endl;

			for (Leader *q = head; q != NULL; q = q->next)  // 匹配信息
			{
				if (q->Output_Num() == changeof_Engineer)
				{
					cout << "请输入编号、姓名和年龄以及专业和职称" << endl;
					cin >> x >> y >> z >> posit >> depart;
					q->Change_Num(x);
					q->Change_Name(y);
					q->Change_Birday(z);
					q->Change_posit(posit);
					q->Change_depart(depart);
					ifexist = true;
				}
			}
			if (!ifexist)
			{
				cout << "错误输入该编号无对应工程师" << endl;
				ifrenew = InitfileLeader(head);
				outfiles.close();
			}
			else
			{
				//写入文件更新后的数据
				ifrenew = InitfileLeader(head);
				if (ifrenew)
				{
					cout << "更新成功" << endl;
					outfiles.close();
				}
				else
				{
					cout << "更新不成功" << endl;
					outfiles.close();
				}
			}
		}
		else
		{
			cout << "打开失败" << endl;
			outfiles.close();
		}
	}
	else
	{
		cout << "Leader 人员为零" << endl;
	}

	return 0;
}

//查询数据
int Leader::SearchLeader()
{
	string searchof_Leader;
	bool ifexist = false;
	bool isprint = false;

	Leader *head = InitLinkLeader();
	PrintLinkLeader(head);
	if (head != NULL)
	{
		cout << "请输入需要查询信息的工程师编号" << endl;
		cin >> searchof_Leader;
		cout << endl;
		for (Leader *q = head; q != NULL; q = q->next)  // 匹配信息
		{
			if (q->Output_Num() == searchof_Leader)
			{
				ifexist = true;
				isprint = true;
				if (isprint)
				{
					cout << "编号\t姓名\t年龄\t专业\t职称\t" << endl;
					isprint = false;
				}
				cout << q->Output_Num() << "\t";
				cout << q->Output_Name() << "\t";
				cout << q->Output_Birday() << "\t";
				cout << q->Output_posit() << "\t";
				cout << q->Output_depart() << endl;
			}
		}

		if (!ifexist)
		{
			cout << "错误输入该编号无对应领导" << endl;
		}
	}
	else
	{
		cout << "Leader人数为0" << endl;
	}
	return 0;
}

//删除数据
int Leader::DelLeader()
{
	bool ifexist = false;
	bool ifrenew = false;

	string delof_Leader;
	Leader *head = InitLinkLeader();

	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++代码/019-课设封装/TestLeader.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "请输入需要删除信息的工程师编号" << endl;
			cin >> delof_Leader;
			cout << endl;

			if (head->Output_Num() == delof_Leader)
			{
				Leader *r;
				r = head;
				head = head->next;
				ifexist = true;
				delete r;
			}
			else
			{
				for (Leader *q = head; q->next != NULL; q = q->next)  // 匹配信息
				{
					//if (head->Output_Num() == delof_Engineer)
					//{
					//	head = q->next;
					//	ifexist = true;
					//	break; // 若允许同名同姓注释
					//}
					if (q->next->Output_Num() == delof_Leader)
					{
						q->next = q->next->next;
						delete q->next;
						ifexist = true;
						break;   //同上
					}
				}
			}

			if (!ifexist)
			{
				cout << "错误输入该编号无对应领导" << endl;
				InitfileLeader(head);
				outfiles.close();
			}
			else
			{
				if (head != NULL)
				{
					ifrenew = InitfileLeader(head);
				}
				else
				{
					ifrenew = true;
				}
				if (ifrenew)
				{
					cout << "删除成功" << endl;
					outfiles.close();
				}
				else
				{
					cout << "删除失败" << endl;
					outfiles.close();
				}
			}
		}
		else
		{
			cout << "打开失败" << endl;
			outfiles.close();
		}
	}
	else
	{
		cout << "Leader 人员为零" << endl;
	}
	return 0;
}


Leader::~Leader()
{
	//cout << "~Leader" << endl;
}
