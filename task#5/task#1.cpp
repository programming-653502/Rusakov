
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
		if (!f) puts("Ошибка ввода! Повторите ввод!");
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
	puts("Введите многоразрядное число");
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
		if (!f) puts("Ошибка ввода! Повторите ввод!\n");
		else break;
	}

	for (i = 0; i < strlen(s); i++)	lst.Add(((int)s[i])-48);
	int n,a[50];
	char c[50];
	while (1)
	{
		puts("Выберите действие: ");
		puts("1.Сравнение двух многоразрядных чисел ");
		puts("2.Остаток от деления многоразрядного числа на короткое ");
		puts("3.Целочисленное деление многоразрядного числа на короткое ");
		puts("4.Умножение многоразрядного числа на короткое ");
		puts("5.Выход ");
		gets(c);
		if (strlen(c)>1||!isdigit(c[0]))
		{
			puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		n=((int)c[0])-48;
		if (n>5||n<0)
		{
			puts("Ошибка ввода! Повторите ввод!\n");
			continue;
		}
		if (n==1)
		{
			puts("Введите многоразрядное число ");
			puts("(1 - первое больше, 2 - второе больше,3 - равны) ");
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
				if (!f) puts("Ошибка ввода! Повторите ввод!");
				else break;
			}
			for (i = 0; i < strlen(s); i++) a[i]=((int)s[i])-48;
			printf("%d\n",lst.Equal(a,strlen(s)));
		}
		if (n==2)
		{
			puts("Введите короткое число ");
			lst.LongModShort(Enter());
		}
		if (n==3)
		{
			puts("Введите короткое число ");
			lst.LongDivShort(Enter());
		}
		if (n==4)
		{
			puts("Введите короткое число ");
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

