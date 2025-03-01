#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>
#include <wincrypt.h>
#include <time.h>
#include <stdarg.h>

#define BYTE unsigned char
#define DWORD unsigned long

__int64 __stdcall sub_3D18D0(BYTE *pbData, int a2, DWORD dwDataLen)
{
    int v3;               // edx
    __int64 v5;           // [esp-8h] [ebp-150h]
    DWORD i;              // [esp+D0h] [ebp-78h]
    BYTE v7[72];          // [esp+DCh] [ebp-6Ch] BYREF
    DWORD pdwDataLen[3];  // [esp+124h] [ebp-24h] BYREF
    HCRYPTPROV phProv[3]; // [esp+130h] [ebp-18h] BYREF
    HCRYPTHASH phHash[2]; // [esp+13Ch] [ebp-Ch] BYREF
    int savedregs;        // [esp+148h] [ebp+0h] BYREF

    phProv[0] = 0;
    pdwDataLen[0] = 4;
    CryptAcquireContextW(phProv, 0, 0, 1u, 0);
    CryptCreateHash(phProv[0], 0x8004u, 0, 0, phHash);
    CryptHashData(phHash[0], pbData, dwDataLen, 0);
    CryptGetHashParam(phHash[0], 2u, 0, pdwDataLen, 0);
    CryptGetHashParam(phHash[0], 2u, v7, pdwDataLen, 0);
    for (i = 0; i < pdwDataLen[0]; ++i)
        snprintf((char *)(a2 + 2 * i), 2, "%02x", v7[i]);
    CryptDestroyHash(phHash[0]);
    CryptReleaseContext(phProv[0], 0);
    return v5;
}

int main()
{
    char Buf2[68];
    char Str[10] = "0xGameUser";
    time_t v9 = time(0);
    int v3 = 28;
    char v8 = v9 >> v3;
    printf("v8: %d\n", v8);
    for (int i = 0; i < 10; ++i)
    {
        Str[i] ^= v8;
    }

    sub_3D18D0((BYTE *)Str, (int)Buf2, 0xAu);
    printf("0xGame{%s}\n", Buf2);
    // 0xGame{1b4e549d12ccb4bb4936f95fedecebf55494dec8}
    return 0;
}