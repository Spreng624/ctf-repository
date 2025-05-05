#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE1(x) ((unsigned __int8)((x) >> 8))
#define BYTE2(x) ((unsigned __int8)((x) >> 16))
#define HIBYTE(x) ((unsigned __int8)((x) >> 24))
#define _DWORD unsigned int
#define _BYTE unsigned char

_DWORD dword_7FF69B54A028[4] = {0xA3B1BAC6, 0x56AA3350, 0x677D9197, 0xB27022DC};
_DWORD dword_7FF69B54A040[32] = {
    0x70E15, 0x1C232A31, 0x383F464D, 0x545B6269,
    0x70777E85, 0x8C939AA1, 0x0A8AFB6BD, 0x0C4CBD2D9,
    0x0E0E7EEF5, 0x0FC030A11, 0x181F262D, 0x343B4249,
    0x50575E65, 0x6C737A81, 0x888F969D, 0x0A4ABB2B9,
    0x0C0C7CED5, 0x0DCE3EAF1, 0x0F8FF060D, 0x141B2229,
    0x30373E45, 0x4C535A61, 0x686F767D, 0x848B9299,
    0x0A0A7AEB5, 0x0BCC3CAD1, 0x0D8DFE6ED, 0x0F4FB0209,
    0x10171E25, 0x2C333A41, 0x484F565D, 0x646B7279};
_BYTE S_box[256] = {
    0xD6, 0x90, 0xE9, 0xFE, 0xCC, 0xE1, 0x3D, 0xB7, 0x16, 0xB6, 0x14, 0xC2, 0x28, 0xFB, 0x2C, 0x05,
    0x2B, 0x67, 0x9A, 0x76, 0x2A, 0xBE, 0x04, 0xC3, 0xAA, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99,
    0x9C, 0x42, 0x50, 0xF4, 0x91, 0xEF, 0x98, 0x7A, 0x33, 0x54, 0x0B, 0x43, 0xED, 0xCF, 0xAC, 0x62,
    0xE4, 0xB3, 0x1C, 0xA9, 0xC9, 0x08, 0xE8, 0x95, 0x80, 0xDF, 0x94, 0xFA, 0x75, 0x8F, 0x3F, 0xA6,
    0x47, 0x07, 0xA7, 0xFC, 0xF3, 0x73, 0x17, 0xBA, 0x83, 0x59, 0x3C, 0x19, 0xE6, 0x85, 0x4F, 0xA8,
    0x68, 0x6B, 0x81, 0xB2, 0x71, 0x64, 0xDA, 0x8B, 0xF8, 0xEB, 0x0F, 0x4B, 0x70, 0x56, 0x9D, 0x35,
    0x1E, 0x24, 0x0E, 0x5E, 0x63, 0x58, 0xD1, 0xA2, 0x25, 0x22, 0x7C, 0x3B, 0x01, 0x21, 0x78, 0x87,
    0xD4, 0x00, 0x46, 0x57, 0x9F, 0xD3, 0x27, 0x52, 0x4C, 0x36, 0x02, 0xE7, 0xA0, 0xC4, 0xC8, 0x9E,
    0xEA, 0xBF, 0x8A, 0xD2, 0x40, 0xC7, 0x38, 0xB5, 0xA3, 0xF7, 0xF2, 0xCE, 0xF9, 0x61, 0x15, 0xA1,
    0xE0, 0xAE, 0x5D, 0xA4, 0x9B, 0x34, 0x1A, 0x55, 0xAD, 0x93, 0x32, 0x30, 0xF5, 0x8C, 0xB1, 0xE3,
    0x1D, 0xF6, 0xE2, 0x2E, 0x82, 0x66, 0xCA, 0x60, 0xC0, 0x29, 0x23, 0xAB, 0x0D, 0x53, 0x4E, 0x6F,
    0xD5, 0xDB, 0x37, 0x45, 0xDE, 0xFD, 0x8E, 0x2F, 0x03, 0xFF, 0x6A, 0x72, 0x6D, 0x6C, 0x5B, 0x51,
    0x8D, 0x1B, 0xAF, 0x92, 0xBB, 0xDD, 0xBC, 0x7F, 0x11, 0xD9, 0x5C, 0x41, 0x1F, 0x10, 0x5A, 0xD8,
    0x0A, 0xC1, 0x31, 0x88, 0xA5, 0xCD, 0x7B, 0xBD, 0x2D, 0x74, 0xD0, 0x12, 0xB8, 0xE5, 0xB4, 0xB0,
    0x89, 0x69, 0x97, 0x4A, 0x0C, 0x96, 0x77, 0x7E, 0x65, 0xB9, 0xF1, 0x09, 0xC5, 0x6E, 0xC6, 0x84,
    0x18, 0xF0, 0x7D, 0xEC, 0x3A, 0xDC, 0x4D, 0x20, 0x79, 0xEE, 0x5F, 0x3E, 0xD7, 0xCB, 0x39, 0x48};
