//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

List::~List()
 {
	 while (Head)
	 {
		 Tail=Head->Next;
		 delete Head;
		 Head=Tail;
	 }
 }

 void List::Add(int x)
 {
   size++;
   Node *temp=new Node;
   temp->Next=NULL;
   temp->x=x;

   if (Head!=NULL)
   {
	   temp->Prev=Tail;
	   Tail->Next=temp;
	   Tail=temp;
   }
   else
   {
	   temp->Prev=NULL;
	   Head=Tail=temp;
   }
 }

 void List::Show()
 {
	 Node *temp=Tail;
	 while (temp!=NULL)
	 {
	 cout<<temp->x<<" ";
	 temp=temp->Prev;
	 }
	 cout<<"\n";

	 temp=Head;
	  while (temp!=NULL)
	 {
	 cout<<temp->x<<" ";
	 temp=temp->Next;
	 }
	 cout<<"\n";
 }

void List::LongMulShort(int k)
{
	Node *temp=Tail;
	int a[51],b[51],i=0,j,c,n,v=50,min=100000000;
	for (i = 0; i < 51; i++)
	{
		a[i]=0;
		b[i]=0;
	}
	char s[50];
	itoa(k,s,10);
	n=strlen(s);
	for (i = 51-n; i < 51; i++)
	a[i]=((int)s[i-51+n])-48;
	i=50;
	while (temp!=NULL)
	{
		for (j = i; j > i-n ; j--)
		{
			c=temp->x*a[v]+b[j];
			if (c>9)
			{
				b[j]=(c)%10;
				itoa(c,s,10);
				b[j-1]+=((int)s[0])-48;

				if (j-1<min) min=j-1;
			} 	else           b[j]=c;
			v--;
		}
		temp=temp->Prev;
		i--; v=50;
	}
	for (j = min; j < 51; j++) cout<<b[j];
	cout<<endl;
}

void List::LongDivShort(int k)
{
	Node *temp=Head;
	int a[51],i=0,j=0,v,p;
	for (i = 0; i < 51; i++) a[i]=0;
	char s[50];
	for (v = 0; v < 50; v++) s[v]='\0';
	bool f=false;
	i=0;
	while (temp!=NULL)
	{
		s[i]=(char)(temp->x+48);
		p=atoi(s);
		while (p>=k)
		{
			a[j]=p/k;
			for (v = 0; v < 50; v++) s[v]='\0';
			itoa(p-(k*a[j]),s,10);
			i=strlen(s)-1;
			j++;
			p=atoi(s);
			f=false;
		}
		temp=temp->Next;
		if (f)
		{
			a[j]=0;
			j++;
		}
		i++;
		if (j>0) f=true;
	}

	for (v = 0; v < j; v++) cout<<a[v];
	cout<<endl;
}

void List::LongModShort(int k)
{
	Node *temp=Head;
	int a[51],i=0,j=0,v,p;
	for (i = 0; i < 51; i++) a[i]=0;
	char s[50];
	bool f=false;
	i=0;
	while (temp!=NULL)
	{
		s[i]=(char)(temp->x+48);
		p=atoi(s);
		while (p>=k)
		{
			a[j]=p/k;
			for (v = 0; v < 50; v++) s[v]='\0';
			itoa(p-(k*a[j]),s,10);
			i=strlen(s)-1;
			j++;
			p=atoi(s);
			f=false;
		}
		temp=temp->Next;
		if (f)
		{
			a[j]=0;
			j++;
		}
		i++;
		if (j>0) f=true;
	}

	cout<<p;
	cout<<endl;
}

int List::Equal(int *a,int n)
{
	Node *temp=Head;
	int i=0;
	if (size>n) return 1;
	if (size<n) return -1;
	while (temp!=NULL)
	{
		if (temp->x>a[i]) return 1;
		if (temp->x<a[i]) return -1;
		temp=temp->Next;
		i++;
	}
	return 0;
}

