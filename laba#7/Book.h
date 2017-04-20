//---------------------------------------------------------------------------

#ifndef BookH
#define BookH
//---------------------------------------------------------------------------
#include <Classes.hpp>

#include <Controls.hpp>

#include <StdCtrls.hpp>

#include <Forms.hpp>

#include <ExtCtrls.hpp>

#include <Grids.hpp>

#include "BookList.h"

#include <fstream>

#include "Main.h"
//---------------------------------------------------------------------------
class TFBook : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Grid;
	TLabel *Author;
	TLabel *Name;
	TLabel *Cost;
	TLabel *Note;
	TLabel *Num;
	TButton *BBookAdd;
	TComboBox *CBookName;
	TButton *BBookDelete;
	TComboBox *CBookAuthor;
	TComboBox *CBookCost;
	TComboBox *CBookNum;
	TComboBox *CBookNote;
	TButton *BBookBack;
	TButton *BBookSearch;
	TPanel *PProperties;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BBookBackClick(TObject *Sender);
	void __fastcall BBookAddClick(TObject *Sender);
	void __fastcall CBookNameSelect(TObject *Sender);
	void __fastcall GridGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall GridExit(TObject *Sender);
	void __fastcall GridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BBookDeleteClick(TObject *Sender);
	void __fastcall BBookSearchClick(TObject *Sender);
	void __fastcall GridSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall FormCreate(TObject *Sender);






private:	// User declarations
public:		// User declarations
	__fastcall TFBook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBook *FBook;
//---------------------------------------------------------------------------
#endif