//---------------------------------------------------------------------------

#ifndef objectH
#define objectH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditIP;
	TLabel *Label2;
	TEdit *EditName;
	TLabel *Label3;
	TEdit *EditFullName;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
