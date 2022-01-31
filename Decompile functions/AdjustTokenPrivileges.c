/*
* Est un pointeur vers la déclaration de la même fonction implémentée dans la librairie ADVAPI32.DLL en redirigeant le flot d'instruction vers celle-ci
*
                             **************************************************************
                             *                POINTER to EXTERNAL FUNCTION                *
                             **************************************************************
                             BOOL __stdcall AdjustTokenPrivileges(HANDLE TokenHandle,
             BOOL              EAX:4          <RETURN>
             HANDLE            Stack[0x4]:4   TokenHandle
             BOOL              Stack[0x8]:4   DisableAllPrivileges
             PTOKEN_PRIVILE    Stack[0xc]:4   NewState
             DWORD             Stack[0x10]:4  BufferLength
             PTOKEN_PRIVILE    Stack[0x14]:4  PreviousState
             PDWORD            Stack[0x18]:4  ReturnLength
                             25  AdjustTokenPrivileges  <<not bound>>
                             PTR_AdjustTokenPrivileges_00403014              XREF[1]:     AdjustTokenPrivileges:00402172  
        00403014 bc 36 00 00     addr       ADVAPI32.DLL::AdjustTokenPrivileges
*
* addr est une directive assembleur : elle initialise les quatre octets suivants (ou huit octets en mode 64 bits) à l'adresse de son argument.
*
*
                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk BOOL __stdcall AdjustTokenPrivileges(HANDLE TokenH
                               Thunked-Function: ADVAPI32.DLL::AdjustTok
             BOOL              EAX:4          <RETURN>
             HANDLE            Stack[0x4]:4   TokenHandle
             BOOL              Stack[0x8]:4   DisableAllPrivileges
             PTOKEN_PRIVILE    Stack[0xc]:4   NewState
             DWORD             Stack[0x10]:4  BufferLength
             PTOKEN_PRIVILE    Stack[0x14]:4  PreviousState
             PDWORD            Stack[0x18]:4  ReturnLength
                             AdjustTokenPrivileges                           XREF[1]:     FUN_00401f9e:00401fe1(c)  
        00402172 ff 25 14        JMP        dword ptr [->ADVAPI32.DLL::AdjustTokenPrivileg
                 30 40 00
*
*/
/*
* Fonction originelement implémentée dans la bibliothèque ADVAPI32.DLL
* Il semblerait que cette fonction serve à faire le lien entre le programme et l'appel à la fonction de la librairie pour le compilateur
*
* La fonction AdjustTokenPrivileges active ou désactive les privilèges dans le jeton d'accès spécifié. L'activation ou la désactivation des privilèges d'un jeton d'accès 	   nécessite un accès TOKEN_ADJUST_PRIVILEGES.
*
* Paramètres: 
* [in] TokenHandle: Un handle vers le jeton d'accès qui contient les privilèges à modifier. Le handle doit avoir un accès TOKEN_ADJUST_PRIVILEGES au jeton. Si le paramètre 		            PreviousState n'est pas NULL, le handle doit également avoir accès à TOKEN_QUERY.
* [in] DisableAllPrivileges: Indique si la fonction désactive tous les privilèges du jeton. Si cette valeur est VRAIE, la fonction désactive tous les privilèges et ignore le 		                     paramètre NewState. Si elle est FAUX, la fonction modifie les privilèges en fonction des informations indiquées par le paramètre NewState.
* [in, optional] NewState: Un pointeur vers une structure TOKEN_PRIVILEGES qui spécifie un tableau de privilèges et leurs attributs. Si le paramètre DisableAllPrivileges est 				    FALSE, la fonction AdjustTokenPrivileges active, désactive ou supprime ces privilèges pour le jeton. 
* [in] BufferLength: Specifies the size, in bytes, of the buffer pointed to by the PreviousState parameter. This parameter can be zero if the PreviousState parameter is NULL.
* [out, optional] PreviousState: A pointer to a buffer that the function fills with a TOKEN_PRIVILEGES structure that contains the previous state of any privileges that the 					  function modifies. That is, if a privilege has been modified by this function, the privilege and its previous state are contained in the 				  TOKEN_PRIVILEGES structure referenced by PreviousState. If the PrivilegeCount member of TOKEN_PRIVILEGES is zero, then no privileges have been 					  changed by this function. This parameter can be NULL.
				  If you specify a buffer that is too small to receive the complete list of modified privileges, the function fails and does not adjust any 					  privileges. In this case, the function sets the variable pointed to by the ReturnLength parameter to the number of bytes required to hold the 					  complete list of modified privileges.
* [out, optional] ReturnLength: A pointer to a variable that receives the required size, in bytes, of the buffer pointed to by the PreviousState parameter. This parameter can be 				 NULL if PreviousState is NULL.
*
* Retourne: Si la fonction réussit, la valeur de retour est différente de zéro. Pour déterminer si la fonction a ajusté tous les privilèges spécifiés, appelez GetLastError, qui   	      renvoie l'une des valeurs suivantes lorsque la fonction réussit : 
				- ERROR_SUCCESS si La fonction a ajusté tous les privilèges spécifiés. 
				- ERROR_NOT_ALL_ASSIGNED si Le jeton ne possède pas un ou plusieurs des privilèges spécifiés dans le paramètre NewState. La fonction peut réussir  				  avec cette valeur d'erreur même si aucun privilège n'a été ajusté. Le paramètre PreviousState indique les privilèges qui ont été ajustés. 
*/
BOOL AdjustTokenPrivileges
               (HANDLE TokenHandle,BOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,
               DWORD BufferLength,PTOKEN_PRIVILEGES PreviousState,PDWORD ReturnLength)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00402172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = AdjustTokenPrivileges
                    (TokenHandle,DisableAllPrivileges,NewState,BufferLength,PreviousState,
                     ReturnLength);
  return BVar1;
}

