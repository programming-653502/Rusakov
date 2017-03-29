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

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int *h = new int[50],*s = new int[50],*v = new int[50],i,n;
	float A=0;
	printf("Введите кол-во замеров ");
	scanf("%d",&n);
	printf("Введите расстояние от левого берега,\nглубина реки и скорость течения в одну строку\n");
	for (i = 0; i < n; i++) {
	scanf("%d %d %d",&s[i],&h[i],&v[i]);
	if (i!=0) A+=(s[i]-s[i-1])*((h[i]-h[i-1])/2)*((v[i]-v[i-1])/2);
	}
	cout<<"Расход воды в сечении: "<<A;
	delete []h;
	delete []s;
	delete []v;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
