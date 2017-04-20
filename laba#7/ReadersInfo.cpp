//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReadersInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFInfo *FInfo;
Ilist ilist;
//---------------------------------------------------------------------------
__fastcall TFInfo::TFInfo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void IClearGrid()
{
	for (int i = 0; i < 4; i++)
	for (int j = 1; j < FInfo->Grid->RowCount; j++)
	FInfo->Grid->Cells[i][j] = "";
}

void IClearComboBox()
{
	FInfo->CAddBookName    -> Clear();
	FInfo->CDeleteBookName -> Clear();
}

void __fastcall TFInfo::FormActivate(TObject *Sender)
{
	AnsiString S = FReaders->CReadersName->Text;
	int Index = FReaders->CReadersName->ItemIndex;

	IClearComboBox();
	IClearGrid();

	FInfo->Caption = S;
	//if (rlist.Item(Index).Penalty == 0) FInfo->Font->Color=clWindowText;
	//if (rlist.Item(Index).Penalty == 1) FInfo->Font->Color=clYellow;
	//if (rlist.Item(Index).Penalty == 2) FInfo->Font->Color=clRed;
	AnsiString Dir = "e:\\LABI 2 sem\\Prog\\laba#7\\Debug\\Win32\\Info\\"+S+".txt";
	if (!FileExists(Dir))
	{
		char s[200];
		strcpy( s, Dir.c_str() );
		ofstream File(s);
		File.close();
	}

	CAddBookName->Items = FBook->CBookName->Items;

	TStringList *List= new TStringList;
	List->LoadFromFile(Dir);
	if (List->Count == 0)
	{
		return;
	}
	int i;
	IData x;
	CAddBookName->ItemIndex = 0;
	for (i = 0; i < List->Count/5; i++)
	{
		x.Name  = List->Strings[i*5];
		x.Author = List->Strings[i*5+1];
		x.Cost = List->Strings[i*5+2];
		x.Num = List->Strings[i*5+3];
		x.Note  = List->Strings[i*5+4];
		CDeleteBookName->Items->Add(x.Name);
		ilist.Add(x);
	}
	CDeleteBookName->ItemIndex = 0;
	delete List;

	IClearGrid();
	ilist.Show();
}
//---------------------------------------------------------------------------
void __fastcall TFInfo::FormClose(TObject *Sender, TCloseAction &Action)
{
	Grid->RowCount = 2;
	IClearGrid();
	ilist.Clear();
	FReaders->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFInfo::BBackClick(TObject *Sender)
{
	ilist.Save(FReaders->CReadersName->Text);
	FInfo->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFInfo::FormCreate(TObject *Sender)
{
	Grid->Cells[0][0] = "��������";
	Grid->Cells[1][0] = "�����";
	Grid->Cells[2][0] = "����";
	Grid->Cells[3][0] = "����������";
}
//---------------------------------------------------------------------------
void __fastcall TFInfo::BYellowPenaltyClick(TObject *Sender)
{
	Grid->FixedColor=clYellow;
	int Index = FReaders->CReadersName->ItemIndex;
	Rdata x = rlist.Item(Index);
	x.Penalty = 1;
	rlist.Replace(x,Index);
	rlist.Save();
}
//---------------------------------------------------------------------------

void __fastcall TFInfo::BRedPenaltyClick(TObject *Sender)
{
	Grid->FixedColor=clRed;
	int Index = FReaders->CReadersName->ItemIndex;
	Rdata x = rlist.Item(Index);
	x.Penalty = 2;
	rlist.Replace(x,Index);
	rlist.Save();
}
//---------------------------------------------------------------------------

void __fastcall TFInfo::BAnnulPenaltyClick(TObject *Sender)
{
	Grid->FixedColor=clBtnFace;
	int Index = FReaders->CReadersName->ItemIndex;
	Rdata x = rlist.Item(Index);
	x.Penalty = 0;
	rlist.Replace(x,Index);
	rlist.Save();
}
//---------------------------------------------------------------------------

void __fastcall TFInfo::BAddBookClick(TObject *Sender)
{
	int Index = CAddBookName->ItemIndex;
	Data y = blist.Item(Index);
	if (ilist.Check(CAddBookName->Text) != -1 || Index == -1) return;
	if (StrToInt(y.Num) == y.Given )
	{
		ShowMessage("����������� ���� ����� ������ ��� � ����������!");
		return;
	}
	IData x;

	CDeleteBookName->Items->Add(CAddBookName->Text);
	x.Name 	 = y.Name;
	x.Author = y.Author;
	x.Cost   = y.Cost;
	x.Num    = y.Num;
	x.Note   = y.Note;
	CAddBookName->ItemIndex = -1;
	CAddBookName->Text      = "";
	ilist.Add(x);
	IClearGrid();
	ilist.Show();
	ilist.Save(FReaders->CReadersName->Text);
	y.Given++;
	blist.Replace(y,Index);
	blist.Save();
}
//---------------------------------------------------------------------------

void __fastcall TFInfo::BDeleteBookClick(TObject *Sender)
{
	int k = ilist.Check(CDeleteBookName->Text);
	if (k == -1 || CDeleteBookName->ItemIndex == -1) return;
	if (k != -1)
	{
		IData y = ilist.Item(k);
		Data z;
		z.Name = y.Name;
		z.Author = y.Author;
		z.Cost = y.Cost;
		z.Note = y.Note;
		int Index = blist.Check(z);
		Data x = blist.Item(Index);
		x.Given--;
		blist.Replace(x,Index);
		blist.Save();
		CDeleteBookName   ->ItemIndex = -1;
		CDeleteBookName   ->Text = "";
		ilist.Delete(k);
		CDeleteBookName->Items->Delete(k);
	}
	IClearGrid();
	ilist.Show();
	ilist.Save(FReaders->CReadersName->Text);

}
//---------------------------------------------------------------------------

void __fastcall TFInfo::GridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	CDeleteBookName->ItemIndex = ARow-1;
}
//---------------------------------------------------------------------------





void __fastcall TFInfo::GridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	  if (State.Contains(gdFixed))
	  {
		  int x = rlist.Item(FReaders->CReadersName->ItemIndex).Penalty;
		  if (x == 0) Grid->Canvas->Brush->Color = clBtnFace;
		  if (x == 1) Grid->Canvas->Brush->Color = clYellow;
		  if (x == 2) Grid->Canvas->Brush->Color = clRed;
		  Grid->Canvas->Font->Color = clWindowText;
		  Grid->Canvas->FillRect(Rect);
		  Frame3D(Grid->Canvas, Rect,
				  clBtnHighlight, clBtnShadow, 1);
	  }

	  // ���� ������ ��������
	  else if (State.Contains(gdSelected))
	  {
		  Grid->Canvas->Brush->Color = clHighlight;
		  Grid->Canvas->Font->Color = clHighlightText;
		  Grid->Canvas->FillRect(Rect);
	  }

	  // ��� ���� ��������� �����
	  else
	  {
		  Grid->Canvas->Brush->Color = Grid->Color;
		  Grid->Canvas->Font->Color = Grid->Font->Color;
		  Grid->Canvas->FillRect(Rect);
	  }

	  AnsiString text = Grid->Cells[ACol][ARow];
	  Grid->Canvas->TextRect(Rect, Rect.Left, Rect.Top, text);
}
//---------------------------------------------------------------------------
