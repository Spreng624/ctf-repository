#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _BYTE unsigned char
#define _DWORD unsigned int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BYTE1(x) ((unsigned char)((x) >> 8))
#define BYTE2(x) ((unsigned char)((x) >> 16))
#define HIBYTE(x) ((unsigned char)((x) >> 24))

int __cdecl sub_402000(int v2)
{
    int i;           // [esp+4h] [ebp-18h]
    int v4;          // [esp+8h] [ebp-14h]
    int v5;          // [esp+Ch] [ebp-10h]
    int v6;          // [esp+10h] [ebp-Ch]
    int v7;          // [esp+10h] [ebp-Ch]
    unsigned int v8; // [esp+14h] [ebp-8h]
    int v9;          // [esp+18h] [ebp-4h]

    v6 = 0;
    v9 = v2;
    v8 = HIBYTE(v2);
    v5 = BYTE2(v2);
    v4 = BYTE1(v2);
    for (i = 0; i < 32; ++i)
    {
        v7 = v6 * (v8 + 1415881080) * (v9 - 1467486175) * ((v8 - v9) ^ (v8 >> 4));
        v5 = (v9 + v5) ^ (8 * v4);
        v4 = (v9 + v8) ^ (8 * v5);
        v8 = (v9 + v4) ^ (8 * v5);
        v9 -= v4 + v5 + v8;
        if (v9 == 1415881080)
        {
            printf("key: %x\n", v2);
            return 0;
        }
        v6 = v7 + (v8 + 1467486175) * (((v8 - v9) ^ (unsigned __int64)(v8 >> 4)) / (unsigned int)(v9 - 1415881080));
    }
    return v9 ^ v6;
}

unsigned __int8 __cdecl sub_401000(char *Str, unsigned int a2)
{
    unsigned __int8 result; // al
    size_t v3;              // [esp+Ch] [ebp-234h]
    char v4;                // [esp+10h] [ebp-230h]
    int v5;                 // [esp+14h] [ebp-22Ch]
    int ii;                 // [esp+18h] [ebp-228h]
    size_t n;               // [esp+1Ch] [ebp-224h]
    int k;                  // [esp+20h] [ebp-220h]
    int j;                  // [esp+24h] [ebp-21Ch]
    int m;                  // [esp+28h] [ebp-218h]
    int i;                  // [esp+2Ch] [ebp-214h]
    char v12;               // [esp+30h] [ebp-210h]
    char v13;               // [esp+31h] [ebp-20Fh]
    unsigned __int8 v14;    // [esp+32h] [ebp-20Eh]
    unsigned __int8 v15;    // [esp+33h] [ebp-20Dh]
    _BYTE v16[256];         // [esp+34h] [ebp-20Ch] BYREF
    _BYTE v17[256];         // [esp+134h] [ebp-10Ch] BYREF
    _DWORD v18[2];          // [esp+234h] [ebp-Ch]

    v18[0] = 0;
    v18[1] = 0;
    result = (unsigned __int8)memset(v17, 0, sizeof(v17));
    for (i = 0; i < 8; ++i)
    {
        if (i >= 4)
            v4 = 7 - i;
        else
            v4 = i;
        result = i;
        *((_BYTE *)v18 + i) = a2 >> (8 * v4);
    }
    for (j = 0; j < 256; ++j)
    {
        result = j;
        v17[j] = j;
    }
    if (j == 256)
    {
        memset(v16, 0, sizeof(v16));
        for (k = 0; k < 256; ++k)
            v16[k] = *((_BYTE *)v18 + k % 8);
        v5 = 0;
        for (m = 0; m < 256; ++m)
        {
            v5 = ((unsigned __int8)v16[m] + v5 + (unsigned __int8)v17[m]) % 256;
            v13 = v17[m];
            v17[m] = v17[v5];
            v17[v5] = v13;
        }
        v15 = 0;
        v14 = 0;
        v3 = 32;
        for (n = 0; n < v3; ++n)
        {
            v14 += v17[++v15];
            v12 = v17[v15];
            v17[v15] = v17[v14];
            v17[v14] = v12;
            Str[n] ^= *((_BYTE *)v18 + (v15 & 7)) ^ v17[((unsigned __int8)v17[v14] + (unsigned __int8)v17[v15]) % 256];
        }
    }

    printf("%s\n", Str);
    return result;
}

int main()
{
    char Str[32] = {
        0x22, 0xC4, 0xA0, 0x5A, 0xDE, 0xED, 0x62, 0x5E,
        0x25, 0xE2, 0x6D, 0xA6, 0x05, 0xA7, 0x20, 0x8D,
        0x7D, 0x99, 0x52, 0x3E, 0x8C, 0xA7, 0x7F, 0xFA,
        0x09, 0xD8, 0x62, 0xDB, 0x00, 0x80, 0xC2, 0xA9};

    int i, key;
    for (i = 0x755FF000; i <= 0x755FF0FF; i++)
    {
        sub_402000(i);
    }
    sub_401000(Str, 0xF86D35D4);
    return 0;
}