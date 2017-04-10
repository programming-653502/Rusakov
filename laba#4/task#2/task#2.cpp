//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <fstream>
#include "Str.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char buff[50][50];
	int i,j,n=1;
	cout<<"¬ведите текст в файл \"Text.txt\".\n";
	ifstream File1("Text.txt");
	if (!File1.is_open())
	{
		cout<<"‘айл не может быть открыт или создан.\n";
		getch();
		return 0;
	}
	File1.seekg(0,File1.end);
	if (File1.tellg()==0)
	{
		cout<<"‘айл пуст!\n";
		getch();
		return 0;
	}
	while (File1.tellg()!=0)
	{
		if (File1.peek()=='\n') n++;
		File1.seekg(-1,File1.cur);
	}
	//cout<<n<<endl;

	File1.seekg(0,File1.beg);

	for (i = 0; i < n; i++)
	{
		File1.getline(buff[i],50);
		//cout<<buff[i]<<endl;
	}
	File1.close();
	char s1[]=".,:;!?}])",s2[]="{[(";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < length(buff[i]); j++)
		{
			if (j!=0)
			{
				if (pos(buff[i][j],s1)!=-1 && buff[i][j-1]==' ')
				{
					buff[i][j-1]=buff[i][j];
					buff[i][j]=' ';
				}
			}
			if (j!=length(buff[i])-1)
			{
				if (pos(buff[i][j],s2)!=-1 && buff[i][j+1]==' ')
				{
					buff[i][j+1]=buff[i][j];
					buff[i][j]=' ';
				}
			}
		}
	}


	fstream File("Text.txt", ios_base::out | ios_base::trunc);
	for (i = 0; i < n; i++)
	{
		if (i==n-1) File<<buff[i];
		else File<<buff[i]<<endl;
	}
	File.close();

	getch();
	return 0;
}
//---------------------------------------------------------------------------
