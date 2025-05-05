#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _DWORD unsigned int
#define _BYTE unsigned char
#define _QWORD unsigned __int64
#define BYTE4(x) ((unsigned char)((x) >> 24))

char Str[] = "stuvwxyz0123456789+/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqr";
_BYTE *__fastcall b64encode(__int64 a1, signed int a2)
{
    size_t v2;    // rax
    int v4;       // [rsp+20h] [rbp-28h]
    int v5;       // [rsp+24h] [rbp-24h]
    signed int i; // [rsp+28h] [rbp-20h]
    int v7;       // [rsp+2Ch] [rbp-1Ch]
    _BYTE *v8;    // [rsp+30h] [rbp-18h]

    v2 = 2 * a2;
    v8 = malloc(v2);
    v7 = 0;
    v5 = -6;
    v4 = 0;
    for (i = 0; i < a2; ++i)
    {
        v7 = *(_DWORD *)(a1 + 4LL * i) + (v7 << 8);
        for (v5 += 8; v5 >= 0; v5 -= 6)
        {
            v8[v4++] = Str[(v7 >> v5) & 0x3F];
        }
    }
    if (v5 > -6)
        v8[v4++] = Str[(v7 << 8 >> (v5 + 8)) & 0x3F];
    while (v4 % 4)
        v8[v4++] = 61;
    v8[v4] = 0;
    return v8;
}

