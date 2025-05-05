#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOBYTE(x) ((unsigned char)(x))
#define _DWORD unsigned int

int dword_3543D8[8] = {0x31323334, 0x35363738, 0x39414243, 0x44454647, 0x48494A4B, 0x4C4D4E4F, 0x50515253, 0x54555657};

int __cdecl sub_351190(int a1)
{
    unsigned int v1;  // ecx
    unsigned int v2;  // eax
    int result;       // eax
    int v4;           // [esp+0h] [ebp-7Ch]
    unsigned int v5;  // [esp+4h] [ebp-78h]
    unsigned int v6;  // [esp+14h] [ebp-68h]
    unsigned int v7;  // [esp+18h] [ebp-64h]
    unsigned int v8;  // [esp+1Ch] [ebp-60h]
    unsigned int v9;  // [esp+20h] [ebp-5Ch]
    unsigned int v10; // [esp+24h] [ebp-58h]
    unsigned int v11; // [esp+28h] [ebp-54h]
    unsigned int v12; // [esp+30h] [ebp-4Ch]
    unsigned int v13; // [esp+38h] [ebp-44h]
    unsigned int v14; // [esp+3Ch] [ebp-40h]
    unsigned int v15; // [esp+40h] [ebp-3Ch]
    unsigned int v16; // [esp+44h] [ebp-38h]
    unsigned int v17; // [esp+48h] [ebp-34h]
    int i;            // [esp+4Ch] [ebp-30h]
    int v19;          // [esp+50h] [ebp-2Ch]
    int v20;          // [esp+54h] [ebp-28h] BYREF
    int v21;          // [esp+58h] [ebp-24h]
    int v22;          // [esp+5Ch] [ebp-20h]
    int v23;          // [esp+60h] [ebp-1Ch]

    v20 = 0x423DF72D;
    v21 = 0x05F59A01;
    v22 = 0x633FCF1D;
    v23 = 0x77D19122;

    v19 = 4;
    do
    {
        printf("%d %x %x\n", v19, *(_DWORD *)(a1 + 8 * (4 - v19)), *(_DWORD *)(a1 + 8 * (4 - v19) + 4));
        v17 = *(_DWORD *)(a1 + 8 * (4 - v19) + 4);
        v16 = *(_DWORD *)(a1 + 8 * (4 - v19)) + ((v21 + (v17 >> 5)) ^ (v17 + 1579382783) ^ (v20 + 16 * v17));
        v15 = v17 + ((v23 + (v16 >> 5)) ^ (v16 + 1579382783) ^ (v22 + 16 * v16));
        v14 = v16 + ((v21 + (v15 >> 5)) ^ (v15 - 1136201730) ^ (v20 + 16 * v15));
        v13 = v15 + ((v23 + (v14 >> 5)) ^ (v14 - 1136201730) ^ (v22 + 16 * v14));
        v12 = v13 + ((v23 + ((v14 + ((v21 + (v13 >> 5)) ^ (v13 + 443181053) ^ (v20 + 16 * v13))) >> 5)) ^ (v14 + ((v21 + (v13 >> 5)) ^ (v13 + 443181053) ^ (v20 + 16 * v13)) + 443181053) ^ (v22 + 16 * (v14 + ((v21 + (v13 >> 5)) ^ (v13 + 443181053) ^ (v20 + 16 * v13)))));
        v1 = v14 + ((v21 + (v13 >> 5)) ^ (v13 + 443181053) ^ (v20 + 16 * v13)) + ((v21 + (v12 >> 5)) ^ (v12 + 2022563836) ^ (v20 + 16 * v12));
        v11 = v12 + ((v23 + (v1 >> 5)) ^ (v1 + 2022563836) ^ (v22 + 16 * v1));
        v10 = v1 + ((v21 + (v11 >> 5)) ^ (v11 - 693020677) ^ (v20 + 16 * v11));
        v9 = v11 + ((v23 + (v10 >> 5)) ^ (v10 - 693020677) ^ (v22 + 16 * v10));
        v8 = v10 + ((v21 + (v9 >> 5)) ^ (v9 + 886362106) ^ (v20 + 16 * v9));
        v7 = v9 + ((v23 + (v8 >> 5)) ^ (v8 + 886362106) ^ (v22 + 16 * v8));
        v6 = v8 + ((v21 + (v7 >> 5)) ^ (v7 - 1829222407) ^ (v20 + 16 * v7));
        v2 = v7 + ((v23 + (v6 >> 5)) ^ (v6 - 1829222407) ^ (v22 + 16 * v6));
        v5 = v2 + ((v23 + ((v6 + ((v21 + (v2 >> 5)) ^ (v2 - 249839624) ^ (v20 + 16 * v2))) >> 5)) ^ (v6 + ((v21 + (v2 >> 5)) ^ (v2 - 249839624) ^ (v20 + 16 * v2)) - 249839624) ^ (v22 + 16 * (v6 + ((v21 + (v2 >> 5)) ^ (v2 - 249839624) ^ (v20 + 16 * v2)))));
        // *(_DWORD *)(a1 + 8 * (4 - v19)) = (v6 + ((v21 + (v2 >> 5)) ^ (v2 - 249839624) ^ (v20 + 16 * v2))) ^ 0xF;
        // *(_DWORD *)(a1 + 8 * (4 - v19) + 4) = v5 ^ 0xF;
        printf("%d %x %x %x\n", v19, v17, v6, v5);
        v4 = v19;
        // printf("%s", a1);
        result = --v19;
    } while (v4 > 1);
    return result;
}

