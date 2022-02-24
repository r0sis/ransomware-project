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

/*
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __stdcall FUN_00401676(void)
             undefined         AL:1           <RETURN>
             undefined1        Stack[-0x8]:1  local_8                                 XREF[2]:     00401693(*), 
                                                                                                   004016b5(*)  
                             FUN_00401676                                    XREF[2]:     00401d19(c), 00401e15(c)  
        00401676 55              PUSH       EBP
        00401677 8b ec           MOV        EBP,ESP
        00401679 83 c4 fc        ADD        ESP,-0x4
        0040167c e8 3d 0a        CALL       FUN_004020be                                     undefined FUN_004020be(void)     // GetLogicalDrives()
                 00 00
        00401681 b9 19 00        MOV        ECX,0x19
                 00 00
                             LAB_00401686                                    XREF[1]:     004016b3(j)  
        00401686 bb 01 00        MOV        EBX,0x1
                 00 00
        0040168b d3 e3           SHL        EBX,CL
        0040168d 23 d8           AND        EBX,EAX
        0040168f 74 21           JZ         LAB_004016b2
        00401691 50              PUSH       EAX
        00401692 51              PUSH       ECX
        00401693 8d 45 fc        LEA        EAX=>local_8,[EBP + -0x4]
        00401696 50              PUSH       EAX
        00401697 6a 00           PUSH       0x0
        00401699 51              PUSH       ECX
        0040169a 68 d5 16        PUSH       FUN_004016d5
                 40 00
        0040169f 6a 00           PUSH       0x0
        004016a1 6a 00           PUSH       0x0
        004016a3 e8 da 09        CALL       KERNEL32.DLL::CreateThread                       HANDLE CreateThread(LPSECURITY_A
                 00 00
        004016a8 6a 0f           PUSH       0xf
        004016aa 50              PUSH       EAX
        004016ab e8 74 0a        CALL       FUN_00402124                                     undefined FUN_00402124(void)
                 00 00
        004016b0 59              POP        ECX
        004016b1 58              POP        EAX
                             LAB_004016b2                                    XREF[1]:     0040168f(j)  
        004016b2 49              DEC        ECX
        004016b3 7d d1           JGE        LAB_00401686
        004016b5 8d 45 fc        LEA        EAX=>local_8,[EBP + -0x4]
        004016b8 50              PUSH       EAX
        004016b9 6a 00           PUSH       0x0
        004016bb 6a 00           PUSH       0x0
        004016bd 68 cf 10        PUSH       LAB_004010cf
                 40 00
        004016c2 6a 00           PUSH       0x0
        004016c4 6a 00           PUSH       0x0
        004016c6 e8 b7 09        CALL       KERNEL32.DLL::CreateThread                       HANDLE CreateThread(LPSECURITY_A
                 00 00
        004016cb 6a 0f           PUSH       0xf
        004016cd 50              PUSH       EAX
        004016ce e8 51 0a        CALL       FUN_00402124                                     undefined FUN_00402124(void)
                 00 00
        004016d3 c9              LEAVE
        004016d4 c3              RET

*/