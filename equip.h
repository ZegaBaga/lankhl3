//---------------------------------------------------------------------------

#ifndef equipH
#define equipH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormEquip : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TDataSource *DataSource1;
	TADOTable *ADOTable1;
	TADOQuery *ADOQuery1;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormEquip(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEquip *FormEquip;
//---------------------------------------------------------------------------
#endif