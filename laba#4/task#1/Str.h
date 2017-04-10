//---------------------------------------------------------------------------

#ifndef StrH
#define StrH

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

void copy(char *s1,char *s2);

int length(char *s);

int pos(char c,char *s);

bool ifDigit(char c);

int Strcmp(char *s1,char *s2);

char lowreg(char c);

char *ob(char *s1,char *s2);

#endif
