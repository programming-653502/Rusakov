//---------------------------------------------------------------------------

#ifndef ListH
#define ListH


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
using namespace std;

struct Node
{
	int x;
	Node *Next,*Prev;
};

class List
{
	Node *Head,*Tail;
	int size;
public:
	List():Head(NULL),Tail(NULL){size=0;};
	~List();
	void Show();
	void Add(int x);
	void LongMulShort(int k);
	void LongDivShort(int k);
	void LongModShort(int k);
	int Equal(int *a,int n);
};


#endif
