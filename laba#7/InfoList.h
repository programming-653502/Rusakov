//---------------------------------------------------------------------------

#ifndef InfoListH
#define InfoListH


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
#include "ReadersInfo.h"
using namespace std;

struct IData
{
	String Name,Author,Cost,Num,Note;
};

struct INode
{
	IData x;
	INode *Next,*Prev;
};


class Ilist
{
	int size;
	INode *Head,*Tail;
public:
	Ilist():Head(NULL),Tail(NULL){size=0;};
	~Ilist();
	void Show();
	void Add(IData);
	void Replace(IData,int);
	void Delete(int);
	void Save(String);
	int Size();
	int Check(String);
	IData Item(int);
	void Clear();
};
#endif

