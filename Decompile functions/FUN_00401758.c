
void FUN_00401758(uint param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    *param_2 = '0';
  }
  else {
    pcVar2 = param_2;
    if ((int)param_1 < 0) {
      *param_2 = '-';
      param_1 = -param_1;
      param_2 = param_2 + 1;
      pcVar2 = param_2;
    }
    while (param_1 != 0) {
      *param_2 = (char)param_1 + (char)(param_1 / 10) * -10 + '0';
      param_2 = param_2 + 1;
      param_1 = param_1 / 10;
    }
    for (; pcVar2 < param_2; pcVar2 = pcVar2 + 1) {
      param_2 = param_2 + -1;
      cVar1 = *param_2;
      *param_2 = *pcVar2;
      *pcVar2 = cVar1;
    }
  }
  return;
}
