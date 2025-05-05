#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BYTE unsigned char

void base64decode(_BYTE *C, int len, _BYTE *P)
{
    int v3;
    __int64 v5;
    char v6;
    int i, j;
    unsigned char block[4];
    // unsigned char basetable[65] = "GLp/+Wn7uqX8FQ2JDR1c0M6U53sjBwyxglmrCVdSThAfEOvPHaYZNzo4ktK9iebI";
    unsigned char basetable[65] = "53sjBwyxglmrCVdSThAfEOvPHaYZNzo4ktK9iebIGLp/+Wn7uqX8FQ2JDR1c0M6U";

    for (i = 0; 4 * i < len; ++i)
    {
        block[3] = 0;
        block[2] = 0;
        block[1] = 0;
        block[0] = 0;
        for (j = 0; j < 4; ++j)
        {
            if (C[j + 4 * i] == '=')
                break;
            else
                block[j] = strchr(basetable, C[j + 4 * i]) - (int)basetable;
        }
        P[3 * i] = ((block[0] << 2) | (block[1] >> 4)) & 0xFF;
        P[3 * i + 1] = ((block[1] << 4) | (block[2] >> 2)) & 0xFF;
        P[3 * i + 2] = ((block[2] << 6) | block[3]) & 0xFF;
    }
}

int main()
{
    _BYTE C[] = "AwLdOEVEhIWtajB2CbCWCbTRVsFFC8hirfiXC9gWH9HQayCJVbB8CIF=";
    _BYTE P[100];
    base64decode(C, strlen(C), P);
    printf("%s\n", P);
    return 0;
}