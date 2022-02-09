// Creates 25 threads with parameter 25 to 0 that will execute FUN_004016d5 
// and creates 1 thread withut any arg that will execute LAB_004010cf
void FUN_00401676(void) {
  LPVOID lpParameter;
  DWORD lpThreadId;
  
  /* Retrieves a bitmask representing the currently available disk drives.

  Return value : If the function succeeds, the return value is a bitmask representing the currently available disk drives. 
  Bit position 0 (the least-significant bit) is drive A, bit position 1 is drive B, bit position 2 is drive C, and so on.
  */
  uint drives = GetLogicalDrives();

  lpParameter = (LPVOID)0x19; // 25

  do { // Loop 25 times
    LPVOID hThread = lpParameter;
    if ((1 << ((byte)lpParameter & 0x1f) & drives) != 0) {

      /* Creates a thread to execute within the virtual address space of the calling process.
         [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes : A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpThreadAttributes is NULL, the handle cannot be inherited.
         [in] SIZE_T dwStackSize : The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is zero, the new thread uses the default size for the executable. 
         [in] LPTHREAD_START_ROUTINE  lpStartAddress : A pointer to the application-defined function to be executed by the thread. This pointer represents the starting address of the thread. 
         [in, optional] __drv_aliasesMem LPVOID lpParameter : A pointer to a variable to be passed to the thread.
         [in] DWORD dwCreationFlags : The flags that control the creation of the thread. If 0, the thread runs immediately after creation.
         [out, optional] LPDWORD lpThreadId : A pointer to a variable that receives the thread identifier. 
      
        Return value : If the function succeeds, the return value is a handle to the new thread.
      */
      hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_004016d5,lpParameter,0,&lpThreadId);

      /* Sets the priority value for the specified thread. This value, together with the priority class of the thread's process, determines the thread's base priority level.
        [in] HANDLE hThread : A handle to the thread whose priority value is to be set.
        [in] int nPriority = 0xf = THREAD_PRIORITY_TIME_CRITICAL : The priority value for the thread.
                  Time-Critical—The highest priority available for a LabVIEW VI. 
                  Time-critical threads run above the priority of the scheduler itself. 
                  Therefore, time-critical threads always run to completion or until blocked.
      */
      SetThreadPriority(hTread, 0xf);
    }
    lpParameter = (LPVOID)((int)hThread - 1);
  } while (0 < (int)hThread);

  // Creates a thread that execute LAB_004010cf without any parameter
  hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004010cf,(LPVOID)0x0,0,&lpThreadId);

  // Set the priority of the thread to THREAD_PRIORITY_TIME_CRITICAL
  SetThreadPriority(hTread, 0xf);
  
  return;
}