void entry(void)

{
  /* Retrieves a module handle for the specified module. The module must have been loaded by the calling process. 
      [in, optional] LPCSTR lpModuleName : The name of the loaded module (either a .dll or .exe file).
                                           If this parameter is NULL, GetModuleHandle returns a handle to the file used to create the calling process (.exe file).
      Return value : If the function succeeds, the return value is a handle to the specified module.
  */
  DAT_00404b2c = GetModuleHandleA((LPCSTR)0x0); // Handle to the ransomware program

  FUN_004018a0();
  
  ExitProcess(0);
}
