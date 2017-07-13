#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Staff
{
private:
	string Num; // ±àºÅ 
	string Name;//ĞÕÃû
	int Birday;//ÄêÁä
public:
	Staff();
	Staff(string x, string y, int z);

	string Output_Num();
	string Output_Name();
	int Output_Birday();
	void Change_Num(string a);
	void Change_Name(string a);
	void Change_Birday(int a);
	~Staff();
};

