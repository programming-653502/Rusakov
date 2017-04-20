#pragma hdrstop

#include "ReadersList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Rlist::~Rlist()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void Rlist::Add(Rdata pdata)
{
	FReaders->Grid->RowCount += 1;
	size++;
	Rnode *temp = new Rnode;
	temp->Next = NULL;
	temp->x    = pdata;
	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
}

void Rlist::Show()
{
	Rnode *temp = Head;
	int i = 1;
	while (temp != NULL)
	{
		FReaders->Grid->Cells[0][i] = temp->x.Name;
		FReaders->Grid->Cells[1][i] = temp->x.Group;
		FReaders->Grid->Cells[2][i] = temp->x.Phone;
		FReaders->Grid->Cells[3][i] = temp->x.Email;
		FReaders->Grid->Cells[4][i] = temp->x.Note;
		i++;
		temp = temp->Next;
	}

}

int Rlist::Size() {return size;}

int Rlist::Check(Rdata pdata)
{
	Rnode *temp = Head;
	int i = 0;
	while (temp != NULL)
	{
		if (temp->x.Name  == pdata.Name
		&&  temp->x.Group == pdata.Group
		&&  temp->x.Email == pdata.Email
		&&  temp->x.Phone == pdata.Phone
		&&  temp->x.Note  == pdata.Note) return i;
		temp = temp->Next;
		i++;
	}
	return -1;
}

void Rlist::Replace(Rdata pdata,int j)
{
	Rnode *temp = Head;
	int i = 0;
	while (temp != NULL)
	{
		if (i == j)
		{
			temp->x = pdata;
			return;
		}
		i++;
		temp = temp->Next;
	}
}

void Rlist::Delete(int j)
{
	if (Head == NULL) {return;}
	Rnode *temp = Head;
	FReaders->Grid->RowCount -= 1;
	size--;
	if (size==0)
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

void Rlist::Save()
{
	String Dir = "e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Readers\\";

	TStringList *List = new TStringList, *RList = new TStringList;
	Rnode *temp = Head;
	while (temp != NULL)
	{
		List->Add(temp->x.Name);;
		List->Add(temp->x.Group);
		List->Add(temp->x.Phone);
		List->Add(temp->x.Email);
		List->Add(temp->x.Note);
		List->Add(temp->x.Penalty);
		temp = temp->Next;
	}
	List->SaveToFile(Dir+"Grid.txt");
	delete List;
	Dir = "e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Accountability.txt";
	RList->LoadFromFile(Dir);
	RList->Strings[3] = IntToStr(size);
	RList->SaveToFile(Dir);
	delete RList;
}

Rdata Rlist::Item(int k)
{
	Rnode *temp = Head;
	int i = 0;
	while (temp != NULL)
	{
		if (i == k) return temp->x;
		temp = temp->Next;
		i++;
	}
	Rdata y;
	y.Name    = "";
	y.Group   = "";
	y.Phone   = "";
	y.Email   = "";
	y.Note 	  = "";
	y.Penalty = 0;
	return y;
}




