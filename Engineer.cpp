#include "stdafx.h"
#include "Engineer.h"


Engineer::Engineer()
{
	//cout << "Enginteer" << endl;
}

Engineer::Engineer(string x, string y, int z, string prof, string jobt) :Staff(x, y, z)
{
	profession = prof;
	jobtitle = jobt;
	//cout << "Engineer_2" << endl;
	next = NULL;
}

string Engineer::Output_prof()
{
	//cout << profession << endl;
	return profession;
}
void Engineer::Change_prof(string a)
{
	profession = a;
	//cout << profession << endl;
}
string Engineer::Output_jobt()
{
	//cout << jobtitle << endl;
	return jobtitle;
}
void Engineer::Change_jobt(string a)
{
	jobtitle = a;
	//cout << jobtitle << endl;
}

// 创建链表
Engineer* Engineer::InitLinkEngineer()  //// 创建链表
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;

	fstream outinfile;
	outinfile.open("D:/C++代码/019-课设封装/TestEngineer.txt");
	Engineer *head = NULL;
	Engineer *p = NULL;
	if (outinfile.is_open())
	{
		cout << "打开成功" << endl;
		//cout << "编号\t姓名\t年龄\t专业\t职称\t" << endl;
		while (!outinfile.eof())  //链表
		{
			string ch;
			if (outinfile >> x >> y >> z >> prof >> jobt)
			{
				Engineer *r = new Engineer(x, y, z, prof, jobt);
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

//// 输出链表中的Engineer数据
void Engineer::PrintLinkEngineer(Engineer *head)   
{
	for (Engineer *q = head; q != NULL; q = q->next)//循环输出链表文件中的所有数据
	{
		cout << q->Output_Num() << "\t";
		cout << q->Output_Name() << "\t";
		cout << q->Output_Birday() << "\t";
		cout << q->Output_prof() << "\t";
		cout << q->Output_jobt() << endl;
	}
}

// 增加数据
int Engineer::InitEngineer()   
{
	ofstream outfile;
	outfile.open("D:/C++代码/019-课设封装/TestEngineer.txt", ios::out | ios::app);  // 文件不存在则新建
	if (outfile.is_open())
	{
		cout << "打开成功" << endl;
		//outfile << "\n";
		outfile << Output_Num() << "\t";
		outfile << Output_Name() << "\t";
		outfile << Output_Birday() << "\t";
		outfile << Output_prof() << "\t";
		outfile << Output_jobt() << endl;
	}
	else
	{
		cout << "打开失败" << endl;
		outfile.close();
	}
	outfile.close();
	return 0;
}

// 将链表中的Engineer数据存入文件
bool Engineer::InitfileEngineer(Engineer *head)
{
	ofstream outfiles;
	bool ifrenew = false;
	outfiles.open("D:/C++代码/019-课设封装/TestEngineer.txt", ios::out);
	if (outfiles.is_open())
	{
		for (Engineer *q = head; q != NULL; q = q->next)  //当更新不存在时
		{
			outfiles << q->Output_Num() << "\t";
			outfiles << q->Output_Name() << "\t";
			outfiles << q->Output_Birday() << "\t";
			outfiles << q->Output_prof() << "\t";
			outfiles << q->Output_jobt() << endl;
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
int Engineer::UpdataEngineer()
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;
	bool ifexist = false;
	bool ifrenew = false;

	string changeof_Engineer;
	Engineer *head = InitLinkEngineer();
	PrintLinkEngineer(head);

	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++代码/019-课设封装/TestEngineer.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "请输入需要更改信息的工程师编号" << endl;
			cin >> changeof_Engineer;
			cout << endl;

			for (Engineer *q = head; q != NULL; q = q->next)  // 匹配信息
			{
				if (q->Output_Num() == changeof_Engineer)
				{
					cout << "请输入编号、姓名和年龄以及专业和职称" << endl;
					cin >> x >> y >> z >> prof >> jobt;
					q->Change_Num(x);
					q->Change_Name(y);
					q->Change_Birday(z);
					q->Change_prof(prof);
					q->Change_jobt(jobt);
					ifexist = true;
				}
			}
			if (!ifexist)
			{
				cout << "错误输入该编号无对应工程师" << endl;
				ifrenew = InitfileEngineer(head);
				outfiles.close();
			}
			else
			{
				//写入文件更新后的数据
				ifrenew = InitfileEngineer(head);
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
		cout << "Engineer 人员为零" << endl;
	}
	
	return 0;
}

//查询数据
int Engineer::SearchEngineer()
{
	//ifstream infile;
	string searchof_Engineer;
	bool ifexist = false;
	bool isprint = false;

	//infile.open("D:/C++代码/019-课设封装/TestEngineer.txt");

	//if (infile.is_open())
	//{
		//cout << "打开成功" << endl;
		Engineer *head = InitLinkEngineer();
		PrintLinkEngineer(head);
		if (head != NULL)
		{
			cout << "请输入需要查询信息的工程师编号" << endl;
			cin >> searchof_Engineer;
			cout << endl;
			for (Engineer *q = head; q != NULL; q = q->next)  // 匹配信息
			{
				if (q->Output_Num() == searchof_Engineer)
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
					cout << q->Output_prof() << "\t";
					cout << q->Output_jobt() << endl;
				}
			}

			if (!ifexist)
			{
				cout << "错误输入该编号无对应工程师" << endl;
			}
		}
		else
		{
			cout << "Engineer人数为0" << endl;
		}
	//}
	//else
	//{
	//	cout << "文件打开失败" << endl;
	//	infile.close();
	//}
	//infile.close();
	return 0;
}

//删除数据
int Engineer::DelEngineer()
{
	bool ifexist = false;
	bool ifrenew = false;

	string delof_Engineer;
	Engineer *head = InitLinkEngineer();
	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++代码/019-课设封装/TestEngineer.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "请输入需要删除信息的工程师编号" << endl;
			cin >> delof_Engineer;
			cout << endl;
			if (head->Output_Num() == delof_Engineer)
			{
				Engineer *r;
				r = head;
				head = head->next;
				ifexist = true;
				delete r;
			}
			else
			{
				for (Engineer *q = head; q->next != NULL; q = q->next)  // 匹配信息
				{
					//if (head->Output_Num() == delof_Engineer)
					//{
					//	head = q->next;
					//	ifexist = true;
					//	break; // 若允许同名同姓注释
					//}
					if (q->next->Output_Num() == delof_Engineer)
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
				cout << "错误输入该编号无对应工程师" << endl;
				InitfileEngineer(head);
				outfiles.close();
			}
			else
			{
				if (head != NULL)
				{
					ifrenew = InitfileEngineer(head);
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
		cout << "Engineer 人员为零" << endl;
	}
	return 0;
}



Engineer::~Engineer()
{
	//cout << "~Enginteer" << endl;
}
