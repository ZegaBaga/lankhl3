//---------------------------------------------------------------------------

#ifndef myclassH
#define myclassH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
struct tsys
{
	int top,left,width,height;
	void __fastcall loadsys(TADOQuery *ado);
	void __fastcall savesys(TADOQuery *ado);
	bool __fastcall keyexists(TADOQuery *ado,UnicodeString keyy);
	void __fastcall setkey(TADOQuery *ado,UnicodeString keyy,UnicodeString val);
};
class tgroops
{

public:
	tgroops();
	int cod,tipgroop,imgindex;
	UnicodeString gname,id,parentid,fullpath,comm,iconpath,fio,phone,email,ip,adress,fullname;
	void Save(TADOQuery *ado);
	void Delete(TADOQuery *ado);
};
class telements
{
	public:
		telements();
		void __fastcall Load(TADOQuery *ado);
		void __fastcall Save(TADOQuery *ado);
		void __fastcall Delete(TADOQuery *ado);

		int tip;
		UnicodeString id,parentid,chaildid,groupid,name;
};
UnicodeString GetShortPath(UnicodeString way);
UnicodeString GetLongName(UnicodeString way);

//----------------------------------------------------------------------------
#endif