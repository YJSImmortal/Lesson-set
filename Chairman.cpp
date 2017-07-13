#include "stdafx.h"
#include "Chairman.h"


Chairman::Chairman()
{
	//cout << "Chairman" << endl;
}

Chairman::Chairman(string x, string y, int z, string prof, string jobt, string posit, string depart) :Staff(x, y, z), Engineer(x, y, z, prof, jobt), Leader(x, y, z, posit, depart)
{
	//cout << "Chairman _2" << endl;
	next = NULL;
}
// ��������
int Chairman::InitChairman()
{
	ofstream outfile;
	outfile.open("D:/C++����/019-�����װ/TestChairman.txt", ios::out | ios::app);  // �ļ����������½�
	if (outfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//outfile << "\n";
		outfile << Output_Num() << "\t";
		outfile << Output_Name() << "\t";
		outfile << Output_Birday() << "\t";
		outfile << Output_prof() << "\t";
		outfile << Output_jobt() << endl;
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
Chairman* Chairman::InitLinkChairman()  //// ��������
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;
	string posit;
	string depart;

	fstream outinfile;
	outinfile.open("D:/C++����/019-�����װ/TestChairman.txt");
	Chairman *head = NULL;
	Chairman *p = NULL;
	if (outinfile.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
		//cout << "���\t����\t����\tרҵ\tְ��\t" << endl;
		while (!outinfile.eof())  //����
		{
			string ch;
			if (outinfile >> x >> y >> z >> prof >> jobt >> posit >> depart)
			{
				Chairman *r = new Chairman(x, y, z, prof, jobt,posit,depart);
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

//// ��������е�Chairman����
void Chairman::PrintLinkChairman(Chairman *head)
{
	for (Chairman *q = head; q != NULL; q = q->next)//ѭ����������ļ��е���������
	{
		cout << q->Output_Num() << "\t";
		cout << q->Output_Name() << "\t";
		cout << q->Output_Birday() << "\t";
		cout << q->Output_prof() << "\t";
		cout << q->Output_jobt() << "\t";
		cout << q->Output_posit()<< "\t";
		cout << q->Output_depart() << endl;
	}
}

// �������е�Chairman���ݴ����ļ�
bool Chairman::InitfileChairman(Chairman *head)
{
	ofstream outfiles;
	bool ifrenew = false;
	outfiles.open("D:/C++����/019-�����װ/TestChairman.txt", ios::out);
	if (outfiles.is_open())
	{
		for (Chairman *q = head; q != NULL; q = q->next)  //�����²�����ʱ
		{
			outfiles << q->Output_Num() << "\t";
			outfiles << q->Output_Name() << "\t";
			outfiles << q->Output_Birday() << "\t";
			outfiles << q->Output_prof() << "\t";
			outfiles << q->Output_jobt() << "\t";
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
int Chairman::UpdataChairman()
{
	string x;
	string y;
	int z;
	string prof;
	string jobt;
	string posit;
	string depart;
	bool ifexist = false;
	bool ifrenew = false;

	string changeof_Chairman;
	Chairman *head = InitLinkChairman();
	PrintLinkChairman(head);

	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++����/019-�����װ/TestChairman.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫ������Ϣ�Ĺ���ʦ���" << endl;
			cin >> changeof_Chairman;
			cout << endl;

			for (Chairman *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
			{
				if (q->Output_Num() == changeof_Chairman)
				{
					cout << "�������š������������Լ�רҵ��ְ���Լ�ְ��Ͳ���" << endl;
					cin >> x >> y >> z >> prof >> jobt >> posit >> depart;
					q->Change_Num(x);
					q->Change_Name(y);
					q->Change_Birday(z);
					q->Change_prof(prof);
					q->Change_jobt(jobt);
					q->Change_posit(posit);
					q->Change_depart(depart);
					ifexist = true;
				}
			}
			if (!ifexist)
			{
				cout << "��������ñ���޶�Ӧ����ʦ�쵼" << endl;
				ifrenew = InitfileChairman(head);
				outfiles.close();
			}
			else
			{
				//д���ļ����º������
				ifrenew = InitfileChairman(head);
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
		cout << "Chairman ��ԱΪ��" << endl;
	}

	return 0;
}

//��ѯ����
int Chairman::SearchChairman()
{
	string searchof_Chairman;
	bool ifexist = false;
	bool isprint = false;

	Chairman *head = InitLinkChairman();
	PrintLinkChairman(head);
	if (head != NULL)
	{
		cout << "��������Ҫ��ѯ��Ϣ�Ĺ���ʦ���" << endl;
		cin >> searchof_Chairman;
		cout << endl;
		for (Chairman *q = head; q != NULL; q = q->next)  // ƥ����Ϣ
		{
			if (q->Output_Num() == searchof_Chairman)
			{
				ifexist = true;
				isprint = true;
				if (isprint)
				{
					cout << "���\t����\t����\tרҵ\tְ��\tְ��\t����\t" << endl;
					isprint = false;
				}
				cout << q->Output_Num() << "\t";
				cout << q->Output_Name() << "\t";
				cout << q->Output_Birday() << "\t";
				cout << q->Output_prof() << "\t";
				cout << q->Output_jobt() << "\t";
				cout << q->Output_posit() << "\t";
				cout << q->Output_depart() << endl;;
			}
		}
		if (!ifexist)
		{
			cout << "��������ñ���޶�Ӧ����ʦ�쵼" << endl;
		}
	}
	else
	{
		cout << "Chaieman����Ϊ0" << endl;
	}
	return 0;
}

//ɾ������
int Chairman::DelChairman()
{
	bool ifexist = false;
	bool ifrenew = false;

	string delof_Chairman;
	Chairman *head = InitLinkChairman();


	if (head != NULL)
	{
		ofstream outfiles;
		outfiles.open("D:/C++����/019-�����װ/TestChairman.txt", ios::out);

		if (outfiles.is_open())
		{
			cout << "��������Ҫɾ����Ϣ�Ĺ���ʦ�쵼���" << endl;
			cin >> delof_Chairman;
			cout << endl;
			if (head->Output_Num() == delof_Chairman)
			{
				Chairman *r;
				r = head;
				head = head->next;
				ifexist = true;
				delete r;
			}
			else
			{
				for (Chairman *q = head; q->next != NULL; q = q->next)  // ƥ����Ϣ
				{
					//if (head->Output_Num() == delof_Engineer)
					//{
					//	head = q->next;
					//	ifexist = true;
					//	break; // ������ͬ��ͬ��ע��
					//}
					if (q->next->Output_Num() == delof_Chairman)
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
				cout << "��������ñ���޶�Ӧ����ʦ�쵼" << endl;
				InitfileChairman(head);
				outfiles.close();
			}
			else
			{
				if (head != NULL)
				{
					ifrenew = InitfileChairman(head);
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
		cout << "Chairman ��ԱΪ��" << endl;
	}
	return 0;
}

Chairman::~Chairman()
{
	//cout << "~Chairman" << endl;
}
