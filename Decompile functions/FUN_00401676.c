void FUN_00401676(void)

{
  uint uVar1;
  LPVOID pvVar2;
  LPVOID lpParameter;
  DWORD local_8;
  
  uVar1 = GetLogicalDrivers();
  lpParameter = (LPVOID)0x19;
  do {
    pvVar2 = lpParameter;
    if ((1 << ((byte)lpParameter & 0x1f) & uVar1) != 0) {
      pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_004016d5,lpParameter,0,&local_8);
      uVar1 = 0xf;
      SetThreadPriority();
    }
    lpParameter = (LPVOID)((int)pvVar2 + -1);
  } while (0 < (int)pvVar2);
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004010cf,(LPVOID)0x0,0,
               &local_8);
  SetThreadPriority();
  return;
}