int __cdecl de(int a1)
{
    unsigned int v1;  // ecx
    unsigned int v2;  // eax
    int result;       // eax
    int v4;           // [esp+0h] [ebp-7Ch]
    unsigned int v5;  // [esp+4h] [ebp-78h]
    unsigned int v6;  // [esp+14h] [ebp-68h]
    unsigned int v7;  // [esp+18h] [ebp-64h]
    unsigned int v8;  // [esp+1Ch] [ebp-60h]
    unsigned int v9;  // [esp+20h] [ebp-5Ch]
    unsigned int v10; // [esp+24h] [ebp-58h]
    unsigned int v11; // [esp+28h] [ebp-54h]
    unsigned int v12; // [esp+30h] [ebp-4Ch]
    unsigned int v13; // [esp+38h] [ebp-44h]
    unsigned int v14; // [esp+3Ch] [ebp-40h]
    unsigned int v15; // [esp+40h] [ebp-3Ch]
    unsigned int v16; // [esp+44h] [ebp-38h]
    unsigned int v17; // [esp+48h] [ebp-34h]
    int i;            // [esp+4Ch] [ebp-30h]
    int v19;          // [esp+50h] [ebp-2Ch]
    int v20;          // [esp+54h] [ebp-28h] BYREF
    int v21;          // [esp+58h] [ebp-24h]
    int v22;          // [esp+5Ch] [ebp-20h]
    int v23;          // [esp+60h] [ebp-1Ch]
    unsigned int temp;

    v20 = 0x423DF72D;
    v21 = 0x05F59A01;
    v22 = 0x633FCF1D;
    v23 = 0x77D19122;

    v19 = 1;
    printf("%x %x\n", *(_DWORD *)(a1 + 8 * 0 + 4), *(_DWORD *)(a1 + 8 * 0));
    do
    {

        v5 = *(_DWORD *)(a1 + 8 * (4 - v19) + 4) ^ 0xF;
        temp = *(_DWORD *)(a1 + 8 * (4 - v19)) ^ 0xF;
        v2 = v5 - ((v23 + (temp >> 5)) ^ (temp - 249839624) ^ (v22 + 16 * temp));
        v6 = temp - ((v21 + (v2 >> 5)) ^ (v2 - 249839624) ^ (v20 + 16 * v2));
        v7 = v2 - ((v23 + (v6 >> 5)) ^ (v6 - 1829222407) ^ (v22 + 16 * v6));
        v8 = v6 - ((v21 + (v7 >> 5)) ^ (v7 - 1829222407) ^ (v20 + 16 * v7));
        v9 = v7 - ((v23 + (v8 >> 5)) ^ (v8 + 886362106) ^ (v22 + 16 * v8));
        v10 = v8 - ((v21 + (v9 >> 5)) ^ (v9 + 886362106) ^ (v20 + 16 * v9));
        v11 = v9 - ((v23 + (v10 >> 5)) ^ (v10 - 693020677) ^ (v22 + 16 * v10));
        v1 = v10 - ((v21 + (v11 >> 5)) ^ (v11 - 693020677) ^ (v20 + 16 * v11));
        v12 = v11 - ((v23 + (v1 >> 5)) ^ (v1 + 2022563836) ^ (v22 + 16 * v1));

        temp = v1 - ((v21 + (v12 >> 5)) ^ (v12 + 2022563836) ^ (v20 + 16 * v12));
        v13 = v12 - ((v23 + ((temp) >> 5)) ^ (temp + 443181053) ^ (v22 + 16 * temp));
        v14 = temp - ((v21 + (v13 >> 5)) ^ (v13 + 443181053) ^ (v20 + 16 * v13));

        v15 = v13 - ((v23 + (v14 >> 5)) ^ (v14 - 1136201730) ^ (v22 + 16 * v14));
        v16 = v14 - ((v21 + (v15 >> 5)) ^ (v15 - 1136201730) ^ (v20 + 16 * v15));
        v17 = v15 - ((v23 + (v16 >> 5)) ^ (v16 + 1579382783) ^ (v22 + 16 * v16));
        *(_DWORD *)(a1 + 8 * (4 - v19) + 4) = v17;
        *(_DWORD *)(a1 + 8 * (4 - v19)) = v16 - ((v21 + (v17 >> 5)) ^ (v17 + 1579382783) ^ (v20 + 16 * v17));

        // printf("%d %x %x %x\n", v19, v17, v6, v5);
        // printf("%d %x %x\n", v19, *(_DWORD *)(a1 + 8 * (4 - v19)), *(_DWORD *)(a1 + 8 * (4 - v19) + 4));
        v4 = v19;
        result = ++v19;
    } while (v4 < 4);
    return result;
}

