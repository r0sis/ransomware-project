/*
*
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __stdcall FUN_0040212a(void)
             undefined         AL:1           <RETURN>
                             FUN_0040212a                                    XREF[9]:     FUN_004010e7:00401143(c), 
                                                                                          FUN_004010e7:00401160(c), 
                                                                                          FUN_004010e7:0040119f(c), 
                                                                                          FUN_004010e7:00401229(c), 
                                                                                          FUN_004013e3:00401478(c), 
                                                                                          FUN_004013e3:004014ef(c), 
                                                                                          FUN_004016d5:004016f0(c), 
                                                                                          00401dea(c), 
                                                                                          FUN_00401eda:00401f65(c)  
        0040212a ff 25 b0        JMP        dword ptr [DAT_004030b0]
                 30 40 00
                 
                 
                 
                             **************************************************************
                             *                                                            *
                             **************************************************************
                             DAT_004030b0                                    XREF[1]:     FUN_0040212a:0040212a  
        004030b0 04              ??         04h
        004030b1 36              ??         36h    6
        004030b2 00              ??         00h
        004030b3 00              ??         00h
*
*/

/*
* Fonction semblant sauter à une zone mémoire du programme à executé
/*
void FUN_0040212a(void)

{
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x3604)(); // Saut à la zone mémoire à executée
  return;
}