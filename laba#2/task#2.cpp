#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;

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
	printf("¬ведите x ");
	scanf("%f",&x);

	printf("¬ведите точность E ");
	scanf("%f",&E);
	do
	{
		n++;
		ans1=it();
		ans2=rec(1);

	}
	while (abs(sin(x)-ans1)>E);
	cout<<ans1<<" "<<n;
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