int main()
{
    // 测试解密函数
    // unsigned char flag[] = "NSSCTF{111111111111111111111111";
    // flag[31] = '}';

    // for (int i = 0; i < 32; i++)
    // {
    //     printf("%x ", flag[i]);
    // }
    // printf("\n");
    // sub_351190(flag);
    // for (int i = 0; i < 32; i++)
    // {
    //     printf("%02x ", flag[i]);
    // }
    // printf("\n");
    // printf("%x\n", *(_DWORD *)(flag + 8 * 0 + 4)) ^ 0xF;
    // de(flag);
    // for (int i = 0; i < 32; i++)
    // {
    //     printf("%x ", flag[i]);
    // }
    // printf("\n");

    // DC 45 1E 03 89 E9 76 27  47 48 23 01 70 D2 CE 64
    // DA 7F 46 33 B1 03 49 A3  27 00 D1 2C 37 B3 BD 75
    unsigned char flag2[] = {
        0xdc, 0x45, 0x1e, 0x03, 0x89, 0xe9, 0x76, 0x27,
        0x47, 0x48, 0x23, 0x01, 0x70, 0xd2, 0xce, 0x64,
        0xda, 0x7f, 0x46, 0x33, 0xb1, 0x03, 0x49, 0xa3,
        0x27, 0x00, 0xd1, 0x2c, 0x37, 0xb3, 0xbd, 0x75};

    de(flag2);

    for (int i = 0; i < 32; i++)
    {
        printf("%x ", flag2[i]);
    }
    printf("\n");
    printf("%s\n", flag2);

    return 0;
}