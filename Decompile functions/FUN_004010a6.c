
void FUN_004010a6(LPVOID param_1)

{
  DWORD local_8;
  
  /* Creates a thread to execute within the virtual address space of the calling process.
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes : A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpThreadAttributes is NULL, the handle cannot be inherited.
    [in] SIZE_T dwStackSize : The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is zero, the new thread uses the default size for the executable. 
    [in] LPTHREAD_START_ROUTINE  lpStartAddress : A pointer to the application-defined function to be executed by the thread. This pointer represents the starting address of the thread. 
    [in, optional] __drv_aliasesMem LPVOID lpParameter : A pointer to a variable to be passed to the thread.
    [in] DWORD dwCreationFlags : The flags that control the creation of the thread. If 0, the thread runs immediately after creation.
    [out, optional] LPDWORD lpThreadId : A pointer to a variable that receives the thread identifier. 
      
    Return value : If the function succeeds, the return value is a handle to the new thread.
  */
  LPVOID hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_004016d5,param_1,0,&local_8);

  /* Sets the priority value for the specified thread. This value, together with the priority class of the thread's process, determines the thread's base priority level.
    [in] HANDLE hThread : A handle to the thread whose priority value is to be set.
    [in] int nPriority = 0xf = THREAD_PRIORITY_TIME_CRITICAL : The priority value for the thread.
             Time-Critical—The highest priority available for a LabVIEW VI. 
             Time-critical threads run above the priority of the scheduler itself. 
             Therefore, time-critical threads always run to completion or until blocked.
  */
  SetThreadPriority(hTread, 0xf);

  return;
}

