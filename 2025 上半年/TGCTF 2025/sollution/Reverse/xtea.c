#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define _BYTE unsigned char
#define _DWORD unsigned int

unsigned int *__fastcall xtea_decrypt(int a1, unsigned int *a2, unsigned int *a3, __int64 a4)
{
    unsigned int *result; // rax
    unsigned int v5;      // [rsp+24h] [rbp+4h]
    unsigned int v6;      // [rsp+44h] [rbp+24h]
    unsigned int v7;      // [rsp+64h] [rbp+44h]
    int i;                // [rsp+84h] [rbp+64h]

    v5 = *a2;
    v6 = *a3;
    v7 = -a1 * 32;
    for (i = 0; i < 32; ++i)
    {
        // printf("%d %d %d\n", v5, v6, v7);
        v6 -= (*(_DWORD *)(a4 + 4LL * ((v7 >> 11) & 3)) + v7) ^ (v5 + ((v5 >> 5) ^ (16 * v5)));
        v7 += a1;
        v5 -= (*(_DWORD *)(a4 + 4LL * (v7 & 3)) + v7) ^ (v6 + ((v6 >> 5) ^ (16 * v6)));
    }

    *a2 = v5;
    result = a3;
    *a3 = v6;
    return result;
}

int main()
{
    int i;
    _DWORD key[4];
    unsigned int delta;
    _BYTE enc_flag[] = {
        0x24, 0x23, 0xCB, 0x8C, 0x1A, 0x74, 0xA7, 0x09,
        0x8D, 0x67, 0x3C, 0xFB, 0x79, 0x3A, 0x08, 0xF6,
        0x1B, 0x24, 0xCC, 0xF1, 0xF2, 0x59, 0xFA, 0x39,
        0xCC, 0xE1, 0xAB, 0xF2, 0x72, 0x9F, 0x18, 0x17};
    _BYTE flag[33];
    _DWORD v10[15];
    srand(0x7E8u);
    for (i = 0; i < 4; ++i)
        key[i] = rand();

    // test();

    for (delta = 0x9e3779b9; delta < 0xFFFFFFFF; delta++)
    {

        strcpy(flag, enc_flag);
        flag[32] = 0;

        for (i = 6; i >= 0; --i)
        {
            xtea_decrypt(delta, &flag[4 * i], &flag[4 * i + 4], key);
            if (i == 6 && flag[28] != '}')
                break;
        }

        if (!strncmp(flag, "UNZH", 3))
        {
            printf("%s %x\n", flag, delta);
            break;
        }

        if (delta % 0x1000000 == 0)
            printf("%x\n", delta);
    }

    // UNZH{FTC-6ea75f97b4-4b-49-32}be8

    for (int j = 0; j < 32; j += 4)
    {

        v10[j / 4] = *((char *)flag + j + 3) | (*((char *)flag + j + 2) << 8) | (*((char *)flag + j + 1) << 16) | (*((char *)flag + j) << 24);
    }
    for (i = 0; i < 7; ++i)
    {
        *(_DWORD *)(flag + 4 * i) = v10[i];
    }
    *(_DWORD *)(flag + 28) = v10[7];

    printf("%s\n", flag);
    // HZNUCTF{ae6-9f57-4b74-b423-98eb}

    return 0;
}