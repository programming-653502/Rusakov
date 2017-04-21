//---------------------------------------------------------------------------

#ifndef ReadersListH
#define ReadersListH


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
#include "Readers.h"
using namespace std;

int Penalty;

struct Rdata
{
	String Name,Group,Phone,Email,Note;
	int Penalty;
};

struct Rnode
{
	Rdata x;
	Rnode *Next,*Prev;
};

Rnode *Head = NULL, *Tail = NULL;

class Rlist
{
	int size;

public:
	Rlist()/*:Head(NULL),Tail(NULL)*/{size=0;};
	~Rlist();
	void Show();
	void Add(Rdata);
	void Replace(Rdata,int);
	void Delete(int);
	void Save();
	int Size();
	Rdata Item(int k);
	int Check(Rdata);
};
Rlist rlist;
#endif

