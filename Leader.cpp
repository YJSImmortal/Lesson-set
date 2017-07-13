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
// ��������
int Leader::InitLeader()
{
	ofstream outfile;
	outfile.open("D:/C++����/019-�����װ/TestLeader.txt", ios::out | ios::app);  // �ļ����������½�
	if (outfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//outfile << "\n";
		outfile << Output_Num() << "\t";
		outfile << Output_Name() << "\t";
		outfile << Output_Birday() << "\t";
		outfile << Output_posit() << "\t";
		outfile << Output_depart() << endl;
	}
	else
	{
		cout << "��ʧ��" << endl;
		outfile.close();
	}
	outfile.close();
	return 0;
}

// ��������
Leader* Leader::InitLinkLeader()  //// ��������
{
	string x;
	string y;
	int z;
	string posit;
	string depart;

	fstream outinfile;
	outinfile.open("D:/C++����/019-�����װ/TestLeader.txt");
	Leader *head = NULL;
	Leader *p = NULL;
	if (outinfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//cout << "���\t����\t����\tְ��\t����\t" << endl;
		while (!outinfile.eof())  //����
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
		cout << "��ʧ��" << endl;
		outinfile.close();
	}
	outinfile.close();
	return head;
}

//// ��������е�Leader����
void Leader::PrintLinkLeader(Leader *head)
{
	for (Leader *q = head; q != NULL; q = q->next)//ѭ����������ļ��е���������
	{
		cout << q->Output_Num() << "\t";
		cout << q->Output_Name() << "\t";
		cout << q->Output_Birday() << "\t";
		cout << q->Output_posit() << "\t";
		cout << q->Output_depart() << endl;
	}
}

// �������е�Leader���ݴ����ļ�
bool Leader::InitfileLeader(Leader *head)
{
	ofstream outfiles;
	bool ifrenew = false;
	outfiles.open("D:/C++����/019-�����װ/TestLeader.txt", ios::out);
	if (outfiles.is_open())
	{
		for (Leader *q = head; q != NULL; q = q->next)  //�����²�����ʱ
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
		cout << "��ʧ��" << endl;
		outfiles.close();
		return false;
	}
	return ifrenew;
}

//��������
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
		outfiles.open("D:/C++����/019-�����װ/TestLeader.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫ������Ϣ�Ĺ���ʦ���" << endl;
			cin >> changeof_Engineer;
			cout << endl;

			for (Leader *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
			{
				if (q->Output_Num() == changeof_Engineer)
				{
					cout << "�������š������������Լ�רҵ��ְ��" << endl;
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
				cout << "��������ñ���޶�Ӧ����ʦ" << endl;
				ifrenew = InitfileLeader(head);
				outfiles.close();
			}
			else
			{
				//д���ļ����º������
				ifrenew = InitfileLeader(head);
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
		cout << "Leader ��ԱΪ��" << endl;
	}

	return 0;
}

//��ѯ����
int Leader::SearchLeader()
{
	string searchof_Leader;
	bool ifexist = false;
	bool isprint = false;

	Leader *head = InitLinkLeader();
	PrintLinkLeader(head);
	if (head != NULL)
	{
		cout << "��������Ҫ��ѯ��Ϣ�Ĺ���ʦ���" << endl;
		cin >> searchof_Leader;
		cout << endl;
		for (Leader *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
		{
			if (q->Output_Num() == searchof_Leader)
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
				cout << q->Output_posit() << "\t";
				cout << q->Output_depart() << endl;
			}
		}

		if (!ifexist)
		{
			cout << "��������ñ���޶�Ӧ�쵼" << endl;
		}
	}
	else
	{
		cout << "Leader����Ϊ0" << endl;
	}
	return 0;
}

//ɾ������
int Leader::DelLeader()
{
	bool ifexist = false;
	bool ifrenew = false;

	string delof_Leader;
	Leader *head = InitLinkLeader();

	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++����/019-�����װ/TestLeader.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫɾ����Ϣ�Ĺ���ʦ���" << endl;
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
				for (Leader *q = head; q->next != NULL; q = q->next)  // ƥ����Ϣ
				{
					//if (head->Output_Num() == delof_Engineer)
					//{
					//	head = q->next;
					//	ifexist = true;
					//	break; // ������ͬ��ͬ��ע��
					//}
					if (q->next->Output_Num() == delof_Leader)
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
				cout << "��������ñ���޶�Ӧ�쵼" << endl;
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
		cout << "Leader ��ԱΪ��" << endl;
	}
	return 0;
}


Leader::~Leader()
{
	//cout << "~Leader" << endl;
}
