// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//��Ŀ����˾Ա������ϵͳ
//����Ҫ��
//���һ�������ļ�����ʽʵ�ֶԹ�˾��Ա����������ʦ���쵼�����ι���ʦ�����й���
//Ҫ������������ݡ��������ݡ���ѯ���ݡ�ɾ�������Լ���ʵ���ݵĹ��ܡ�
//
//ʵ����ʾ��
//���һ�������Staff��Ա������������š����������䱣�����ݳ�Ա�Լ���صĳ�Ա������
//��Staff����������ʦ��Engineer������רҵ��ְ�Ʊ������ݳ�Ա�Լ���صĳ�Ա������
//����Staff�������쵼��Leader������ְ��Ͳ��ű������ݳ�Ա�Լ���صĳ�Ա������
//Ȼ����Engineer��Leader�����������ι���ʦ��Chairman��

#include "Staff.h"
#include "Leader.h"
#include "Engineer.h"
#include "Chairman.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdbool.h>

using namespace std;
//��������
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
		cout << "�����빤��ʦ�ı�š������������Լ�רҵ��ְ��" << endl;
		cin >> x >> y >> z >> prof >> jobt;
		Engineer Eng(x, y, z, prof, jobt);
		Eng.InitEngineer();
	}
		break;
	case 2:
	{
		cout << "�������쵼�ı�š������������Լ�ְ��Ͳ���" << endl;
		cin >> x >> y >> z >> posit >> depart;
		Leader Lea(x, y, z, posit, depart);
		Lea.InitLeader();
	}
		break;
	case 3:
	{
		cout << "�������쵼����ʦ��š������������Լ�רҵ��ְ�ƻ���ְ��Ͳ���" << endl;
		cin >> x >> y >> z >> prof >> jobt >> posit >> depart;
		Chairman Cha(x, y, z, prof, jobt, posit, depart);
		Cha.InitChairman();
	}
		break;
	default:
		cout << "�Ƿ����벻���ڸ���ѡ��" << endl;
		break;
	}
	return 0;
}

//��������
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
		cout << "�Ƿ����벻���ڸ���ѡ��" << endl;
		break;
	}
	return 0;
}

//��ѯ����
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
		cout << "�Ƿ����벻���ڸ���ѡ��" << endl;
		break;
	}
	return 0;
}

//ɾ������
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
		cout << "�Ƿ����벻���ڸ���ѡ��" << endl;
		break;
	}
	return 0;
}

int main()
{
		int x1, x2;
		do
		{
			cout << "\t\t\t-------ѡ����ʽ--------\t\n"
				<< "\t\t\t\t1.��������\t\t\t\n"
				<< "\t\t\t\t2.��������\t\t\t\n"
				<< "\t\t\t\t3.��ѯ����\t\t\t\n"
				<< "\t\t\t\t4,ɾ������\t\t\t\n"
				<< "\t\t\t\t0.�˳�    \t\t\t\n"
				<< "\t\t\t\t[�밴��������]\t\t\t\n"
				<< endl;

			cin >> x1;
			system("cls");
			switch (x1)
			{
			case 0:
				break;

			case 1:      //��������
				cout << "\t\t-------ѡ�������--------\t\n"
					<< "\t\t1.����ʦEngineer   \t\t\t\n"
					<< "\t\t2..�쵼Leader\t\t\t\t\n"
					<< "\t\t3.���ι���ʦChairman   \t\t\n"
					<< "\t\t0.�˳�    \t\t\t\t\n"
					<< "\t\t[�밴��������]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				InitStaffer_of_EngLeadChair(x2);

				break;

			case 2:    //��������
				cout << "\t\t-------ѡ�������--------\t\n"
					<< "\t\t1.����ʦEngineer   \t\t\t\n"
					<< "\t\t2..�쵼Leader\t\t\t\t\n"
					<< "\t\t3.���ι���ʦChairman   \t\t\n"
					<< "\t\t0.�˳�    \t\t\t\t\n"
					<< "\t\t[�밴��������]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				UpdataStaffer_of_EngLeadChair(x2);

				break;

			case 3:  //��ѯ����
				cout << "\t\t-------ѡ�������--------\t\n"
					<< "\t\t1.����ʦEngineer   \t\t\t\n"
					<< "\t\t2..�쵼Leader\t\t\t\t\n"
					<< "\t\t3.���ι���ʦChairman   \t\t\n"
					<< "\t\t0.�˳�    \t\t\t\t\n"
					<< "\t\t[�밴��������]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				SearchStaffer_of_EngLeadChair(x2);
				break;

			case 4:  // ɾ������
				cout << "\t\t-------ѡ�������--------\t\n"
					<< "\t\t1.����ʦEngineer   \t\t\t\n"
					<< "\t\t2..�쵼Leader\t\t\t\t\n"
					<< "\t\t3.���ι���ʦChairman   \t\t\n"
					<< "\t\t0.�˳�    \t\t\t\t\n"
					<< "\t\t[�밴��������]\t\t\t\t\n"
					<< endl;
				cin >> x2;
				DelStaffer_of_EngLeadChair(x2);
				break;

			default:
			{
				cout << "�Ƿ�����" << endl;
				break;
			}
			}
		} while (x1 != 0 && sizeof(x1) == sizeof(0));
    return 0;
}

