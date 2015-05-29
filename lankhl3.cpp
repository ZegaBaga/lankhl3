//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("mainform.cpp", Form1);
USEFORM("rvia.cpp", rViaForm);
USEFORM("object.cpp", Form3);
USEFORM("equip.cpp", FormEquip);
USEFORM("groops.cpp", Form2);
USEFORM("equiptip.cpp", TipEquip);
USEFORM("storage.cpp", FormStorage);
USEFORM("storageedit.cpp", FormStorageEdit);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TrViaForm), &rViaForm);
		Application->CreateForm(__classid(TTipEquip), &TipEquip);
		Application->CreateForm(__classid(TFormEquip), &FormEquip);
		Application->CreateForm(__classid(TFormStorage), &FormStorage);
		Application->CreateForm(__classid(TFormStorageEdit), &FormStorageEdit);
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