_BYTE byte_7FF69B54A0C0[16] = {0xDF, 0xD2, 0xC5, 0xD7, 0xA3, 0xA5, 0xFF, 0xF2, 0xE5, 0xF7};

unsigned __int64 __fastcall encrypt(__int64 a1, __int64 a2, __int64 a3)
{
    unsigned __int64 result; // rax
    int i;                   // [rsp+0h] [rbp-178h]
    int j;                   // [rsp+4h] [rbp-174h]
    int m;                   // [rsp+8h] [rbp-170h]
    int ii;                  // [rsp+Ch] [rbp-16Ch]
    int k;                   // [rsp+10h] [rbp-168h]
    int n;                   // [rsp+14h] [rbp-164h]
    int v10;                 // [rsp+18h] [rbp-160h]
    int v11;                 // [rsp+1Ch] [rbp-15Ch]
    _DWORD v12[4];           // [rsp+30h] [rbp-148h] BYREF
    _DWORD v13[36];          // [rsp+40h] [rbp-138h] BYREF
    _DWORD v14[36];          // [rsp+D0h] [rbp-A8h] BYREF

    memset(v14, 0, sizeof(v14));
    memset(v13, 0, sizeof(v13));
    result = (unsigned __int64)v12;
    for (i = 0; i < 4; ++i)
    {
        // 4个字节为一组逆序存入v13前4个字节
        v10 = *(_DWORD *)(a1 + 4LL * i);
        v13[i] = (BYTE1(v10) << 16) | ((unsigned __int8)v10 << 24);
        v13[i] |= HIBYTE(v10) | (BYTE2(v10) << 8);
        v14[i] = dword_7FF69B54A028[i] ^ ((unsigned __int8)HIBYTE(*(_DWORD *)(a2 + 4LL * i)) | ((unsigned __int8)BYTE2(*(_DWORD *)(a2 + 4LL * i)) << 8) | ((unsigned __int8)BYTE1(*(_DWORD *)(a2 + 4LL * i)) << 16) | ((unsigned __int8)*(_DWORD *)(a2 + 4LL * i) << 24));
        result = (unsigned int)(i + 1);
    }
    // 拓展v14至36个字节
    for (j = 0; j < 32; ++j)
    {
        v12[0] = dword_7FF69B54A040[j] ^ v14[j + 3] ^ v14[j + 2] ^ v14[j + 1];
        for (k = 0; k < 4; ++k)
            *((_BYTE *)v12 + k) = S_box[*((unsigned __int8 *)v12 + k)];
        v14[j + 4] = ((v12[0] >> 9) | (v12[0] << 23)) ^ ((v12[0] >> 19) | (v12[0] << 13)) ^ v12[0] ^ v14[j];
        result = (unsigned int)(j + 1);
    }
    for (m = 0; m < 32; ++m)
    {
        v12[0] = v14[m + 4] ^ v13[m + 3] ^ v13[m + 2] ^ v13[m + 1];
        for (n = 0; n < 4; ++n)
            *((_BYTE *)v12 + n) = S_box[*((unsigned __int8 *)v12 + n)];
        v13[m + 4] = ((v12[0] >> 8) | (v12[0] << 24)) ^ ((v12[0] >> 14) | (v12[0] << 18)) ^ ((v12[0] >> 22) | (v12[0] << 10)) ^ ((v12[0] >> 30) | (v12[0] << 2)) ^ v12[0] ^ v13[m];
        result = (unsigned int)(m + 1);
    }
    for (ii = 0; ii < 4; ++ii)
    {
        v11 = v13[35 - ii];
        *(_DWORD *)(a3 + 4LL * ii) = (BYTE1(v11) << 16) | ((unsigned __int8)v11 << 24);
        *(_DWORD *)(a3 + 4LL * ii) |= HIBYTE(v11) | (BYTE2(v11) << 8);
        result = (unsigned int)(ii + 1);
    }

    // 过程量验证

    // printf("v13:\n");
    // for (int i = 0; i < 36; i++)
    // {
    //     printf("%x ", v13[i]);
    // }
    // printf("\n");

    // printf("v14:\n");
    // for (int i = 0; i < 36; i++)
    // {
    //     printf("%x ", v14[i]);
    // }
    // printf("\n");

    return result;
}

