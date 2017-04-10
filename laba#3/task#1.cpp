#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;

int Enter()
{
	bool f;
	char s[50];
	while (1)
	{
		f=true;
		gets(s);
		for (int i = 0; i < strlen(s); i++)
		{
			if (!isdigit(s[i]))
			{
				f=false;
				break;
			}
		}
		if (!f) puts("Ошибка ввода! Повторите ввод!");
		else break;
	}
	return atoi(s);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int *h = new int[50],*s = new int[50],*v = new int[50],i,n;
	float A=0;
	puts("Введите кол-во замеров ");
	n=Enter();
	puts("Введите расстояние от левого берега,\nглубина реки и скорость(соответственно).\n");
	for (i = 0; i < n; i++)
	{
		s[i]=Enter();
		h[i]=Enter();
		v[i]=Enter();
		cout<<"---------"<<endl;
		if (i!=0) A+=(s[i]-s[i-1])*((abs(h[i]-h[i-1]))/2)*((abs(v[i]-v[i-1]))/2);
	}
	cout<<"Расход воды в сечении: "<<A;
	delete []h;
	delete []s;
	delete []v;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
