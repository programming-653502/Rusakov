//---------------------------------------------------------------------------

#ifndef ListH
#define ListH


#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <iomanip>
#include <system.hpp>
#include <SysUtils.hpp>
#include "Main.h"
using namespace std;

int Lose = 0;

struct Data
{
	TShape* STarget;
	bool F;
};
struct Node
{
	Data x;
	Node *Next, *Prev;
};

Node *Head=NULL,*Tail=NULL;

class List
{
	int size;
	//Node *Head,*Tail;
public:
	List()/*:Head(NULL),Tail(NULL)*/{size = 0;};
	~List();
	void Clear();
	void Show(wchar_t*);
	void Add(Data);
	//void Replace(Data,int);
	void Delete(int);
	//void Save();
	//Data Item(int k);
	int Size();
	void Find(int,int,int);
};
List list;
#endif

