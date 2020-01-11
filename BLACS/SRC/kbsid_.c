#include "Bdef.h"

#if (INTFACE == C_CALL)
Int Ckbsid(Int ConTxt, char *scope)
#else
F_INT_FUNC kbsid_(Int *ConTxt, F_CHAR scope)
#endif
{
   char tmpscope;
   Int msgid;
   BLACSCONTEXT *ctxt;

   MGetConTxt(Mpval(ConTxt), ctxt);
   tmpscope = Mlowcase(F2C_CharTrans(scope));
   switch(tmpscope)
   {
   case 'c' :
      ctxt->scp = &ctxt->cscp;
      break;
   case 'r' :
      ctxt->scp = &ctxt->rscp;
      break;
   case 'a' :
      ctxt->scp = &ctxt->ascp;
      break;
   }
   msgid = Mscopeid(ctxt);
   return(msgid);
}
