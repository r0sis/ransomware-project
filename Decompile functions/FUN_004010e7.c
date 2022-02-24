
void FUN_004010e7(LPNETRESOURCEA param_1,int param_2)
// Pointer to a NETRESOURCE structure that specifies the network resource for which information is required.
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
    //The WNetOpenEnum function starts an enumeration of network resources or existing connections
    /*
      [in]  DWORD          dwScope, : Scope of the enumeration | 2 : RESOURCE_GLOBALNET : all resources of the network
      [in]  DWORD          dwType, : Resource types to be enumerated
      [in]  DWORD          dwUsage, : Resource usage type to be enumerated. 0 means All resources. This parameter is ignored unless the dwScope parameter is equal to RESOURCE_GLOBALNET
      [in]  LPNETRESOURCEA lpNetResource, : Pointer to a NETRESOURCE structure that specifies the container to enumerate. If the dwScope parameter is not RESOURCE_GLOBALNET, this parameter must be NULL...
      [out] LPHANDLE       lphEnum : Pointer to an enumeration handle that can be used in a subsequent call to WNetEnumResource.

      ------------------- RETURN VALUE ---------------------------
      If the function succeeds, the return value is NO_ERROR and a system error code otherwise.

      // Enum of the network connections and resources in the container param_1
    */
  }
  else {
    DVar1 = WNetOpenEnumA(2,0,0,(LPNETRESOURCEA)0x0,&local_28);
    // Enum of the network connections and resources generally
  }
  if (DVar1 == 0) {
    local_10 = 0xffffffff;
    local_14 = 0x4000;
    while (local_8 = (LPCSTR)GlobalAlloc(0x40,0x4000), local_8 == (LPCSTR)0x0) {
      local_28 = (HANDLE)0xc8;
      FUN_0040212a();
    }
    while (local_1c = GlobalAlloc(0x40,local_14), local_1c == (HGLOBAL)0x0) {
      local_28 = (HANDLE)0xc8;
      FUN_0040212a();
    }
    DVar1 = WNetEnumResourceA(local_28,&local_10,local_1c,&local_14);
    /*
    Continues an enumeration of network resources that was started by a call to the WNetOpenEnum function.

    DWORD WNetEnumResourceA(
      [in]      HANDLE  hEnum, : Handle that identifies an enumeration instance
      [in, out] LPDWORD lpcCount, : Pointer to a variable specifying the number of entries requested.If the function succeeds, on return the variable pointed to by this parameter contains the number of entries actually read.
      [out]     LPVOID  lpBuffer, : Pointer to the buffer that receives the enumeration results. The results are returned as an array of NETRESOURCE structures
      [in, out] LPDWORD lpBufferSize, :  Pointer to a variable that specifies the size of the lpBuffer parameter, in bytes. If the buffer is too small to receive even one entry, this parameter receives the required size of the buffer.
    );

    ------------------- RETURN VALUE ---------------------------
    In case of a sucess : NO_ERROR or ERROR_NO_MORE_ITEMS.
    Otherwise a system error code is returned.
    */
    if (DVar1 == 0xea) {
      GlobalFree(local_1c);
      while (lpBuffer = GlobalAlloc(0x40,local_14), lpBuffer == (HGLOBAL)0x0) {
        local_28 = (HANDLE)0xc8;
        FUN_0040212a();
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
              FUN_0040212a(); // Sleep();
            }
            local_c = lpWideCharStr;
            iVar4 = MultiByteToWideChar(3,0,local_8,-1,lpWideCharStr,0); //Maps a character string to a UTF-16 (wide character) string
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
  // Ends the enumeration started by the WNetOpenEnum function
  return;
}
