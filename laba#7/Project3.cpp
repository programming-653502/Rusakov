//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Readers.cpp", FReaders);
USEFORM("Book.cpp", FBook);
USEFORM("Main.cpp", FMain);
USEFORM("ReadersInfo.cpp", FInfo);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->CreateForm(__classid(TFBook), &FBook);
		Application->CreateForm(__classid(TFReaders), &FReaders);
		Application->CreateForm(__classid(TFInfo), &FInfo);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
