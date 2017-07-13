#include "stdafx.h"
#include "Staff.h"


Staff::Staff()
{
	//cout << "Staff" << endl;
}

Staff::Staff(string x, string y, int z)
{
	Num = x;
	Name = y;
	Birday = z;
	//cout << "Staff_2" << endl;
}

string Staff::Output_Num()
{
	//cout << Num << endl;
	return Num;
}

string Staff::Output_Name()
{
	//cout << Name << endl;
	return Name;
}

int Staff::Output_Birday()
{
	//cout << Birday << endl;
	return Birday;
}


void Staff::Change_Num(string a)
{
	Num = a;
	//cout << Num << endl;
}

void Staff::Change_Name(string a)
{
	Name = a;
	//cout << Name << endl;
}

void Staff::Change_Birday(int a)
{
	Birday = a;
	//cout << Birday << endl;
}


Staff::~Staff()
{
	//cout << "~Staff" << endl;
}
