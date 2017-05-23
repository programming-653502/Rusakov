//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "time.h"
#include "List.h"
#include <Math.h>
#include <windows.h>
#include <ComCtrls.hpp>
#include <pngimage.hpp>
#include "mmsystem.h"
#include "shlobj.h"
#include <pngimage.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
bool Flag = false;
class TFMain : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TTimer *Timer2;
	TLabel *LGameOver;
	TTimer *Timer3;
	TLabel *LMinutes;
	TLabel *LColon;
	TLabel *LSeconds;
	TLabel *LMiss;
	TLabel *LHit;
	TLabel *LMissNum;
	TLabel *LHitNum;
	TPanel *PBar;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Play;
	TImage *Back;
	TPanel *POptions;
	TTrackBar *TBSens;
	TButton *BApply;
	TButton *BOptionsBack;
	TEdit *Sens;
	TGroupBox *GBColor;
	TLabel *LR;
	TLabel *LG;
	TLabel *LB;
	TTrackBar *TBRed;
	TTrackBar *TBGreen;
	TTrackBar *TBBlue;
	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *GBSound;
	TGroupBox *GBMouse;
	TLabel *LSens;
	TEdit *ERed;
	TEdit *EGreen;
	TEdit *EBlue;
	TLabel *Label3;
	TShape *SBackground;
	TShape *SBrush;
	TShape *SPen;
	TCheckBox *CBSound;
	TPanel *PConfirm;
	TLabel *LConfirm;
	TButton *BYes;
	TButton *BNo;
	TShape *BackGround;
	TButton *BReset;
	TLabel *Label;
	TPanel *PRecord;
	TGroupBox *GBRecord;
	TLabel *LRTime;
	TLabel *LRHit;
	TLabel *LRMiss;
	TButton *BOk;
	TLabel *LRecordTime;
	TLabel *LRecordHit;
	TLabel *LRecordMiss;
	TImage *BOptions;
	TImage *BRecord;
	TImage *BExit;
	TImage *BRetry;

	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall STargetMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PlayClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall BOptionsClick(TObject *Sender);
	void __fastcall BApplyClick(TObject *Sender);
	void __fastcall BOptionsBackClick(TObject *Sender);
	void __fastcall TBSensChange(TObject *Sender);
	void __fastcall SensKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SBackgroundMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SBrushMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SPenMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall TBRedChange(TObject *Sender);
	void __fastcall TBGreenChange(TObject *Sender);
	void __fastcall TBBlueChange(TObject *Sender);
	void __fastcall ERedKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall EGreenKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall EBlueKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall EBlueChange(TObject *Sender);
	void __fastcall EGreenChange(TObject *Sender);
	void __fastcall ERedChange(TObject *Sender);
	void __fastcall SensChange(TObject *Sender);
	void __fastcall BackGroundMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BYesClick(TObject *Sender);
	void __fastcall BNoClick(TObject *Sender);
	void __fastcall BResetClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BRecordClick(TObject *Sender);
	void __fastcall BOkClick(TObject *Sender);
	void __fastcall BExitClick(TObject *Sender);




private:	// User declarations
public:		// User declarations
	__fastcall TFMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
