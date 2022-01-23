undefined8 __fastcall
//                 extraout_ECX,      extraout_EDX,  current_exec_path,(undefined *)local_74, 256 == 0x100
FUN_00401816(undefined4 param_1,undefined4 param_2,uint *param_3,undefined *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_EAX;
  uint uVar3;
  char *pcVar4;
  char s_004043f6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-Microsoft Enhanced Cryptographic Provider v1.0"
  
  if (param_5 != 0) {

    do {
      uVar1 = *param_3;
      uVar3 = uVar1;

      if ((param_5 < 3) && (uVar3 = uVar1 & 0xffff, param_5 < 2)) {
        uVar3 = uVar1 & 0xff;
      }

      uVar2 = (uVar3 & 0xff0000) >> 8;
      uVar1 = uVar2 | (uVar3 & 0xff00) << 8;
      *param_4 = s_004043f6[(uVar3 << 0x18) >> 0x1a];
      param_4[1] = s_004043f6[(uVar1 | uVar3 << 0x18) >> 0x14 & 0x3f];

      if (param_5 == 1) {
        param_4[2] = '=';

LAB_00401891:
        pcVar4 = param_4 + 3;
        param_4 += 4;
        *pcVar4 = '=';
        break;
      }
      pcVar4 = param_4 + 3;
      param_4[2] = s_004043f6[(uVar1 & 0xfc000) >> 0xe];

      if (param_5 == 2) goto LAB_00401891;

      param_4 += 4;
      *pcVar4 = s_004043f6[(uVar2 & 0x3f00) >> 8];
      param_3 = (uint *)((int)param_3 + 3);
      param_5 -= 3;
    } while (param_5 != 0);
    
  }

  *param_4 = '\0';

  return CONCAT44(param_2,in_EAX);
}