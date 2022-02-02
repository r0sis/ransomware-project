
/* WARNING: Instruction at (ram,0x00401f9e) overlaps instruction at (ram,0x00401f9a)
    */

// This funtction deals with the access tokens of a function

BOOL FUN_00401f6f(void)

{
  char *pcVar1;
  undefined uVar2;
  BOOL BVar3;
  char extraout_CH;
  char extraout_CH_00;
  char cVar4;
  undefined2 extraout_DX;
  undefined2 uVar5;
  short unaff_SI;
  undefined *unaff_EDI;
  undefined2 in_GS;
  bool bVar6;
  undefined6 uVar7;
  PLUID lpSystemName;
  LPCSTR in_stack_ffffffd8;
  PLUID in_stack_ffffffdc;
  HANDLE in_stack_ffffffe0;
  LONG in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  DWORD in_stack_ffffffec;
  DWORD in_stack_fffffff0;
  DWORD in_stack_fffffff4;
  DWORD in_stack_fffffff8;

  // HANDLE : Represents a type that has its lifetime controlled by the workflow runtime.

  BVar3 = OpenProcessToken((HANDLE)0xffffffff,0x28,(PHANDLE)&stack0xffffffd8);
  /*          ******* PARAMETERS ********
    [in]  HANDLE  ProcessHandle
        A handle to the process whose access token is opened. The process must have the PROCESS_QUERY_INFORMATION access permission.
    [in]  DWORD   DesiredAccess
        Specifies an access mask (32-bit value) that specifies the requested types of access to the access token.
        These requested access types are compared with the discretionary access control list (DACL) of the token to determine which accesses are granted or denied.
    [out] PHANDLE TokenHandle
        A pointer to a handle that identifies the newly opened access token when the function returns.
  */

  /*          ******* RETURN VALUE ********
  * If the function succeeds, the return value is nonzero.
      For example : When debogging the value of eax = 00000001
  * If the function fails, the return value is zero.
  */

  bVar6 = false;
  if (BVar3 != 0) {
    lpSystemName = (PLUID)&stack0xffffffe0;
    uVar7 = FUN_00401f9e(lpSystemName,in_stack_ffffffd8,in_stack_ffffffdc,(DWORD)in_stack_ffffffe0,
                         in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,
                         in_stack_fffffff4,in_stack_fffffff8);
    uVar5 = (undefined2)((uint6)uVar7 >> 0x20);
    BVar3 = (BOOL)uVar7;
    if (bVar6) {
      BVar3 = 0;
    }
    else {
      cVar4 = extraout_CH_00;
      if (!bVar6 && (undefined *)register0x00000010 != (undefined *)0x2f) goto code_r0x00401f99;
    }
    return BVar3;
  }
  lpSystemName = (PLUID)0x0;
  cVar4 = extraout_CH;
  uVar5 = extraout_DX;
code_r0x00401f99:
  uVar2 = in(uVar5);
  *unaff_EDI = uVar2;
  pcVar1 = (char *)segment(in_GS,(short)register0x00000010 + -4 + unaff_SI);
  *pcVar1 = *pcVar1 + cVar4;
  BVar3 = LookupPrivilegeValueA((LPCSTR)lpSystemName,in_stack_ffffffd8,in_stack_ffffffdc);
  if (BVar3 != 0) {
    BVar3 = AdjustTokenPrivileges
                      (in_stack_ffffffe0,0,(PTOKEN_PRIVILEGES)&stack0xfffffff4,0x10,
                       (PTOKEN_PRIVILEGES)&stack0xfffffff4,(PDWORD)&stack0xfffffff0);
  }
  return BVar3;
}
