#include <stdio.h>
#define _DWORD unsigned int

#include <stdio.h>
#include <stdlib.h>

_DWORD dword_140020100[64];
_DWORD dword_140020200[64];
_DWORD dword_140020300[64];
_DWORD dword_140020400[64];
_DWORD dword_140020500[64];
_DWORD dword_140020600[64];
_DWORD dword_140020700[64];
_DWORD dword_140020800[64];

#define HIBYTE(x) (unsigned char)((x) >> 24)
#define HIWORD(x) (unsigned short)((x) >> 16)

_DWORD *__fastcall sub_140012510(unsigned int *a1, _DWORD *a2)
{
    _DWORD *result;   // rax
    int v3;           // [rsp+24h] [rbp+4h]
    int v4;           // [rsp+24h] [rbp+4h]
    int v5;           // [rsp+44h] [rbp+24h]
    int v6;           // [rsp+44h] [rbp+24h]
    int v7;           // [rsp+44h] [rbp+24h]
    int v8;           // [rsp+44h] [rbp+24h]
    unsigned int v9;  // [rsp+44h] [rbp+24h]
    unsigned int v10; // [rsp+44h] [rbp+24h]
    unsigned int v11; // [rsp+44h] [rbp+24h]
    unsigned int v12; // [rsp+44h] [rbp+24h]
    unsigned int v13; // [rsp+44h] [rbp+24h]
    unsigned int v14; // [rsp+44h] [rbp+24h]
    int v15;          // [rsp+44h] [rbp+24h]
    int v16;          // [rsp+44h] [rbp+24h]
    int v17;          // [rsp+44h] [rbp+24h]
    unsigned int v18; // [rsp+64h] [rbp+44h]
    int v19;          // [rsp+64h] [rbp+44h]
    unsigned int v20; // [rsp+64h] [rbp+44h]
    unsigned int v21; // [rsp+64h] [rbp+44h]
    unsigned int v22; // [rsp+64h] [rbp+44h]
    unsigned int v23; // [rsp+64h] [rbp+44h]
    int v24;          // [rsp+64h] [rbp+44h]
    int v25;          // [rsp+64h] [rbp+44h]
    int v26;          // [rsp+64h] [rbp+44h]
    int v27;          // [rsp+64h] [rbp+44h]
    unsigned int v28; // [rsp+64h] [rbp+44h]
    int v29;          // [rsp+84h] [rbp+64h]
    int v30;          // [rsp+84h] [rbp+64h]
    int v31;          // [rsp+84h] [rbp+64h]
    int v32;          // [rsp+84h] [rbp+64h]
    unsigned int v33; // [rsp+84h] [rbp+64h]
    unsigned int v34; // [rsp+84h] [rbp+64h]
    unsigned int v35; // [rsp+84h] [rbp+64h]
    int v36;          // [rsp+84h] [rbp+64h]
    int v37;          // [rsp+84h] [rbp+64h]
    int i;            // [rsp+A4h] [rbp+84h]
    _DWORD *v41;      // [rsp+1A8h] [rbp+188h]

    v18 = a1[1];
    v5 = (v18 ^ (*a1 >> 4)) & 0xF0F0F0F;
    v19 = v5 ^ v18;
    v29 = (16 * v5) ^ *a1;
    v6 = (unsigned __int16)(v19 ^ HIWORD(v29));
    v20 = v6 ^ v19;
    v30 = (v6 << 16) ^ v29;
    v7 = (v30 ^ (v20 >> 2)) & 0x33333333;
    v31 = v7 ^ v30;
    v21 = (4 * v7) ^ v20;
    v8 = (v31 ^ (v21 >> 8)) & 0xFF00FF;
    v32 = v8 ^ v31;
    v22 = (((v8 << 8) ^ v21) >> 31) | (2 * ((v8 << 8) ^ v21));
    v9 = (v22 ^ v32) & 0xAAAAAAAA;

    v23 = v9 ^ v22;
    v33 = ((v9 ^ v32) >> 31) | (2 * (v9 ^ v32));
    for (i = 0; i < 8; ++i)
    {
        v10 = *a2 ^ ((v23 >> 4) | (v23 << 28));
        v41 = a2 + 1;
        v3 = dword_140020100[HIBYTE(v10) & 0x3F] | dword_140020300[HIWORD(v10) & 0x3F] | dword_140020500[(v10 >> 8) & 0x3F] | dword_140020700[v10 & 0x3F];
        v11 = *v41++ ^ v23;
        v33 ^= dword_140020200[HIBYTE(v11) & 0x3F] | dword_140020400[HIWORD(v11) & 0x3F] | dword_140020600[(v11 >> 8) & 0x3F] | dword_140020800[v11 & 0x3F] | v3;
        v12 = *v41++ ^ ((v33 >> 4) | (v33 << 28));
        v4 = dword_140020100[HIBYTE(v12) & 0x3F] | dword_140020300[HIWORD(v12) & 0x3F] | dword_140020500[(v12 >> 8) & 0x3F] | dword_140020700[v12 & 0x3F];
        v13 = *v41 ^ v33;
        a2 = v41 + 1;
        v23 ^= dword_140020200[HIBYTE(v13) & 0x3F] | dword_140020400[HIWORD(v13) & 0x3F] | dword_140020600[(v13 >> 8) & 0x3F] | dword_140020800[v13 & 0x3F] | v4;
    }
    v24 = (v23 >> 1) | (v23 << 31);
    v14 = (v24 ^ v33) & 0xAAAAAAAA;
    v25 = v14 ^ v24;
    v34 = ((v14 ^ v33) >> 1) | ((v14 ^ v33) << 31);
    v15 = (v25 ^ (v34 >> 8)) & 0xFF00FF;
    v26 = v15 ^ v25;
    v35 = (v15 << 8) ^ v34;
    v16 = (v26 ^ (v35 >> 2)) & 0x33333333;
    v27 = v16 ^ v26;
    v36 = (4 * v16) ^ v35;
    v17 = (unsigned __int16)(v36 ^ HIWORD(v27));
    v37 = v17 ^ v36;
    v28 = (v17 << 16) ^ v27;
    *a1 = (16 * ((v37 ^ (v28 >> 4)) & 0xF0F0F0F)) ^ v28;
    result = a1 + 1;
    a1[1] = (v37 ^ (v28 >> 4)) & 0xF0F0F0F ^ v37;
    return result;
}