unsigned __int64 __fastcall decrypt(__int64 a1, __int64 a2, __int64 a3)
{
    unsigned __int64 result; // rax
    int i;                   // [rsp+0h] [rbp-178h]
    int j;                   // [rsp+4h] [rbp-174h]
    int m;                   // [rsp+8h] [rbp-170h]
    int ii;                  // [rsp+Ch] [rbp-16Ch]
    int k;                   // [rsp+10h] [rbp-168h]
    int n;                   // [rsp+14h] [rbp-164h]
    int v10;                 // [rsp+18h] [rbp-160h]
    int v11;                 // [rsp+1Ch] [rbp-15Ch]
    _DWORD v12[4];           // [rsp+30h] [rbp-148h] BYREF
    _DWORD v13[36];          // [rsp+40h] [rbp-138h] BYREF
    _DWORD v14[36];          // [rsp+D0h] [rbp-A8h] BYREF

    memset(v14, 0, sizeof(v14));
    memset(v13, 0, sizeof(v13));

    for (ii = 0; ii < 4; ++ii)
    {
        v11 = *(_DWORD *)(a3 + 4LL * ii);
        v13[35 - ii] = (BYTE1(v11) << 16) | ((unsigned __int8)v11 << 24);
        v13[35 - ii] |= HIBYTE(v11) | (BYTE2(v11) << 8);
        v14[ii] = dword_7FF69B54A028[ii] ^ ((unsigned __int8)HIBYTE(*(_DWORD *)(a2 + 4LL * ii)) | ((unsigned __int8)BYTE2(*(_DWORD *)(a2 + 4LL * ii)) << 8) | ((unsigned __int8)BYTE1(*(_DWORD *)(a2 + 4LL * ii)) << 16) | ((unsigned __int8)*(_DWORD *)(a2 + 4LL * ii) << 24));
    }

    // 拓展v14至36个字节
    for (j = 0; j < 32; ++j)
    {
        v12[0] = dword_7FF69B54A040[j] ^ v14[j + 3] ^ v14[j + 2] ^ v14[j + 1];
        for (k = 0; k < 4; ++k)
            *((_BYTE *)v12 + k) = S_box[*((unsigned __int8 *)v12 + k)];
        v14[j + 4] = ((v12[0] >> 9) | (v12[0] << 23)) ^ ((v12[0] >> 19) | (v12[0] << 13)) ^ v12[0] ^ v14[j];
    }

    for (m = 31; m >= 0; --m)
    {
        v12[0] = v14[m + 4] ^ v13[m + 3] ^ v13[m + 2] ^ v13[m + 1];
        for (n = 0; n < 4; ++n)
            *((_BYTE *)v12 + n) = S_box[*((unsigned __int8 *)v12 + n)];
        v13[m] = ((v12[0] >> 8) | (v12[0] << 24)) ^ ((v12[0] >> 14) | (v12[0] << 18)) ^ ((v12[0] >> 22) | (v12[0] << 10)) ^ ((v12[0] >> 30) | (v12[0] << 2)) ^ v12[0] ^ v13[m + 4];
    }

    for (i = 0; i < 4; ++i)
    {
        v10 = (BYTE1(v13[i]) << 16) | ((unsigned __int8)v13[i] << 24);
        v10 |= HIBYTE(v13[i]) | (BYTE2(v13[i]) << 8);
        *(_DWORD *)(a1 + 4LL * i) = v10;
    }

    // 过程量验证

    // printf("v13:\n");
    // for (int i = 0; i < 36; i++)
    // {
    //     printf("%x ", v13[i]);
    // }
    // printf("\n");

    // printf("v14:\n");
    // for (int i = 0; i < 36; i++)
    // {
    //     printf("%x ", v14[i]);
    // }
    // printf("\n");
}
char *__fastcall sub_7FF69B521E80(char *a1, char *a2)
{
    char *result; // rax
    char v3;      // [rsp+0h] [rbp-18h]

    v3 = *a1;
    *a1 = *a2;
    result = a2;
    *a2 = v3;
    return result;
}
__int64 sub_7FF69B521480()
{
    __int64 result; // rax
    int i;          // [rsp+20h] [rbp-18h]
    int j;          // [rsp+24h] [rbp-14h]

    for (i = 0; i < 10; ++i)
    {
        byte_7FF69B54A0C0[i] ^= 0x91u;
        result = (unsigned int)(i + 1);
    }
    for (j = 0; j < 10; ++j)
    {
        sub_7FF69B521E80(S_box, &S_box[byte_7FF69B54A0C0[j]]);
        result = (unsigned int)(j + 1);
    }
    return result;
}

int main()
{
    _BYTE v4[16];
    _BYTE Buf[16];

    sub_7FF69B521480();
    memcpy(v4, &byte_7FF69B54A0C0, 10);
    memcpy(&v4[10], &byte_7FF69B54A0C0, 6);

    // 测试解密函数
    // _BYTE test_flag[17] = "1111111111111111";
    // printf("test_flag: %s\n", test_flag);
    // encrypt(test_flag, v4, Buf);
    // decrypt(Buf, v4, Buf);
    // printf("test_flag: %s\n", test_flag);

    _BYTE flag[33] = {
        0xFB, 0x97, 0x3C, 0x3B, 0xF1, 0x99, 0x12, 0xDF,
        0x13, 0x30, 0xF7, 0xD8, 0x7F, 0xEB, 0xA0, 0x6C,
        0x14, 0x5B, 0xA6, 0x2A, 0xA8, 0x05, 0xA5, 0xF3,
        0x76, 0xBE, 0xC9, 0x01, 0xF9, 0x36, 0x7B, 0x46, 0x00};
    decrypt(flag, v4, flag);
    decrypt(&flag[16], v4, &flag[16]);
    printf("NCTF{%s}", flag);
    // NCTF{58cb925e0cd823c0d0b54fd06b820b7e}
    return 0;
}