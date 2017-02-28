#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int bask[2];

void exit();
void Menu();
void mandarin();
void peach();
void grapes();
void basket();
void price();
void feedback();
void rep();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol=0,i,j,k,x=0;
	printf("��� ������������ ��������-������� \"eFruit\"\n");
	printf("���������� �������� ��� �����\n");
	Menu();
	getch();
}

void exit()
{
	return;
}

void rep()
{
	char c[20];
	printf("������� ����������?(��/���)\n");
	scanf("%s",&c);
	if (!strcmp(c,"��"))
	{
		Menu();
		return;
	} else
	if (!strcmp(c,"���"))
	{
		exit();
		return;
	} else
	{
		printf("������ �����!\n��������� ����\n");
		rep();
		return;
	}
}

void mandarin()
{
	int i,k=0,weight;
	char s[20];

	printf("������� ����������(��)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("������ �����!\n��������� ����\n");
			mandarin();
			return;
		}
	}
	weight=atoi(s);
	bask[0]=bask[0]+weight;
	rep();
}

void peach()
{
	int i,k=0,weight;
	char s[20];

	printf("������� ����������(��)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("������ �����!\n��������� ����\n");
			peach();
			return;
		}
	}
	weight=atoi(s);
	bask[1]=bask[1]+weight;
	rep();
}

void grapes()
{
	int i,k=0,weight;
	char s[20];

	printf("������� ����������(��)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("������ �����!\n��������� ����\n");
			grapes();
			return;
		}
	}
	weight=atoi(s);
	bask[2]=bask[2]+weight;
	rep();
}

void basket()
{
	int weight=bask[0]+bask[1]+bask[2];

	if (!weight)
	{
		printf("�� ������ �� ��������\n");
		rep();
		return;
	}
	printf("\n�� ��������:\n");
	printf("��������� - %d(��)\n",bask[0]);
	printf("������� - %d(��)\n",bask[1]);
	printf("�������� - %d(��)\n",bask[2]);
	rep();
}

void price()
{
	int weight=0,deliv=0;
	double sum=0;

	weight=bask[0]+bask[1]+bask[2];
	if (!weight)
	{
		printf("�� ������ �� ��������\n");
		rep();
		return;
	}

	printf("\n��������� - 1,14$ �� ��.\n");
	printf("������� - 1,00$ �� ��.\n");
	printf("�������� - 1,28$ �� ��.\n");
	sum=bask[0]*1.14+bask[1]+bask[2]*1.28;
	if (sum>=100)
	{
		printf("��� ��������������� ������ � ������� 10%\n");
		sum=sum*0.9;
	}
	else printf("��� �� ��������������� ������\n");
	if (weight<5) deliv=1; else
	if ((weight>=5)&&(weight<=20)) deliv=3;
	else deliv=10+weight*2;
	printf("������� �� ��������: %d\n",deliv);
	printf("����� ��������� ������: %.2f\n",deliv+sum);
	rep();
}

void feedback()
{
	printf("\n������� \"eFruit\"\n");
	printf("����� �������� 6484392302352\n");
	printf("���������� ����������:\n");
	printf("������� +375291168548\n");
	rep();
}

void Menu()
{
	int num;
	char c[20];

	printf("\n1.����� ����������(��)\n");
	printf("2.����� ��������(��)\n");
	printf("3.����� ���������(��)\n");
	printf("4.���������� �������\n");
	printf("5.��������� ��������� ������\n");
	printf("6.�������� �����\n");
	printf("7.��������� �����\n\n");
	printf("������� ����� �� 1 �� 7\n");
	scanf("%s",&c);
	if (!isdigit(c[0])||(strlen(c)>1))
	{
		printf("������ �����!\n��������� ����\n");
		Menu();
		return;
	}
	num=(int)c[0]-48;
	if ((num<1)||(num>7))
	{
		printf("������ �����!\n��������� ����\n");
		Menu();
		return;
	}
	switch (num){
	case 1:
	{
		mandarin();
		break;
	}
	case 2:
	{
		peach();
		break;
	}
	case 3:
	{
		grapes();
		break;
	}
	case 4:
	{
		basket();
		break;
	}
	case 5:
	{
		price();
		break;
	}
	case 6:
	{
		feedback();
		break;
	}
	case 7:
	{
		exit();
		break;
	}}
}

//---------------------------------------------------------------------------

