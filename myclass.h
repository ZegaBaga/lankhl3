//---------------------------------------------------------------------------

#ifndef myclassH
#define myclassH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <vector>
//---------------------------------------------------------------------------
struct QuikList
{
	UnicodeString Name;
	UnicodeString Path;
	UnicodeString Param;
	UnicodeString Icon;
	int Cod;
	bool Check;

};
struct func
{
	UnicodeString shname;
	UnicodeString name;
};

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
class tkomp
{
	public:
		tkomp();
		void __fastcall Load(TADOQuery *ado);
		void __fastcall Save(TADOQuery *ado);
		void __fastcall Delete(TADOQuery *ado);

		int tip;
		UnicodeString id,ip,naz,nname;
		UnicodeString rport,rlogin,rpass,rdomen,rwid;
		std::vector<QuikList> quicklist;


};
UnicodeString GetShortPath(UnicodeString way);
UnicodeString GetLongName(UnicodeString way);

//----------------------------------------------------------------------------
#endif
