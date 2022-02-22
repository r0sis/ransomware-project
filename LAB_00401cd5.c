
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 UndefinedFunction_00401cd5(HWND param_1,int param_2,int param_3,int param_4)
// HWND : Handle to a window
{
  LPVOID pvVar1;
  // Windows API -> typedef void*

  if (param_2 == 0x110) { // 0x110 = 272
    // EAX 0x00000030 0
    // EAX 00000110 L'D'
    DAT_00404b28 = param_1;
    // EAX 000801C8 É...
    // EAX 0000006D m...
    // EAX 0000006F o...

    // h
    // EAX 00000128 i
    // EAX 00000046 f
    _DAT_00404b30 = FUN_0040204c();
    _DAT_00404b34 = FUN_0040204c();
    FUN_00401676();
  }
  else if (param_2 == 0x219) { // 0x219 = 537
    if ((param_3 == 0x8000) && (*(int *)(param_4 + 4) == 2)) { // 0x8000 = 32768
      pvVar1 = (LPVOID)0x1f; // 0x1f = 31
      if (*(uint *)(param_4 + 0xc) != 0) { // 0xc = 12
        for (; *(uint *)(param_4 + 0xc) >> (int)pvVar1 == 0; pvVar1 = (LPVOID)((int)pvVar1 + -1)) {
        }
      }
      FUN_004010a6(pvVar1);
    }
  }
  else if (param_2 == 0x113) { // 0x113 = 275
    DAT_00404b40 = DAT_00404b40 + 1;
    DATA_00404000._38_4_ = 0x20202020; // 538976288 ??
    FUN_00401758(DAT_00404b40,DATA_00404000 + 0x26); //0x26 = 38
    FUN_00401758(DAT_00404b48,DATA_00404000);
    DATA_00404000._19_4_ = 0x20202020;
    FUN_00401758(DAT_00404b48 - _DAT_00404b4c,DATA_00404000 + 0x13); //0x13 = 19
    _DAT_00404b4c = DAT_00404b48;
    DATA_00404000._56_4_ = 0x20202020;
    FUN_00401758(DAT_00404b44,DATA_00404000 + 0x38); // 0x38 = 56
    FUN_00401e9a();
  }
  else if ((DATA_00404000[81] == 'n') && (DAT_00404b44 == 0)) {
    FUN_0040212a();
    if (_DAT_00404b24 == 0) {
      _DAT_00404b24 = 1;
      ShellExecuteA((HWND)0x0,&DAT_0040431f,s_c:\Windows\notepad.exe_"c:\How_T_00404546,(LPCSTR)0x0,
                    (LPCSTR)0x0,5);
      /* HINSTANCE ShellExecuteA(
            [in, optional] HWND   hwnd :
  handle to a parent window,
            [in, optional] LPCSTR lpOperation :
  A pointer to a null-terminated string, referred to in this case as a verb, that specifies the action to be performed,
            [in]           LPCSTR lpFile :
  A pointer to a null-terminated string that specifies the file or object on which to execute the specified verb,
            [in, optional] LPCSTR lpParameters :
  If lpFile specifies an executable file, this parameter is a pointer to a null-terminated string that specifies the parameters to be passed to the application,
            [in, optional] LPCSTR lpDirectory :
  A pointer to a null-terminated string that specifies the default (working) directory for the action,
            [in]           INT    nShowCmd :
  The flags that specify how an application is to be displayed when it is opened.
  5 : Activates the window and displays it in its current size and position.
      ); */

      // Return Value ? > 32 if succeeded : explicit_error if failed
    }
    FUN_00401676();
  }
  else {
    if (param_2 != 0x10) { // 0x10 = 16
      return 0;
    }
    ShowWindow(param_1,0);
  }
  return 1;
}
