#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BYTE unsigned char
#define _DWORD unsigned int
#define BYTE unsigned char
#define HIBYTE(x) ((unsigned char)((x) >> 24)) // 提取最高字节
#define BYTE1(x) ((unsigned char)((x) >> 8))   // 提取次高字节
#define BYTE2(x) ((unsigned char)((x) >> 16))  // 提取次低字节

#define LODWORD(x) (*((DWORD *)&x))
#define HIDWORD(x) (*((DWORD *)&x + 1))
#define __ROL4__(value, shift) (((value) << (shift)) | ((value) >> (32 - (shift))))

_DWORD dword_7342D0[] = {
    0xD76AA478,
    0xE8C7B756,
    0x242070DB,
    0xC1BDCEEE,
    0xF57C0FAF,
    0x4787C62A,
    0xA8304613,
    0xFD469501,
    0x698098D8,
    0x8B44F7AF,
    0xFFFF5BB1,
    0x895CD7BE,
    0x6B901122,
    0xFD987193,
    0xA679438E,
    0x49B40821,
    0xF61E2562,
    0xC040B340,
    0x265E5A51,
    0xE9B6C7AA,
    0xD62F105D,
    0x02441453,
    0xD8A1E681,
    0xE7D3FBC8,
    0x21E1CDE6,
    0xC33707D6,
    0xF4D50D87,
    0x455A14ED,
    0xA9E3E905,
    0xFCEFA3F8,
    0x676F02D9,
    0x8D2A4C8A,
    0xFFFA3942,
    0x8771F681,
    0x6D9D6122,
    0xFDE5380C,
    0xA4BEEA44,
    0x4BDECFA9,
    0xF6BB4B60,
    0xBEBFBC70,
    0x289B7EC6,
    0xEAA127FA,
    0xD4EF3085,
    0x04881D05,
    0xD9D4D039,
    0xE6DB99E5,
    0x1FA27CF8,
    0xC4AC5665,
    0xF4292244,
    0x432AFF97,
    0xAB9423A7,
    0xFC93A039,
    0x655B59C3,
    0x8F0CCC92,
    0xFFEFF47D,
    0x85845DD1,
    0x6FA87E4F,
    0xFE2CE6E0,
    0xA3014314,
    0x4E0811A1,
    0xF7537E82,
    0xBD3AF235,
    0x2AD7D2BB,
    0xEB86D391};
_DWORD dword_7343D0[] = {
    0x07, 0x0C, 0x11, 0x16,
    0x07, 0x0C, 0x11, 0x16,
    0x07, 0x0C, 0x11, 0x16,
    0x07, 0x0C, 0x11, 0x16,
    0x05, 0x09, 0x0E, 0x14,
    0x05, 0x09, 0x0E, 0x14,
    0x05, 0x09, 0x0E, 0x14,
    0x05, 0x09, 0x0E, 0x14,
    0x04, 0x0B, 0x10, 0x17,
    0x04, 0x0B, 0x10, 0x17,
    0x04, 0x0B, 0x10, 0x17,
    0x04, 0x0B, 0x10, 0x17,
    0x06, 0x0A, 0x0F, 0x15,
    0x06, 0x0A, 0x0F, 0x15,
    0x06, 0x0A, 0x0F, 0x15,
    0x06, 0x0A, 0x0F, 0x15};
