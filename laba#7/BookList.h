//---------------------------------------------------------------------------

#ifndef BookListH
#define BookListH


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
#include "Book.h"
using namespace std;

struct Data
{
	String Name,Author,Cost,Num,Note;
	int Given;
};

struct Node
{
	Data x;
	Node *Next,*Prev;
};

Node *BHead=NULL,*BTail=NULL;

class Blist
{
	int size;
	//Node *Head,*Tail;
public:
	Blist()/*:Head(NULL),Tail(NULL)*/{size=0;};
	~Blist();
	void Show();
	void Add(Data);
	void Replace(Data,int);
	void Delete(int);
	void Save();
	Data Item(int k);
	int Size();
	int Check(Data);
};
Blist blist;
#endif

