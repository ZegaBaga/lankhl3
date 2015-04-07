//---------------------------------------------------------------------------

#ifndef equiptipH
#define equiptipH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTipEquip : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBNavigator *DBNavigator1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTipEquip(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTipEquip *TipEquip;
//---------------------------------------------------------------------------
#endif