int __cdecl sub_7324A0(int a1, _DWORD *a2)
{
    *a2 = a1;
    return 3;
}
int __cdecl sub_732500(unsigned __int16 *a1)
{
    return (*((unsigned __int8 *)a1 + 3) << 24) | (*((unsigned __int8 *)a1 + 2) << 16) | *a1;
}
int __cdecl sub_7321A0(void *Src, size_t Size, int a3)
{
    size_t v3;        // edx
    int v4;           // eax
    _DWORD v6[16];    // [esp+4h] [ebp-7Ch]
    int v7;           // [esp+44h] [ebp-3Ch]
    unsigned int v8;  // [esp+48h] [ebp-38h]
    unsigned int v9;  // [esp+4Ch] [ebp-34h]
    unsigned int v10; // [esp+50h] [ebp-30h]
    unsigned int v11; // [esp+54h] [ebp-2Ch]
    int v12;          // [esp+58h] [ebp-28h]
    unsigned int v13; // [esp+5Ch] [ebp-24h]
    int v14;          // [esp+60h] [ebp-20h]
    int v15;          // [esp+64h] [ebp-1Ch]
    void *Block;      // [esp+68h] [ebp-18h]
    int v17;          // [esp+6Ch] [ebp-14h]
    unsigned int i;   // [esp+70h] [ebp-10h]
    int v19;          // [esp+74h] [ebp-Ch]
    unsigned int j;   // [esp+78h] [ebp-8h]
    unsigned int k;   // [esp+7Ch] [ebp-4h]

    Block = 0;
    v11 = 1732584193;
    v10 = -271733879;
    v9 = -1732584194;
    v8 = 271733878;
    for (i = Size + 1; i % 0x40 != 56; ++i)
        ;
    v3 = i + 8;
    if (i >= 0xFFFFFFF8)
        v3 = -1;
    Block = malloc(v3);
    memcpy(Block, Src, Size);
    *((_BYTE *)Block + Size) = 0x80;
    for (j = Size + 1; j < i; ++j)
        *((_BYTE *)Block + j) = 0;
    sub_7324A0(8 * Size, (char *)Block + i);
    sub_7324A0(Size >> 29, (char *)Block + i + 4);
    for (j = 0; j < i; j += 64)
    {
        for (k = 0; k < 0x10; ++k)
        {
            v4 = sub_732500((char *)Block + 4 * k + j);
            v6[k] = v4;
        }
        v12 = v11;
        v19 = v10;
        v15 = v9;
        v17 = v8;
        for (k = 0; k < 0x40; ++k)
        {
            if (k >= 0x10)
            {
                if (k >= 0x20)
                {
                    if (k >= 0x30)
                    {
                        v14 = v15 ^ (v19 | ~v17);
                        v13 = 7 * k % 0x10;
                    }
                    else
                    {
                        v14 = v17 ^ v15 ^ v19;
                        v13 = (3 * k + 5) % 0x10;
                    }
                }
                else
                {
                    v14 = v15 & ~v17 | v19 & v17;
                    v13 = (5 * k + 1) % 0x10;
                }
            }
            else
            {
                v14 = v17 & ~v19 | v15 & v19;
                v13 = k;
            }
            v7 = v17;
            v17 = v15;
            v15 = v19;
            v19 += __ROL4__(v6[v13] + dword_7342D0[k] + v14 + v12, dword_7343D0[k]);
            v12 = v7;
        }
        v11 += v12;
        v10 += v19;
        v9 += v15;
        v8 += v17;
    }
    free(Block);
    sub_7324A0(v11, a3);
    sub_7324A0(v10, a3 + 4);
    sub_7324A0(v9, a3 + 8);
    return sub_7324A0(v8, a3 + 12);
}
_BYTE byte_A46000[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};
int dword_734148[] = {
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1B000000, 0x36000000};
char byte_736000[] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5,
    0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0,
    0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC,
    0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A,
    0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0,
    0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B,
    0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85,
    0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5,
    0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17,
    0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88,
    0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C,
    0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9,
    0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6,
    0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E,
    0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94,
    0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68,
    0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};
