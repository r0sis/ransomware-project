
void FUN_004010e7(LPNETRESOURCEA param_1,int param_2)

{
  DWORD DVar1;
  HGLOBAL lpBuffer;
  LPNETRESOURCEA p_Var2;
  int iVar3;
  LPWSTR lpWideCharStr;
  int iVar4;
  short *lpString;
  LPCSTR pCVar5;
  HANDLE local_28;
  uint local_24;
  HGLOBAL local_1c;
  SIZE_T local_14;
  uint local_10;
  LPWSTR local_c;
  LPCSTR local_8;
  
  if (param_2 == 0) {
    DVar1 = WNetOpenEnumA(2,0,0,param_1,&local_28);
  }
  else {
    DVar1 = WNetOpenEnumA(2,0,0,(LPNETRESOURCEA)0x0,&local_28);
  }
  if (DVar1 == 0) {
    local_10 = 0xffffffff;
    local_14 = 0x4000;
    while (local_8 = (LPCSTR)GlobalAlloc(0x40,0x4000), local_8 == (LPCSTR)0x0) {
      local_28 = (HANDLE)0xc8;
      Sleep();
    }
    while (local_1c = GlobalAlloc(0x40,local_14), local_1c == (HGLOBAL)0x0) {
      local_28 = (HANDLE)0xc8;
      Sleep();
    }
    DVar1 = WNetEnumResourceA(local_28,&local_10,local_1c,&local_14);
    if (DVar1 == 0xea) {
      GlobalFree(local_1c);
      while (lpBuffer = GlobalAlloc(0x40,local_14), lpBuffer == (HGLOBAL)0x0) {
        local_28 = (HANDLE)0xc8;
        Sleep();
      }
      local_10 = 0xffffffff;
      local_1c = lpBuffer;
      DVar1 = WNetEnumResourceA(local_28,&local_10,lpBuffer,&local_14);
    }
    if (DVar1 == 0) {
      local_24 = 0;
      do {
        p_Var2 = (LPNETRESOURCEA)(local_24 * 0x20 + (int)local_1c);
        if (p_Var2->dwUsage == 1) {
          lpString = (short *)p_Var2->lpRemoteName;
          if (*lpString == 0x5c5c) {
            iVar3 = lstrlenA((LPCSTR)lpString);
            pCVar5 = local_8;
            for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pCVar5 = *(CHAR *)lpString;
              lpString = (short *)((int)lpString + 1);
              pCVar5 = pCVar5 + 1;
            }
            *(undefined4 *)(local_8 + iVar3) = 0x2a2e2a5c;
            *(undefined *)((int)(local_8 + iVar3) + 4) = 0;
            while (lpWideCharStr = (LPWSTR)GlobalAlloc(0x40,0x18064), lpWideCharStr == (LPWSTR)0x0)
            {
              local_28 = (HANDLE)0xc8;
              Sleep();
            }
            local_c = lpWideCharStr;
            iVar4 = MultiByteToWideChar(3,0,local_8,-1,lpWideCharStr,0);
            MultiByteToWideChar(3,0,local_8,-1,local_c,iVar4);
            DAT_00404b44 = DAT_00404b44 + 1;
            FUN_004013e3(local_c);
          }
        }
        else {
          FUN_004010e7(p_Var2,0);
        }
        local_24 = local_24 + 1;
      } while (local_24 < local_10);
    }
    GlobalFree(local_8);
    GlobalFree(local_1c);
  }
  WNetCloseEnum(local_28);
  return;
}

