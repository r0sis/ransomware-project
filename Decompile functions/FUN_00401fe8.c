
longlong __fastcall FUN_00401fe8(undefined4 param_1,uint param_2,LPCWSTR param_3)
// LPCWSTR : Long Pointer to Constant wide String
// It implies that a the string wille be stored following 2 bytes per char instead of 1byte per char. 
{
  int iVar1;
  wchar_t *lpString2;

  lpString2 = u_[System_process]_0040459f;
  do {
    iVar1 = lstrcmpiW(param_3,lpString2);
    if (iVar1 == 0) {
      return (ulonglong)param_2 << 0x20;
    }
    iVar1 = lstrlenW(lpString2);
    lpString2 = lpString2 + iVar1 + 1;
  } while (*lpString2 != L'\0');
  return CONCAT44(param_2,1);
}
