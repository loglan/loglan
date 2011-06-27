#define         INCL_BASE
#include        <os2.h>

int pascal inkey(dummy)
int *dummy;
{
    KBDKEYINFO kdata;
    int i;
    unsigned u;
	
    KbdPeek(&kdata, 0);
    if (kdata.fbStatus)
    {
        KbdCharIn(&kdata, 0, 0);
        if (kdata.chChar != '\0')
        {
            u = kdata.chChar;    
            return(u);
        }
        else
        {
            i = kdata.chScan;
	    if (i < 0x80) return(-i);  else return(i);
        }
    }
    else
        return(0);
}
