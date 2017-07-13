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

// ��������
Engineer* Engineer::InitLinkEngineer()  //// ��������
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;

	fstream outinfile;
	outinfile.open("D:/C++����/019-�����װ/TestEngineer.txt");
	Engineer *head = NULL;
	Engineer *p = NULL;
	if (outinfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//cout << "���\t����\t����\tרҵ\tְ��\t" << endl;
		while (!outinfile.eof())  //����
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
		cout << "��ʧ��" << endl;
		outinfile.close();
	}
		outinfile.close();
		return head;
}

//// ��������е�Engineer����
void Engineer::PrintLinkEngineer(Engineer *head)   
{
	for (Engineer *q = head; q != NULL; q = q->next)//ѭ����������ļ��е���������
	{
		cout << q->Output_Num() << "\t";
		cout << q->Output_Name() << "\t";
		cout << q->Output_Birday() << "\t";
		cout << q->Output_prof() << "\t";
		cout << q->Output_jobt() << endl;
	}
}

// ��������
int Engineer::InitEngineer()   
{
	ofstream outfile;
	outfile.open("D:/C++����/019-�����װ/TestEngineer.txt", ios::out | ios::app);  // �ļ����������½�
	if (outfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//outfile << "\n";
		outfile << Output_Num() << "\t";
		outfile << Output_Name() << "\t";
		outfile << Output_Birday() << "\t";
		outfile << Output_prof() << "\t";
		outfile << Output_jobt() << endl;
	}
	else
	{
		cout << "��ʧ��" << endl;
		outfile.close();
	}
	outfile.close();
	return 0;
}

// �������е�Engineer���ݴ����ļ�
bool Engineer::InitfileEngineer(Engineer *head)
{
	ofstream outfiles;
	bool ifrenew = false;
	outfiles.open("D:/C++����/019-�����װ/TestEngineer.txt", ios::out);
	if (outfiles.is_open())
	{
		for (Engineer *q = head; q != NULL; q = q->next)  //�����²�����ʱ
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
		cout << "��ʧ��" << endl;
		outfiles.close();
		return false;
	}
	return ifrenew;
}

//��������
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
		outfiles.open("D:/C++����/019-�����װ/TestEngineer.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫ������Ϣ�Ĺ���ʦ���" << endl;
			cin >> changeof_Engineer;
			cout << endl;

			for (Engineer *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
			{
				if (q->Output_Num() == changeof_Engineer)
				{
					cout << "�������š������������Լ�רҵ��ְ��" << endl;
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
				cout << "��������ñ���޶�Ӧ����ʦ" << endl;
				ifrenew = InitfileEngineer(head);
				outfiles.close();
			}
			else
			{
				//д���ļ����º������
				ifrenew = InitfileEngineer(head);
				if (ifrenew)
				{
					cout << "���³ɹ�" << endl;
					outfiles.close();
				}
				else
				{
					cout << "���²��ɹ�" << endl;
					outfiles.close();
				}
			}
		}
		else
		{
			cout << "��ʧ��" << endl;
			outfiles.close();
		}
	}
	else
	{
		cout << "Engineer ��ԱΪ��" << endl;
	}
	
	return 0;
}

//��ѯ����
int Engineer::SearchEngineer()
{
	//ifstream infile;
	string searchof_Engineer;
	bool ifexist = false;
	bool isprint = false;

	//infile.open("D:/C++����/019-�����װ/TestEngineer.txt");

	//if (infile.is_open())
	//{
		//cout << "�򿪳ɹ�" << endl;
		Engineer *head = InitLinkEngineer();
		PrintLinkEngineer(head);
		if (head != NULL)
		{
			cout << "��������Ҫ��ѯ��Ϣ�Ĺ���ʦ���" << endl;
			cin >> searchof_Engineer;
			cout << endl;
			for (Engineer *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
			{
				if (q->Output_Num() == searchof_Engineer)
				{
					ifexist = true;
					isprint = true;
					if (isprint)
					{
						cout << "���\t����\t����\tרҵ\tְ��\t" << endl;
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
				cout << "��������ñ���޶�Ӧ����ʦ" << endl;
			}
		}
		else
		{
			cout << "Engineer����Ϊ0" << endl;
		}
	//}
	//else
	//{
	//	cout << "�ļ���ʧ��" << endl;
	//	infile.close();
	//}
	//infile.close();
	return 0;
}

//ɾ������
int Engineer::DelEngineer()
{
	bool ifexist = false;
	bool ifrenew = false;

	string delof_Engineer;
	Engineer *head = InitLinkEngineer();
	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++����/019-�����װ/TestEngineer.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫɾ����Ϣ�Ĺ���ʦ���" << endl;
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
				for (Engineer *q = head; q->next != NULL; q = q->next)  // ƥ����Ϣ
				{
					//if (head->Output_Num() == delof_Engineer)
					//{
					//	head = q->next;
					//	ifexist = true;
					//	break; // ������ͬ��ͬ��ע��
					//}
					if (q->next->Output_Num() == delof_Engineer)
					{
						q->next = q->next->next;
						delete q->next;
						ifexist = true;
						break;   //ͬ��
					}
				}
			}

			if (!ifexist)
			{
				cout << "��������ñ���޶�Ӧ����ʦ" << endl;
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
					cout << "ɾ���ɹ�" << endl;
					outfiles.close();
				}
				else
				{
					cout << "ɾ��ʧ��" << endl;
					outfiles.close();
				}
			}
		}
		else
		{
			cout << "��ʧ��" << endl;
			outfiles.close();
		}
	}
	else
	{
		cout << "Engineer ��ԱΪ��" << endl;
	}
	return 0;
}



Engineer::~Engineer()
{
	//cout << "~Enginteer" << endl;
}
