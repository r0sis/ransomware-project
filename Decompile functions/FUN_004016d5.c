void FUN_004016d5(char param_1)

{
  LPCWSTR lpWideCharStr;
  int cchWideChar;
  undefined4 local_44;
  char local_40;
  undefined4 local_3f;
  undefined local_3b;
  undefined local_3a;
  
  while( true ) {
    lpWideCharStr = (LPCWSTR)GlobalAlloc(0x40,0x18064);
    if (lpWideCharStr != (LPCWSTR)0x0) break;
    Sleep();
  }
  local_40 = param_1 + 'A';
  local_44 = 0x5c3f5c5c;
  local_3f = 0x2e2a5c3a;
  local_3b = 0x2a;
  local_3a = 0;
  cchWideChar = MultiByteToWideChar(0x3a4,0,(LPCSTR)&local_44,-1,lpWideCharStr,0);
  MultiByteToWideChar(0x3a4,0,(LPCSTR)&local_44,-1,lpWideCharStr,cchWideChar);
  DAT_00404b44 = DAT_00404b44 + 1;
  FUN_004013e3(lpWideCharStr);
  return;
}
