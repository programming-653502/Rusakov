#pragma hdrstop

#include "BookList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Blist::~Blist()
{
	while (BHead)
	{
		BTail=BHead->Next;
		delete BHead;
		BHead=BTail;
	}
}

void Blist::Add(Data pdata)
{
	FBook->Grid->RowCount += 1;
	size++;
	Node *temp=new Node;
	temp->Next=NULL;
	temp->x=pdata;
	if (BHead!=NULL)
	{
		temp->Prev=BTail;
		BTail->Next=temp;
		BTail=temp;
	}
	else
	{
		temp->Prev=NULL;
		BHead=BTail=temp;
	}
}

void Blist::Show()
{
	Node *temp=BHead;
	int i=1;
	while (temp!=NULL)
	{
		FBook->Grid->Cells[0][i]=temp->x.Name;
		FBook->Grid->Cells[1][i]=temp->x.Author;
		FBook->Grid->Cells[2][i]=temp->x.Cost;
		FBook->Grid->Cells[3][i]=temp->x.Num;
		FBook->Grid->Cells[4][i]=temp->x.Note;
		i++;
		temp=temp->Next;
	}

}

int Blist::Size() {return size;}

int Blist::Check(Data pdata)
{
	Node *temp=BHead;
	int i=0;
	while (temp!=NULL)
	{
		if (temp->x.Name==pdata.Name
		&&  temp->x.Author==pdata.Author
		&&  temp->x.Cost==pdata.Cost
		&&  temp->x.Note==pdata.Note) return i;
		temp=temp->Next;
		i++;
	}
	return -1;
}

void Blist::Replace(Data pdata,int j)
{
	Node *temp=BHead;
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

void Blist::Delete(int j)
{
	if (BHead == NULL) {return;}
	Node *temp = BHead;
	FBook->Grid->RowCount -= 1;
	size--;
	if (size==0)
	{
		delete temp;
		BHead = NULL;
		BTail = NULL;
		return;
	}
	if (j == 0)
	{
		BHead = temp->Next;
		temp->Next->Prev=NULL;
		delete temp;
		return;
	}
	if (j == size)
	{
		temp=BTail;
		BTail = temp->Prev;
		BTail->Next=NULL;
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

void Blist::Save()
{
	String Dir="e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Book\\";
	int Cost = 0, Given = 0, BNum = 0;
	TStringList *List = new TStringList,*BList =  new TStringList;
	Node *temp=BHead;
	while (temp!=NULL)
	{
		Cost  += StrToInt(temp->x.Num)*StrToInt(temp->x.Cost);
		Given += temp->x.Given;
		BNum  += StrToInt(temp->x.Num);
		List->Add(temp->x.Name);
		List->Add(temp->x.Author);
		List->Add(temp->x.Cost);
		List->Add(temp->x.Num);
		List->Add(temp->x.Note);
		List->Add(temp->x.Given);
		temp=temp->Next;
	}
	List->SaveToFile(Dir+"Grid.txt");
	delete List;
	Dir = "e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Accountability.txt";
	BList->LoadFromFile(Dir);
	BList->Strings[0] = IntToStr(BNum);
	BList->Strings[1] = IntToStr(Cost);
	BList->Strings[2] = IntToStr(Given);
	BList->SaveToFile(Dir);
	delete BList;
}

Data Blist::Item(int k)
{
	Node *temp = BHead;
	int i = 0;
	while (temp != NULL)
	{
		if (i == k) return temp->x;
		temp = temp->Next;
		i++;
	}
	Data y;
	y.Name   = "";
	y.Author = "";
	y.Cost   = "";
	y.Num    = "";
	y.Note 	 = "";
	y.Given  =  0;
	return y;
}