_BYTE *__fastcall b64decode(unsigned char *a1, signed int *a2)
{
    int v4, v5, v7, i;
    _BYTE *v8 = malloc(*a2);

    // 计算解码后数据的长度

    v4 = 0;  // 用于索引解码后的数据
    v5 = -8; // 用于控制位操作
    v7 = 0;  // 用于累积位数据

    for (i = 0; i < *a2; ++i)
    {
        if (a1[i] == '=') // 处理填充字符
            v7 = (v7 << 6);
        else
        {
            // 查找当前字符在Base64编码表中的位置
            int val = 0;
            while (val < 64 && Str[val] != a1[i])
                ++val;
            // printf("%c %d\n", a1[i], val);

            // 如果字符不在编码表中，忽略
            if (val == 64)
                continue;

            // 将当前字符的6位累积到 v7 中
            v7 = (v7 << 6) | val;
        }

        // 每累积16位（4个字符），解码为2个字节
        if ((i + 1) % 4 == 0)
        {
            v8[v4++] = (v7 >> 16) & 0xFF;
            v8[v4++] = (v7 >> 8) & 0xFF;
            v8[v4++] = v7 & 0xFF;
            v7 = 0; // 重置 v7
        }
    }

    v8[v4] = 0; // 添加字符串终止符
    *a2 = v4;
    return v8;
}
__int64 __fastcall RC4(__int64 a1, const char *a2, __int64 a3)
{
    __int64 v3;      // kr00_8
    __int64 result;  // rax
    int i;           // [rsp+20h] [rbp-438h]
    int j;           // [rsp+20h] [rbp-438h]
    int v7;          // [rsp+20h] [rbp-438h]
    int v8;          // [rsp+24h] [rbp-434h]
    int v9;          // [rsp+24h] [rbp-434h]
    int k;           // [rsp+28h] [rbp-430h]
    int v11;         // [rsp+30h] [rbp-428h]
    int v12;         // [rsp+34h] [rbp-424h]
    _DWORD v13[258]; // [rsp+50h] [rbp-408h]

    v8 = 0;
    for (i = 0; i < 256; ++i)
        v13[i] = i;
    for (j = 0; j < 256; ++j)
    {
        v3 = a2[j % strlen(a2)] + v13[j] + v8;
        v8 = (unsigned __int8)(BYTE4(v3) + v3) - BYTE4(v3);
        v11 = v13[j];
        v13[j] = v13[v8];
        v13[v8] = v11;
    }

    v9 = 0;
    v7 = 0;
    for (k = 0;; ++k)
    {
        result = (unsigned int)*(char *)(a1 + k);
        if (!*(_BYTE *)(a1 + k))
            break;
        v7 = (v7 + 1) % 256;
        v9 = (v13[v7] + v9) % 256;
        v12 = v13[v7];
        v13[v7] = v13[v9];
        v13[v9] = v12;
        *(_DWORD *)(a3 + 4LL * k) = ((v13[(v13[v9] + v13[v7]) % 256] ^ *(char *)(a1 + k)) + 57) % 256;
    }
    return result;
}
__int64 __fastcall de_RC4(__int64 a1, const char *a2, __int64 a3)
{
    __int64 v3;      // kr00_8
    __int64 result;  // rax
    int i;           // [rsp+20h] [rbp-438h]
    int j;           // [rsp+20h] [rbp-438h]
    int v7;          // [rsp+20h] [rbp-438h]
    int v8;          // [rsp+24h] [rbp-434h]
    int v9;          // [rsp+24h] [rbp-434h]
    int k;           // [rsp+28h] [rbp-430h]
    int v11;         // [rsp+30h] [rbp-428h]
    int v12;         // [rsp+34h] [rbp-424h]
    _DWORD v13[258]; // [rsp+50h] [rbp-408h]

    v8 = 0;
    for (i = 0; i < 256; ++i)
        v13[i] = i;
    for (j = 0; j < 256; ++j)
    {
        v3 = a2[j % strlen(a2)] + v13[j] + v8;
        v8 = (unsigned __int8)(BYTE4(v3) + v3) - BYTE4(v3);
        v11 = v13[j];
        v13[j] = v13[v8];
        v13[v8] = v11;
    }

    v9 = 0;
    v7 = 0;
    for (k = 0;; ++k)
    {
        result = (unsigned int)*(char *)(a3 + k);
        if (!*(_BYTE *)(a3 + k))
            break;
        v7 = (v7 + 1) % 256;
        v9 = (v13[v7] + v9) % 256;
        v12 = v13[v7];
        v13[v7] = v13[v9];
        v13[v9] = v12;
    }

    for (k = strlen(a3) - 1; k >= 0; --k)
    {
        *(char *)(a1 + k) = v13[(v13[v9] + v13[v7]) % 256] ^ ((*(unsigned char *)(a3 + k) - 57 + 256) % 256);

        v12 = v13[v7];
        v13[v7] = v13[v9];
        v13[v9] = v12;

        v9 = (v9 - v13[v7]) % 256;
        v7 = (v7 - 1) % 256;
    }
    *(char *)(a1 + strlen(a3)) = 0;
    return result;
}
void __fastcall en(char *a1, const char *a2, int a3)
{
    size_t v3;       // rax
    unsigned int v4; // eax
    size_t v5;       // rax
    unsigned int v6; // eax
    int i;           // [rsp+20h] [rbp-F8h]
    int j;           // [rsp+24h] [rbp-F4h]
    int v9;          // [rsp+28h] [rbp-F0h]
    int v10;         // [rsp+2Ch] [rbp-ECh]
    char v11;        // [rsp+30h] [rbp-E8h]
    int m;           // [rsp+34h] [rbp-E4h]
    int n;           // [rsp+38h] [rbp-E0h]
    int i1;          // [rsp+3Ch] [rbp-DCh]
    int k;           // [rsp+40h] [rbp-D8h]
    int ii;          // [rsp+44h] [rbp-D4h]
    int jj;          // [rsp+48h] [rbp-D0h]
    int v18;         // [rsp+4Ch] [rbp-CCh]
    int nn;          // [rsp+50h] [rbp-C8h]
    int kk;          // [rsp+54h] [rbp-C4h]
    int v21;         // [rsp+58h] [rbp-C0h]
    int v22;         // [rsp+5Ch] [rbp-BCh]
    int mm;          // [rsp+60h] [rbp-B8h]
    _QWORD *Block;   // [rsp+68h] [rbp-B0h]
    int v25;         // [rsp+7Ch] [rbp-9Ch]
    _DWORD *v26;     // [rsp+88h] [rbp-90h]
    void *v27;       // [rsp+90h] [rbp-88h]
    void *v28;       // [rsp+98h] [rbp-80h]
    char *Source;    // [rsp+A0h] [rbp-78h]
    char *v30;       // [rsp+A8h] [rbp-70h]
    char *v31;       // [rsp+B0h] [rbp-68h]
    _DWORD v32[12];  // [rsp+B8h] [rbp-60h]
    __int64 v33;     // [rsp+E8h] [rbp-30h]
    __int64 v34;     // [rsp+F0h] [rbp-28h]

    v9 = strlen(a1);
    v21 = strlen(a2);
    switch (a3)
    {
    // 凯撒
    case 1:
        for (i = 0; i < v9; ++i)
        {
            v22 = a2[i % v21];
            if (a1[i] < 65 || a1[i] > 90)
            {
                if (a1[i] < 97 || a1[i] > 122)
                {
                    if (a1[i] >= 48 && a1[i] <= 57)
                        a1[i] = (a1[i] + v22 - 48 + 10) % 10 + 48;
                }
                else
                {
                    a1[i] = (a1[i] + v22 - 97 + 26) % 26 + 97;
                }
            }
            else
            {
                a1[i] = (a1[i] + v22 - 65 + 26) % 26 + 65;
            }
        }
        break;
    // 换位
    case 3:
        v10 = *a2 % 10 + 2;
        Block = malloc(v10 * 8);
        for (k = 0; k < v10; ++k)
        {
            Block[k] = malloc(v9 + 1);
            memset((void *)Block[k], 0, v9 + 1);
        }
        for (m = 0; v10 * m < v9; ++m)
        {
            for (n = 0; n < v10 && n + v10 * m < v9; ++n)
                *(_BYTE *)(Block[n] + m) = a1[n + v10 * m];
        }
        v18 = 0;
        for (ii = 0; ii < v10; ++ii)
        {
            for (jj = 0; jj < m; ++jj)
            {
                if (*(_BYTE *)(Block[ii] + jj) && v18 < v9)
                {
                    a1[v18++] = *(_BYTE *)(Block[ii] + jj);
                }
            }
        }
        a1[v18] = 0;
        for (kk = 0; kk < v10; ++kk)
            free((void *)Block[kk]);
        free(Block);
        break;
    // 移位
    case 4:
        v25 = *a2 % 10 + 2;
        for (mm = 0; mm < v25; ++mm)
        {
            v11 = a1[v9 - 1];
            for (nn = v9 - 1; nn > 0; --nn)
                a1[nn] = a1[nn - 1];
            *a1 = v11;
        }
        break;
    // Base64
    case 5:
        v34 = v9;
        v26 = malloc(v9 * 4);
        for (i1 = 0; i1 < v9; ++i1)
            v26[i1] = (a2[i1 % v21] + 57) ^ a1[i1];

        Source = (char *)b64encode(v26, (unsigned int)v9);
        strcpy(a1, Source);
        free(v26);
        free(Source);
        break;
    // RC4+Base64
    case 6:
        v3 = strlen(a1) * 4;
        v27 = malloc(v3);
        RC4(a1, a2, v27);
        v4 = strlen(a1);
        v30 = (char *)b64encode(v27, v4);
        strcpy(a1, v30);
        free(v27);
        free(v30);
        break;
    }
}

