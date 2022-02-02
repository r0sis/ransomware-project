
/* WARNING: Instruction at (ram,0x00401f9e) overlaps instruction at (ram,0x00401f9a)
    */

// This function deals with the access tokens of a function

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
  /*          ******* PARAMETERS ********

    [in, optional] lpSystemName

        A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved. If a null string is specified, the function attempts to find the privilege name on the local system.

    [in] lpName

        A pointer to a null-terminated string that specifies the name of the privilege, as defined in the Winnt.h header file. For example, this parameter could specify the constant, SE_SECURITY_NAME, or its corresponding string, "SeSecurityPrivilege".

    [out] lpLuid

        A pointer to a variable that receives the LUID by which the privilege is known on the system specified by the lpSystemName parameter.
  */

  /*          ******* RETURN VALUE ********
  If the function succeeds, the function returns nonzero.

  If the function fails, it returns zero.
  */

  if (BVar3 != 0) {
    // The AdjustTokenPrivileges function enables or disables privileges in the specified access token. Enabling or disabling privileges in an access token requires TOKEN_ADJUST_PRIVILEGES access.
    BVar3 = AdjustTokenPrivileges
                      (in_stack_ffffffe0,0,(PTOKEN_PRIVILEGES)&stack0xfffffff4,0x10,
                       (PTOKEN_PRIVILEGES)&stack0xfffffff4,(PDWORD)&stack0xfffffff0);
     /*          ******* PARAMETERS ********
     [in] TokenHandle
          A handle to the access token that contains the privileges to be modified. The handle must have TOKEN_ADJUST_PRIVILEGES access to the token. If the PreviousState parameter is not NULL, the handle must also have TOKEN_QUERY access.

     [in] DisableAllPrivileges
          Specifies whether the function disables all of the token's privileges. If this value is TRUE, the function disables all privileges and ignores the NewState parameter. If it is FALSE, the function modifies privileges based on the information pointed to by the NewState parameter.
     [in, optional] NewState
          A pointer to a TOKEN_PRIVILEGES structure that specifies an array of privileges and their attributes. If the DisableAllPrivileges parameter is FALSE, the AdjustTokenPrivileges function enables, disables, or removes these privileges for the token. The following table describes the action taken by the AdjustTokenPrivileges function, based on the privilege attribute.
     */

    // The AdjustTokenPrivileges function cannot add new privileges to the access token. It can only enable or disable the token's existing privileges.

    /*          ******* RETURN VALUE ********
    If the function succeeds, the return value is nonzero.
    */
  }
  return BVar3;
}
