// ---------------------------------------------------------------------------

#ifndef groopsH
#define groopsH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>

// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *Label1;
	TEdit *Edit1;
	TGroupBox *GroupBox1;
	TImage *Image1;
	TEdit *Edit2;
	TMemo *Memo1;
	TLabel *Label2;
	TPanel *Panel1;
	TEdit *EName;
	TLabel *LName;
	TLabel *LBoss;
	TEdit *EBoss;
	TLabel *LPhone;
	TEdit *EPhone;
	TEdit *EEmail;
	TLabel *LEmail;
	TPanel *Panel2;
	TEdit *EAdress;
	TLabel *LAdress;
	TLabel *LIP;
	TEdit *EIP;
	TSpeedButton *SpeedButton1;

	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall LNameClick(TObject *Sender);

private: // User declarations

public: // User declarations
	__fastcall TForm2(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
