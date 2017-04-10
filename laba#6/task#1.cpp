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
using namespace std;

struct Item
{
	int data;
	Item *left,*right;
};

void AddNode(int data, Item **node);
void LeftOrder(Item *node);
void RightOrder(Item *node);

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

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	randomize();
	char buff[128];
	int i,j,n=0,a[50][50],x,y,max=-1000000000,x1,y1;
	Item *root[50][50];
	for (i = 0; i < 50; i++)
	for (j = 0; j < 50; j++) root[i][j]=NULL;


	ifstream File1("Text.txt");
	if (!File1.is_open())
	{
		cout<<"Файл не может быть открыт или создан.\n";
		getch();
		return 0;
	}

	File1.seekg(0,File1.end);
	if (File1.tellg()==0)
	{
		cout<<"Файл пуст!\n";
		getch();
		return 0;
	}
	while (File1.tellg()!=0)
	{
		if (File1.peek()=='\n') n++;
		File1.seekg(-1,File1.cur);
	}
	File1.seekg(0,File1.beg);
	puts("Введите размеры \"поля\"(<=50)");
	while (1)
	{
		x=Enter();
		if (x<0||x>50)
		{
			puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		break;
	}
	while (1)
	{
		y=Enter();
		if (y<0||y>50)
		{
			puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		break;
	}
	for (i = 0; i < n; i++)
	{
		File1.getline(buff,50);
		x1=rand()%x;
		y1=rand()%y;
		a[x1][y1]++;
		AddNode(atoi(buff), &root[x1][y1]);
	}
	for (i = 0; i < x; i++)
	for (j = 0; j < y; j++)
	if (max<a[i][j])
	{
		max=a[i][j];
		x1=i; y1=j;
	}
	puts("Cамое \"плодовитое\" дерево: ");
	LeftOrder(root[x1][y1]);
	printf("\n");
	RightOrder(root[x1][y1]);
	getch();
	File1.close();
	return 0;
}

void AddNode(int data, Item **node)
{
	if (*node == NULL)
	{
		*node = (Item *)calloc(1, sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	} else
	{
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else
		if (data > (*node)->data)
			AddNode(data, &(*node)->right);
	}
}

void LeftOrder(Item *node)
{
	if (node->left) LeftOrder(node->left);
	printf("%d ", node->data);
	if (node->right)
	LeftOrder(node->right);
}

void RightOrder(Item *node)
{
	if (node->right) RightOrder(node->right);
	printf("%d ", node->data);
	if (node->left)
	RightOrder(node->left);
}
