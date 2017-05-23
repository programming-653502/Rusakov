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

void List::Add(Data pdata)
{
	size++;
	Node *temp=new Node;
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

void List::Clear()
{
	while (Head)
	{
		Tail=Head->Next;
		Head->x.STarget->Width = 0;
		Head->x.STarget->Height = 0;
		delete Head;
		Head=Tail;
	}
	Head = NULL;
	Tail = NULL;
	size = 0;
}


void List::Show(wchar_t *Dir)
{
	int i = 0;
	Node *temp = Head;
	while (temp!=NULL)
	{
		if (!temp->x.F)
		{
			temp->x.STarget->Top --;
			temp->x.STarget->Left --;
			temp->x.STarget->Width +=2;
			temp->x.STarget->Height+=2;

		} else
		{
			temp->x.STarget->Top ++;
			temp->x.STarget->Left ++;
			temp->x.STarget->Width-=2;
			temp->x.STarget->Height-=2;
		}
		if (temp->x.STarget->Width == 50) temp->x.F = true;
		if (temp->x.STarget->Width == 0)
		{
			wchar_t temp[255],play[255] = L"play ", stop[255] = L"stop ";
			if (FMain->CBSound->Checked)
			{
				wcscpy( temp, Dir );
				wcscat( temp, L"//Fail.wav");
				wcscat( play, temp );
				wcscat( stop, temp );
				mciSendString(stop,0,0,0);
				mciSendString(play,0,0,0);
			}
			Lose++;
			if (Lose == 1)
			{
				FMain->Image3->Hide();
			}
			if (Lose == 2)
			{
				FMain->Image3->Hide();
				FMain->Image2->Hide();
			}
			if (Lose == 3)
			{
				wcscpy( temp, Dir );
				wcscat( temp, L"//Record.txt");
				TStringList *List = new TStringList;
				List->LoadFromFile( temp );
				if (StrToInt(FMain->LHitNum->Caption) > StrToInt(List->Strings[2]))
				{
					if (FMain->CBSound->Checked)
					{
						wchar_t temp1[255];
						wcscpy( play, L"play " );
						wcscpy( stop,  L"stop " );
						wcscpy( temp1, Dir );
						wcscat( temp1, L"//Record.wav");
						wcscat( play, temp1 );
						wcscat( stop, temp1 );
						mciSendString(stop,0,0,0);
						mciSendString(play,0,0,0);

					}
					FMain->LGameOver->Caption = "New Record!";
					FMain->LGameOver->Font->Color = RGB( 238, 221, 130 );
					List->Clear();
					List->Add(FMain->LMinutes->Caption);
					List->Add(FMain->LSeconds->Caption);
					List->Add(FMain->LHitNum->Caption);
					List->Add(FMain->LMissNum->Caption);
					List->SaveToFile( temp );
				} else
				{
					if (FMain->CBSound->Checked)
					{
						wchar_t temp1[255];
						wcscpy( play, L"play " );
						wcscpy( stop,  L"stop " );
						wcscpy( temp1, Dir );
						wcscat( temp1, L"//GameOver.wav");
						wcscat( play, temp1 );
						wcscat( stop, temp1 );
						mciSendString(stop,0,0,0);
						mciSendString(play,0,0,0);
					}
					FMain->LGameOver->Caption = "Game Over!";
					FMain->LGameOver->Font->Color = clRed;
				}
                FMain->BRetry->Show();
				FMain->Label->Hide();
				FMain->BackGround->Hide();
                FMain->Image3->Hide();
				FMain->Image2->Hide();
				FMain->Image1->Hide();
				FMain->Timer1->Enabled = false;
				list.Clear();
				FMain->LGameOver->Show();
				Lose = 0;
				FMain->Timer2->Enabled = false;
				FMain->Timer3->Enabled = false;
				Flag = false;
				FMain->Timer2->Interval = 500;
				delete List;
				return;
			}
			list.Delete(i);
		}
		temp=temp->Next;
		i++;
	}
}

int List::Size() {return size;}

void List::Find(int X,int Y, int C)
{
	Node *temp = Head;
	int i = 0;
	float CenX,CenY,R,Dis,Code;
	while (temp != NULL)
	{
		if (C == temp->x.STarget->GetHashCode())
		{
			Delete(i);
		}
		temp = temp->Next;
		i++;
	}
}

/*void List::Replace(Data pdata,int j)
{
	Node *temp=Head;
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
}      */

void List::Delete(int j)
{
	if (Head == NULL) {return;}
	Node *temp = Head;
	size--;
	if (size==0)
	{
		temp->x.STarget->Width = 0;
		temp->x.STarget->Height = 0;
		delete temp;
		Head = NULL;
		Tail = NULL;
		return;
	}
	if (j == 0)
	{
		Head = temp->Next;
		temp->Next->Prev=NULL;
		temp->x.STarget->Width = 0;
		temp->x.STarget->Height = 0;
		delete temp;
		return;
	}
	if (j == size)
	{
		temp=Tail;
		Tail = temp->Prev;
		Tail->Next=NULL;
		temp->x.STarget->Width = 0;
		temp->x.STarget->Height = 0;
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
			temp->x.STarget->Width = 0;
			temp->x.STarget->Height = 0;
			delete temp;
			return;
		}
		i++;
		temp = temp->Next;
	}


}

/*void List::Save()
{
	String Dir="e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Book\\";
	int Cost = 0, Given = 0, BNum = 0;
	TStringList *List = new TStringList,*List =  new TStringList;
	Node *temp=Head;
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
	List->LoadFromFile(Dir);
	List->Strings[0] = IntToStr(BNum);
	List->Strings[1] = IntToStr(Cost);
	List->Strings[2] = IntToStr(Given);
	List->SaveToFile(Dir);
	delete List;
}           */

/*Data List::Item(int k)
{
	Node *temp = Head;
	int i = 0;
	while (temp != NULL)
	{
		if (i == k) return temp->x;
		temp = temp->Next;
		i++;
	}
	/*Data y;
	y.Name   = "";
	y.Author = "";
	y.Cost   = "";
	y.Num    = "";
	y.Note 	 = "";
	y.Given  =  0;
	return y;
}                */






