
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
#include "List.h"
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
		if (!f) puts("������ �����! ��������� ����!");
		else break;
	}
	return atoi(s);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List lst;
	int i;
	char s[50];
	bool f;
	puts("������� �������������� �����");
	while (1)
	{
		f=true;
		gets(s);
		for (i = 0; i < strlen(s); i++)
		{
			if (!isdigit(s[i]))
			{
				f=false;
				break;
			}
		}
		if (!f) puts("������ �����! ��������� ����!\n");
		else break;
	}

	for (i = 0; i < strlen(s); i++)	lst.Add(((int)s[i])-48);
	int n,a[50];
	char c[50];
	while (1)
	{
		puts("�������� ��������: ");
		puts("1.��������� ���� �������������� ����� ");
		puts("2.������� �� ������� ��������������� ����� �� �������� ");
		puts("3.������������� ������� ��������������� ����� �� �������� ");
		puts("4.��������� ��������������� ����� �� �������� ");
		puts("5.����� ");
		gets(c);
		if (strlen(c)>1||!isdigit(c[0]))
		{
			puts("������ �����! ��������� ����!");
			continue;
		}
		n=((int)c[0])-48;
		if (n>5||n<0)
		{
			puts("������ �����! ��������� ����!\n");
			continue;
		}
		if (n==1)
		{
			puts("������� �������������� ����� ");
			puts("(1 - ������ ������, 2 - ������ ������,3 - �����) ");
			while (1)
			{
				f=true;
				gets(s);
				for (i = 0; i < strlen(s); i++)
				{
					if (!isdigit(s[i]))
					{
						f=false;
						break;
					}
				}
				if (!f) puts("������ �����! ��������� ����!");
				else break;
			}
			for (i = 0; i < strlen(s); i++) a[i]=((int)s[i])-48;
			printf("%d\n",lst.Equal(a,strlen(s)));
		}
		if (n==2)
		{
			puts("������� �������� ����� ");
			lst.LongModShort(Enter());
		}
		if (n==3)
		{
			puts("������� �������� ����� ");
			lst.LongDivShort(Enter());
		}
		if (n==4)
		{
			puts("������� �������� ����� ");
			lst.LongMulShort(Enter());
		}
		if (n==5)
		{
			break;
		}
	}
	getch();
	return 0;
}

