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
#include "Str.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s[80];
	bool f;
	int i;
	printf("Введите кол-во строк в тексте.\n(Не отделять пробелами знаки препинания!)\n");
	while (1)
	{
		f=true;
		gets(s);
		for (i = 0; i < length(s); i++)
		{
			if (!ifDigit(s[i]))
			{
				f=false;
				break;
			}
		}
		if (!f) printf("Ошибка ввода! Повторите ввод!\n");
		else break;
	}
	int j,n = atoi(s),k=0,v,x;
	char S[20][80],temp[80],alpeng[]="abcdefghijklmnopqrstuvwxyz",
	alprus[]="абвгдеёжзийклмнопрстуфхцчшщъыьэюя",sign[]="?!., ";
	for (i = 0; i < n; i++)
	{
		gets(S[i]);
		for (j = 0; j < length(S[i]); j++)
		{
			if (j>2)
			{
				if (S[i][j-1]=='.')
				{
					if (pos(S[i][j],alpeng)!=-1) S[i][j]=char((int)S[i][j]-32);
					if (pos(S[i][j],alprus)!=-1) S[i][j]=char((int)S[i][j]-32);
				}
			}

			if (pos(S[i][j],sign)!=-1)
			{
				s[k]='\0';
				k=0;
				if (temp[0]=='\0')
				{
					copy(temp,s);
					continue;
				}

				if (Strcmp(temp,s)==0)
				{
					for (v = j+1; v < length(S[i]); v++)
					{
						S[i][v-1-length(s)]=S[i][v];
					}
					S[i][v-1-length(s)]='\0';
					j=j-1-length(s);
				}
				copy(temp,s);
			}
			else
			{
				s[k]=lowreg(S[i][j]);
				k++;
			}
		}
		if (Strcmp(temp,s)==0&&pos(S[i][j-1],sign)==-1) S[i][length(S[i])-length(s)-1]='\0';
	}
	for (i = 0; i < n; i++)
	{
		puts(S[i]);
	}
	getch();
	return 0;
}
//---------------------------------------------------------------------------

