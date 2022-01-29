undefined8 __fastcall
//           0x025e1da8,  0x025e21a8,  0x100 == 256
FUN_00401816(uint *source,undefined *dest, uint size)

{
  uint dword1;
  uint dword2;

  uint byte;
  undefined4 in_EAX;
  char alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-Microsoft Enhanced Cryptographic Provider v1.0"
  
  if (size != 0) {

    // Calcule 4 caractères à chaque passage
    do {
      dword1 = source[0-7]; // charge un dword depuis l'adresse source (0x025e1da8). Ex : dword1 = 1ab917d3
      dword2 = dword1;   // Ex : dword2 = 1ab917d3

      if ((size < 3) && (dword2 = dword1 & 0xffff, size < 2)) {
        dword2 = dword1 & 0xff;
      }

      byte = dword2[0-1];          // Ex : 1ab917d3 => 1a
      dword1 = byte | dword2[4-5]; // Ex : 1ab917d3 => 17 => 1a | 17 => dword1 = 1f
      dest[0] = alphabet[(dword2 << 24) >> 26];  // dest[0] = alphabet[6] = 'G'
      dest[1] = alphabet[(dword1 | dword2 << 24) >> 20 & 0x3f]; // dest[1] = alphabet[43] = 'r'

      if (size == 1) {
        dest[2] = '=';

LAB_00401891:
        dest[3] = '=';
        dest += 4;
        break;
      }

      dest[2] = alphabet[(dword1 & 0xfc000) >> 0xe];

      if (size == 2) goto LAB_00401891;

      dest[3] = alphabet[(byte & 0x3f00) >> 8]; //
      source = (uint *)((int)source + 3);
      dest += 4;
      size -= 3;
    } while (size != 0);
  }

  dest[0] = '\0';

  return CONCAT44(? + eax);
}