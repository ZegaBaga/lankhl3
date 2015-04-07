//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "equiptip.h"
#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTipEquip *TipEquip;
//---------------------------------------------------------------------------
__fastcall TTipEquip::TTipEquip(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTipEquip::FormShow(TObject *Sender)
{
	Left=Form1->Left+Form1->Width/2-Width/2;
	Top=Form1->Top+Form1->Height/2-Height/2;
	ADOTable1->Active=true;
	DBGrid1->Columns->Items[0]->Visible=false;
	DBGrid1->Columns->Items[1]->Title->Caption="Название";
	DBGrid1->Columns->Items[1]->Width=100;
}
//---------------------------------------------------------------------------
void __fastcall TTipEquip::FormCreate(TObject *Sender)
{

	//DBGrid1->Columns->Items[2]->Title->Caption="Расходиник";
	//DBGrid1->Columns->Items[2]->Width=100;
	//ADOTable1->Sort=L"Model";

}
//---------------------------------------------------------------------------
void __fastcall TTipEquip::FormHide(TObject *Sender)
{
	ADOTable1->Active=false;

}
//---------------------------------------------------------------------------
