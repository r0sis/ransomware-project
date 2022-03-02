
longlong __fastcall FUN_00401fe8(undefined4 param_1,uint param_2,LPCWSTR lpString1)
// LPCWSTR : Long Pointer to Constant wide String
// Wide implies that a the string wille be stored following 2 bytes per char instead of 1byte per char.
{
  int iVar1;
  wchar_t *lpString2;

  lpString2 = "[System_process]";
  do {
    /* Compares two character strings. The comparison is not case-sensitive.
        [in] LPCWSTR lpString1 : The first null-terminated string to be compared.
        [in] LPCWSTR lpString2 : The second null-terminated string to be compared.

        Return value : If the string pointed to by lpString1 is less than the string pointed to by lpString2, the return value is negative. If the string pointed to by lpString1 is greater than the string pointed to by lpString2, the return value is positive. If the strings are equal, the return value is zero.
    */
    ret_val = lstrcmpiW(lpString1,lpString2);

    if (ret_val == 0) {
      return (ulonglong)param_2 << 0x20; // return false
    }

    ret_val = lstrlenW(lpString2);
    lpString2 += ret_val + 1;
  } while (*lpString2 != L'\0');

  return CONCAT44(param_2,1);
  // it takes 4 bytes from first location 4 bytes from second location and produces a 8 byte result


  // The function return 0 if something went wrong and non-zero otherwise
}
