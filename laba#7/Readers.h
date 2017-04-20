//---------------------------------------------------------------------------

#ifndef ReadersH
#define ReadersH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "Main.h"
#include "ReadersInfo.h"
//---------------------------------------------------------------------------
class TFReaders : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Grid;
	TPanel *PProperties;
	TLabel *Group;
	TLabel *Name;
	TLabel *Phone;
	TLabel *Note;
	TLabel *Email;
	TButton *BReadersAdd;
	TComboBox *CReadersName;
	TComboBox *CReadersGroup;
	TComboBox *CReadersPhone;
	TComboBox *CReadersEmail;
	TComboBox *CReadersNote;
	TButton *BReadersBack;
	TButton *BReadersSearch;
	TButton *BReadersInfo;

	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BReadersBackClick(TObject *Sender);
	void __fastcall BReadersAddClick(TObject *Sender);
	void __fastcall CReadersNameSelect(TObject *Sender);
	void __fastcall GridGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall GridExit(TObject *Sender);
	void __fastcall GridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BReadersDeleteClick(TObject *Sender);
	void __fastcall BReadersSearchClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall GridSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall BReadersInfoClick(TObject *Sender);
	void __fastcall GridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);



private:	// User declarations
public:		// User declarations
	__fastcall TFReaders(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFReaders *FReaders;
//---------------------------------------------------------------------------
#endif
