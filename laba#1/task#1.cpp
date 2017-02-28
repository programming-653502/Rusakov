#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol=0,i,j,k,x=0;
	printf("Первые 10 пифагоровыx тройки:\n");
	for (i = 1; i < 100; i++)
	for (j = i+1; j < 100; j++)
	for (k = j+1; k < 100; k++)
	  if (i*i+j*j==k*k)
		{
			kol++;
			printf("%d, %d, %d\n", i, j, k);
			if (kol==10)
			{
				getch();
				return 0;
			}
		}

}
//---------------------------------------------------------------------------
