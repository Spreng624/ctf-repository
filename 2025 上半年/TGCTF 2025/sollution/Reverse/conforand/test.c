#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define __int64 long long
#define _DWORD unsigned int
#define _BYTE unsigned char

#define LOBYTE(x) ((x))

unsigned int x_7, x_9, y_8, y_10;

int main()
{
    int v4;                 // eax
    int v5;                 // edi
    char v6;                // r14
    int v7;                 // eax
    int v8;                 // ecx
    int v9;                 // r10d
    unsigned __int8 v10;    // r9
    unsigned __int8 v11;    // bl
    char v12;               // si
    char v13;               // r13
    char v14;               // di
    char v15;               // r11
    unsigned __int8 v16;    // r11
    int v17;                // edi
    bool v18;               // r11
    char v19;               // r8
    char v20;               // r11
    char v21;               // r14
    char v22;               // r11
    int v23;                // eax
    int v24;                // r9d
    bool v25;               // r14
    unsigned __int8 v26;    // r10
    char v27;               // di
    char v28;               // r15
    char v29;               // al
    char v30;               // di
    char v31;               // r11
    char v32;               // cl
    char v33;               // r10
    char v34;               // di
    bool v35;               // al
    bool v36;               // zf
    int v37;                // eax
    int v38;                // r8d
    bool v39;               // r11
    char v40;               // r9
    char v41;               // si
    char v42;               // r9
    bool v43;               // al
    int v44;                // eax
    int v45;                // edi
    char v46;               // si
    char v47;               // r12
    int v48;                // eax
    int v49;                // eax
    int v50;                // r9d
    int v51;                // edi
    char v52;               // r8
    char v53;               // cl
    unsigned __int8 v54;    // si
    unsigned __int8 v55;    // r8
    bool v56;               // r8
    char v57;               // al
    int v58;                // eax
    int v59;                // edx
    char v60;               // si
    char v61;               // r15
    char v62;               // di
    int v63;                // r9d
    int v64;                // esi
    int v65;                // ecx
    char v66;               // dl
    unsigned int v67;       // esi
    int v68;                // r10d
    int v69;                // edi
    char v70;               // r13
    char v71;               // r13
    char v72;               // r12
    char v73;               // dl
    unsigned int v74;       // ecx
    char v75;               // bl
    char v76;               // r13
    char v77;               // r14
    char v78;               // r9
    char v79;               // r9
    char v80;               // r14
    char v81;               // r15
    char v82;               // r9
    char v83;               // r14
    char v84;               // dl
    char v85;               // r8
    char v86;               // dl
    int v87;                // eax
    int v88;                // r8d
    char v89;               // di
    bool v90;               // si
    char v91;               // r12
    bool v92;               // di
    char v93;               // r15
    bool v94;               // si
    int v95;                // eax
    int v96;                // r8d
    unsigned __int8 v97;    // di
    int v98;                // eax
    int v99;                // r8d
    bool v100;              // r15
    char v101;              // r14
    char v102;              // si
    int v103;               // edi
    bool v104;              // r15
    char v105;              // si
    char v106;              // r13
    char v107;              // r8
    bool v108;              // si
    unsigned __int8 v109;   // r9
    bool v110;              // si
    int v111;               // eax
    int v113;               // ecx
    int v114;               // esi
    int v115;               // edi
    int v116;               // r8d
    int v117;               // r9d
    int v118;               // r10d
    int v119;               // r11d
    int inited;             // eax
    _DWORD v121[4];         // [rsp+0h] [rbp-340h] BYREF
    int *v122;              // [rsp+10h] [rbp-330h]
    int v123;               // [rsp+1Ch] [rbp-324h]
    int v124;               // [rsp+20h] [rbp-320h]
    int v125;               // [rsp+24h] [rbp-31Ch]
    int v126;               // [rsp+28h] [rbp-318h]
    int v127;               // [rsp+2Ch] [rbp-314h]
    int v128;               // [rsp+30h] [rbp-310h]
    int v129;               // [rsp+34h] [rbp-30Ch]
    int v130;               // [rsp+38h] [rbp-308h]
    int v131;               // [rsp+3Ch] [rbp-304h]
    int v132;               // [rsp+40h] [rbp-300h]
    unsigned int v133;      // [rsp+44h] [rbp-2FCh]
    int v134;               // [rsp+48h] [rbp-2F8h]
    char v135;              // [rsp+4Fh] [rbp-2F1h]
    int v136;               // [rsp+50h] [rbp-2F0h]
    char v137;              // [rsp+56h] [rbp-2EAh]
    bool v138;              // [rsp+57h] [rbp-2E9h]
    int v139;               // [rsp+58h] [rbp-2E8h]
    char v140;              // [rsp+5Ch] [rbp-2E4h]
    bool v141;              // [rsp+5Dh] [rbp-2E3h]
    char v142;              // [rsp+5Eh] [rbp-2E2h]
    bool v143;              // [rsp+5Fh] [rbp-2E1h]
    char v144;              // [rsp+60h] [rbp-2E0h]
    bool v145;              // [rsp+61h] [rbp-2DFh]
    char v146;              // [rsp+62h] [rbp-2DEh]
    char v147;              // [rsp+63h] [rbp-2DDh]
    int v148;               // [rsp+64h] [rbp-2DCh]
    int v149;               // [rsp+68h] [rbp-2D8h]
    int v150;               // [rsp+6Ch] [rbp-2D4h]
    int v151;               // [rsp+70h] [rbp-2D0h]
    char v152;              // [rsp+75h] [rbp-2CBh]
    char v153;              // [rsp+76h] [rbp-2CAh]
    unsigned __int8 v154;   // [rsp+77h] [rbp-2C9h]
    char v155;              // [rsp+78h] [rbp-2C8h]
    char v156;              // [rsp+79h] [rbp-2C7h]
    char v157;              // [rsp+7Ah] [rbp-2C6h]
    char v158;              // [rsp+7Bh] [rbp-2C5h]
    char v159;              // [rsp+7Ch] [rbp-2C4h]
    char v160;              // [rsp+7Dh] [rbp-2C3h]
    char v161;              // [rsp+7Eh] [rbp-2C2h]
    unsigned __int8 v162;   // [rsp+7Fh] [rbp-2C1h]
    int v163;               // [rsp+80h] [rbp-2C0h]
    char v164;              // [rsp+85h] [rbp-2BBh]
    char v165;              // [rsp+86h] [rbp-2BAh]
    char v166;              // [rsp+87h] [rbp-2B9h]
    unsigned __int8 v167;   // [rsp+88h] [rbp-2B8h]
    char v168;              // [rsp+89h] [rbp-2B7h]
    char v169;              // [rsp+8Ah] [rbp-2B6h]
    char v170;              // [rsp+8Bh] [rbp-2B5h]
    int v171;               // [rsp+8Ch] [rbp-2B4h]
    int v172;               // [rsp+90h] [rbp-2B0h]
    char v173;              // [rsp+97h] [rbp-2A9h]
    char v174;              // [rsp+98h] [rbp-2A8h]
    char v175;              // [rsp+99h] [rbp-2A7h]
    char v176;              // [rsp+9Ah] [rbp-2A6h]
    char v177;              // [rsp+9Bh] [rbp-2A5h]
    char v178;              // [rsp+9Ch] [rbp-2A4h]
    char v179;              // [rsp+9Dh] [rbp-2A3h]
    char v180;              // [rsp+9Eh] [rbp-2A2h]
    bool v181;              // [rsp+9Fh] [rbp-2A1h]
    char v182;              // [rsp+A0h] [rbp-2A0h]
    char v183;              // [rsp+A1h] [rbp-29Fh]
    char v184;              // [rsp+A2h] [rbp-29Eh]
    char v185;              // [rsp+A3h] [rbp-29Dh]
    bool v186;              // [rsp+A4h] [rbp-29Ch]
    char v187;              // [rsp+A5h] [rbp-29Bh]
    char v188;              // [rsp+A6h] [rbp-29Ah]
    char v189;              // [rsp+A7h] [rbp-299h]
    int v190;               // [rsp+A8h] [rbp-298h]
    int v191;               // [rsp+ACh] [rbp-294h]
    int v192;               // [rsp+B0h] [rbp-290h]
    int v193;               // [rsp+B4h] [rbp-28Ch]
    int v194;               // [rsp+B8h] [rbp-288h]
    int v195;               // [rsp+BCh] [rbp-284h]
    int v196;               // [rsp+C0h] [rbp-280h]
    int v197;               // [rsp+C4h] [rbp-27Ch]
    int v198;               // [rsp+C8h] [rbp-278h]
    int v199;               // [rsp+CCh] [rbp-274h]
    int v200;               // [rsp+D0h] [rbp-270h]
    int v201;               // [rsp+D4h] [rbp-26Ch]
    int v202;               // [rsp+D8h] [rbp-268h]
    int v203;               // [rsp+DCh] [rbp-264h]
    int v204;               // [rsp+E0h] [rbp-260h]
    int v205;               // [rsp+E4h] [rbp-25Ch]
    int v206;               // [rsp+E8h] [rbp-258h]
    int v207;               // [rsp+ECh] [rbp-254h]
    int v208;               // [rsp+F0h] [rbp-250h]
    int v209;               // [rsp+F4h] [rbp-24Ch]
    int v210;               // [rsp+F8h] [rbp-248h]
    int v211;               // [rsp+FCh] [rbp-244h]
    int v212;               // [rsp+100h] [rbp-240h]
    int v213;               // [rsp+104h] [rbp-23Ch]
    int v214;               // [rsp+108h] [rbp-238h]
    int v215;               // [rsp+10Ch] [rbp-234h]
    int v216;               // [rsp+110h] [rbp-230h]
    int v217;               // [rsp+114h] [rbp-22Ch]
    int v218;               // [rsp+118h] [rbp-228h]
    int v219;               // [rsp+11Ch] [rbp-224h]
    int v220;               // [rsp+120h] [rbp-220h]
    int v221;               // [rsp+124h] [rbp-21Ch]
    int v222;               // [rsp+128h] [rbp-218h]
    int v223;               // [rsp+12Ch] [rbp-214h]
    int v224;               // [rsp+130h] [rbp-210h]
    int v225;               // [rsp+134h] [rbp-20Ch]
    __int64 v226;           // [rsp+138h] [rbp-208h]
    __int64 v227;           // [rsp+140h] [rbp-200h]
    unsigned __int64 v228;  // [rsp+148h] [rbp-1F8h]
    __int64 v229;           // [rsp+150h] [rbp-1F0h]
    int v230;               // [rsp+15Ch] [rbp-1E4h]
    _BYTE v231[312];        // [rsp+160h] [rbp-1E0h] BYREF
    __int64 v232;           // [rsp+298h] [rbp-A8h]
    __int64 v233;           // [rsp+2A0h] [rbp-A0h]
    unsigned __int64 v234;  // [rsp+2A8h] [rbp-98h]
    __int64 v235;           // [rsp+2B0h] [rbp-90h]
    int *v236;              // [rsp+2B8h] [rbp-88h]
    int *v237;              // [rsp+2C0h] [rbp-80h]
    int *v238;              // [rsp+2C8h] [rbp-78h]
    unsigned __int64 *v239; // [rsp+2D0h] [rbp-70h]
    _BYTE *v240;            // [rsp+2D8h] [rbp-68h]
    __int64 v241;           // [rsp+2E0h] [rbp-60h]
    unsigned __int64 v242;  // [rsp+2E8h] [rbp-58h]
    unsigned __int64 v243;  // [rsp+2F0h] [rbp-50h]
    bool v244;              // [rsp+2FBh] [rbp-45h]
    int v245;               // [rsp+2FCh] [rbp-44h]
    _BYTE *v246;            // [rsp+300h] [rbp-40h]
    unsigned __int64 v247;  // [rsp+308h] [rbp-38h]
    unsigned __int64 v248;  // [rsp+310h] [rbp-30h]
    unsigned char a = 0x14;
    unsigned char b = 0x87;

    // printf("%x\n", ~a | ~b & a);
    // printf("%x\n", ~(a & b));

    // a = 1;
    // b = 1;
    // printf("%x\n", ~a | ~b & a);

    // a = 1;
    // b = 0;
    // printf("%x\n", ~a | ~b & a);

    // a = 0;
    // b = 1;
    // printf("%x\n", ~a | ~b & a);

    // a = 0;
    // b = 0;
    // printf("%x\n", ~a | ~b & a);

    // unsigned char v67 = 0x00, v66 = 0xff;
    // printf("%x\n", v66 & ~v66 ^ (~v66 | ~v66) | v66 & ~v66 & (~v66 | ~v66));

    unsigned char flag;
    // unsigned int v248 = 0x87654321;
    // unsigned int v249 = ~(~(v248 | ~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) | (~v248 & 0xE8692D02 | v248 & 0x1796D2FD) ^ (~(~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0xE8692D02 | (~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0x1796D2FD));
    // printf("%x\n", v249);

    // v64 = (unsigned __int8)v231[*v237] + (unsigned __int8)v231[*v236];
    // *v238 = v64 % 257;
    // v66 = v231[*v238];

    v66 = 0x12;
    flag = 0x47;

    v134 = -1;
    v65 = flag;

    v67 = (v134 ^ 0x7E050B95 | ~v134 & 0x7E050B95) ^ ((v134 ^ 0x7E050B95) & ((v134 ^ 0xD7FABE8 | 0xD7FABE8) & ~(~(v65 & ~v65) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581))) | ((v134 ^ 0xD7FABE8) & v65 & ~v65 | ~(v65 & ~v65) & 0xD7FABE8) ^ ((v134 ^ 0xD7FABE8) & ((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) & 0xD7FABE8)) | ~((v134 ^ 0xD7FABE8 | 0xD7FABE8) & ~(~(v65 & ~v65) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581))) | ((v134 ^ 0xD7FABE8) & v65 & ~v65 | ~(v65 & ~v65) & 0xD7FABE8) ^ ((v134 ^ 0xD7FABE8) & ((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) & 0xD7FABE8)) & 0x7E050B95);
    v68 = ~v67 & 0x5F51A4D1 | (v134 ^ 0x5F51A4D1) & v67;
    v69 = v68 & (v134 ^ 0x5F51A4D1 ^ v68);
    LOBYTE(v67) = ~(_BYTE)v134 & v65 | ~flag;

    v70 = ((v134 ^ 0xFA) & ((v134 ^ 0x56 | ~(_BYTE)v134 & 0x56) ^ ((v134 ^ 0x56) & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) & 0x56)) | ~((v134 ^ 0x56 | ~(_BYTE)v134 & 0x56) ^ ((v134 ^ 0x56) & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) & 0x56)) & 0xFA) ^ ((v134 ^ 0xFA) & v67 | ~(_BYTE)v67 & 0xFA);
    v71 = (v134 ^ 0xFA | 0xFA) & ~(~((v134 ^ 0x56 | ~(_BYTE)v134 & 0x56) ^ ((v134 ^ 0x56) & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) & 0x56)) | ~(_BYTE)v67) | v70;
    LOBYTE(v67) = v66 & ~v66 ^ (~(_BYTE)v134 & v66 | ~v66) | v66 & ~v66 & (~(_BYTE)v134 & v66 | ~v66);
    LOBYTE(v68) = (v134 ^ 0x92 | 0x92) & ~(~(_BYTE)v67 | ~(((v134 ^ 0xD2) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xD2) ^ ((v134 ^ 0xD2) & v67 | ~(_BYTE)v67 & 0xD2)));
    LOBYTE(v65) = (v134 ^ 0xA8 | ~(_BYTE)v134 & 0xA8) ^ ((v134 ^ 0xA8) & v66 | ~v66 & 0xA8);
    v72 = (v134 ^ 0xA1 | 0xA1) & ~(~(~(_BYTE)v134 & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA)) | ~(_BYTE)v65) | ((v134 ^ 0xA1) & (~(_BYTE)v134 & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA)) | ~(~(_BYTE)v134 & (((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA) | ~(((v134 ^ 0xEA) & (~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) | ~(~(_BYTE)v134 & 0xD1 | v134 ^ 0xD1) & 0xEA) ^ 0xEA)) & 0xA1) ^ ((v134 ^ 0xA1) & v65 | ~(_BYTE)v65 & 0xA1);
    v73 = (v134 ^ 0x98 | 0x98) & ~(~((~(_BYTE)v134 & 0xD0 | v134 ^ 0xD0) ^ 0xD0 | ~(_BYTE)v134 & 0xD0 | (v134 ^ 0xD0) & 0xD0) | ~(~(_BYTE)v134 & v72 | ~v72));
    v74 = (v134 ^ 0xB3272901 | ~v134 & 0xB3272901) ^ ((v134 ^ 0xB3272901) & v69 | ~v69 & 0xB3272901);
    LOBYTE(v67) = ~(_BYTE)v134 & (~(_BYTE)v134 & v71 | ~v71) & (~((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D) ^ 0x2E | ((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D)) & 0x2E) ^ (~(_BYTE)v134 & v71 | ~v71)) | ~((~(_BYTE)v134 & v71 | ~v71) & (~((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D) ^ 0x2E | ((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D)) & 0x2E) ^ (~(_BYTE)v134 & v71 | ~v71)));
    v75 = (v134 ^ 0x4D | 0x4D) & ~(v134 ^ 0x11 | ~((v134 ^ 1 | ((v134 & 1) == 0)) ^ ((v134 ^ 1) & v69 | ((v69 & 1) == 0))));
    LOBYTE(v69) = (v134 ^ 0x7E | 0x7E) & ~(~((v134 ^ 0xF3 | ~(_BYTE)v134 & 0xF3) ^ ((v134 ^ 0xF3) & 0x11 | (v134 ^ 0x11) & 0xF3)) | ~(_BYTE)v69);
    v76 = (~(_BYTE)v134 & v71 | ~v71) & (~((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D) ^ 0x2E | ((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D)) & 0x2E) ^ (~(_BYTE)v134 & v71 | ~v71)) & (~((v134 ^ 0xF3 | ~(_BYTE)v134 & 0xF3) ^ ((v134 ^ 0xF3) & 0x11 | (v134 ^ 0x11) & 0xF3)) ^ (~(_BYTE)v134 & v71 | ~v71) & (~((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D) ^ 0x2E | ((v134 ^ 0x8D | ~(_BYTE)v134 & 0x8D) ^ ((v134 ^ 0x8D) & 0x2E | (v134 ^ 0x2E) & 0x8D)) & 0x2E) ^ (~(_BYTE)v134 & v71 | ~v71)));
    v133 = v74;
    v77 = (v134 ^ 0xF0 | 0xF0) & ~(~(_BYTE)v69 | ~v75) | ((v134 ^ 0xF0) & v69 | ~(_BYTE)v69 & 0xF0) ^ ((v134 ^ 0xF0) & v75 | ~v75 & 0xF0);
    v78 = (v134 ^ 0xAB | 0xAB) & ~(~v76 | ~(v67 & (v134 ^ 0x11 ^ v67))) | ((v134 ^ 0xAB) & v76 | ~v76 & 0xAB) ^ ((v134 ^ 0xAB) & v67 & (v134 ^ 0x11 ^ v67) | ~(v67 & (v134 ^ 0x11 ^ v67)) & 0xAB);
    LOBYTE(v67) = (v134 ^ 0x5B | 0x5B) & ~(~((v134 ^ 0xD4 | 0xD4) & ~(~((v134 ^ 0xF3 | ~(_BYTE)v134 & 0xF3) ^ ((v134 ^ 0xF3) & 0x11 | (v134 ^ 0x11) & 0xF3)) | v134 ^ 0x11) | ((v134 ^ 0xD4) & ((v134 ^ 0xF3 | ~(_BYTE)v134 & 0xF3) ^ ((v134 ^ 0xF3) & 0x11 | (v134 ^ 0x11) & 0xF3)) | ~((v134 ^ 0xF3 | ~(_BYTE)v134 & 0xF3) ^ ((v134 ^ 0xF3) & 0x11 | (v134 ^ 0x11) & 0xF3)) & 0xD4) ^ ((v134 ^ 0xD4) & 0x11 | (v134 ^ 0x11) & 0xD4)) | ~(~(_BYTE)v134 & (v67 ^ v133 | v67 & v133) | ~(v67 ^ v133 | v67 & v133)));
    LOBYTE(v69) = v67 ^ ((v134 ^ 0x52) & v78 | ~v78 & 0x52) ^ ((v134 ^ 0x52) & v77 | ~v77 & 0x52) | v67 & (((v134 ^ 0x52) & v78 | ~v78 & 0x52) ^ ((v134 ^ 0x52) & v77 | ~v77 & 0x52));
    LOBYTE(v74) = (v134 ^ 0x4D | ~(_BYTE)v134 & 0x4D) ^ ((v134 ^ 0x4D) & v68 | ~(_BYTE)v68 & 0x4D);
    LOBYTE(v67) = ~(_BYTE)v134 & v73 | ~v73;
    LOBYTE(v68) = (v134 ^ 0xD9 | 0xD9) & ~(~((v134 ^ 0x92 | ~(_BYTE)v134 & 0x92) ^ ((v134 ^ 0x92) & 0x4F | (v134 ^ 0x4F) & 0x92)) | ~(_BYTE)v68);
    v79 = (v134 ^ 0x48 | 0x48) & ~(v134 ^ 0x4F | ~(_BYTE)v67);
    v80 = v73 & (~((v134 ^ 0x92 | ~(_BYTE)v134 & 0x92) ^ ((v134 ^ 0x92) & 0x4F | (v134 ^ 0x4F) & 0x92)) ^ v73);
    v81 = (v134 ^ 0x9C | 0x9C) & ~(~v80 | ~v79) | ((v134 ^ 0x9C) & v80 | ~v80 & 0x9C) ^ ((v134 ^ 0x9C) & v79 | ~v79 & 0x9C);
    v82 = ((v134 ^ 0xEF) & v81 | ~v81 & 0xEF) ^ ((v134 ^ 0xEF) & (v68 ^ v74 & (v134 ^ 0x4F ^ v74) | v68 & v74 & (v134 ^ 0x4F ^ v74)) | ~(v68 ^ v74 & (v134 ^ 0x4F ^ v74) | v68 & v74 & (v134 ^ 0x4F ^ v74)) & 0xEF);
    v83 = (v134 ^ 0x65) & v67 | ~(_BYTE)v67 & 0x65;
    LOBYTE(v74) = ~(_BYTE)v134 & ((v134 ^ 0x65 | 0x65) & ~(~(_BYTE)v67 | ~(_BYTE)v74) | v83 ^ ((v134 ^ 0x65) & v74 | ~(_BYTE)v74 & 0x65)) | ~((v134 ^ 0x65 | 0x65) & ~(~(_BYTE)v67 | ~(_BYTE)v74) | v83 ^ ((v134 ^ 0x65) & v74 | ~(_BYTE)v74 & 0x65));
    LOBYTE(v67) = v74 & (~((v134 ^ 0x92 | ~(_BYTE)v134 & 0x92) ^ ((v134 ^ 0x92) & 0x4F | (v134 ^ 0x4F) & 0x92) ^ 0x4F | ((v134 ^ 0x92 | ~(_BYTE)v134 & 0x92) ^ ((v134 ^ 0x92) & 0x4F | (v134 ^ 0x4F) & 0x92)) & 0x4F) ^ v74);
    LOBYTE(v68) = (v134 ^ 0xDC | 0xDC) & ~(~(_BYTE)v67 | ~v82) | ((v134 ^ 0xDC) & v67 | ~(_BYTE)v67 & 0xDC) ^ ((v134 ^ 0xDC) & v82 | ~v82 & 0xDC);
    v84 = (v134 ^ 0x77 | 0x77) & ~(~(~(_BYTE)v134 & v69 | ~(_BYTE)v69) | v134 ^ 0x30);
    LOBYTE(v69) = (v134 ^ 0x4A | 0x4A) & ~(~(~(_BYTE)v134 & 0x30 | v134 ^ 0x30) | ~(_BYTE)v69);
    LOBYTE(v67) = ~((v134 ^ 0x61 | ~(_BYTE)v134 & 0x61) ^ ((v134 ^ 0x61) & v68 | ~(_BYTE)v68 & 0x61));
    v85 = v68 & (~(~(_BYTE)v134 & 0x30 | v134 ^ 0x30) ^ v68);
    LOBYTE(v74) = v69 ^ v84 | v69 & v84;
    v86 = v85 ^ (v134 ^ 0x8C | 0x8C) & ~(v134 ^ 0x30 | v67) | v85 & (v134 ^ 0x8C | 0x8C) & ~(v134 ^ 0x30 | v67);
    flag = ~v86 & v74 | ~(_BYTE)v74 & v86;

    printf("%x\n", flag);

    return 0;
}