#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;


float Enter()
{
	bool f;
	char s[50];
	int k=0;
	while (1)
	{
		f=true;
		k=0;
		gets(s);
		if (strlen(s)==1&&!isdigit(s[0]))
		{
            puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i]=='-')
			{
				if (i!=0)
				{
					f=false;
					break;
				}
			}
			if (s[i]=='.')
			{
				k++;
				if (i==0||i==strlen(s)-1)
				{
					f=false;
					break;
				}
			}
			if ((!isdigit(s[i])&&s[i]!='.'&&s[i]!='-')||k>1)
			{
				f=false;
				break;
			}
		}
		if (!f) puts("Ошибка ввода! Повторите ввод!");
		else break;
	}
	return atof(s);
}

long double it();
long double rec(int i1);
float E,x;
int n=0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long double ans1=0,ans2=0;
	int i;
	puts("Введите x (от -1.57 до 1.57)");
	while (1)
	{
		x=Enter();
		if (x<(-1.57)||x>1.57)
		{
			puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		break;
	}
	puts("Введите точность E (от 0.000001 до 1)");
	while (1)
	{
		E=Enter();
		if (E<0.0000001||E>1)
		{
			puts("Ошибка ввода! Повторите ввод!");
			continue;
		}
		break;
	}
	do
	{
		n++;
		ans1=it();
		ans2=rec(1);

	}
	while (abs(sin(x)-ans1)>E);
	cout<<"Sin(x)="<<ans1<<endl<<"При n="<<n<<" исследуемое выражение"<<
	" отличается от sin(x)="<<sin(x)<<" менее,\nчем на заданную погрешность E="<<E;
	getch();
	return 0;
}

long double it()
{
	int i,j;
	long double ans=0,k;
	for (i = 1; i <=n; i++)
	{
		k=pow(x,2*i-1);
		for (j = 2; j <= 2*i-1; j++) k/=j;
		ans+=pow(-1.0,i-1)*k;
	}
	return ans;
}

long double rec(int i1)
{
	if (i1==n+1) return 0;
	int j;
	long double k=pow(x,2*i1-1);
	for (j = 2; j <= 2*i1-1; j++) k/=j;
	return rec(i1+1)+pow(-1.0,i1-1)*k;
}
//---------------------------------------------------------------------------
