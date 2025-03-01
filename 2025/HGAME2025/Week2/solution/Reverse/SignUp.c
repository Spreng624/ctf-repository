#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define _BYTE unsigned char
#define _DWORD unsigned int

void encrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 11; v8 > 0; v8--)
    {
        v6 += *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 0; i < 9; ++i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] += ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}

void decrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 1; v8 < 12; v8++)
    {
        v6 -= *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 8; i >= 0; --i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] -= ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}


int main()
{
    char s[] = {
        0x23, 0xEA, 0x50, 0x30, 0x00, 0x4C, 0x51, 0x47,
        0xEE, 0x9C, 0x76, 0x2B, 0xD5, 0xE6, 0x94, 0x17,
        0xED, 0x2B, 0xE4, 0xB3, 0xCB, 0x36, 0xD5, 0x61,
        0xC0, 0xC2, 0xA0, 0x7C, 0xFE, 0x67, 0xD7, 0x5E,
        0xAF, 0xE0, 0x79, 0xC5};

    _DWORD a2[4] = {2544000949, 3782569402, 2705540682, 1519331407};
    _DWORD a3[4] = {0, 0, 0, 0};

    decrypt((_DWORD *)s, a2, a3);
    // 3fe4722c-1dbf-43b7-8659-c1c4a0e42e4d
    // hgame{3fe4722c-1dbf-43b7-8659-c1c4a0e42e4d}
    for (int i = 0; i < 36; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
