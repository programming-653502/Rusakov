//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Book.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFBook *FBook;

bool Modified;
int ColN,RowN;

//---------------------------------------------------------------------------
__fastcall TFBook::TFBook(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Modif()
{
	Modified = false;
	Data x;
	x.Name   = FBook->Grid->Cells[0][RowN];
	x.Author = FBook->Grid->Cells[1][RowN];
	x.Cost   = FBook->Grid->Cells[2][RowN];
	x.Num    = FBook->Grid->Cells[3][RowN];
	x.Note   = FBook->Grid->Cells[4][RowN];
	x.Given  = blist.Item(RowN-1).Given;
	FBook->CBookName->   Items->Delete(RowN-1);
	FBook->CBookName->   Items->Insert(RowN-1,x.Name);
	FBook->CBookAuthor-> Items->Delete(RowN-1);
	FBook->CBookAuthor-> Items->Insert(RowN-1,x.Author);
	FBook->CBookCost->   Items->Delete(RowN-1);
	FBook->CBookCost->   Items->Insert(RowN-1,x.Cost);
	FBook->CBookNum->    Items->Delete(RowN-1);
	FBook->CBookNum->    Items->Insert(RowN-1,x.Num);
	FBook->CBookNote->   Items->Delete(RowN-1);
	FBook->CBookNote->   Items->Insert(RowN-1,x.Note);
	blist.Replace(x,RowN-1);
	blist.Save();
}

void ClearGrid()
{
	for (int i = 0; i < 5; i++)
	for (int j = 1; j < FBook->Grid->RowCount; j++)
	FBook->Grid->Cells[i][j] = "";

}

void ComboBoxClear()
{
	FBook->CBookName   ->ItemIndex = -1;
	FBook->CBookAuthor ->ItemIndex = -1;
	FBook->CBookCost   ->ItemIndex = -1;
	FBook->CBookNum    ->ItemIndex = -1;
	FBook->CBookNote   ->ItemIndex = -1;
	FBook->CBookName   ->Text = "";
	FBook->CBookAuthor ->Text = "";
	FBook->CBookCost   ->Text = "";
	FBook->CBookNum    ->Text = "";
	FBook->CBookNote   ->Text = "";
}

void __fastcall TFBook::BBookBackClick(TObject *Sender)
{
	FBook->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFBook::BBookAddClick(TObject *Sender)
{
	Data x;
	int i,size = blist.Size(),k = 0;
	x.Name   = CBookName  ->Text;
	x.Author = CBookAuthor->Text;
	x.Cost   = CBookCost  ->Text;
	x.Num    = CBookNum   ->Text;
	x.Note   = CBookNote  ->Text;
	x.Given  = 0;
	if (x.Name   == ""
	&&	x.Author == ""
	&& 	x.Cost   == ""
	&& 	x.Num    == ""
	&&	x.Note   == "")
	{
		return;
	}
	ComboBoxClear();

	k=blist.Check(x);
	if (k!=-1)
	{
		x.Given = blist.Item(k).Given;
		blist.Replace(x,k);
		CBookCost->Items->Delete(k);
		CBookCost->Items->Insert(k,x.Cost);
	} else
	{
		blist.Add(x);
		CBookName   -> Items->Add(x.Name);
		CBookAuthor -> Items->Add(x.Author);
		CBookCost   -> Items->Add(x.Cost);
		CBookNum    -> Items->Add(x.Num);
		CBookNote   -> Items->Add(x.Note);
	}
	ClearGrid();
	blist.Show();
	blist.Save();
}
//---------------------------------------------------------------------------
void __fastcall TFBook::CBookNameSelect(TObject *Sender)
{
	CBookAuthor ->ItemIndex = CBookName->ItemIndex;
	CBookCost   ->ItemIndex = CBookName->ItemIndex;
	CBookNum    ->ItemIndex = CBookName->ItemIndex;
	CBookNote   ->ItemIndex = CBookName->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TFBook::GridGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value)
{
	Modified=true;
	ColN=ACol;
	RowN=ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFBook::GridExit(TObject *Sender)
{
	if (Modified)
	{
		Modif();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFBook::GridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	if (Modified)
	{
		Modif();
	}
	CBookName   ->ItemIndex = ARow-1;
	CBookAuthor ->ItemIndex = ARow-1;
	CBookCost   ->ItemIndex = ARow-1;
	CBookNum    ->ItemIndex = ARow-1;
	CBookNote   ->ItemIndex = ARow-1;
}
//---------------------------------------------------------------------------


void __fastcall TFBook::FormClose(TObject *Sender, TCloseAction &Action)
{
	FMain->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFBook::BBookDeleteClick(TObject *Sender)
{
	Data x;
	int k = 0;
	x.Name   = CBookName   -> Text;
	x.Author = CBookAuthor -> Text;
	x.Cost   = CBookCost   -> Text;
	x.Num    = CBookNum    -> Text;
	x.Note   = CBookNote   -> Text;

	k = blist.Check(x);
	if (k != -1)
	{
		ComboBoxClear();
		blist.Delete(k);
		CBookName   -> Items->Delete(k);
		CBookAuthor -> Items->Delete(k);
		CBookCost   -> Items->Delete(k);
		CBookNum    -> Items->Delete(k);
		CBookNote   -> Items->Delete(k);
	} else
	{
		ShowMessage("����� ����� ��� � ����������!");
		return;
	}
	ClearGrid();
	blist.Show();
	blist.Save();
}
//---------------------------------------------------------------------------

void __fastcall TFBook::BBookSearchClick(TObject *Sender)
{
	Data x;
	int k = 0;
	x.Name   = CBookName   ->Text;
	x.Author = CBookAuthor ->Text;
	x.Cost   = CBookCost   ->Text;
	x.Num    = CBookNum    ->Text;
	x.Note   = CBookNote   ->Text;

	k = blist.Check(x);
	if (k != -1)
	{
		Grid->Col = 0;
		Grid->Row = k+1;
	} else
	{
		ShowMessage("����� ����� ��� � ����������!");
		return;
	}
}
//---------------------------------------------------------------------------




void __fastcall TFBook::FormActivate(TObject *Sender)
{
	Grid->Cells[0][0] = "��������";
	Grid->Cells[1][0] = "�����";
	Grid->Cells[2][0] = "����";
	Grid->Cells[3][0] = "���-�� ��.";
	Grid->Cells[4][0] = "����������";
	ClearGrid();
	blist.Show();
}
//---------------------------------------------------------------------------




void __fastcall TFBook::GridSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	if (ACol == 0) CBookName   -> Text = Value;
	if (ACol == 1) CBookAuthor -> Text = Value;
	if (ACol == 2) CBookCost   -> Text = Value;
	if (ACol == 3) CBookNum    -> Text = Value;
	if (ACol == 4) CBookNote   -> Text = Value;
}
//---------------------------------------------------------------------------

void __fastcall TFBook::FormCreate(TObject *Sender)
{
    TStringList *List = new TStringList;
	String Dir = "e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Book\\";
	List->LoadFromFile(Dir+"Grid.txt");
	if (List->Count == 0)
	{
		return;
	}
	int i;
	Data x;
	for (i = 0; i < List->Count/6; i++)
	{
		x.Name   = List->Strings[i*6];
		x.Author = List->Strings[i*6+1];
		x.Cost   = List->Strings[i*6+2];
		x.Num    = List->Strings[i*6+3];
		x.Note   = List->Strings[i*6+4];
		x.Given  = StrToInt(List->Strings[i*6+5]);
		blist.Add(x);
	}
	FBook->CBookName   ->Items->LoadFromFile(Dir+"CBookName.txt");
	FBook->CBookAuthor ->Items->LoadFromFile(Dir+"CBookAuthor.txt");
	FBook->CBookCost   ->Items->LoadFromFile(Dir+"CBookCost.txt");
	FBook->CBookNum    ->Items->LoadFromFile(Dir+"CBookNum.txt");
	FBook->CBookNote   ->Items->LoadFromFile(Dir+"CBookNote.txt");
	delete List;
	FBook->CBookName   ->ItemIndex = 0;
	FBook->CBookAuthor ->ItemIndex = 0;
	FBook->CBookCost   ->ItemIndex = 0;
	FBook->CBookNum    ->ItemIndex = 0;
	FBook->CBookNote   ->ItemIndex = 0;

}
//---------------------------------------------------------------------------

