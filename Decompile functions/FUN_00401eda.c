void FUN_00401eda(void)

{
  undefined4 *puVar1;
  DWORD process_id;
  HANDLE hProcess;
  undefined4 extraout_ECX;
  undefined4 uVar3;
  undefined4 extraout_ECX_00;
  undefined *unaff_ESI;
  undefined *puVar4;
  undefined *unaff_EDI;
  undefined8 process;
  undefined4 auStack556 [138];
  
  FUN_00401f6f();

  puVar1 = (undefined4 *)&stack0xfffffffc;
  
  do {
    
    puVar4 = unaff_ESI;
    unaff_ESI = (undefined *)puVar1;

    /* Takes a snapshot of the specified processes, as well as the heaps, modules, and threads used by these processes.
      [in] DWORD dwFlags = 2 = TH32CS_SNAPPROCESS (Includes all processes in the system in the snapshot) : The portions of the system to be included in the snapshot
      [in] DWORD th32ProcessID = 0 (current process) : The process identifier of the process to be included in the snapshot.
    
      Return value : If the function succeeds, it returns an open handle to the specified snapshot.
    */
    HANDLE handle_snapshot = CreateToolhelp32Snapshot(2,0,unaff_EDI);

    ADD_04D7FD54 = 0x22c; // Size of the PROCESSENTRY32W structure (0x22c = 556)

    /* Retrieves information about the first process encountered in a system snapshot.
        [in] HANDLE hSnapshot : A handle to the snapshot returned from a previous call to the CreateToolhelp32Snapshot function.
        [in, out] LPPROCESSENTRY32W lppe : A pointer to a PROCESSENTRY32W structure. It contains process information such as the name of the executable file, the process identifier, and the process identifier of the parent process.

        Return value : Returns TRUE if the first entry of the process list has been copied to the buffer or FALSE otherwise.
    */
    process = Process32FirstW(handle_snapshot, ADD_04D7FD54);

    uVar3 = extraout_ECX;

    while (process != 0) {
      
      longlong ret_val = FUN_00401fe8(uVar3,(uint)((ulonglong)process >> 0x20),ADD_04D7FD78);
      
      if (ret_val != 0) {
        /* Retrieves the process identifier of the calling process.
        Return value : The return value is the process identifier of the calling process.
        */
        process_id = GetCurrentProcessId();

        if (process_id != *(DWORD *)ADD_04D6FD5C) {

          /* Opens an existing local process object.
            [in] DWORD dwDesiredAccess : The access to the process object.
            [in] BOOL  bInheritHandle : If this value is TRUE, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.
            [in] DWORD dwProcessId : The identifier of the local process to be opened.

            Return value : If the function succeeds, the return value is an open handle to the specified process.
          */
          hProcess = OpenProcess(1,0,*(DWORD *)ADD_04D6FD5C);
          

          if (hProcess != (HANDLE)0x0) {
            /* Terminates the specified process and all of its threads.
              [in] HANDLE hProcess : A handle to the process to be terminated.
              [in] UINT   uExitCode : The exit code to be used by the process and threads terminated as a result of this call.
            */
            TerminateProcess(hProcess,0);
          }
        }
      }

      /* Retrieves information about the next process recorded in a system snapshot.
        [in]  HANDLE hSnapshot : A handle to the snapshot returned from a previous call to the CreateToolhelp32Snapshot function.
        [out] LPPROCESSENTRY32W lppe : A pointer to a PROCESSENTRY32W structure. It contains process information such as the name of the executable file, the process identifier, and the process identifier of the parent process.

        Return value : Returns TRUE if the next entry of the process list has been copied to the buffer or FALSE otherwise.
      */
      process = Process32NextW(handle_snapshot,ADD_04D7FD54);
      uVar3 = extraout_ECX_00;
    }

    /* Closes an open object handle.
      [in] HANDLE hObject : A valid handle to an open object.
    */
    CloseHandle(handle_snapshot);

    auStack556[0] = 1000;
    
    Sleep();
    
    puVar1 = auStack556;
    unaff_EDI = puVar4;

  } while( true );
}