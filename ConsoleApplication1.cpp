// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//题目：公司员工管理系统
//基本要求：
//设计一个利用文件处理方式实现对公司人员（包括工程师、领导和主任工程师）进行管理，
//要求具有增加数据、更新数据、查询数据、删除数据以及现实数据的功能。
//
//实现提示：
//设计一个虚基类Staff（员工），包含编号、姓名和年龄保护数据成员以及相关的成员函数；
//由Staff派生出工程师类Engineer，包含专业和职称保护数据成员以及相关的成员函数；
//再由Staff派生出领导类Leader，包含职务和部门保护数据成员以及相关的成员函数；
//然后由Engineer和Leader类派生出主任工程师类Chairman。

#include "Staff.h"
#include "Leader.h"
#include "Engineer.h"
#include "Chairman.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdbool.h>

using namespace std;
//增加数据
int InitStaffer_of_EngLeadChair(int n)
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;
	string posit;
	string depart;
	switch (n)
	{
	case 0:
		break;
	case 1:
	{
		cout << "请输入工程师的编号、姓名和年龄以及专业和职称" << endl;
		cin >> x >> y >> z >> prof >> jobt;
		Engineer Eng(x, y, z, prof, jobt);
		Eng.InitEngineer();
	}
		break;
	case 2:
	{
		cout << "请输入领导的编号、姓名和年龄以及职务和部门" << endl;
		cin >> x >> y >> z >> posit >> depart;
		Leader Lea(x, y, z, posit, depart);
		Lea.InitLeader();
	}
		break;
	case 3:
	{
		cout << "请输入领导工程师编号、姓名和年龄以及专业和职称还有职务和部门" << endl;
		cin >> x >> y >> z >> prof >> jobt >> posit >> depart;
		Chairman Cha(x, y, z, prof, jobt, posit, depart);
		Cha.InitChairman();
	}
		break;
	default:
		cout << "非法输入不存在该种选项" << endl;
		break;
	}
	return 0;
}

//更新数据
int UpdataStaffer_of_EngLeadChair(int n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:  //Engineer
	{
		Engineer Eng;
		Eng.UpdataEngineer();
	}
		break;
	case 2:  //Leader
	{
		Leader Lea;
	    Lea.UpdataLeader();
	}
		break;
	case 3:  //Chairman
	{
		Chairman Chair;
		Chair.UpdataChairman();
	}
		break;
	default:
		cout << "非法输入不存在该种选项" << endl;
		break;
	}
	return 0;
}

//查询数据
int SearchStaffer_of_EngLeadChair(int n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:
	{
		Engineer Eng;
		Eng.SearchEngineer();
	}
		break;
	case 2:
	{
		Leader Lea;
		Lea.SearchLeader();
	}
		break;
	case 3:
	{
		Chairman Chair;
		Chair.SearchChairman();
	}
		break;
	default:
		cout << "非法输入不存在该种选项" << endl;
		break;
	}
	return 0;
}

//删除数据
int DelStaffer_of_EngLeadChair(int n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:
	{
		Engineer Eng;
		Eng.DelEngineer();
	}
	break;
	case 2:
	{
		Leader Lea;
		Lea.DelLeader();
	}
		break;
	case 3:
	{
		Chairman Chair;
		Chair.DelChairman();
	}
		break;
	default:
		cout << "非法输入不存在该种选项" << endl;
		break;
	}
	return 0;
}

int main()
{
		int x1, x2;
		do
		{
			cout << "\t\t\t-------选择处理方式--------\t\n"
				<< "\t\t\t\t1.增加数据\t\t\t\n"
				<< "\t\t\t\t2.更新数据\t\t\t\n"
				<< "\t\t\t\t3.查询数据\t\t\t\n"
				<< "\t\t\t\t4,删除数据\t\t\t\n"
				<< "\t\t\t\t0.退出    \t\t\t\n"
				<< "\t\t\t\t[请按需求输入]\t\t\t\n"
				<< endl;

			cin >> x1;
			system("cls");
			switch (x1)
			{
			case 0:
				break;

			case 1:      //增加数据
				cout << "\t\t-------选择处理对象--------\t\n"
					<< "\t\t1.工程师Engineer   \t\t\t\n"
					<< "\t\t2..领导Leader\t\t\t\t\n"
					<< "\t\t3.主任工程师Chairman   \t\t\n"
					<< "\t\t0.退出    \t\t\t\t\n"
					<< "\t\t[请按需求输入]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				InitStaffer_of_EngLeadChair(x2);

				break;

			case 2:    //更新数据
				cout << "\t\t-------选择处理对象--------\t\n"
					<< "\t\t1.工程师Engineer   \t\t\t\n"
					<< "\t\t2..领导Leader\t\t\t\t\n"
					<< "\t\t3.主任工程师Chairman   \t\t\n"
					<< "\t\t0.退出    \t\t\t\t\n"
					<< "\t\t[请按需求输入]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				UpdataStaffer_of_EngLeadChair(x2);

				break;

			case 3:  //查询数据
				cout << "\t\t-------选择处理对象--------\t\n"
					<< "\t\t1.工程师Engineer   \t\t\t\n"
					<< "\t\t2..领导Leader\t\t\t\t\n"
					<< "\t\t3.主任工程师Chairman   \t\t\n"
					<< "\t\t0.退出    \t\t\t\t\n"
					<< "\t\t[请按需求输入]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				SearchStaffer_of_EngLeadChair(x2);
				break;

			case 4:  // 删除数据
				cout << "\t\t-------选择处理对象--------\t\n"
					<< "\t\t1.工程师Engineer   \t\t\t\n"
					<< "\t\t2..领导Leader\t\t\t\t\n"
					<< "\t\t3.主任工程师Chairman   \t\t\n"
					<< "\t\t0.退出    \t\t\t\t\n"
					<< "\t\t[请按需求输入]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				DelStaffer_of_EngLeadChair(x2);
				break;

			default:
			{
				cout << "非法输入" << endl;
				break;
			}
			}
		} while (x1 != 0 && sizeof(x1) == sizeof(0));
    return 0;
}

