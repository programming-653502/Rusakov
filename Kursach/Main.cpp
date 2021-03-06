//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMain *FMain;
int n = 0, Miss = 0, Hit = 0;
bool FlagColor[3] = {false,false,false},
	 FlagEdit[3]  = {false,false,false},
	 FlagLabel    = false,
	 DefSound 	  = true;

int B[3]       = {0,0,0},
	P[3]       = {0,0,0},
	BG[3]      = {0,0,0},
	TB[3]      = {0,0,0},
	TP[3]      = {0,0,0},
	TBG[3]     = {0,0,0},
	DefB[3]    = {255,161,97},
	DefP[3]    = {100,0,0},
	DefBG[3]   = {135,206,250},
	DefSens    = 8,
	Case       = -1,
	Btn        = 0,
	PrevSens   = 0;
wchar_t Dir[255];


//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMain::Timer1Timer(TObject *Sender)
{
	list.Show(Dir);
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Timer2Timer(TObject *Sender)
{
	n++;
	Data x;
	x.STarget = new TShape(Application);
	x.F = false;
	x.STarget->Parent=FMain;
	x.STarget->Left=50+rand()%401;
	x.STarget->Top=110+rand()%416;
	x.STarget->Brush->Color = RGB( B[0], B[1], B[2] );
	x.STarget->Pen->Color = RGB( P[0], P[1], P[2] );
	x.STarget->Width = 0;
	x.STarget->Height = 0;
	x.STarget->Shape=stCircle;
	x.STarget->OnMouseDown = STargetMouseDown;
	list.Add(x);
	Timer2->Interval--;
}
//---------------------------------------------------------------------------



void __fastcall TFMain::STargetMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Hit++;
	if (CBSound->Checked)
	{
		wchar_t temp[255],play[255] = L"play ", stop[255] = L"stop ";
		wcscpy( temp, Dir );
		wcscat( temp, L"//Hit.wav");
		wcscat( play, temp );
		wcscat( stop, temp );
		mciSendString(stop,0,0,0);
		mciSendString(play,0,0,0);
	}
	LHitNum->Caption = IntToStr(Hit);
	list.Find(X,Y,Sender->GetHashCode());
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Timer3Timer(TObject *Sender)
{
	if (FlagLabel)
	{
		Label->Hide();
		FlagLabel = false;
	}
	int M = StrToInt(LMinutes->Caption),S = StrToInt(LSeconds->Caption);
	S++;
	if (S == 60)
	{
		M++;
		S = 0;
	}
	if (M < 10) LMinutes->Caption = "0"+IntToStr(M);
		   else LMinutes->Caption = IntToStr(M);
	if (S < 10) LSeconds->Caption = "0"+IntToStr(S);
		   else LSeconds->Caption = IntToStr(S);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	SystemParametersInfo( SPI_GETMOUSESPEED , 0 , &PrevSens , 0);
	PConfirm->Top  = 250;
	PConfirm->Left = 208;
	PRecord->Top   = 200;
	PRecord->Left  = 150;
	srand( time(NULL) );
	wchar_t temp[255];
	const wchar_t* FolderName = L"AimTraining";
	SHGetSpecialFolderPath( 0, Dir, CSIDL_PERSONAL, True);   //�������� ���� � �����
	wcscat( Dir, L"//" );                                    //"��� ���������"
	wcscat( Dir, FolderName );                               //
	if (!FileExists(Dir))                                    //��������� ������� �����
	{                                                        //AimTraining
		CreateDirectory( Dir, NULL );
	}
	wcscpy( temp, Dir );
	wcscat( temp, L"//Hit.wav");
	if(!FileExists(temp))                                    //��������� ������� ����� Hit.wav
	{                                                        //���� ��� ���, ��������� �� ��������
		TResourceStream* ResPtr = new TResourceStream((int)HInstance,
		UnicodeString("HIT").c_str(), UnicodeString("SOUND").c_str());
		ResPtr->SaveToFile(temp);
		delete ResPtr;
	}

	wcscpy( temp, Dir );
	wcscat( temp, L"//Miss.wav");
	if(!FileExists(temp))                                    //��������� ������� ����� Miss.wav
	{                                                        //���� ��� ���, ��������� �� ��������
		TResourceStream* ResPtr = new TResourceStream((int)HInstance,
		UnicodeString("MISS").c_str(), UnicodeString("SOUND").c_str());
		ResPtr->SaveToFile(temp);
		delete ResPtr;
	}

	wcscpy( temp, Dir );
	wcscat( temp, L"//Fail.wav");
	if(!FileExists(temp))                                    //��������� ������� ����� Fail.wav
	{                                                        //���� ��� ���, ��������� �� ��������
		TResourceStream* ResPtr = new TResourceStream((int)HInstance,
		UnicodeString("FAIL").c_str(), UnicodeString("SOUND").c_str());
		ResPtr->SaveToFile(temp);
		delete ResPtr;
	}

	wcscpy( temp, Dir );
	wcscat( temp, L"//GameOver.wav");
	if(!FileExists(temp))                                    //��������� ������� ����� GameOver.wav
	{                                                        //���� ��� ���, ��������� �� ��������
		TResourceStream* ResPtr = new TResourceStream((int)HInstance,
		UnicodeString("GAMEOVER").c_str(), UnicodeString("SOUND").c_str());
		ResPtr->SaveToFile(temp);
		delete ResPtr;
	}

	wcscpy( temp, Dir );
	wcscat( temp, L"//Record.wav");
	if(!FileExists(temp))                                    //��������� ������� ����� Record.wav
	{                                                        //���� ��� ���, ��������� �� ��������
		TResourceStream* ResPtr = new TResourceStream((int)HInstance,
		UnicodeString("RECORD").c_str(), UnicodeString("SOUND").c_str());
		ResPtr->SaveToFile(temp);
		delete ResPtr;
	}

	wcscpy( temp, Dir );
	wcscat( temp, L"//Record.txt");
	if(!FileExists(temp))                                    //��������� ������� ����� Record.txt
	{                                                        //���� ��� ���, ������
		TStringList *List = new TStringList;
		List->Add("00");
		List->Add("00");
		List->Add('0');
		List->Add('0');
		List->SaveToFile( temp );
		delete List;
	}

	wcscpy( temp, Dir );                                     //��������� ������� ����� Options.txt
	wcscat( temp, L"//Options.txt");                         //���� ��� ���, ������
	if (!FileExists( temp ))
	{
		TStringList *List = new TStringList;
		List->Add(IntToStr( DefB[0] ));
		List->Add(IntToStr( DefB[1] ));
		List->Add(IntToStr( DefB[2] ));
		List->Add(IntToStr( DefP[0] ));
		List->Add(IntToStr( DefP[1] ));
		List->Add(IntToStr( DefP[2] ));
		List->Add(IntToStr( DefBG[0] ));
		List->Add(IntToStr( DefBG[1] ));
		List->Add(IntToStr( DefBG[2] ));
		if (DefSound) List->Add('1');
				 else List->Add('0');
		List->Add(IntToStr( DefSens ));
		List->SaveToFile( temp );
		delete List;
	}
	TStringList *List = new TStringList;
	List->LoadFromFile( temp );
	for (int i = 0; i < 3; i++)
	{
		B[i] = StrToInt(List->Strings[i]);
		P[i] = StrToInt(List->Strings[i+3]);
		BG[i] = StrToInt(List->Strings[i+6]);
		TB[i] = B[i];
		TP[i] = P[i];
		TBG[i] = BG[i];
	}
	if (StrToInt(List->Strings[9])) CBSound->Checked = true;
					else  CBSound->Checked = false;
	TBSens->Position = StrToInt(List->Strings[10]);
	SystemParametersInfo(SPI_SETMOUSESPEED, 0 , (PVOID)TBSens->Position, SPIF_SENDCHANGE);
	FMain->Color = RGB( 135, 206, 250 );
	SBackground->Brush->Color = RGB( BG[0], BG[1], BG[2] );
	SBrush->Brush->Color = RGB( B[0], B[1], B[2] );
	SPen->Brush->Color = RGB( P[0], P[1], P[2] );
}
//---------------------------------------------------------------------------

void __fastcall TFMain::PlayClick(TObject *Sender)
{

   BackGround->Brush->Color = RGB( BG[0], BG[1], BG[2] );
   BackGround->Pen->Color   = RGB( BG[0], BG[1], BG[2] );
   n = 0;
   LMinutes->Caption="00";
   LSeconds->Caption="00";
   LHitNum->Caption="0";
   LMissNum->Caption="0";
   BackGround->Top = 59;
   BackGround->Left = 0;
   BackGround->Show();
   BRecord->Hide();
   BRetry->Hide();
   BExit->Hide();
   PBar->Show();
   Play->Hide();
   Back->Show();
   BOptions->Hide();
   Image1->Show();
   Image2->Show();
   Image3->Show();
   Miss = 0;
   Hit = 0;
   n++;
   Timer3->Enabled = True;
   Timer2->Enabled = True;
   Timer1->Enabled = True;
   Flag = true;
   list.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BackClick(TObject *Sender)
{
	FMain->Timer1->Enabled = false;
	FMain->Timer2->Enabled = false;
	FMain->Timer3->Enabled = false;
	Flag = false;
	FMain->Timer2->Interval = 500;
	list.Clear();
	BRetry->Hide();
	BRecord->Show();
	BExit->Show();
	Label->Hide();
	BackGround->Hide();
	PBar->Hide();
	LGameOver->Hide();
	Back->Hide();
	Play->Show();
	BOptions->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BOptionsClick(TObject *Sender)
{
	//������� RGB ��������
	FlagColor[0] = true;
	FlagColor[1] = true;
	FlagColor[2] = true;
	FlagEdit[0]  = true;
	FlagEdit[1]  = true;
	FlagEdit[2]  = true;
	EBlue->Text = "";
	ERed->Text = "";
	EGreen->Text = "";
	TBRed->Position = 0;
	TBGreen->Position = 0;
	TBBlue->Position = 0;
	//������� "���������" ������
	Case = -1;
	int i = 0 ;
	POptions->Top = 0;
	POptions->Left = 0;
	POptions->Show();
	Play->Hide();
	BOptions->Hide();
	BRecord->Hide();
	BExit->Hide();
	//SystemParametersInfo( SPI_GETMOUSESPEED , 0 , &i , 0);
	//Sens->Text = IntToStr ( i );
	//TBSens->Position = i;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BApplyClick(TObject *Sender)
{
	Btn = 2;
	PConfirm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BOptionsBackClick(TObject *Sender)
{
	POptions->Hide();
	Play->Show();
	BOptions->Show();
	BRecord->Show();
	BExit->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::TBSensChange(TObject *Sender)
{
	Sens->Text = IntToStr(TBSens->Position);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SensKeyPress(TObject *Sender, wchar_t &Key)
{
	if ((Key >= '0' && Key <= '9')
	||   Key == VK_BACK
	||   Key == VK_RETURN
	||   Key == VK_DELETE) {}
	else Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SBackgroundMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	FlagColor[0] = true;
	FlagColor[1] = true;
	FlagColor[2] = true;
	TBRed->Position   = TBG[0];
	TBGreen->Position = TBG[1];
	TBBlue->Position  = TBG[2];
	ERed   -> Text = IntToStr( TBG[0] );
	EGreen -> Text = IntToStr( TBG[1] );
	EBlue  -> Text = IntToStr( TBG[2] );
	Case = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SBrushMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	FlagColor[0] = true;
	FlagColor[1] = true;
	FlagColor[2] = true;
	TBRed->Position   = TB[0];
	TBGreen->Position = TB[1];
	TBBlue->Position  = TB[2];
	ERed   -> Text = IntToStr( TB[0] );
	EGreen -> Text = IntToStr( TB[1] );
	EBlue  -> Text = IntToStr( TB[2] );
	Case = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SPenMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	FlagColor[0] = true;
	FlagColor[1] = true;
	FlagColor[2] = true;
	TBRed->Position   = TP[0];
	TBGreen->Position = TP[1];
	TBBlue->Position  = TP[2];
	ERed   -> Text = IntToStr( TP[0] );
	EGreen -> Text = IntToStr( TP[1] );
	EBlue  -> Text = IntToStr( TP[2] );
	Case = 2;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::TBRedChange(TObject *Sender)
{
	if (FlagColor[0])
	{
		FlagColor[0] = false;
		return;
	}
	if (Case == -1)
	{
		TBRed->Position = 0;
		return;
	}
	int x = TBRed->Position;
	ERed->Text = IntToStr( x );
	if (Case == 0)
	{
		TBG[0] = x;
		SBackground->Brush->Color = RGB ( TBG[0], TBG[1], TBG[2] );
	}
	if (Case == 1)
	{
		TB[0] = x;
		SBrush->Brush->Color = RGB ( TB[0], TB[1], TB[2] );
	}
	if (Case == 2)
	{
		TP[0] = x;
		SPen->Brush->Color = RGB ( TP[0], TP[1], TP[2] );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::TBGreenChange(TObject *Sender)
{
	if (FlagColor[1])
	{
		FlagColor[1] = false;
		return;
	}
	if (Case == -1)
	{
		TBGreen->Position = 0;
		return;
	}
	int x = TBGreen->Position;
	EGreen->Text = IntToStr( x );
	if (Case == 0)
	{
		TBG[1] = x;
		SBackground->Brush->Color = RGB ( TBG[0], TBG[1], TBG[2] );
	}
	if (Case == 1)
	{
		TB[1] = x;
		SBrush->Brush->Color = RGB ( TB[0], TB[1], TB[2] );
	}
	if (Case == 2)
	{
		TP[1] = x;
		SPen->Brush->Color = RGB ( TP[0], TP[1], TP[2] );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::TBBlueChange(TObject *Sender)
{
	if (FlagColor[2])
	{
		FlagColor[2] = false;
		return;
	}
	if (Case == -1)
	{
		TBBlue->Position = 0;
		return;
	}
	int x = TBBlue->Position;
	EBlue->Text = IntToStr( x );
	if (Case == 0)
	{
		TBG[2] = x;
		SBackground->Brush->Color = RGB ( TBG[0], TBG[1], TBG[2] );
	}
	if (Case == 1)
	{
		TB[2] = x;
		SBrush->Brush->Color = RGB ( TB[0], TB[1], TB[2] );
	}
	if (Case == 2)
	{
		TP[2] = x;
		SPen->Brush->Color = RGB ( TP[0], TP[1], TP[2] );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::ERedKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Case = -1)
	{
		Key = 0;
		return;
	}
	if ((Key >= '0' && Key <= '9')
	||   Key == VK_BACK
	||   Key == VK_RETURN
	||   Key == VK_DELETE) {}
	else Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::EGreenKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Case = -1)
	{
		Key = 0;
		return;
	}
	if ((Key >= '0' && Key <= '9')
	||   Key == VK_BACK
	||   Key == VK_RETURN
	||   Key == VK_DELETE) {}
	else Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::EBlueKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Case = -1)
	{
		Key = 0;
		return;
	}
	if ((Key >= '0' && Key <= '9')
	||   Key == VK_BACK
	||   Key == VK_RETURN
	||   Key == VK_DELETE) {}
	else Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::EBlueChange(TObject *Sender)
{
	if (FlagEdit[2])
	{
		FlagEdit[2] = false;
		return;
	}
	int Pos = StrToInt(EBlue->Text);
	if (Pos > 255)
	{
		EBlue->Text = "255";
	}
	if (Pos < 0)
	{
		EBlue->Text = "0";
	}
	TBBlue->Position = Pos;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::EGreenChange(TObject *Sender)
{
	if (FlagEdit[1])
	{
		FlagEdit[1] = false;
		return;
	}
	int Pos = StrToInt(EGreen->Text);
	if (Pos > 255)
	{
		EGreen->Text = "255";
	}
	if (Pos < 0)
	{
		EGreen->Text = "0";
	}
	TBGreen->Position = Pos;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::ERedChange(TObject *Sender)
{
	if (FlagEdit[0])
	{
		FlagEdit[0] = false;
		return;
	}
	int Pos = StrToInt(ERed->Text);
	if (Pos > 255)
	{
		ERed->Text = "255";
	}
	if (Pos < 0)
	{
		ERed->Text = "0";
	}
	TBRed->Position = Pos;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SensChange(TObject *Sender)
{
	if (Sens->Text == "")
	{
		Sens->Text = IntToStr( TBSens->Position );
		return;
	}
	int Pos = StrToInt(Sens->Text);
	if (Pos > 255)
	{
		Sens->Text = "20";
	}
	if (Pos < 0)
	{
		Sens->Text = "1";
	}
	TBSens->Position = Pos;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BackGroundMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (Flag)
	{
		Label->Show();
		Label->Left = X;
		Label->Top  = Y+60;
		FlagLabel = true;
		if (CBSound->Checked)
		{
			wchar_t temp[255],play[255] = L"play ", stop[255] = L"stop ";
			wcscpy( temp, Dir );
			wcscat( temp, L"//Miss.wav");
			wcscat( play, temp );
			wcscat( stop, temp );
			mciSendString(stop,0,0,0);
			mciSendString(play,0,0,0);
		}
		Miss++;
		LMissNum->Caption = IntToStr(Miss);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BYesClick(TObject *Sender)
{
	if (Btn == 2)  //���� ���� ������ ������ "���������"
	{
		// ��������� ����
		int TBPos = TBSens->Position;
		if (Sens->Text == "")
		{
			Sens->Text = IntToStr( TBPos );
		} else
		{
			SystemParametersInfo(SPI_SETMOUSESPEED, 0 , (PVOID)TBPos, SPIF_SENDCHANGE);
			TBSens->Position = StrToInt(Sens->Text);
			Sens->Text = IntToStr( TBPos );
		}
		//��������� �����
		B[0] = TB[0];
		B[1] = TB[1];
		B[2] = TB[2];
		P[0] = TP[0];
		P[1] = TP[1];
		P[2] = TP[2];
		BG[0] = TBG[0];
		BG[1] = TBG[1];
		BG[2] = TBG[2];
		//������� RGB ��������
		FlagColor[0]      = true;
		FlagColor[1]      = true;
		FlagColor[2]      = true;
		FlagEdit[0]       = true;
		FlagEdit[1]       = true;
		FlagEdit[2]       = true;
		EBlue->Text       = "";
		ERed->Text        = "";
		EGreen->Text      = "";
		TBRed->Position   = 0;
		TBGreen->Position = 0;
		TBBlue->Position  = 0;
		//������� "���������" ������
		Case = -1;
		//�������� ������ �������������
		PConfirm->Hide();
		//������� "���������" ������
		Btn = 0;
	}
	if (Btn == 1) //���� ���� ������ ������ "�������� ���������"
	{
		//���������� ����������������
		SystemParametersInfo(SPI_SETMOUSESPEED, 0 , (PVOID)DefSens, SPIF_SENDCHANGE);
		TBSens->Position = DefSens;
		Sens->Text = IntToStr(DefSens);
		//���������� ����
		CBSound->Checked = DefSound;
		//���������� �����
		B[0]  = DefB[0];  TB[0]  = B[0];
		B[1]  = DefB[1];  TB[1]  = B[1];
		B[2]  = DefB[2];  TB[2]  = B[2];
		P[0]  = DefP[0];  TP[0]  = P[0];
		P[1]  = DefP[1];  TP[1]  = P[1];
		P[2]  = DefP[2];  TP[2]  = P[2];
		BG[0] = DefBG[0]; TBG[0] = BG[0];
		BG[1] = DefBG[1]; TBG[1] = BG[1];
		BG[2] = DefBG[2]; TBG[2] = BG[2];
		SBrush->Brush->Color        = RGB ( B[0], B[1], B[2] );
		SPen->Brush->Color          = RGB ( P[0], P[1], P[2] );
		SBackground->Brush->Color   = RGB ( BG[0], BG[1], BG[2] );
		//������� RGB ��������
		FlagColor[0] = true;
		FlagColor[1] = true;
		FlagColor[2] = true;
		FlagEdit[0]  = true;
		FlagEdit[1]  = true;
		FlagEdit[2]  = true;
		EBlue->Text = "";
		ERed->Text = "";
		EGreen->Text = "";
		TBRed->Position = 0;
		TBGreen->Position = 0;
		TBBlue->Position = 0;
		//������� "���������" ������
		Case = -1;
		//�������� ������ �������������
		PConfirm->Hide();
		//������� "���������" ������
		Btn = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BNoClick(TObject *Sender)
{
	//�������� ������ �������������
	PConfirm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BResetClick(TObject *Sender)
{
	Btn = 1;
	PConfirm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFMain::FormClose(TObject *Sender, TCloseAction &Action)
{
		wchar_t temp[255];
		wcscpy( temp, Dir );
		wcscat( temp, L"//Options.txt");
		TStringList *List = new TStringList;
		List->Add(IntToStr( B[0] ));
		List->Add(IntToStr( B[1] ));
		List->Add(IntToStr( B[2] ));
		List->Add(IntToStr( P[0] ));
		List->Add(IntToStr( P[1] ));
		List->Add(IntToStr( P[2] ));
		List->Add(IntToStr( BG[0] ));
		List->Add(IntToStr( BG[1] ));
		List->Add(IntToStr( BG[2] ));
		if (CBSound->Checked) List->Add('1');
						 else List->Add('0');
		List->Add( Sens->Text );
		List->SaveToFile( temp );
		delete List;
		SystemParametersInfo(SPI_SETMOUSESPEED, 0 , (PVOID)PrevSens, SPIF_SENDCHANGE);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BRecordClick(TObject *Sender)
{
	PRecord->Show();
	wchar_t temp[255];
	wcscpy( temp, Dir );
	wcscat( temp, L"//Record.txt");
	TStringList *List = new TStringList;
	List->LoadFromFile( temp );
	LRecordTime->Caption = List->Strings[0]+":"+List->Strings[1];
	LRecordHit->Caption  = List->Strings[2];
	LRecordMiss->Caption = List->Strings[3];
	delete List;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BOkClick(TObject *Sender)
{
	PRecord->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


