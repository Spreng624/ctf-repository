#include <stdio.h>
#define __int64 long long
#define _BYTE unsigned char

unsigned __int64 __fastcall set_v1(__int64 a1, int a2, __int64 a3)
{
    unsigned __int64 result; // rax
    unsigned __int8 v4;      // [rsp+7h] [rbp-9h]
    int v5;                  // [rsp+8h] [rbp-8h]
    int i;                   // [rsp+Ch] [rbp-4h]
    int j;                   // [rsp+Ch] [rbp-4h]

    v5 = 0;
    for (i = 0; i <= 255; ++i)
    {
        result = a3 + i;
        *(_BYTE *)result = i;
    }
    for (j = 0; j <= 255; ++j)
    {
        v5 = (*(unsigned __int8 *)(a3 + j) + v5 + *(unsigned __int8 *)(a1 + j % a2)) % 256;
        v4 = *(_BYTE *)(a3 + j);
        *(_BYTE *)(a3 + j) = *(_BYTE *)(a3 + v5);
        result = v4;
        *(_BYTE *)(v5 + a3) = v4;
    }
    return result;
}

__int64 __fastcall decrypt1(__int64 a1, int a2, __int64 a3)
{
    __int64 result; // rax
    char v4;        // [rsp+3h] [rbp-Dh]
    unsigned int i; // [rsp+4h] [rbp-Ch]
    int v6;         // [rsp+8h] [rbp-8h]
    int v7;         // [rsp+Ch] [rbp-4h]

    v7 = 0;
    v6 = 0;
    for (i = 0;; ++i)
    {
        result = i;
        if ((int)i >= a2)
            break;
        v7 = (v7 + 1) % 256;
        v6 = (*(unsigned __int8 *)(a3 + v7) + v6) % 256;
        v4 = *(_BYTE *)(a3 + v7);
        *(_BYTE *)(a3 + v7) = *(_BYTE *)(a3 + v6);
        *(_BYTE *)(v6 + a3) = v4;
        *(_BYTE *)(a1 + (int)i) ^= *(_BYTE *)(a3 + (unsigned __int8)(*(_BYTE *)(a3 + v7) + *(_BYTE *)(a3 + v6)));
    }
    return result;
}

__int64 __fastcall decrypt2(__int64 a1, int a2, __int64 a3)
{
    __int64 result; // rax
    char v4;        // [rsp+3h] [rbp-Dh]
    unsigned int i; // [rsp+4h] [rbp-Ch]
    int v6;         // [rsp+8h] [rbp-8h]
    int v7;         // [rsp+Ch] [rbp-4h]

    v7 = 0;
    v6 = 0;
    for (i = 0;; ++i)
    {
        result = i;
        if ((int)i >= a2)
            break;
        v7 = (v7 + 1) % 256;
        v6 = (*(unsigned __int8 *)(a3 + v7) + v6) % 256;
        v4 = *(_BYTE *)(a3 + v7);
        *(_BYTE *)(a3 + v7) = *(_BYTE *)(a3 + v6);
        *(_BYTE *)(v6 + a3) = v4;
        *(_BYTE *)(a1 + (int)i) += *(_BYTE *)(a3 + (unsigned __int8)(*(_BYTE *)(a3 + v7) + *(_BYTE *)(a3 + v6)));
    }
    return result;
}

int main()
{
    _BYTE v1[256];
    char key[7] = {-51, -113, 37, 61, -31, 'Q', 'J'};
    char v8[7] = "yekyek";
    char v2[40] = {-8, -43, 98, -49, 67, -70, -62, 35, 21, 74, 81, 16, 39, 16, -79, -49, -60, 9, -2, -29, -97, 73, -121, -22, 89, -62, 7, 59, -87, 17, -63, -68, -3, 75, 87, -60, 126, -48, -86, 10};

    set_v1(v8, 6, v1);
    decrypt1(key, 7, v1);
    fwrite(key, sizeof(char), 7, stdout);
    putchar('\n');

    set_v1(key, 7, v1);
    decrypt2(v2, 40, v1);
    fwrite(v2, sizeof(char), 40, stdout);
    return 0;
}
