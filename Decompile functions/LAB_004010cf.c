
void UndefinedFunction_004010cf(void)

{
  char *data = "            files\r\n          files/s\r\n               s\r\n        ftreads\r\nnetwork   ";

  data[81] = 'y';
  FUN_004010e7((LPNETRESOURCEA)0x0,1);
  data[81] = 'n';
  return;
}