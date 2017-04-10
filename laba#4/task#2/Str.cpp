//---------------------------------------------------------------------------

#pragma hdrstop

#include "Str.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int length(char *s)
{
	int i=0;
	while (*s!='\0')
	{
		s++;
		i++;
	}
	return i;
}

char lowreg(char c)
{
	char  ALPENG[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		  ALPRUS[]="ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß",
		  alpeng[]="abcdefghijklmnopqrstuvwxyz",
		  alprus[]="àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
	if (pos(c,ALPENG)!=-1) return alpeng[pos(c,ALPENG)];	else
	if (pos(c,ALPRUS)!=-1) return alprus[pos(c,ALPRUS)];	else
						   return c;

}

char *ob(char *s1,char *s2)
{
	int l1,l2,i;
	l1=length(s1);
	l2=length(s2);
	for (i = l1; i <=l1+l2; i++) {
	s1[i]=s2[i-l1];
	}
	return s1;
}

void copy(char *s1,char *s2)
{
	while (*s2!='\0')
	{
		*s1=*s2;
		*s1++; *s2++;
	}
	*s1=*s2;
}

int pos(char c,char *s)
{
	int i=0;;
	bool f=false;
	while (*s!='\0')
	{
		if (*s==c)
		{
			f=true;
			break;
		}
		*s++;
		i++;
	}
	if (f)	return i;
	else    return -1;
}

int Strcmp(char *s1,char *s2)
{
  while ((*s1!='\0')&&(*s2!='\0'))
  {
	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	++s1; ++s2;
  }
  if (*s1='\0') return -1; else
  if (*s2='\0') return 1; else
  return 0;
}


bool ifDigit(char c)
{
	char dig[]="0123456789";
	bool f=false;
	if (pos(c,dig)!=-1) f=true;
	return f;
}
