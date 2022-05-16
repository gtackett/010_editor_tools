//------------------------------------------------
//--- 010 Editor v12.0.1 Include File
//
//      File: UtilityFunctions.inc
//   Authors: 
//   Version: 
//   Purpose: 
//  Category: 
// File Mask: 
//  ID Bytes: 
//   History: 
//------------------------------------------------
#ifndef _UTILITYFUNCTIONS_INC_

#define _UTILITYFUNCTIONS_INC_

#ifndef WARNINGDELAYMAX
#define WARNINGDELAYMAX 10
#endif
void warningWithLimitedDelay(string s, float seconds)
{
    Warning(s);
    if (seconds > 0)
        Sleep( (int) (Min(seconds,WARNINGDELAYMAX) * 100) );
}

#ifdef MYASSERTFATAL
#define myAssert Assert
#undef MYASSERTFATAL
#else
#undef myAssert
#define myAssert __warnAssert
void myAssert(int c, string s) {
    if (!c)
        warningWithLimitedDelay(s, 5);
}
#endif




#endif // _UTILITYFUNCTIONS_INC_