int __cdecl sub_731490(int a1, int a2, _DWORD *a3)
{
    _DWORD *v4;  // [esp+4h] [ebp-18h]
    int k;       // [esp+8h] [ebp-14h]
    int j;       // [esp+Ch] [ebp-10h]
    int m;       // [esp+10h] [ebp-Ch]
    int i;       // [esp+14h] [ebp-8h]
    _DWORD *v9;  // [esp+18h] [ebp-4h]
    _DWORD *v10; // [esp+18h] [ebp-4h]

    if (!a1 || !a3)
        return -1;
    if (a2 != 16)
        return -1;
    v9 = a3;
    v4 = a3 + 44;
    for (i = 0; i < 4; ++i)
        a3[i] = _byteswap_ulong(*(_DWORD *)(a1 + 4 * i));
    for (j = 0; j < 10; ++j)
    {

        v9[4] = dword_734148[j] ^ *v9 ^ (unsigned __int8)byte_736000[HIBYTE(v9[3])] ^ (unsigned __int16)((unsigned __int8)byte_736000[(unsigned __int8)v9[3]] << 8) ^ ((unsigned __int8)byte_736000[BYTE1(v9[3])] << 16) & 0xFF0000 ^ ((unsigned __int8)byte_736000[(unsigned __int8)BYTE2(v9[3])] << 24);
        v9[5] = v9[4] ^ v9[1];
        v9[6] = v9[5] ^ v9[2];
        v9[7] = v9[6] ^ v9[3];
        v9 += 4;
    }
    v10 = a3 + 40;
    for (k = 0; k < 11; ++k)
    {
        for (m = 0; m < 4; ++m)
            v4[m] = v10[m];
        v10 -= 4;
        v4 += 4;
    }
    return 0;
}
unsigned int __cdecl re_xorF(int a1)
{
    unsigned int result; // eax
    unsigned int i;      // [esp+0h] [ebp-Ch]
    unsigned int v3;     // [esp+4h] [ebp-8h]
    char v4;             // [esp+Bh] [ebp-1h]

    v3 = 0;
    for (i = 15;; --i)
    {
        result = v3;
        if (v3 >= i)
            break;
        v4 = *(_BYTE *)(v3 + a1) ^ 0xF;
        *(_BYTE *)(v3 + a1) = *(_BYTE *)(i + a1) ^ 0xF;
        *(_BYTE *)(i + a1) = v4;
        ++v3;
    }
    return result;
}
int __cdecl toMatrix(int a1, char *a2)
{
    int i;   // [esp+0h] [ebp-Ch]
    int j;   // [esp+4h] [ebp-8h]
    char v5; // [esp+Bh] [ebp-1h]

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            v5 = *a2++;
            *(_BYTE *)(a1 + 4 * j + i) = v5;
        }
    }
    return 0;
}
int __cdecl fromMatrix(int a1, _BYTE *a2)
{
    int i; // [esp+0h] [ebp-8h]
    int j; // [esp+4h] [ebp-4h]

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
            *a2++ = *(_BYTE *)(a1 + 4 * j + i);
    }
    return 0;
}
int __cdecl tran_enc(int a1)
{
    int i;        // [esp+4h] [ebp-18h]
    _DWORD v3[4]; // [esp+8h] [ebp-14h] BYREF
    _BYTE temp;

    memset(v3, 0, sizeof(v3));
    for (i = 0; i < 4; ++i)
    {
        for (int j = 0; j < i; j++)
        {
            temp = *(_BYTE *)(a1 + 4 * i);
            *(_BYTE *)(a1 + 4 * i) = *(_BYTE *)(a1 + 4 * i + 1);
            *(_BYTE *)(a1 + 4 * i + 1) = *(_BYTE *)(a1 + 4 * i + 2);
            *(_BYTE *)(a1 + 4 * i + 2) = *(_BYTE *)(a1 + 4 * i + 3);
            *(_BYTE *)(a1 + 4 * i + 3) = temp;
        }
    }

    return 0;
}
int __cdecl tran_dec(int a1)
{
    int i;        // [esp+4h] [ebp-18h]
    _DWORD v3[4]; // [esp+8h] [ebp-14h] BYREF
    _BYTE temp;

    memset(v3, 0, sizeof(v3));
    for (i = 0; i < 4; ++i)
    {
        for (int j = 0; j < i; j++)
        {
            temp = *(_BYTE *)(a1 + 4 * i + 3);
            *(_BYTE *)(a1 + 4 * i + 3) = *(_BYTE *)(a1 + 4 * i + 2);
            *(_BYTE *)(a1 + 4 * i + 2) = *(_BYTE *)(a1 + 4 * i + 1);
            *(_BYTE *)(a1 + 4 * i + 1) = *(_BYTE *)(a1 + 4 * i);
            *(_BYTE *)(a1 + 4 * i) = temp;
        }
    }

    return 0;
}
int __cdecl key_enc(int a1, int a2)
{
    _DWORD v3[4]; // [esp+0h] [ebp-18h] BYREF
    int j;        // [esp+10h] [ebp-8h]
    int i;        // [esp+14h] [ebp-4h]

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            *((_BYTE *)&v3[i] + j) = *(_DWORD *)(a2 + 4 * j) >> (8 * (3 - i));
            *(_BYTE *)(a1 + 4 * i + j) ^= *((_BYTE *)&v3[i] + j);
        }
    }
    return 0;
}
int __cdecl key_dec(int a1, int a2)
{
    _DWORD v3[4]; // [esp+0h] [ebp-18h] BYREF
    int j;        // [esp+10h] [ebp-8h]
    int i;        // [esp+14h] [ebp-4h]

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            *((_BYTE *)&v3[i] + j) = *(_DWORD *)(a2 + 4 * j) >> (8 * (3 - i));
            *(_BYTE *)(a1 + 4 * i + j) ^= *((_BYTE *)&v3[i] + j);
        }
    }
    return 0;
}
int __cdecl box_enc(int a1)
{
    int j; // [esp+0h] [ebp-8h]
    int i; // [esp+4h] [ebp-4h]

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
            *(_BYTE *)(a1 + 4 * i + j) = byte_A46000[*(unsigned __int8 *)(a1 + 4 * i + j)];
    }
    return 0;
}
int __cdecl box_dec(int a1)
{
    int j; // [esp+0h] [ebp-8h]
    int i; // [esp+4h] [ebp-4h]
    _BYTE box[256];
    for (int i = 0; i < 256; i++)
    {
        box[byte_A46000[i]] = i;
    }

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
            *(_BYTE *)(a1 + 4 * i + j) = box[*(unsigned __int8 *)(a1 + 4 * i + j)];
    }
    return 0;
}
unsigned int __cdecl swap_xor5(int a1)
{
    unsigned int result; // eax
    unsigned int i;      // [esp+0h] [ebp-8h]
    char v3;             // [esp+7h] [ebp-1h]

    for (i = 0; i < 0x10; i += 2)
    {
        v3 = *(_BYTE *)(i + a1) ^ 5;
        *(_BYTE *)(i + a1) = *(_BYTE *)(i + a1 + 1) ^ 5;
        *(_BYTE *)(i + a1 + 1) = v3;
        result = i + 2;
    }
    return result;
}
int __cdecl sub_A41100(unsigned __int8 a1, char a2)
{
    int v3;             // [esp+0h] [ebp-Ch]
    int i;              // [esp+4h] [ebp-8h]
    unsigned __int8 v5; // [esp+Bh] [ebp-1h]

    v5 = 0;
    for (i = 0; i < 8; ++i)
    {
        if ((a1 & 1) != 0) // 奇数
            v5 ^= a2;
        v3 = a2 & 0x80;
        a2 *= 2;
        if (v3) // a2 的最高位有值
            a2 ^= 0x1Bu;
        a1 >>= 1;
    }
    return v5;
}
int __cdecl hard_enc(int a1)
{
    char v1;      // bl
    char v2;      // bl
    char v3;      // bl
    char v4;      // al
    _BYTE v6[16]; // [esp+8h] [ebp-30h] BYREF
    _BYTE v7[16]; // [esp+18h] [ebp-20h] BYREF
    int j;        // [esp+28h] [ebp-10h]
    int i;        // [esp+2Ch] [ebp-Ch]
    int m;        // [esp+30h] [ebp-8h]
    int k;        // [esp+34h] [ebp-4h]

    v7[0] = 2;
    v7[1] = 3;
    v7[2] = 1;
    v7[3] = 1;
    v7[4] = 1;
    v7[5] = 2;
    v7[6] = 3;
    v7[7] = 1;
    v7[8] = 1;
    v7[9] = 1;
    v7[10] = 2;
    v7[11] = 3;
    v7[12] = 3;
    v7[13] = 1;
    v7[14] = 1;
    v7[15] = 2;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
            v6[4 * i + j] = *(_BYTE *)(a1 + 4 * i + j);
    }
    for (k = 0; k < 4; ++k)
    {
        for (m = 0; m < 4; ++m)
        {
            v1 = sub_A41100(v7[4 * k], v6[m]);
            v2 = sub_A41100(v7[4 * k + 1], v6[m + 4]) ^ v1;
            v3 = sub_A41100(v7[4 * k + 2], v6[m + 8]) ^ v2;
            v4 = sub_A41100(v7[4 * k + 3], v6[m + 12]);
            *(_BYTE *)(a1 + 4 * k + m) = v4 ^ v3;
        }
    }
    return 0;
}
int __cdecl hard_dec(int a1)
{
    char v1;      // bl
    char v2;      // bl
    char v3;      // bl
    char v4;      // al
    _BYTE v6[16]; // [esp+8h] [ebp-30h] BYREF
    _BYTE v7[16]; // [esp+18h] [ebp-20h] BYREF
    int j;        // [esp+28h] [ebp-10h]
    int i;        // [esp+2Ch] [ebp-Ch]
    int m;        // [esp+30h] [ebp-8h]
    int k;        // [esp+34h] [ebp-4h]
    _BYTE a_1, a_2, a_3, a_4;
    _BYTE t_1, t_2, t_3;

    v7[0] = 2;
    v7[1] = 3;
    v7[2] = 1;
    v7[3] = 1;
    v7[4] = 1;
    v7[5] = 2;
    v7[6] = 3;
    v7[7] = 1;
    v7[8] = 1;
    v7[9] = 1;
    v7[10] = 2;
    v7[11] = 3;
    v7[12] = 3;
    v7[13] = 1;
    v7[14] = 1;
    v7[15] = 2;

    for (int i = 0; i < 4; i++)
    {
        a_1 = *(_BYTE *)(a1 + i);
        a_2 = *(_BYTE *)(a1 + 4 + i);
        a_3 = *(_BYTE *)(a1 + 8 + i);
        a_4 = *(_BYTE *)(a1 + 12 + i);
        t_1 = a_1 ^ a_2 ^ a_3 ^ a_4;
        t_2 = sub_A41100(2, t_1) ^ a_1 ^ a_3;
        t_3 = sub_A41100(2, t_2) ^ a_1 ^ a_2;
        *(_BYTE *)(a1 + i) = sub_A41100(2, t_3) ^ a_1 ^ t_1;
        *(_BYTE *)(a1 + 4 + i) = *(_BYTE *)(a1 + i) ^ t_3;
        *(_BYTE *)(a1 + 8 + i) = *(_BYTE *)(a1 + i) ^ t_2;
        *(_BYTE *)(a1 + 12 + i) = *(_BYTE *)(a1 + i) ^ *(_BYTE *)(a1 + 4 + i) ^ *(_BYTE *)(a1 + 8 + i) ^ t_1;
    }

    return 0;
}
int __cdecl decrypt(void *Src, size_t Size, int a3, unsigned int a4)
{
    int j;          // [esp+10h] [ebp-19Ch]
    unsigned int i; // [esp+14h] [ebp-198h]
    int v7;         // [esp+18h] [ebp-194h]
    _BYTE *v8;      // [esp+20h] [ebp-18Ch]
    _DWORD v10[4];  // [esp+188h] [ebp-24h] BYREF
    _DWORD v11[4];  // [esp+198h] [ebp-14h] BYREF
    _DWORD v9[88];

    v7 = a3; // flag
    v8 = v9; // const
    memset(v10, 0, sizeof(v10));
    memset(v11, 0, sizeof(v11));
    memcpy(v10, Src, Size);

    swap_xor5((int)v10);
    sub_731490((int)v10, 16, v9);
    v8 += 0x90;
    for (i = 0; i < (int)a4; i += 16)
    {
        swap_xor5((int)v7);
        toMatrix((int)v11, (int)v7); // copy v7->v10 4*4mode
        key_dec((int)v11, (int)(v8 + 16));
        tran_dec((int)v11);
        box_dec((int)v11);
        for (j = 1; j < 10; j++)
        {
            key_dec((int)v11, (int)v8);
            hard_dec((int)v11);
            tran_dec((int)v11);
            box_dec((int)v11);
            v8 -= 16;
        }
        key_dec((int)v11, (int)v9);
        fromMatrix((int)v11, (int)v7); // copy v11->v7 4*4mode
        re_xorF(a3);
        v7 += 16;
        a3 += 16;
        v8 = v9;
        v8 += 0x90;
    }
    return 39;
}
int __cdecl encrypt(void *Src, size_t Size, int a3, unsigned int a4)
{
    int j;          // [esp+10h] [ebp-19Ch]
    unsigned int i; // [esp+14h] [ebp-198h]
    int v7;         // [esp+18h] [ebp-194h]
    _BYTE *v8;      // [esp+20h] [ebp-18Ch]
    _DWORD v10[4];  // [esp+188h] [ebp-24h] BYREF
    _DWORD v11[4];  // [esp+198h] [ebp-14h] BYREF
    _DWORD v9[88];

    v7 = a3; // flag
    v8 = v9; // const
    memset(v10, 0, sizeof(v10));
    memset(v11, 0, sizeof(v11));
    memcpy(v10, Src, Size);
    swap_xor5((int)v10);
    sub_731490((int)v10, 16, v9);

    for (i = 0; i < (int)a4; i += 16)
    {

        re_xorF(a3);            // reverse then xor 0xF
        toMatrix((int)v11, a3); // copy a3->v11 4*4mode
        key_enc((int)v11, (int)v9);
        for (j = 1; j < 10; ++j)
        {
            v8 += 16;
            box_enc((int)v11); // <- byte_A46000 <- v11
            tran_enc((int)v11);
            hard_enc((int)v11);
            key_enc((int)v11, (int)v8);
        }
        box_enc((int)v11);
        tran_enc((int)v11);
        key_enc((int)v11, (int)(v8 + 16));
        fromMatrix((int)v11, (int)v7); // copy v11->v7 4*4mode
        swap_xor5((int)v7);
        v7 += 16;
        a3 += 16;
        v8 = v9;
    }
    return 39;
}
int __cdecl make_key(int a1, int date, int month, int year)
{
    _DWORD Src[3]; // [esp+18h] [ebp-10h] BYREF
    int k;

    Src[0] = date;
    Src[1] = month;
    Src[2] = year;
    printf("%02x %02x %02x \n", Src[0], Src[1], Src[2]);
    sub_7321A0(Src, 0xCu, a1);
    for (k = 0; k < 4; ++k)
        printf("%x ", *(_DWORD *)(a1 + 4 * k));
    printf("\n");

    for (k = 0; k < 16; ++k)
        *(_BYTE *)(k + a1) ^= 0x14u ^ 0x11u;

    return 0;
}
int main()
{
    _DWORD Src[4];
    unsigned char flag[] = {
        0xCD, 0x16, 0xDB, 0xB5, 0xD1, 0x02, 0xA4, 0x82,
        0x8E, 0x59, 0x73, 0x9E, 0x96, 0x26, 0x56, 0xF2,
        0x16, 0x8E, 0x46, 0xF2, 0x55, 0x7B, 0x92, 0x31,
        0x30, 0xDC, 0xAA, 0x8A, 0xF3, 0x1C, 0xA0, 0xAA};
    unsigned char flag_copy[] = {
        0xCD, 0x16, 0xDB, 0xB5, 0xD1, 0x02, 0xA4, 0x82,
        0x8E, 0x59, 0x73, 0x9E, 0x96, 0x26, 0x56, 0xF2,
        0x16, 0x8E, 0x46, 0xF2, 0x55, 0x7B, 0x92, 0x31,
        0x30, 0xDC, 0xAA, 0x8A, 0xF3, 0x1C, 0xA0, 0xAA};

    // char test_flag[16] = "NSSCTF{fuck_Liv}";
    // make_key((int)Src, 28, 0, 0x7d);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%x ", Src[i]);
    // }
    // printf("\n");
    // encrypt(Src, 0x10u, test_flag, 16);
    // putFlag(test_flag);

    for (int j = 0; j <= 11; j++)
    {
        for (int i = 1; i <= 31; i++)
        {
            memcpy(flag, flag_copy, 32);
            make_key((int)Src, i, j, 0x7c);
            decrypt(Src, 0x10u, flag, 32);
            if ((flag[0] == 'N' && flag[1] == 'S') || (flag[0] == 'n' && flag[1] == 's'))
            {
                printf("flag: %s\n", flag);
                return 0;
            }
        }
    }
    return 0;
}