//---------------------------------------------------------------------------

#ifndef rviaH
#define rviaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TrViaForm : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView2;
	TTreeView *TreeView1;
	TADOQuery *ADOQuery1;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TreeView1Click(TObject *Sender);
	void __fastcall TreeView2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TrViaForm(TComponent* Owner);
	void __fastcall LoadGroops();
	void __fastcall SetIcons();
	void __fastcall SetIconsOjects() ;
	UnicodeString groopid,elementid,kompid,wid;
};
//---------------------------------------------------------------------------
extern PACKAGE TrViaForm *rViaForm;
//---------------------------------------------------------------------------
#endif
