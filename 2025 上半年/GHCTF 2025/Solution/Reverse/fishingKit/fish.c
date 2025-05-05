#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _BYTE unsigned char

unsigned __int8 byte_1400060C0[256];

__int64 __fastcall init(const char *a1)
{
    __int64 result;          // rax
    int k;                   // [rsp+20h] [rbp-138h]
    unsigned int i;          // [rsp+24h] [rbp-134h]
    int j;                   // [rsp+28h] [rbp-130h]
    int v5;                  // [rsp+2Ch] [rbp-12Ch]
    unsigned int v6;         // [rsp+30h] [rbp-128h]
    unsigned __int8 v7[256]; // [rsp+40h] [rbp-118h] BYREF

    for (i = 0; i < 0x100; ++i)
        byte_1400060C0[i] = i;
    v6 = strlen(a1);
    result = 0LL;
    memset(v7, 0, sizeof(v7));
    for (j = 0; j < 256; ++j)
    {
        v7[j] = a1[j % v6];
        result = (unsigned int)(j + 1);
    }
    v5 = 0;
    for (k = 0; k < 256; ++k)
    {
        v5 = ((unsigned __int8)v7[k] + (unsigned __int8)byte_1400060C0[k] + v5) % 256;
        _BYTE temp = byte_1400060C0[k];
        byte_1400060C0[k] = byte_1400060C0[v5];
        byte_1400060C0[v5] = temp;
        result = (unsigned int)(k + 1);
    }
    return result;
}

__int64 __fastcall de(char *a1, __int64 a2)
{
    __int64 result;     // rax
    unsigned __int8 v4; // [rsp+20h] [rbp-18h]
    unsigned __int8 v5; // [rsp+21h] [rbp-17h]
    unsigned int i;     // [rsp+24h] [rbp-14h]
    unsigned int v7;    // [rsp+28h] [rbp-10h]

    v4 = 23;
    v5 = 32;
    v7 = strlen(a1);
    for (i = 22; (int)i >= 0; --i)
    {
        a1[i] = 0x14u ^ *(_BYTE *)(a2 + i) ^ byte_1400060C0[(unsigned __int8)(byte_1400060C0[v5] + byte_1400060C0[v4])];

        _BYTE temp = byte_1400060C0[v4];
        byte_1400060C0[v4] = byte_1400060C0[v5];
        byte_1400060C0[v5] = temp;
        v5 -= byte_1400060C0[v4--];
    }
    result = v7;
    *(_BYTE *)(a2 + v7) = 0;
    return result;
}

void tea(unsigned int *a1, unsigned int *a2, unsigned int *key)
{
    unsigned int v6 = *a1, v9 = *a2;

    unsigned int v3 = 0;

    for (int k = 0; k < 24; ++k)
    {
        v6 += (key[v3 & 3] + v3) ^ (v9 + ((v9 >> 5) ^ (16 * v9)));
        v3 += 1719109785;
        v9 += (key[(v3 >> 11) & 3] + v3) ^ (v6 + ((v6 >> 5) ^ (16 * v6)));
        printf("%x %x %x %x %x\n", v6, v9, v3, key[v3 & 3], key[(v3 >> 11) & 3]);
    }
    *a1 = v6;
    *a2 = v9;
}

void de_tea(unsigned int *a1, unsigned int *a2, unsigned int *key)
{
    unsigned int v6 = *a1, v9 = *a2;

    unsigned int v3 = 2603929176;

    for (int k = 0; k < 24; ++k)
    {
        v9 -= (key[(v3 >> 11) & 3] + v3) ^ (v6 + ((v6 >> 5) ^ (16 * v6)));
        v3 -= 1719109785;
        v6 -= (key[v3 & 3] + v3) ^ (v9 + ((v9 >> 5) ^ (16 * v9)));
    }
    *a1 = v6;
    *a2 = v9;
}

int main()
{
    unsigned char bait[] = {68, 101, 108, 117, 120, 101, 66, 97, 105, 116, 0, 0, 0, 0, 0, 0};
    unsigned int *key = (unsigned int *)bait;
    unsigned char test_flag[] = "NSSCTF{}";
    printf("%s\n", bait);

    unsigned char fake_flag[] = {
        0xE9, 0x37, 0xF8, 0xE2, 0x0C, 0x0F, 0x3D, 0xB9,
        0x5C, 0xA3, 0xDE, 0x2D, 0x55, 0x96, 0xDF, 0xA2,
        0x35, 0xFE, 0xB3, 0xDD, 0x7F, 0x91, 0x3C, 0x00};

    unsigned char enc[] = {
        0x21, 0x56, 0x97, 0xA6, 0x1A, 0xD5, 0xC4, 0xDE,
        0xA4, 0x9C, 0x82, 0x4D, 0xD1, 0x45, 0xC8, 0x56,
        0xA7, 0xB4, 0x96, 0x5C, 0x4D, 0x49, 0x87, 0x20};

    unsigned char ture_flag[] = {
        0x21, 0x56, 0x97, 0xA6, 0x1A, 0xD5, 0xC4, 0xDE,
        0xA4, 0x9C, 0x82, 0x4D, 0xD1, 0x45, 0xC8, 0x56,
        0xA7, 0xB4, 0x96, 0x5C, 0x4D, 0x49, 0x87, 0x20};

    // unsigned __int8 v4 = 0;
    // unsigned __int8 v5 = 0;
    // init(bait);

    // for (int i = 0; i < 23; ++i)
    // {
    //     v5 += byte_1400060C0[++v4];
    //     _BYTE temp = byte_1400060C0[v4];
    //     byte_1400060C0[v4] = byte_1400060C0[v5];
    //     byte_1400060C0[v5] = temp;
    // }

    // de(fake_flag, (__int64)&fake_flag);
    // printf("Fake flag: %s\n", fake_flag);

    for (int i = 0; i < 24; i++)
    {
        ture_flag[i] = enc[i];
    }
    key = (unsigned int *)bait;
    for (int i = 0; i < 3; ++i)
    {
        de_tea((unsigned int *)(ture_flag + 8 * i), (unsigned int *)(ture_flag + 8 * i + 4), key);
    }
    printf("Ture flag: %s\n", ture_flag);

    return 0;
}