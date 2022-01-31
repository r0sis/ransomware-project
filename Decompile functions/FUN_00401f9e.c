/*
*                
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __cdecl FUN_00401f9e(PLUID param_1, HANDLE par
             undefined         AL:1           <RETURN>
             PLUID             Stack[0x4]:4   param_1
             HANDLE            Stack[0x8]:4   param_2                                 XREF[1]:     00401fdc(R)  
             undefined4        Stack[0xc]:4   param_3
             DWORD             Stack[0x10]:4  param_4                                 XREF[1]:     00401fb1(R)  
             LONG              Stack[0x14]:4  param_5                                 XREF[1]:     00401fb9(R)  
             undefined4        Stack[0x18]:4  param_6                                 XREF[1]:     00401fc9(*)  
             DWORD             Stack[0x1c]:4  param_7                                 XREF[3]:     00401fa9(W), 
                                                                                                   00401fce(*), 
                                                                                                   00401fd5(*)  
             DWORD             Stack[0x20]:4  param_8                                 XREF[1]:     00401fb5(W)  
             LONG              Stack[0x24]:4  param_9                                 XREF[1]:     00401fbd(W)  
             DWORD             Stack[0x28]:4  param_10                                XREF[1]:     00401fc1(W)  
                             FUN_00401f9e                                    XREF[2]:     FUN_00401f6f:00401f81(j), 
                                                                                          FUN_00401f6f:00401f88(c)  
        00401f9e 6a 00           PUSH       0x0
        00401fa0 e8 fd 01        CALL       LookupPrivilegeValueA                            BOOL LookupPrivilegeValueA(LPCST
                 00 00
        00401fa5 85 c0           TEST       EAX,EAX
        00401fa7 74 3d           JZ         LAB_00401fe6
        00401fa9 c7 44 24        MOV        dword ptr [ESP + param_7],0x1
                 14 01 00 
                 00 00
        00401fb1 8b 44 24 08     MOV        EAX,dword ptr [ESP + param_4]
        00401fb5 89 44 24 18     MOV        dword ptr [ESP + param_8],EAX
        00401fb9 8b 44 24 0c     MOV        EAX,dword ptr [ESP + param_5]
        00401fbd 89 44 24 1c     MOV        dword ptr [ESP + param_9],EAX
        00401fc1 c7 44 24        MOV        dword ptr [ESP + param_10],0x2
                 20 02 00 
                 00 00
        00401fc9 8d 44 24 10     LEA        EAX=>param_6,[ESP + 0x10]
        00401fcd 50              PUSH       EAX
        00401fce 8d 44 24 18     LEA        EAX=>param_7,[ESP + 0x18]
        00401fd2 50              PUSH       EAX
        00401fd3 6a 10           PUSH       0x10
        00401fd5 8d 44 24 20     LEA        EAX=>param_7,[ESP + 0x20]
        00401fd9 50              PUSH       EAX
        00401fda 6a 00           PUSH       0x0
        00401fdc 8b 44 24 14     MOV        EAX,dword ptr [ESP + param_2]
        00401fe0 50              PUSH       EAX
        00401fe1 e8 8c 01        CALL       AdjustTokenPrivileges                            BOOL AdjustTokenPrivileges(HANDL
                 00 00
                             LAB_00401fe6                                    XREF[1]:     00401fa7(j)  
        00401fe6 c9              LEAVE
        00401fe7 c3              RET
*
*/
/*
* Fonction sans retour dont le but semble de vérifier si le programme détient les bon privilèges Windows lié à son "token"
* Dans un premier temps, la fonction vérifie les privilèges du token courant via utilisation de la librairie ADVAPI32.DLL.
* Si le token ne possède pas les bons privilèges, alors la fonction fait appel de nouveau a la librairie ADVAPI32.DLL afin de mettre à jour les privilèges de son token
* 
* Paramètres: information sytèmes lié au processus du malware
*
* Retourne: void
*/
void __cdecl
FUN_00401f9e(PLUID param_1,HANDLE param_2,undefined4 param_3,DWORD param_4,LONG param_5,
            DWORD param_6,DWORD param_7,DWORD param_8,LONG param_9,DWORD param_10)

{
  BOOL BVar1; // Création d'un booléen
  LPCSTR unaff_retaddr; // Création d'un pointeur vers une chaîne de caractères terminée.
  
  BVar1 = LookupPrivilegeValueA((LPCSTR)0x0,unaff_retaddr,param_1); // Appel à la fonction LookupPrivilegeValueA (ADVAPI32.DLL) pour vérifier le token de privilèges
  
  // Si notre booléen est faux après execution de la précédente fonction (erreur dans l'accès aux privilèges du token)
  if (BVar1 != 0) {
    // Changement de valeur des paramètres suivants
    param_7 = 1;
    param_8 = param_4;
    param_9 = param_5;
    param_10 = 2;
    
    // Appel à la fonction AdjustTokenPrivileges (ADVAPI32.DLL) avec les nouveaux paramètres pour mettre à jour le token de privilèges.
    AdjustTokenPrivileges(param_2,0,(PTOKEN_PRIVILEGES)&param_7,0x10,(PTOKEN_PRIVILEGES)&param_7,&param_6);
  }
  return; // On ne retourne rien car de type void
}

/*
advapi32.dll est une partie d'une bibliothèque avancée de services d'api supportant de nombreux api comprenant beaucoup d'appels sytèmes de sécurité et d'enregistrement.
advapi32.dll est un processus système nécessaire au fonctionnement approprié de Windows
*/