void de(char *a1, const char *a2, int a3)
{
    size_t v3;       // rax
    unsigned int v4; // eax
    size_t v5;       // rax
    unsigned int v6; // eax
    int i;           // [rsp+20h] [rbp-F8h]
    int j;           // [rsp+24h] [rbp-F4h]
    int v9;          // [rsp+28h] [rbp-F0h]
    int v10;         // [rsp+2Ch] [rbp-ECh]
    char v11;        // [rsp+30h] [rbp-E8h]
    int m;           // [rsp+34h] [rbp-E4h]
    int n;           // [rsp+38h] [rbp-E0h]
    int i1;          // [rsp+3Ch] [rbp-DCh]
    int k;           // [rsp+40h] [rbp-D8h]
    int ii;          // [rsp+44h] [rbp-D4h]
    int jj;          // [rsp+48h] [rbp-D0h]
    int v18;         // [rsp+4Ch] [rbp-CCh]
    int nn;          // [rsp+50h] [rbp-C8h]
    int kk;          // [rsp+54h] [rbp-C4h]
    int v21;         // [rsp+58h] [rbp-C0h]
    int v22;         // [rsp+5Ch] [rbp-BCh]
    int mm;          // [rsp+60h] [rbp-B8h]
    _QWORD *Block;   // [rsp+68h] [rbp-B0h]
    int v25;         // [rsp+7Ch] [rbp-9Ch]
    _DWORD *v26;     // [rsp+88h] [rbp-90h]
    void *v27;       // [rsp+90h] [rbp-88h]
    void *v28;       // [rsp+98h] [rbp-80h]
    char *Source;    // [rsp+A0h] [rbp-78h]
    char *v30;       // [rsp+A8h] [rbp-70h]
    char *v31;       // [rsp+B0h] [rbp-68h]
    _DWORD v32[12];  // [rsp+B8h] [rbp-60h]
    __int64 v33;     // [rsp+E8h] [rbp-30h]
    __int64 v34;     // [rsp+F0h] [rbp-28h]

    v9 = strlen(a1);
    v21 = strlen(a2);
    switch (a3)
    {
    case 1:
        for (i = 0; i < v9; ++i)
        {
            v22 = a2[i % v21];
            if (a1[i] < 65 || a1[i] > 90)
            {
                if (a1[i] < 97 || a1[i] > 122)
                {
                    if (a1[i] >= 48 && a1[i] <= 57)
                        a1[i] = (a1[i] - v22 - 48 + 1000) % 10 + 48;
                }
                else
                {
                    a1[i] = (a1[i] - v22 - 97 + 260) % 26 + 97;
                }
            }
            else
            {
                a1[i] = (a1[i] - v22 - 65 + 260) % 26 + 65;
            }
        }
        break;
    case 3:
        v10 = *a2 % 10 + 2;
        Block = malloc(v10 * 8);
        for (k = 0; k < v10; ++k)
        {
            Block[k] = malloc(v9 + 1);
            memset((void *)Block[k], 0, v9 + 1);
        }
        for (m = 0; v10 * m < v9; ++m)
        {
            ;
        }
        v18 = 0;
        for (ii = 0; ii < v10; ++ii)
        {
            for (jj = 0; jj < m; ++jj)
            {
                if (v18 < v9)
                {
                    *(_BYTE *)(Block[ii] + jj) = a1[v18++];
                }
            }
        }
        for (m = 0; v10 * m < v9; ++m)
        {
            for (n = 0; n < v10 && n + v10 * m < v9; ++n)
            {
                a1[n + v10 * m] = *(_BYTE *)(Block[n] + m);
            }
        }
        a1[v18] = 0;
        for (kk = 0; kk < v10; ++kk)
            free((void *)Block[kk]);
        free(Block);
        break;
    case 4:
        v25 = *a2 % 10 + 2;
        for (mm = 0; mm < v25; ++mm)
        {

            v11 = *a1;
            for (nn = 1; nn < v9; ++nn)
                a1[nn - 1] = a1[nn];
            a1[v9 - 1] = v11;
        }
        break;
    case 5:
        v34 = v9;
        Source = (char *)b64decode(a1, &v34);
        // printf("%d\n", strlen(Source));
        for (i1 = 0; i1 < v34; ++i1)
            a1[i1] = (a2[i1 % v21] + 57) ^ Source[i1];
        a1[v34] = 0;

        free(Source);
        break;
    case 6:
        v3 = strlen(a1) * 4;
        v27 = malloc(v3);
        v4 = strlen(a1);
        v27 = (char *)b64decode(a1, v4);
        de_RC4(a1, a2, v27);
        free(v27);
        break;
    }
}
int __fastcall main(int argc, const char **argv, const char **envp)
{
    int j;           // [rsp+20h] [rbp-1F8h]
    int i;           // [rsp+24h] [rbp-1F4h]
    int v6;          // [rsp+28h] [rbp-1F0h]
    _DWORD v7[4];    // [rsp+30h] [rbp-1E8h]
    __int64 v8;      // [rsp+40h] [rbp-1D8h]
    __int64 v9;      // [rsp+48h] [rbp-1D0h]
    __int64 v10;     // [rsp+50h] [rbp-1C8h]
    _DWORD v11[8];   // [rsp+58h] [rbp-1C0h]
    _DWORD v12[4];   // [rsp+78h] [rbp-1A0h]
    char Str[12];    // [rsp+88h] [rbp-190h] BYREF
    char Source[12]; // [rsp+94h] [rbp-184h] BYREF
    char v15[16];    // [rsp+A0h] [rbp-178h] BYREF
    char flag1[112]; // [rsp+B0h] [rbp-168h] BYREF
    char flag2[112]; // [rsp+120h] [rbp-F8h] BYREF
    char flag3[112]; // [rsp+190h] [rbp-88h] BYREF

    strcpy(Str, "NSSCTF{1111111111111111111111111111}");
    strncpy(flag1, "NSSCTF{11111", 0xCuLL);
    v8 = 12LL;
    flag1[12] = 0;
    strncpy(flag2, "111111111111", 0xCuLL);
    v9 = 12LL;
    flag2[12] = 0;
    strncpy(flag3, "11111111111}", 0xCuLL);
    v10 = 12LL;
    flag3[12] = 0;

    v11[0] = 1;
    v11[1] = 5;
    v11[2] = 6;
    v11[3] = 3;
    v11[4] = 4;
    v11[5] = 1;
    v11[6] = 4;
    v11[7] = 5;
    v12[0] = 0;
    v12[1] = 1;
    v12[2] = 2;
    v7[0] = 0;
    v7[1] = 0;
    v7[2] = 0;
    for (i = 0; i < 8; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            if (i >= v12[j])
            {
                v6 = v7[j];
                if (v6 < 8)
                {
                    if (j)
                    {
                        if (j == 1)
                        {
                            printf("%d %d %d %d\n", i, j, v6, v11[v6]);
                            en(flag2, flag3, v11[v6]);
                        }
                        else if (j == 2)
                        {
                            printf("%d %d %d %d\n", i, j, v6, v11[v6]);
                            en(flag3, flag1, v11[v6]);
                        }
                    }
                    else
                    {
                        printf("%d %d %d %d\n", i, j, v6, v11[v6]);
                        en(flag1, flag2, v11[v6]);
                    }
                    printf("%s\n", flag1);
                    printf("%s\n", flag2);
                    printf("%s\n", flag3);
                    ++v7[j];
                }
            }
        }
    }
    // printf("%s\n", flag1);
    // printf("%s\n", flag2);
    // printf("%s\n", flag3);
}