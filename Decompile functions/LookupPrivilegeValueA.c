/*
* Est un pointeur vers la déclaration de la même fonction implémenter dans la librairie ADVAPI32.DLL en redirigeant le flot d'instruction vers celle-ci
*
                             **************************************************************
                             *                POINTER to EXTERNAL FUNCTION                *
                             **************************************************************
                             BOOL __stdcall LookupPrivilegeValueA(LPCSTR lpSystemName
             BOOL              EAX:4          <RETURN>
             LPCSTR            Stack[0x4]:4   lpSystemName
             LPCSTR            Stack[0x8]:4   lpName
             PLUID             Stack[0xc]:4   lpLuid
                             321  LookupPrivilegeValueA  <<not bound>>
                             PTR_LookupPrivilegeValueA_00403028              XREF[1]:     LookupPrivilegeValueA:004021a2 
        00403028 54 37 00 00     addr       ADVAPI32.DLL::LookupPrivilegeValueA
*
* addr est une directive assembleur : elle initialise les quatre octets suivants (ou huit octets en mode 64 bits) à l'adresse de son argument.
*                               
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk BOOL __stdcall LookupPrivilegeValueA(LPCSTR lpSyst
                               Thunked-Function: ADVAPI32.DLL::LookupPri
             BOOL              EAX:4          <RETURN>
             LPCSTR            Stack[0x4]:4   lpSystemName
             LPCSTR            Stack[0x8]:4   lpName
             PLUID             Stack[0xc]:4   lpLuid
                             LookupPrivilegeValueA                           XREF[1]:     FUN_00401f9e:00401fa0(c)  
        004021a2 ff 25 28        JMP        dword ptr [->ADVAPI32.DLL::LookupPrivilegeValu
                 30 40 00
*
*/
/*
* Fonction originelement implémentée dans la bibliothèque ADVAPI32.DLL
* Il semblerait que cette fonction serve à faire le lien entre le programme et l'appel à la fonction de la librairie pour le compilateur
* 
* La fonction LookupPrivilegeValue récupère l'identifiant unique local (LUID) utilisé sur un système spécifié pour représenter localement le nom de privilège spécifié.
*
* Paramètres: 
* [in, optional] lpSystemName: Un pointeur vers une chaîne à terminaison nulle qui spécifie le nom du système sur lequel le nom du privilège est récupéré. Si une chaîne nulle est 	                         spécifiée, la fonction tente de trouver le nom du privilège sur le système local.
* [in] lpName: Un pointeur vers une chaîne à terminaison nulle qui spécifie le nom du privilège, tel que défini dans le fichier d'en-tête Winnt.h. Par exemple, ce paramètre  	            peut spécifier la constante SE_SECURITY_NAME, ou la chaîne correspondante, "SeSecurityPrivilege".
* [out] lpLuid: Un pointeur vers une variable qui reçoit le LUID par lequel le privilège est connu sur le système spécifié par le paramètre lpSystemName.
*
* Retourne: Si la fonction réussit, elle renvoie une valeur non nulle.
	    Si la fonction échoue, elle renvoie zéro. Pour obtenir des informations supplémentaires sur les erreurs, appelez GetLastError.
*/
BOOL LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004021a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = LookupPrivilegeValueA(lpSystemName,lpName,lpLuid);
  return BVar1;
}

