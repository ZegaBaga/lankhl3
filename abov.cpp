//---------------------------------------------------------------------------

#pragma hdrstop

#include "abov.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
__fastcall tabov::tabov()
{
   UnicodeString S;
   UnicodeString filename=Application->ExeName;
   nameapp="";
   version="";
   autor="";
   discription="";
   unsigned long h;
   unsigned long Size = GetFileVersionInfoSize(filename.w_str(), &h);

   if (Size == 0) return;

   wchar_t *buf = new wchar_t[Size];
   if (GetFileVersionInfo(filename.c_str(), h, Size, buf) != 0)
   {
	  struct LANGANDCODEPAGE {
		 WORD wLanguage;
		 WORD wCodePage;
	  } *lpTranslate;

      LPTSTR ValueBuf;
      unsigned int Len;
	  VerQueryValue(buf, L"\\VarFileInfo\\Translation", &(void*)lpTranslate, &Len);
      if (Len >= 4)
      {
         UnicodeString CharSet = UnicodeString().sprintf(L"%04x%04x",
                        lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);

		 if (VerQueryValue(buf, UnicodeString(L"\\StringFileInfo\\" + CharSet + L"\\ProductName").w_str(),
                           &(void*)ValueBuf, &Len) != 0)
		 {

			nameapp = ValueBuf;

		 }

		 if (VerQueryValue(buf, UnicodeString("\\StringFileInfo\\" + CharSet + "\\FileVersion").w_str(),
						   &(void*)ValueBuf, &Len) != 0)
		 {
			version = ValueBuf;

		 }
		 if (VerQueryValue(buf, UnicodeString("\\StringFileInfo\\" + CharSet + "\\LegalCopyright").w_str(),
						   &(void*)ValueBuf, &Len) != 0)
		 {
			autor = ValueBuf;

		 }
		 if (VerQueryValue(buf, UnicodeString("\\StringFileInfo\\" + CharSet + "\\FileDescription").w_str(),
						   &(void*)ValueBuf, &Len) != 0)
		 {
			discription =L"Описание: "+UnicodeString(ValueBuf);

		 }


	  }
   }
   delete [] buf;
   //Form2->Caption = ProductName->Caption+" "+Version->Caption;
}