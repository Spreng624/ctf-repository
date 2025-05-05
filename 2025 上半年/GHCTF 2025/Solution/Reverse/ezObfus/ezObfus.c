#include <stdio.h>
#include <string.h>
#include <windows.h>

int i;
int v22, v23, v24, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v47;
int j, k;
int v52, v51, v57, v56, v55, v54, v58, v59;
int v60, v61, v62, v63, v64, v65, v66;
char v78[0x100];
int v72, v73, v74, v75, v76, v77;

int main_0()
{
    // 00 00 00 00 54 55 79 9E  A8 E1 1C DA 04 1D C1 6E
    // 80 82 0D 8A 4C 65 E1 46  71 31 ED D2 14 C5 39 B5
    // 49 E2 04 A9 00 00 00 00  00 00 00 00 00 00 00 00
    unsigned char enc_flag[33] = {
        0x54, 0x55, 0x79, 0x9E, 0xA8, 0xE1, 0x1C, 0xDA,
        0x04, 0x1D, 0xC1, 0x6E, 0x80, 0x82, 0x0D, 0x8A,
        0x4C, 0x65, 0xE1, 0x46, 0x71, 0x31, 0xED, 0xD2,
        0x14, 0xC5, 0x39, 0xB5, 0x49, 0xE2, 0x04, 0xA9, 0x00};
    unsigned char flag[0x100];
    unsigned int key;
    unsigned char v76;

    printf("Password:");
    scanf("%d", &key);
    printf("%d\n", key);

    unsigned int key_hash = 0x811C9DC5;
    for (int i = 0; i < 4; i++)
    {
        v76 = key >> (i * 8);
        if (v76 % 2)
            key_hash ^= v76;
        else
            key_hash *= 0x1000193;

        key_hash = (key_hash >> 25) | (key_hash << 7);
        key_hash -= v76;
    }

    if (key_hash != 1172912374) // 0x45E938F6
    {
        printf("Wrong Password!");
        return 0;
    }

    memset(flag, 0, 0x100u);
    printf("Flag:");
    scanf("%s", flag);

    for (i = 0; i < 32; i++)
    {
        flag[i] ^= 0x48;
    }

    for (i = 0; i < 32; i++)
    {
        flag[i] ^= i ^ (key >> ((3 - i % 4) * 8));
        flag[i] = (flag[i] >> 5) | (flag[i] << 3);
        flag[i] += i;
    }

    if (!strcmp(enc_flag, flag))
    {
        printf("Correct Flag");
    }
    else
    {
        printf("Wrong Flag");
    }

    return 0;
}

int main()
{

    unsigned char flag[33] = {
        0x54, 0x55, 0x79, 0x9E, 0xA8, 0xE1, 0x1C, 0xDA,
        0x04, 0x1D, 0xC1, 0x6E, 0x80, 0x82, 0x0D, 0x8A,
        0x4C, 0x65, 0xE1, 0x46, 0x71, 0x31, 0xED, 0xD2,
        0x14, 0xC5, 0x39, 0xB5, 0x49, 0xE2, 0x04, 0xA9, 0x00};

    unsigned int key = 0x8c90f77b;

    // key = 0x8c90f77b; // -1936656517
    for (i = 0; i < 32; i++)
    {
        flag[i] -= i;
        flag[i] = (flag[i] >> 3) | (flag[i] << 5);
        flag[i] ^= i ^ (key >> ((3 - i % 4) * 8));
        flag[i] ^= 0x48;
    }

    printf("%s\n", flag);
    // NSSCTF{NSSCTF{NSSCTF{NSSCTF{}}}}

    return 0;
}