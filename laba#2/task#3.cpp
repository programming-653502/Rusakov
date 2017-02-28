#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;

unsigned long long int fact(int x);
float it(float x, float E);
int rec();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float x1=0,E1=0;
	scanf("%f",&x1);
	printf("%d",fact((int)x1));
	getch();
	return 0;
}

unsigned long long int fact(int x)
{
	int i;
	unsigned long long int ans=1;
	for (i = 1; i <= x; i++) {
	ans=ans*i;
	}
	return ans;
}

float it(float x,float E)
{
	int n=0,i;
	float ans;
	do
	{
		n++;
		ans=0;
		for (i = 1; i <=n; i++)
		{
			ans+=pow(-1.0,i-1)*(pow(x,2*i-1)/fact(2*i-1));
		}
	}
	while (abs(sin(x)-ans)>E);
	return ans;
}
//---------------------------------------------------------------------------
