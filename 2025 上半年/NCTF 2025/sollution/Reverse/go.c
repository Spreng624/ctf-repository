// "1" * 32

// 03 00 00 00 90 9B 77 E3  AD C4 54 E2 51 F6 27 B9  ......w...T...'.
// 66 74 63 6E 10 65 7F 92  3D 5F 23 01 37 82 44 D7  ftcn.e..=_#.7.D.
// 8B 2A D0 1A 74 E1 67 D8  FF CB B7 C2 F5 85 69 10  .*..t....˷ ...i.
// F4 51 21 D3 00 00 00 00  04 00 00 00 20 00 00 00  ............ ...
// AD C4 54 E2 F0 12 34 E0  08 E6 19 D3 51 F6 27 B9  ......4.........
// F4 51 21 D3 00 00 00 00  00 00 00 00 B9 79 37 9E  .............y7.
// 66 74 63 6E ED F0 2E 06  4F 0B 8C A7 34 32 30 32  ftcn....O...4202

// 03 00 00 00 90 9B 77 E3  87 62 81 14 78 2C 82 5E  ......w.....x,.^
// 34 32 30 32 C7 22 E8 05  17 F9 F6 F7 4C 1E B2 6C  4202...........l
// A0 0E 49 77 63 17 A9 64  C3 19 E0 13 31 83 41 CE  ..Iwc..d......A.
// F4 9C 21 E2 00 00 00 00  04 00 00 00 20 00 00 00  ............ ...
// 87 62 81 14 C5 A4 86 36  E7 13 1A 20 78 2C 82 5E  .b..Ť .6... x,.^
// F4 9C 21 E2 00 00 00 00  01 00 00 00 B9 79 37 9E  .............y7.
// 34 32 30 32 C3 12 EB D6  2E F7 1C 9F 46 54 43 4E  4202........FTCN

// 03 00 00 00 90 9B 77 E3  58 73 A5 FD C8 F4 A6 88
// 34 32 30 32 4C 6F 8A 08  C8 E8 D2 1E FC C6 96 BA
// 62 BB 59 11 C4 AF 69 D9  A6 14 30 C8 E6 9F A9 3A
// 8C B4 D9 02 00 00 00 00  04 00 00 00 20 00 00 00
// 58 73 A5 FD 44 6C D2 FF  B3 C0 BE 9F C8 F4 A6 88
// 8C B4 D9 02 00 00 00 00  01 00 00 00 B9 79 37 9E
// 34 32 30 32 C3 12 EB D6  2E F7 1C 9F 46 54 43 4E

// "2" * 32

// 03 00 00 00 90 9B 77 E3  AF 1B D5 F3 29 A0 A1 B8  ......w.....)...
// 66 74 63 6E 90 02 1A 8A  3F 80 A2 10 4F D4 C2 D6  ftcn....?...O...
// A2 05 F2 5E 8E 54 65 E7  2C 51 97 B9 21 C1 01 6B  ......e.....!..k
// 4D 12 99 24 00 00 00 00  04 00 00 00 20 00 00 00  M..$........ ...
// AF 1B D5 F3 1A 14 F9 20  30 C8 94 5D 29 A0 A1 B8  ....... 0Ȕ ])...
// 4D 12 99 24 00 00 00 00  00 00 00 00 B9 79 37 9E  M..$.........y7.
// 66 74 63 6E ED F0 2E 06  4F 0B 8C A7 34 32 30 32  ftcn....O...4202

// 03 00 00 00 90 9B 77 E3  58 73 A5 FD C8 F4 A6 88  ......w.........
// 34 32 30 32 4C 6F 8A 08  C8 E8 D2 1E FC C6 96 BA  4202Lo.......Ɩ .
// 62 BB 59 11 C4 AF 69 D9  A6 14 30 C8 E6 9F A9 3A  b.Y.į i٦ .0....:
// 8C B4 D9 02 00 00 00 00  04 00 00 00 20 00 00 00  ............ ...
// 58 73 A5 FD 44 6C D2 FF  B3 C0 BE 9F C8 F4 A6 88  Xs..Dl..........
// 8C B4 D9 02 00 00 00 00  01 00 00 00 B9 79 37 9E  .............y7.
// 34 32 30 32 C3 12 EB D6  2E F7 1C 9F 46 54 43 4E  4202........FTCN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define RTYPE_chan__4_uint8 0
#define RTYPE_chan_bool 1
#define RTYPE_string 2
#define RTYPE__ptr_string 3
#define RTYPE_main_coroutVM 4
#define main_coroutVM main_coroutVM
#define _QWORD __int64
#define _DWORD unsigned int
#define _WORD unsigned short
#define _BYTE unsigned char

