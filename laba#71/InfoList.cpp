#pragma hdrstop

#include "InfoList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ilist::~Ilist()
{
	while (Head)
	{
		Tail=Head->Next;
		delete Head;
		Head=Tail;
	}
}

void Ilist::Add(IData pdata)
{
	FInfo->Grid->RowCount += 1;
	size++;
	INode *temp=new INode;
	temp->Next=NULL;
	temp->x=pdata;
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

void Ilist::Clear()
{
	while (Head)
	{
		Tail=Head->Next;
		delete Head;
		Head=Tail;
	}
	Head = NULL;
	Tail = NULL;
	size = 0;
}

void Ilist::Show()
{
	INode *temp=Head;
	int i=1;
	while (temp!=NULL)
	{
		FInfo->Grid->Cells[0][i]=temp->x.Name;
		FInfo->Grid->Cells[1][i]=temp->x.Author;
		FInfo->Grid->Cells[2][i]=temp->x.Cost;
		FInfo->Grid->Cells[3][i]=temp->x.Note;
		i++;
		temp=temp->Next;
	}

}

int Ilist::Size() {return size;}

int Ilist::Check(String s)
{
	INode *temp=Head;
	int i=0;
	while (temp!=NULL)
	{
		if (temp->x.Name == s) return i;
		temp=temp->Next;
		i++;
	}
	return -1;
}

void Ilist::Replace(IData pdata,int j)
{
	INode *temp=Head;
	int i=0;
	while (temp!=NULL)
	{
		if (i==j)
		{
			temp->x=pdata;
			return;
		}
		i++;
		temp=temp->Next;
	}
}

void Ilist::Delete(int j)
{
	if (Head == NULL) {return;}
	INode *temp = Head;
	FInfo->Grid->RowCount -= 1;
	size--;
	if (size == 0)
	{
		delete temp;
		Head = NULL;
		Tail = NULL;
		return;
	}
	if (j == 0)
	{
		Head = temp->Next;
		temp->Next->Prev=NULL;
		delete temp;
		return;
	}
	if (j == size)
	{
		temp=Tail;
		Tail = temp->Prev;
		Tail->Next=NULL;
		delete temp;
		return;
	}
	int i = 1;
	temp = temp->Next;
	while (temp != NULL)
	{
		if (i == j)
		{
			temp->Prev->Next=temp->Next;
			temp->Next->Prev=temp->Prev;
			delete temp;
			return;
		}
		i++;
		temp = temp->Next;
	}


}

void Ilist::Save(String S)
{
	String Dir="e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Info\\";

	TStringList *List= new TStringList;
	INode *temp=Head;
	while (temp!=NULL)
	{
		List->Add(temp->x.Name);
		List->Add(temp->x.Author);
		List->Add(temp->x.Cost);
		List->Add(temp->x.Num);
		List->Add(temp->x.Note);
		temp=temp->Next;
	}
	//char s[200];
	//AnsiString S1 = Dir+S+".txt";
	//strcpy( s, S1.c_str() );
	//DeleteFile(Dir+S+".txt");
	//ofstream File(s);
	//File.close();
	List->SaveToFile(Dir+S+".txt");

	delete List;
}

IData Ilist::Item(int k)
{
	INode *temp = Head;
	int i = 0;
	while (temp != NULL)
	{
		if (i == k) return temp->x;
		temp = temp->Next;
		i++;
	}
	IData y;
	y.Name    = "";
	y.Author  = "";
	y.Cost    = "";
	y.Num     = "";
	y.Note    = "";
	return y;
}





