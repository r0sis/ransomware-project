/* Get a shift and build a regex from it for a specific windows disk drives (A:/, ..., F:/)*/
void FUN_004016d5(char shift)
{
  undefined4 local_44;
  char local_40;
  undefined4 local_3f;
  undefined local_3b;
  undefined local_3a;
  
  while(true) {
    /* Allocates the specified number of bytes from the heap.
      [in] UINT uFlags = 0x40 : GMEM_ZEROINIT (Initializes memory contents to zero)
      [in] dbBytes = 0x18064 : The number of bytes to allocate 
      
      Return value : If the function succeeds, the return value is a handle to the newly allocated memory object.
    */
    LPCWSTR handle_memory_heap = (LPCWSTR)GlobalAlloc(0x40,0x18064);
    if (handle_memory_heap != (LPCWSTR)0x0) break;
    Sleep();
  }

  local_40 = shift + 'A'; // Calculate the disk drives 
  local_44 = 0x5c3f5c5c; // '\?\\'
  local_3f = 0x2e2a5c3a; // '.*\:'
  local_3b = 0x2a;       // '*'
  local_3a = 0;

  /* Memory like follow : 
      | 3a| 3b| 3c| 3d| 3e| 3f| 40| 41| 42| 43| 44|
      | 0 | * | . | * | \ | : | A | \ | ? | \ | \ |

  Possible content of local_44 depending on shift value are : 
      shift == 0 : "\\?\A:\*.*"
      shift == 1 : "\\?\B:\*.*"
      shift == 2 : "\\?\C:\*.*"
      shift == 3 : "\\?\D:\*.*"
      shift == 4 : "\\?\E:\*.*"
      shift == 5 : "\\?\F:\*.*"
  */

  /* Maps a character string to a UTF-16 (wide character) string.
    [in] UINT CodePage = 0x3a4 = 932 : Code page to use in performing the conversion. (932 = ANSI/OEM Japanese; Japanese (Shift-JIS))
    [in] DWORD dwFlags : Flags indicating the conversion type.
    [in] _In_NLS_string_(cbMultiByte)LPCCH lpMultiByteStr : Pointer to the character string to convert.
    [in] int cbMultiByte : Size, in bytes, of the string indicated by the lpMultiByteStr parameter. Alternatively, this parameter can be set to -1 if the string is null-terminated.
    [out, optional] LPWSTR lpWideCharStr : Pointer to a buffer that receives the converted string.
    [in] int cchWideChar : Size, in characters, of the buffer indicated by lpWideCharStr. If this value is 0, the function returns the required buffer size, in characters, including any terminating null character, and makes no use of the lpWideCharStr buffer.
  
  Return value : Returns the number of characters written to the buffer indicated by lpWideCharStr if successful. If the function succeeds and cchWideChar is 0, the return value is the required size, in characters, for the buffer indicated by lpWideCharStr. 
  */
  int size = MultiByteToWideChar(0x3a4,0,(LPCSTR)&local_44,-1,handle_memory_heap,0); 
  MultiByteToWideChar(0x3a4,0,(LPCSTR)&local_44,-1,handle_memory_heap,size);
  // handle_memory_heap now contains the regex of the disk drives, for instance for F:/ => "\.\.?.\.E.:.\.*...*." 

  // Value of DAT_00404b44 before is 0
  DAT_00404b44 = DAT_00404b44 + 1;

  // Call next function with handle_memory_heap that contains the regex chain
  FUN_004013e3(handle_memory_heap);
  return;
}