struct string
{
    char *ptr;
    size_t len;
};
void __fastcall main_main()
{
    main_coroutVM *p_main_coroutVM;
    main_coroutVM *v3;
    main_coroutVM *v7;
    main_coroutVM *v15;
    uint8 *mem;
    _QWORD *v17;
    int v18;
    int v19;
    int v20;
    main_coroutVM **v21;
    main_coroutVM *v22;
    _QWORD *v23;
    int v24;
    int v25;
    int v26;
    main_coroutVM **v27;
    main_coroutVM *v28;
    __int64 v29;
    __int64 i;
    char v31;
    unsigned __int64 v32;
    __int64 v33;
    char v34;
    int v35;
    char v36;
    __int64 v38;
    __int64 v39;
    main_coroutVM *v40;
    __int64 v41;
    main_coroutVM *v42;
    __int64 v43;
    size_t len;
    char *ptr;
    _QWORD v46[2], v47[2], v48[2], v49[2], v50[2];
    struct string *p_string;

    v39 = runtime_makechan((unsigned int)&RTYPE_chan__4_uint8, 0);
    v41 = runtime_makechan((unsigned int)&RTYPE_chan__4_uint8, 0);
    v43 = runtime_makechan((unsigned int)&RTYPE_chan_bool, 2);

    printf("Input flag: ");
    scanf("%s", p_string->ptr);
    p_string->len = strlen(p_string->ptr);
    ptr = p_string->ptr;
    len = p_string->len;

    p_main_coroutVM = (main_coroutVM *)runtime_newobject(&RTYPE_main_coroutVM); // ptr, instr v41, checkres v43, instrSet qword_89FFC0
    p_main_coroutVM->instr = v41;
    p_main_coroutVM->checkres = v43;
    p_main_coroutVM->instrSet = (void *)qword_89FFC0;

    v7 = (main_coroutVM *)runtime_newobject(&RTYPE_main_coroutVM); // ptr, instr v39, checkres v43, instrSet qword_89FFC8
    v7->instr = (void *)v39;
    v7->checkres = (void *)v43;
    v7->instrSet = (void *)qword_89FFC8;

    v40 = v7;
    v42 = p_main_coroutVM;

    if (p_string->len != 40)
    {
        printf("Length Error\n");
        return;
    }


    mem = v42->mem;
    runtime_memmove(v42->mem, ptr, 20LL);

    v7 = v40;
    v3 = (main_coroutVM *)((char *)ptr + 20);
    runtime_memmove(v7->mem, ((char *)ptr + 20), 20LL);

    *v17 = main_main_gowrap1;
    v17[1] = v42;
    runtime_newproc((_DWORD)v17, (_DWORD)((char *)ptr + 20), (_DWORD)v42, (_DWORD)mem, (_DWORD)ptr, v18, v19, v20, (_DWORD)v21);

    *v23 = main_main_gowrap2;
    v23[1] = v40;
    runtime_newproc((_DWORD)v23, (_DWORD)((char *)ptr + 20), (_DWORD)v40, (_DWORD)mem, (_DWORD)ptr, v24, v25, v26, (_DWORD)v27);

    for (i = 0LL; i < 0x4BF4; i += 4)
    {
        v35 = 0;
        v33 = i;
        if (&v35 != (int *)((char *)off_898470 + i))
            v35 = *(_DWORD *)((char *)off_898470 + i);
        runtime_chansend1(v41);
        v3 = (main_coroutVM *)&v35;
        runtime_chansend1(v39);
        v29 = v41;
    }

    v34 = 0;
    runtime_chanrecv1(v43, &v34);
    v31 = 0;
    runtime_chanrecv1(v43, &v31);
    if (v31 && v34)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Wrong!\n");
    }
}