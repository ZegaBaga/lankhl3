// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "groops.h"
#include "myclass.h"
//#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender) {

	UnicodeString FileName=GetLongName(Edit2->Text);
	UnicodeString DirInit=ExtractFilePath(FileName);
	if(FileExists(FileName))
		OpenPictureDialog1->FileName = FileName;
	else
		if(DirectoryExists(DirInit))
			OpenPictureDialog1->InitialDir=DirInit;
		else
		{
			OpenPictureDialog1->InitialDir=ExtractFilePath(Application->ExeName);
			OpenPictureDialog1->FileName = "";
		}


	if (OpenPictureDialog1->Execute())
	{
		Edit2->Text = GetShortPath(OpenPictureDialog1->FileName);
		Image1->Picture->LoadFromFile(GetLongName(Edit2->Text));
	}

	//FormShow(Form2);

}
// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------





void __fastcall TForm2::LNameClick(TObject *Sender)
{
	EName->Text=Edit1->Text;
}
//---------------------------------------------------------------------------


