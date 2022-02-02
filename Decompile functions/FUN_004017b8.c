
void FUN_004017b8(void)

{
  LPCSTR lpParameters;
  LPSTR lpBuffer;
  LPSTR lpFilename;
  
  DeleteFileA(s_c:\Windows\notepad+++.exe_00404585);
  lpParameters = (LPCSTR)GlobalAlloc(0x40,0x10000);
  lpBuffer = lpParameters + 0x8000;
  lpFilename = (LPSTR)GetEnvironmentVariableA(s_ComSpec_00404317,lpBuffer,0x8000);
  GetModuleFileNameA((HMODULE)0x0,lpFilename,0x8000);
  ShellExecuteA((HWND)0x0,(LPCSTR)0x0,lpBuffer,lpParameters,(LPCSTR)0x0,0);
  GlobalFree(lpParameters);
  return;
}
