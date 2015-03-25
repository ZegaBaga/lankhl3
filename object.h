// ---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//#include <Sockets.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <IdIPWatch.hpp>
#include <IdIPAddrMon.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

class TForm3 : public TForm {
__published: // IDE-managed Components
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TLabel *Label4;
	TEdit *EditIP;
	TLabel *Label7;
	TEdit *EditName;
	TLabel *Label2;
	TEdit *EditFullName;
	TCheckBox *CheckBox2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TLabel *Label1;
	TMemo *Memo1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TLabel *Label3;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TOpenDialog *OpenDialog1;
	TCheckListBox *ListBox1;
	TLabel *Label16;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TButtonedEdit *WidEdit;
	TImageList *ImageList1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit3;
	TIdIPAddrMon *IdIPAddrMon1;
	TSpeedButton *SpeedButton4;
	TPopupMenu *PopupMenu2;
	TMenuItem *HTTP1;
	TMenuItem *HTTPS1;
	TMenuItem *telnet1;
	TCheckBox *CBexip;
	TGroupBox *GroupBox2;
	TEdit *OnLine;
	TBitBtn *BitBtn6;
	TBitBtn *BitBtn4;
	TLabel *Label13;
	TLabel *Label15;
	TEdit *EditOnLineMess;
	TGroupBox *GroupBox3;
	TBitBtn *BitBtn7;
	TBitBtn *BitBtn5;
	TEdit *OffLine;
	TEdit *EditOffLineMess;
	TLabel *Label17;
	TTabSheet *TabSheet5;
	TCheckListBox *FuncCheckBox;
	TTabSheet *TabSheet6;
	TMemo *Dop;
	TEdit *DataV;
	TLabel *Label14;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *Inv;
	TEdit *SN;
	TSpeedButton *SpeedButton6;
	TLabel *Label21;
	TADOQuery *ADOQuery1;
	TEdit *Model;

	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Label7MouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Label2MouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ListBox1ClickCheck(TObject *Sender);
	void __fastcall WidEditRightButtonClick(TObject *Sender);
	void __fastcall WidEditLeftButtonClick(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall HTTP1Click(TObject *Sender);
	void __fastcall HTTPS1Click(TObject *Sender);
	void __fastcall telnet1Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall FuncCheckBoxClickCheck(TObject *Sender);
	void __fastcall ComboBoxEx1Change(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);

private: // User declarations

public: // User declarations
	__fastcall TForm3(TComponent* Owner);
	UnicodeString Wid;
	bool isnew;
	void ShowWid();
	void __fastcall FillFunc();
	void __fastcall ShowTabs();
	//void __fastcall LoadPrinter();
	UnicodeString functions;
	int row;
};
// ---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
// ---------------------------------------------------------------------------
#endif
