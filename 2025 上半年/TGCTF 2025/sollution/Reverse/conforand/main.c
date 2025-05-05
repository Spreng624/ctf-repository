#include <stdio.h>

#define _BYTE unsigned char
#define _QWORD unsigned long long
#define _DWORD unsigned long
#define _WORD unsigned short
#define bool unsigned char
#define LOBYTE(x) ((x))

_DWORD x, x_11;
_DWORD y, y_11, y_12;
int __fastcall main(int argc, const char **argv, const char **envp)
{
    __int64 v3;            // rsi
    __int64 v4;            // rdx
    char v5;               // r14
    char v6;               // r15
    char v7;               // r10
    char v8;               // al
    char v9;               // si
    char v10;              // r10
    char v11;              // al
    bool v12;              // al
    char v13;              // di
    bool v14;              // al
    char v15;              // r8
    int v16;               // eax
    int v17;               // r8d
    char v18;              // r10
    char v19;              // bl
    bool v20;              // al
    char v21;              // r9
    char v22;              // al
    char v23;              // r9
    bool v24;              // al
    char v25;              // al
    char v26;              // cl
    int v27;               // eax
    int v28;               // eax
    int v29;               // eax
    int v30;               // eax
    int v31;               // r8d
    unsigned __int8 v32;   // di
    int v33;               // eax
    int v34;               // r8d
    bool v35;              // r13
    char v36;              // di
    char v37;              // r12
    bool v38;              // di
    char v39;              // r10
    int v40;               // eax
    int v41;               // r8d
    bool v42;              // r12
    char v43;              // di
    char v44;              // r11
    int v45;               // eax
    int v46;               // edi
    char v47;              // r11
    char v48;              // bl
    char v49;              // dl
    int v50;               // eax
    int v51;               // eax
    int v52;               // r8d
    bool v53;              // di
    bool v54;              // r13
    unsigned __int8 v55;   // al
    char v56;              // r9
    char v57;              // di
    int v58;               // eax
    int v59;               // r11d
    unsigned __int8 v60;   // r9
    char v61;              // r8
    char v62;              // al
    bool v63;              // r8
    char v64;              // r13
    char v65;              // r10
    char v66;              // bl
    char v67;              // al
    char v68;              // r8
    char v69;              // r9
    bool v70;              // di
    char v71;              // r9
    char v72;              // r10
    char v73;              // bl
    int v74;               // eax
    int v75;               // eax
    int v76;               // edi
    char v77;              // r9
    bool v78;              // r8
    unsigned __int8 v79;   // al
    bool v80;              // zf
    int v81;               // eax
    int v82;               // r9d
    bool v83;              // r14
    char v84;              // r12
    unsigned __int8 v85;   // al
    bool v86;              // r8
    char v87;              // r10
    char v88;              // al
    char v89;              // al
    bool v90;              // r12
    unsigned __int8 v91;   // r10
    int v92;               // eax
    bool v93;              // di
    char v94;              // r13
    char v95;              // r14
    char v96;              // r14
    char v97;              // bl
    bool v98;              // r12
    char v99;              // r8
    bool v100;             // di
    char v101;             // r10
    bool v102;             // al
    int v103;              // eax
    int v104;              // eax
    int v105;              // r8d
    bool v106;             // r11
    char v107;             // di
    char v108;             // r9
    int v109;              // r8d
    unsigned __int8 v110;  // r14
    char v111;             // r11
    char v112;             // r10
    int v113;              // eax
    int v114;              // r8d
    bool v115;             // r14
    bool v116;             // r14
    char v117;             // di
    bool v118;             // bl
    char v119;             // r11
    bool v120;             // di
    int v121;              // eax
    _QWORD v123[3];        // [rsp+0h] [rbp-1E0h] BYREF
    unsigned int v124;     // [rsp+1Ch] [rbp-1C4h]
    unsigned int v125;     // [rsp+20h] [rbp-1C0h]
    unsigned int v126;     // [rsp+24h] [rbp-1BCh]
    unsigned int v127;     // [rsp+28h] [rbp-1B8h]
    unsigned int v128;     // [rsp+2Ch] [rbp-1B4h]
    int *v129;             // [rsp+30h] [rbp-1B0h]
    _QWORD *v130;          // [rsp+38h] [rbp-1A8h]
    int v131;              // [rsp+40h] [rbp-1A0h]
    int v132;              // [rsp+44h] [rbp-19Ch]
    char v133;             // [rsp+48h] [rbp-198h]
    char v134;             // [rsp+49h] [rbp-197h]
    char v135;             // [rsp+4Ah] [rbp-196h]
    bool v136;             // [rsp+4Bh] [rbp-195h]
    int v137;              // [rsp+4Ch] [rbp-194h]
    char v138;             // [rsp+52h] [rbp-18Eh]
    char v139;             // [rsp+53h] [rbp-18Dh]
    char v140;             // [rsp+54h] [rbp-18Ch]
    bool v141;             // [rsp+55h] [rbp-18Bh]
    char v142;             // [rsp+56h] [rbp-18Ah]
    char v143;             // [rsp+57h] [rbp-189h]
    char v144;             // [rsp+58h] [rbp-188h]
    char v145;             // [rsp+59h] [rbp-187h]
    char v146;             // [rsp+5Ah] [rbp-186h]
    char v147;             // [rsp+5Bh] [rbp-185h]
    int v148;              // [rsp+5Ch] [rbp-184h]
    int v149;              // [rsp+60h] [rbp-180h]
    int v150;              // [rsp+64h] [rbp-17Ch]
    char v151;             // [rsp+6Ah] [rbp-176h]
    char v152;             // [rsp+6Bh] [rbp-175h]
    char v153;             // [rsp+6Ch] [rbp-174h]
    char v154;             // [rsp+6Dh] [rbp-173h]
    char v155;             // [rsp+6Eh] [rbp-172h]
    char v156;             // [rsp+6Fh] [rbp-171h]
    char v157;             // [rsp+70h] [rbp-170h]
    char v158;             // [rsp+71h] [rbp-16Fh]
    char v159;             // [rsp+72h] [rbp-16Eh]
    char v160;             // [rsp+73h] [rbp-16Dh]
    char v161;             // [rsp+74h] [rbp-16Ch]
    char v162;             // [rsp+75h] [rbp-16Bh]
    char v163;             // [rsp+76h] [rbp-16Ah]
    char v164;             // [rsp+77h] [rbp-169h]
    int v165;              // [rsp+78h] [rbp-168h]
    int v166;              // [rsp+7Ch] [rbp-164h]
    int v167;              // [rsp+80h] [rbp-160h]
    int v168;              // [rsp+84h] [rbp-15Ch]
    int v169;              // [rsp+88h] [rbp-158h]
    int v170;              // [rsp+8Ch] [rbp-154h]
    int v171;              // [rsp+90h] [rbp-150h]
    char v172;             // [rsp+97h] [rbp-149h]
    char v173;             // [rsp+98h] [rbp-148h]
    char v174;             // [rsp+99h] [rbp-147h]
    char v175;             // [rsp+9Ah] [rbp-146h]
    bool v176;             // [rsp+9Bh] [rbp-145h]
    char v177;             // [rsp+9Ch] [rbp-144h]
    char v178;             // [rsp+9Dh] [rbp-143h]
    char v179;             // [rsp+9Eh] [rbp-142h]
    char v180;             // [rsp+9Fh] [rbp-141h]
    int v181;              // [rsp+A0h] [rbp-140h]
    char v182;             // [rsp+A7h] [rbp-139h]
    unsigned __int8 v183;  // [rsp+A8h] [rbp-138h]
    bool v184;             // [rsp+A9h] [rbp-137h]
    char v185;             // [rsp+AAh] [rbp-136h]
    char v186;             // [rsp+ABh] [rbp-135h]
    int v187;              // [rsp+ACh] [rbp-134h]
    char v188;             // [rsp+B0h] [rbp-130h]
    unsigned __int8 v189;  // [rsp+B1h] [rbp-12Fh]
    bool v190;             // [rsp+B2h] [rbp-12Eh]
    char v191;             // [rsp+B3h] [rbp-12Dh]
    char v192;             // [rsp+B4h] [rbp-12Ch]
    char v193;             // [rsp+B5h] [rbp-12Bh]
    char v194;             // [rsp+B6h] [rbp-12Ah]
    bool v195;             // [rsp+B7h] [rbp-129h]
    int v196;              // [rsp+B8h] [rbp-128h]
    int v197;              // [rsp+BCh] [rbp-124h]
    int v198;              // [rsp+C0h] [rbp-120h]
    int v199;              // [rsp+C4h] [rbp-11Ch]
    int v200;              // [rsp+C8h] [rbp-118h]
    int v201;              // [rsp+CCh] [rbp-114h]
    int v202;              // [rsp+D0h] [rbp-110h]
    int v203;              // [rsp+D4h] [rbp-10Ch]
    int v204;              // [rsp+D8h] [rbp-108h]
    int v205;              // [rsp+DCh] [rbp-104h]
    int v206;              // [rsp+E0h] [rbp-100h]
    int v207;              // [rsp+E4h] [rbp-FCh]
    int v208;              // [rsp+E8h] [rbp-F8h]
    int v209;              // [rsp+ECh] [rbp-F4h]
    int v210;              // [rsp+F0h] [rbp-F0h]
    int v211;              // [rsp+F4h] [rbp-ECh]
    int v212;              // [rsp+F8h] [rbp-E8h]
    int v213;              // [rsp+FCh] [rbp-E4h]
    int v214;              // [rsp+100h] [rbp-E0h]
    int v215;              // [rsp+104h] [rbp-DCh]
    int v216;              // [rsp+108h] [rbp-D8h]
    int v217;              // [rsp+10Ch] [rbp-D4h]
    int v218;              // [rsp+110h] [rbp-D0h]
    int v219;              // [rsp+114h] [rbp-CCh]
    int v220;              // [rsp+118h] [rbp-C8h]
    int v221;              // [rsp+11Ch] [rbp-C4h]
    int v222;              // [rsp+120h] [rbp-C0h]
    int v223;              // [rsp+124h] [rbp-BCh]
    int v224;              // [rsp+128h] [rbp-B8h]
    int v225;              // [rsp+12Ch] [rbp-B4h]
    int v226;              // [rsp+130h] [rbp-B0h]
    int v227;              // [rsp+134h] [rbp-ACh]
    int v228;              // [rsp+138h] [rbp-A8h]
    int v229;              // [rsp+13Ch] [rbp-A4h]
    int v230;              // [rsp+140h] [rbp-A0h]
    int v231;              // [rsp+144h] [rbp-9Ch]
    int v232;              // [rsp+148h] [rbp-98h]
    int v233;              // [rsp+14Ch] [rbp-94h]
    int v234;              // [rsp+150h] [rbp-90h]
    int v235;              // [rsp+154h] [rbp-8Ch]
    int v236;              // [rsp+158h] [rbp-88h]
    unsigned __int8 v237;  // [rsp+15Eh] [rbp-82h]
    bool v238;             // [rsp+15Fh] [rbp-81h]
    _DWORD *v239;          // [rsp+160h] [rbp-80h]
    _QWORD *v240;          // [rsp+168h] [rbp-78h]
    char *v241;            // [rsp+170h] [rbp-70h]
    int *v242;             // [rsp+178h] [rbp-68h]
    _QWORD *v243;          // [rsp+180h] [rbp-60h]
    int v244;              // [rsp+18Ch] [rbp-54h]
    unsigned __int64 v245; // [rsp+190h] [rbp-50h]
    bool v246;             // [rsp+19Fh] [rbp-41h]
    char *v247;            // [rsp+1A0h] [rbp-40h]
    char v248;             // [rsp+1ABh] [rbp-35h]
    unsigned int v249;     // [rsp+1ACh] [rbp-34h]
    unsigned int v250;     // [rsp+1B0h] [rbp-30h]
    int v251;              // [rsp+1B4h] [rbp-2Ch]

    v3 = (unsigned int)y_12;
    v4 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
    v237 = (_DWORD)v4 == 0;
    v238 = y_12 < 10;
    v236 = 2063125205;
    while (1)
    {
        while (1)
        {
            while (1)
            {
                while (1)
                {
                    while (1)
                    {
                        while (1)
                        {
                            while (1)
                            {
                                while (1)
                                {
                                    while (1)
                                    {
                                        while (1)
                                        {
                                            while (1)
                                            {
                                                while (1)
                                                {
                                                    while (1)
                                                    {
                                                        while (1)
                                                        {
                                                            while (1)
                                                            {
                                                                while (1)
                                                                {
                                                                    while (1)
                                                                    {
                                                                        while (1)
                                                                        {
                                                                            while (1)
                                                                            {
                                                                                while (1)
                                                                                {
                                                                                    while (1)
                                                                                    {
                                                                                        while (1)
                                                                                        {
                                                                                            while (1)
                                                                                            {
                                                                                                while (1)
                                                                                                {
                                                                                                    while (1)
                                                                                                    {
                                                                                                        while (1)
                                                                                                        {
                                                                                                            while (1)
                                                                                                            {
                                                                                                                while (1)
                                                                                                                {
                                                                                                                    while (1)
                                                                                                                    {
                                                                                                                        while (1)
                                                                                                                        {
                                                                                                                            while (1)
                                                                                                                            {
                                                                                                                                while (1)
                                                                                                                                {
                                                                                                                                    while (1)
                                                                                                                                    {
                                                                                                                                        while (1)
                                                                                                                                        {
                                                                                                                                            while (1)
                                                                                                                                            {
                                                                                                                                                v235 = v236;
                                                                                                                                                v234 = v236 + 2107129647;
                                                                                                                                                if (v236 != -2107129647)
                                                                                                                                                    break;
                                                                                                                                                v30 = -1135137198;
                                                                                                                                                v3 = 1LL;
                                                                                                                                                v31 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                                                                                                                v32 = ((y_12 >= 10 && v31 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v31 != 0) ^ (y_12 < 10))) != 0) | (~(y_12 >= 10 && v31 == 0) ^ ~((y_12 < 10) & (~(v31 != 0) ^ (y_12 < 10)))) & 1) ^ (v31 == 0 && y_12 >= 10 != (v31 == 0));
                                                                                                                                                LOBYTE(v3) = v32 ^ (((y_12 >= 10 && v31 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v31 != 0) ^ (y_12 < 10))) != 0) | ((unsigned __int8)~(y_12 >= 10 && v31 == 0) ^ (unsigned __int8)~((y_12 < 10) & (~(v31 != 0) ^ (y_12 < 10)))) & 1) != 0 && v31 == 0 && y_12 >= 10 != (v31 == 0));
                                                                                                                                                LOBYTE(v4) = v3 | v32 & (((y_12 >= 10 && v31 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v31 != 0) ^ (y_12 < 10))) != 0) | ((unsigned __int8)~(y_12 >= 10 && v31 == 0) ^ (unsigned __int8)~((y_12 < 10) & (~(v31 != 0) ^ (y_12 < 10)))) & 1) != 0 && v31 == 0 && y_12 >= 10 != (v31 == 0));
                                                                                                                                                if (v3 & 1 | v32 & (((y_12 >= 10 && v31 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v31 != 0) ^ (y_12 < 10))) != 0) | ((unsigned __int8)~(y_12 >= 10 && v31 == 0) ^ (unsigned __int8)~((y_12 < 10) & (~(v31 != 0) ^ (y_12 < 10)))) & 1) != 0 && v31 == 0 && y_12 >= 10 != (v31 == 0)))
                                                                                                                                                    v30 = 475160657;
                                                                                                                                                v236 = v30;
                                                                                                                                            }
                                                                                                                                            v233 = v235 + 1992124853;
                                                                                                                                            if (v235 != -1992124853)
                                                                                                                                                break;
                                                                                                                                            v250 = *v242;
                                                                                                                                            v3 = (unsigned int)(x_11 - 1);
                                                                                                                                            v82 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                                                                                                            v83 = v82 == 0;
                                                                                                                                            LOBYTE(v82) = v82 != 0;
                                                                                                                                            v148 = -484395982;
                                                                                                                                            v147 = (((y_12 < 10) & ((y_12 < 10) ^ 0xFE)) == 0) ^ 0xFE;
                                                                                                                                            v146 = 0;
                                                                                                                                            v84 = ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) == 0) & ~((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) == 0);
                                                                                                                                            v145 = 0;
                                                                                                                                            v144 = 0;
                                                                                                                                            v143 = 0;
                                                                                                                                            v142 = 0;
                                                                                                                                            v141 = y_12 >= 10;
                                                                                                                                            v85 = ~(~(y_12 >= 10) & (v84 ^ ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0) | v84 & ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0)) | ~(v84 ^ ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0) | v84 & ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0)) & (y_12 >= 10));
                                                                                                                                            v86 = !((((((y_12 >= 10) ^ ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0) | (y_12 >= 10 && (((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0)) != 0) | v85 & 1) == 0) | ((unsigned __int8)~(((y_12 >= 10) ^ ((((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0) | (y_12 >= 10 && (((v147 & 1) == 0) | ((unsigned __int8)~((v147 & 1) == 0) ^ 0xFE) & 1) != 0)) == 0) ^ v85) & 1);
                                                                                                                                            v87 = ~v147 & v82 | ~(_BYTE)v82 & v147;
                                                                                                                                            v88 = v87 ^ v82 & (~v147 ^ v82) | v87 & v82 & (~v147 ^ v82);
                                                                                                                                            v140 = v88 & ~v88 ^ ((v88 & 1) == 0) | v88 & ~v88 & ((v88 & 1) == 0);
                                                                                                                                            v139 = 0;
                                                                                                                                            v138 = 0;
                                                                                                                                            v89 = ((unsigned __int8)~v86 & !v83 | (unsigned __int8)~!v83 & v86) == 0;
                                                                                                                                            v90 = ((unsigned __int8)~v86 & !v83 | (unsigned __int8)~!v83 & v86) != 0;
                                                                                                                                            v91 = ~((((((v140 & 1) != 0) & (((v140 & 1) != 0) ^ 0xFE)) == 0 && (v89 & 1) != 0) | ((unsigned __int8)~((((v140 & 1) != 0) & (((v140 & 1) != 0) ^ 0xFE)) == 0) ^ (unsigned __int8)~v89) & 1) == 0);
                                                                                                                                            LOBYTE(v3) = 0;
                                                                                                                                            LOBYTE(v4) = 1;
                                                                                                                                            v92 = -484395982;
                                                                                                                                            if (((v91 & 1 | (((((((v140 & 1) != 0) & (((v140 & 1) != 0) ^ 0xFE)) != 0) ^ v90) & 1) == 0)) == 0) | (v91 ^ (unsigned __int8)~(((((v140 & 1) != 0) & (((v140 & 1) != 0) ^ 0xFE)) != 0) ^ v90)) & 1)
                                                                                                                                                v92 = -631219671;
                                                                                                                                            v236 = v92;
                                                                                                                                        }
                                                                                                                                        v232 = v235 + 1912028916;
                                                                                                                                        if (v235 != -1912028916)
                                                                                                                                            break;
                                                                                                                                        LOBYTE(v4) = 1;
                                                                                                                                        v3 = 1LL;
                                                                                                                                        v109 = (((_BYTE)x_11 - 6 + 5) * (_BYTE)x_11) & 1;
                                                                                                                                        v110 = ((y_12 >= 10) ^ (v109 != 0) | (y_12 >= 10 && v109 != 0)) == 0;
                                                                                                                                        v111 = ((unsigned __int8)~((y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) & (y_12 >= 10)) & ((unsigned __int8)~(v109 != 0) ^ 1) & 1 | (unsigned __int8)~((~(v109 != 0) ^ 1) & 1) & ((y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) & (y_12 >= 10))) == 0;
                                                                                                                                        v132 = 1282747590;
                                                                                                                                        v112 = ((v110 & (unsigned __int8)~v110 & 1) != 0 && !(v110 & 1)) | v110 & ~v110 & 1 ^ !(v110 & 1);
                                                                                                                                        LOBYTE(v109) = ~v111 & v112 | ~v112 & v111;
                                                                                                                                        LOBYTE(v3) = (((v111 & 1) != 0 && !(v110 & 1)) | ((unsigned __int8)~v111 ^ (unsigned __int8)~!(v110 & 1)) & 1) == 0;
                                                                                                                                        v113 = 1282747590;
                                                                                                                                        if (((((v111 & 1) != 0 && !(v110 & 1)) | ((unsigned __int8)~v111 ^ (unsigned __int8)~!(v110 & 1)) & 1) == 0 && (v109 & 1) != 0) | (unsigned __int8)(v3 ^ v109 & 1))
                                                                                                                                            v113 = 48635079;
                                                                                                                                        v236 = v113;
                                                                                                                                    }
                                                                                                                                    v231 = v235 + 1903219903;
                                                                                                                                    if (v235 != -1903219903)
                                                                                                                                        break;
                                                                                                                                    v236 = 635195153;
                                                                                                                                }
                                                                                                                                v230 = v235 + 1750281581;
                                                                                                                                if (v235 != -1750281581)
                                                                                                                                    break;
                                                                                                                                v4 = v250;
                                                                                                                                v3 = v250;
                                                                                                                                v236 = 977246770;
                                                                                                                                v128 = v250;
                                                                                                                                v127 = v250;
                                                                                                                                v126 = v250;
                                                                                                                                v125 = v250;
                                                                                                                                v124 = v250;
                                                                                                                            }
                                                                                                                            v229 = v235 + 1746552021;
                                                                                                                            if (v235 != -1746552021)
                                                                                                                                break;
                                                                                                                            v3 = 0LL;
                                                                                                                            v4 = ~(~(v248 | ~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) | (~v248 & 0xE8692D02 | v248 & 0x1796D2FD) ^ (~(~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0xE8692D02 | (~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0x1796D2FD));
                                                                                                                            v249 = ~(~(v248 | ~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) | (~v248 & 0xE8692D02 | v248 & 0x1796D2FD) ^ (~(~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0xE8692D02 | (~(~v248 | 0xFFFFFF00 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00)) | (~(~v248 | 0xFFFFFF00) & 0xCCCF735B | ~v248 & 0xA4 | 0x33308C00) ^ ((v248 ^ 0xFFFFFF00) & 0xCCCF7300 | ~((v248 ^ 0xFFFFFF00) & 0xFFFFFF00) & 0x33308CA4)) & 0x1796D2FD));
                                                                                                                            v236 = 1567410093;
                                                                                                                        }
                                                                                                                        v228 = v235 + 1524645074;
                                                                                                                        if (v235 != -1524645074)
                                                                                                                            break;
                                                                                                                        v236 = 1366452227;
                                                                                                                    }
                                                                                                                    v227 = v235 + 1494641013;
                                                                                                                    if (v235 != -1494641013)
                                                                                                                        break;
                                                                                                                    v236 = 955426707;
                                                                                                                }
                                                                                                                v226 = v235 + 1387909944;
                                                                                                                if (v235 != -1387909944)
                                                                                                                    break;
                                                                                                                v236 = 1611828785;
                                                                                                            }
                                                                                                            v225 = v235 + 1332896369;
                                                                                                            if (v235 != -1332896369)
                                                                                                                break;
                                                                                                            v245 = v244;
                                                                                                            v236 = 1872920811;
                                                                                                        }
                                                                                                        v224 = v235 + 1135137198;
                                                                                                        if (v235 != -1135137198)
                                                                                                            break;
                                                                                                        v236 = 475160657;
                                                                                                        v130 = v240;
                                                                                                    }
                                                                                                    v223 = v235 + 1066141244;
                                                                                                    if (v235 != -1066141244)
                                                                                                        break;
                                                                                                    v236 = 1503558591;
                                                                                                }
                                                                                                v222 = v235 + 1027831003;
                                                                                                if (v235 != -1027831003)
                                                                                                    break;
                                                                                                v236 = 1663306798;
                                                                                                v123[2] = v242;
                                                                                                v123[1] = v240;
                                                                                            }
                                                                                            v221 = v235 + 825629503;
                                                                                            if (v235 != -825629503)
                                                                                                break;
                                                                                            v236 = 444411832;
                                                                                        }
                                                                                        v220 = v235 + 631219671;
                                                                                        if (v235 != -631219671)
                                                                                            break;
                                                                                        v236 = 2097689902;
                                                                                    }
                                                                                    v219 = v235 + 484395982;
                                                                                    if (v235 != -484395982)
                                                                                        break;
                                                                                    v236 = -1992124853;
                                                                                    v129 = v242;
                                                                                }
                                                                                v218 = v235 + 167809242;
                                                                                if (v235 != -167809242)
                                                                                    break;
                                                                                LOBYTE(v4) = 1;
                                                                                v3 = 3566509057LL;
                                                                                v76 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                                                LOBYTE(v3) = !((y_12 >= 10 && v76 != 0) | (y_12 >= 10) ^ (v76 != 0));
                                                                                v77 = (v76 == 0) & (~(y_12 >= 10) ^ (v76 == 0));
                                                                                LOBYTE(v76) = v77 ^ (v76 != 0 && y_12 < 10) | v77 & (v76 != 0 && y_12 < 10);
                                                                                v78 = (v3 & 1) == 0;
                                                                                v149 = -484395982;
                                                                                LOBYTE(v3) = ~(v76 & (v76 ^ 0xFE)) & ((v3 & 1) != 0) | ~((v3 & 1) != 0) & v76 & (v76 ^ 0xFE);
                                                                                LOBYTE(v76) = !((((v76 & 1) == 0) ^ v78) & 1 | ((v76 & 1) == 0 && v78));
                                                                                v79 = v76 & v3;
                                                                                LOBYTE(v3) = v76 ^ v3;
                                                                                v80 = (((unsigned __int8)v3 | v79) & 1) == 0;
                                                                                v81 = -484395982;
                                                                                if (!v80)
                                                                                    v81 = -1992124853;
                                                                                v236 = v81;
                                                                            }
                                                                            v217 = v235 - 48635079;
                                                                            if (v235 != 48635079)
                                                                                break;
                                                                            LOBYTE(v4) = 1;
                                                                            *v242 = v251;
                                                                            v114 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                                            v115 = v114 == 0;
                                                                            v3 = y_12 < 10;
                                                                            LOBYTE(v3) = ((y_12 >= 10 && v114 != 0) | ((unsigned __int8)~(y_12 >= 10) ^ (unsigned __int8)~(v114 != 0)) & 1) == 0;
                                                                            LOBYTE(v114) = (y_12 < 10) & (~(v114 != 0) ^ (y_12 < 10));
                                                                            v116 = y_12 >= 10 && v115;
                                                                            v117 = v116 ^ v114 | v116 & v114;
                                                                            v131 = 1282747590;
                                                                            v118 = (v3 & 1) == 0;
                                                                            v119 = (v117 & ~v117 ^ ((v117 & 1) == 0)) & 1 | v117 & ~v117 & ((v117 & 1) == 0);
                                                                            v120 = (((v117 & 1) == 0) ^ v118 | ((v117 & 1) == 0 && v118)) == 0;
                                                                            LOBYTE(v3) = v120 ^ v119 ^ v118;
                                                                            v121 = 1282747590;
                                                                            if ((((unsigned __int8)v3 | v120 & (unsigned __int8)(v119 ^ v118)) & 1) != 0)
                                                                                v121 = 1067352764;
                                                                            v236 = v121;
                                                                        }
                                                                        v216 = v235 - 276231395;
                                                                        if (v235 != 276231395)
                                                                            break;
                                                                        v51 = 1723233988;
                                                                        LOBYTE(v4) = v246;
                                                                        if (v246)
                                                                            v51 = 1297083923;
                                                                        v236 = v51;
                                                                    }
                                                                    v215 = v235 - 444411832;
                                                                    if (v235 != 444411832)
                                                                        break;
                                                                    v239 = &v123[-2];
                                                                    v3 = (unsigned int)(x_11 - 1);
                                                                    v17 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                                    v187 = -825629503;
                                                                    v186 = -1;
                                                                    v185 = 1;
                                                                    v184 = v17 != 0;
                                                                    v183 = ((y_12 < 10) & 0xFE | (y_12 >= 10)) & (~(y_12 < 10) ^ ((y_12 < 10) & 0xFE | (y_12 >= 10)));
                                                                    v182 = -1;
                                                                    v181 = -1524645074;
                                                                    v180 = 0;
                                                                    v179 = 1;
                                                                    v178 = 0;
                                                                    v177 = 0;
                                                                    v176 = v17 == 0;
                                                                    v175 = 0;
                                                                    v18 = (((v17 == 0) | ((unsigned __int8)~(v17 == 0) ^ 0xFE) & 1) == 0) & ((((v17 == 0) | ((unsigned __int8)~(v17 == 0) ^ 0xFE) & 1) == 0) ^ 0xFE);
                                                                    v174 = ((unsigned __int8)~(y_12 < 10) & (unsigned __int8)(~(y_12 >= 10) ^ ~(y_12 < 10)) & 1) == 0;
                                                                    v173 = 0;
                                                                    v172 = 0;
                                                                    v19 = ~(((v183 & (unsigned __int8)~v183) != 0 && v183 == 0) | v183 & ~v183 ^ (v183 == 0)) & v174 | ~v174 & (((v183 & (unsigned __int8)~v183) != 0 && v183 == 0) | v183 & ~v183 ^ (v183 == 0));
                                                                    v20 = ((v183 == 0 && ((unsigned __int8)~(y_12 < 10) & (unsigned __int8)(~(y_12 >= 10) ^ ~(y_12 < 10)) & 1) == 0) | ((unsigned __int8)~(v183 == 0) ^ (unsigned __int8)~v174) & 1) == 0;
                                                                    v21 = v20 ^ v19 | v20 & v19;
                                                                    v22 = ~((((unsigned __int8)(v18 ^ (v17 != 0) ^ 0xFE) | v18 & ((v17 != 0) ^ 0xFE)) & 1) == 0) ^ 1;
                                                                    v23 = ~(v21 & ~v21 ^ ((v21 & 1) == 0) | v21 & ~v21 & ((v21 & 1) == 0)) & v22 & 1 | ~(v22 & 1) & (v21 & ~v21 ^ ((v21 & 1) == 0) | v21 & ~v21 & ((v21 & 1) == 0));
                                                                    v24 = ((y_12 < 10 && v17 == 0) | ((unsigned __int8)~(y_12 < 10) ^ (unsigned __int8)~(v17 == 0)) & 1) == 0;
                                                                    v25 = ~(((v24 && (((unsigned __int8)~(y_12 >= 10) ^ (v17 == 0)) & 1) != 0) | v24 ^ ((unsigned __int8)~(y_12 >= 10) ^ (v17 == 0)) & 1) == 0) ^ 1;
                                                                    v26 = v23 & (~((v25 & 1) != 0) ^ v23);
                                                                    LOBYTE(v3) = (v25 & 1) != 0;
                                                                    LOBYTE(v4) = v3 ^ v23 & 1 ^ v26 | (v3 ^ v23 & 1) & v26;
                                                                    v27 = -825629503;
                                                                    if ((v4 & 1) != 0)
                                                                        v27 = -1524645074;
                                                                    v236 = v27;
                                                                }
                                                                v214 = v235 - 475160657;
                                                                if (v235 != 475160657)
                                                                    break;
                                                                v33 = -1135137198;
                                                                LOBYTE(v4) = 1;
                                                                v243 = v240;
                                                                v3 = 1275940352LL;
                                                                v34 = (((_BYTE)x_11 - 115 + 114) * (_BYTE)x_11) & 1;
                                                                v35 = v34 == 0 && ((unsigned __int8)~(y_12 >= 10) & (v34 == 0) | (unsigned __int8)~(v34 == 0) & (y_12 >= 10)) != 0;
                                                                v36 = v34 != 0 && y_12 < 10;
                                                                LOBYTE(v34) = (v34 == 0) & (~(y_12 >= 10) ^ (v34 == 0));
                                                                v37 = ((v34 & 1) != 0 && (v36 & 1) != 0) | ~(_BYTE)v34 ^ ~v36;
                                                                v38 = (((v34 & 1) != 0 && (v36 & 1) != 0) | ((unsigned __int8)~(_BYTE)v34 ^ (unsigned __int8)~v36) & 1) == 0;
                                                                v39 = (v37 & ~v37 ^ v38 | v37 & ~v37 & v38) & 1 ^ !v35;
                                                                LOBYTE(v3) = ((v38 && !v35) | v38 ^ !v35) == 0;
                                                                if ((((v38 && !v35) | v38 ^ !v35) == 0 && (v39 & 1) != 0) | (unsigned __int8)(v3 ^ v39 & 1))
                                                                    v33 = 1645281787;
                                                                v236 = v33;
                                                            }
                                                            v213 = v235 - 635195153;
                                                            if (v235 != 635195153)
                                                                break;
                                                            v244 = *v242;
                                                            v236 = -1332896369;
                                                        }
                                                        v212 = v235 - 955426707;
                                                        if (v235 != 955426707)
                                                            break;
                                                        v45 = -1494641013;
                                                        v3 = (unsigned int)(1123613118 - (309949526 - x_11) - 813663593);
                                                        v46 = ((-66 - (86 - (_BYTE)x_11) - 105) * (_BYTE)x_11) & 1;
                                                        v47 = v46 != 0 || (((unsigned __int8)~(y_12 >= 10) ^ (v46 != 0)) & 1) == 0;
                                                        v48 = ((y_12 >= 10 && v46 == 0) ^ (y_12 < 10) & (unsigned __int8)(~(v46 != 0) ^ (y_12 < 10)) | (y_12 >= 10 && v46 == 0) & (y_12 < 10) & (unsigned __int8)(~(v46 != 0) ^ (y_12 < 10))) == 0;
                                                        LOBYTE(v3) = ~v48 ^ (v46 == 0 && (((unsigned __int8)~(y_12 >= 10) ^ (v46 != 0)) & 1) != 0);
                                                        LOBYTE(v46) = (((v48 & 1) != 0 && (v47 & 1) != 0) | ((unsigned __int8)~v48 ^ (unsigned __int8)~v47) & 1) == 0;
                                                        v49 = v46 & v3;
                                                        LOBYTE(v3) = v46 ^ v3;
                                                        LOBYTE(v4) = v3 | v49;
                                                        if ((v4 & 1) != 0)
                                                            v45 = -1066141244;
                                                        v236 = v45;
                                                    }
                                                    v211 = v235 - 977246770;
                                                    if (v235 != 977246770)
                                                        break;
                                                    v104 = -1750281581;
                                                    v251 = v250 - 981133022 + 981133023;
                                                    v3 = (unsigned int)(x_11 - 1);
                                                    v105 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                                    v106 = v105 == 0;
                                                    LOBYTE(v3) = !((y_12 >= 10 && v105 != 0) | (y_12 >= 10) ^ (v105 != 0));
                                                    LOBYTE(v105) = (y_12 < 10) & (~(v105 != 0) ^ (y_12 < 10));
                                                    v107 = v106 & (~(y_12 >= 10) ^ v106) ^ v105 | v106 & (~(y_12 >= 10) ^ v106) & v105;
                                                    LOBYTE(v105) = (v107 & 1) != 0 && (v3 & 1) != 0;
                                                    v108 = ~(_BYTE)v3 & v107;
                                                    LOBYTE(v3) = ~v107 & v3;
                                                    LOBYTE(v4) = (v3 | v108) ^ v105 | (v3 | v108) & v105;
                                                    if ((v4 & 1) != 0)
                                                        v104 = 1475621906;
                                                    v236 = v104;
                                                }
                                                v210 = v235 - 1067352764;
                                                if (v235 != 1067352764)
                                                    break;
                                                v236 = -1903219903;
                                            }
                                            v209 = v235 - 1282747590;
                                            if (v235 != 1282747590)
                                                break;
                                            *v242 = v251;
                                            v236 = 48635079;
                                        }
                                        v208 = v235 - 1297083923;
                                        if (v235 != 1297083923)
                                            break;
                                        LOBYTE(v4) = 1;
                                        v3 = (unsigned int)(x_11 - 1);
                                        v52 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                                        LOBYTE(v3) = ((unsigned __int8)(~(y_12 >= 10) ^ (v52 != 0)) & (unsigned __int8)(~(v52 == 0) ^ ~(y_12 >= 10) ^ (v52 != 0)) & 1) == 0;
                                        v53 = !((y_12 >= 10 && v52 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v52 != 0) ^ (y_12 < 10))) != 0) | ((unsigned __int8)~(y_12 >= 10 && v52 == 0) ^ (unsigned __int8)~((y_12 < 10) & (~(v52 != 0) ^ (y_12 < 10)))) & 1);
                                        v54 = ((y_12 >= 10 && v52 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v52 != 0) ^ (y_12 < 10))) != 0) | ((unsigned __int8)~(y_12 >= 10 && v52 == 0) ^ (unsigned __int8)~((y_12 < 10) & (~(v52 != 0) ^ (y_12 < 10)))) & 1) != 0;
                                        v166 = -1027831003;
                                        v55 = ~(((unsigned __int8)(~(y_12 >= 10) ^ (v52 != 0)) & (unsigned __int8)(~(v52 == 0) ^ ~(y_12 >= 10) ^ (v52 != 0)) & 1) != 0);
                                        v56 = ~(v54 ^ (v53 && !v53) | (v54 && v53 && !v53)) ^ ((((v55 & 1 | (((unsigned __int8)v3 & ((unsigned __int8)v3 ^ 1) & 1) == 0)) == 0) | (v55 ^ (unsigned __int8)~(v3 & (v3 ^ 1))) & 1) == 0);
                                        LOBYTE(v3) = !(((unsigned __int8)(v53 ^ v3) | v53 & (unsigned __int8)v3) & 1);
                                        v57 = v3 & (v3 ^ 0xFE);
                                        LOBYTE(v3) = ~v57;
                                        v58 = -1027831003;
                                        if (((v57 & 1) != 0 && (v56 & 1) != 0) | v57 & 1 ^ v56 & 1)
                                            v58 = 1663306798;
                                        v236 = v58;
                                    }
                                    v207 = v235 - 1366452227;
                                    if (v235 != 1366452227)
                                        break;
                                    v240 = &v123[-6];
                                    v241 = (char *)&v123[-2];
                                    v242 = (int *)&v123[-2];
                                    *v239 = 0;
                                    // init(v241, (const char *)v3, v4);
                                    v171 = printf("Welcome to HZNUCTF!!!\n");
                                    v170 = printf("%s", v241);
                                    v28 = printf("Plz input the flag:\n");
                                    v3 = (__int64)v240;
                                    v169 = v28;
                                    v29 = scanf("%s", v240);
                                    v236 = -2107129647;
                                    v168 = v29;
                                }
                                v206 = v235 - 1475621906;
                                if (v235 != 1475621906)
                                    break;
                                v236 = -1912028916;
                            }
                            v205 = v235 - 1503558591;
                            if (v235 != 1503558591)
                                break;
                            v3 = 42LL;
                            // v50 = rc4((__int64)v243, 0x2AuLL, (__int64)v241, 9LL);
                            *v242 = 0;
                            v236 = 635195153;
                            v167 = v50;
                        }
                        v204 = v235 - 1567410093;
                        if (v235 != 1567410093)
                            break;
                        v3 = v249;
                        v75 = printf("%x ", v249);
                        v236 = -167809242;
                        v150 = v75;
                    }
                    v203 = v235 - 1611828785;
                    if (v235 != 1611828785)
                        break;
                    v248 = *v247;
                    v236 = -1746552021;
                }
                v202 = v235 - 1645281787;
                if (v235 != 1645281787)
                    break;
                v40 = -1494641013;
                v3 = 1LL;
                v41 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
                LOBYTE(v3) = !((y_12 >= 10) ^ (v41 != 0) | (y_12 >= 10 && v41 != 0)) & (!((y_12 >= 10) ^ (v41 != 0) | (y_12 >= 10 && v41 != 0)) ^ 0xFE);
                v42 = y_12 >= 10 && v41 == 0;
                v43 = v3 & (~((y_12 >= 10 && v41 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v41 != 0) ^ (y_12 < 10))) != 0) | v42 ^ (y_12 < 10) & (~(v41 != 0) ^ (y_12 < 10))) ^ v3);
                LOBYTE(v3) = ~((y_12 >= 10 && v41 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v41 != 0) ^ (y_12 < 10))) != 0) | v42 ^ (y_12 < 10) & (~(v41 != 0) ^ (y_12 < 10))) & v3;
                v44 = v3 | ~(!((y_12 >= 10) ^ (v41 != 0) | (y_12 >= 10 && v41 != 0)) & (!((y_12 >= 10) ^ (v41 != 0) | (y_12 >= 10 && v41 != 0)) ^ 0xFE)) & ((y_12 >= 10 && v41 == 0 && ((y_12 < 10) & (unsigned __int8)(~(v41 != 0) ^ (y_12 < 10))) != 0) | v42 ^ (y_12 < 10) & (~(v41 != 0) ^ (y_12 < 10)));
                LOBYTE(v4) = v44 ^ v43 | v44 & v43;
                if ((v4 & 1) != 0)
                    v40 = 955426707;
                v236 = v40;
            }
            v201 = v235 - 1663306798;
            if (v235 != 1663306798)
                break;
            v247 = (char *)v240 + *v242;
            v59 = (((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1;
            v60 = ~(v59 != 0) ^ 1;
            v3 = y_12 < 10;
            v165 = -1027831003;
            LOBYTE(v3) = ((v59 == 0) & 0xFE | (v59 != 0)) & (~(v59 == 0) ^ ((v59 == 0) & 0xFE | (v59 != 0)));
            v164 = -2;
            v163 = 0;
            v162 = 0;
            LOBYTE(v59) = (_BYTE)v3 == 0;
            v161 = (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0;
            v160 = v3 & ~(_BYTE)v3;
            v159 = 0;
            v158 = ~v161;
            v157 = ~(v60 & (~v60 ^ v60) & ~(v60 & (~v60 ^ v60)));
            v156 = ~v161;
            v61 = ((((v59 & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | ((unsigned __int8)~(_BYTE)v59 ^ (unsigned __int8)~v161) & 1) == 0) & (((((v59 & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | ((unsigned __int8)~(_BYTE)v59 ^ (unsigned __int8)~v161) & 1) == 0) ^ 0xFE);
            v62 = v61 ^ (~(v160 ^ v59 | v160 & v59) & ((((unsigned __int8)(v60 & (~v60 ^ v60)) & (unsigned __int8)~(v60 & (~v60 ^ v60)) & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | v157 ^ ~v161) | ~((((unsigned __int8)(v60 & (~v60 ^ v60)) & (unsigned __int8)~(v60 & (~v60 ^ v60)) & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | v157 ^ ~v161) & (v160 ^ v59 | v160 & v59)) | v61 & (~(v160 ^ v59 | v160 & v59) & ((((unsigned __int8)(v60 & (~v60 ^ v60)) & (unsigned __int8)~(v60 & (~v60 ^ v60)) & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | v157 ^ ~v161) | ~((((unsigned __int8)(v60 & (~v60 ^ v60)) & (unsigned __int8)~(v60 & (~v60 ^ v60)) & 1) != 0 && (v60 & (unsigned __int8)(~v60 ^ v60) & 1) == 0) | v157 ^ ~v161) & (v160 ^ v59 | v160 & v59));
            v63 = !((y_12 >= 10 && y_12 < 10) & ((y_12 >= 10 && y_12 < 10) ^ 0xFE));
            v64 = (y_12 >= 10 && y_12 < 10) & ((y_12 >= 10 && y_12 < 10) ^ 0xFE) & ~((y_12 >= 10 && y_12 < 10) & ((y_12 >= 10 && y_12 < 10) ^ 0xFE));
            v65 = ~(((unsigned __int8)~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (unsigned __int8)(~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0)) & 1) == 0);
            v155 = v62;
            v154 = 0;
            v153 = v65;
            v152 = ~(~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0)) & ~(~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0))));
            v66 = ((v64 ^ v63) & 1 | v64 & v63) ^ ((((((unsigned __int8)(~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0))) & (unsigned __int8)~(~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0))) & 1) == 0) | v65 & 1) == 0) | (v152 ^ v65) & 1);
            LOBYTE(v3) = ((v63 ^ (((unsigned __int8)~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (unsigned __int8)(~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0)) & 1) == 0)) & 1 | (v63 && ((unsigned __int8)~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0) & (unsigned __int8)(~((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & ~(y_12 < 10) ^ (y_12 >= 10)) ^ ~(((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0)) & 1) == 0)) == 0;
            v67 = v3 & (v3 ^ 0xFE) ^ v66 | v3 & (v3 ^ 0xFE) & v66;
            LOBYTE(v3) = !(v60 & 1);
            v68 = ((((y_12 < 10) & (unsigned __int8)~(y_12 < 10)) != 0 && y_12 >= 10) | (y_12 < 10) & (unsigned __int8)~(y_12 < 10) ^ (y_12 >= 10)) == 0;
            v151 = ((v67 & 1) != 0) ^ ((v155 & 1) != 0);
            v69 = ~v68 & (((v60 & (unsigned __int8)~v60 & 1) != 0 && (_BYTE)v3 != 0) | ~(v60 & ~v60) ^ ~(_BYTE)v3) | ~(((v60 & (unsigned __int8)~v60 & 1) != 0 && (_BYTE)v3 != 0) | ~(v60 & ~v60) ^ ~(_BYTE)v3) & v68;
            LOBYTE(v3) = (((unsigned __int8)(v68 ^ v3) | (unsigned __int8)(v68 & v3)) & 1) == 0;
            LOBYTE(v3) = ~((((unsigned __int8)(v3 ^ v69) | (unsigned __int8)(v3 & v69)) & 1) == 0) ^ 1;
            v70 = (v3 & 1) != 0;
            LOBYTE(v3) = (v3 & 1) == 0;
            v71 = v70 ^ v3 & (v3 ^ 1) | v70 & v3 & (v3 ^ 1);
            v72 = ~v71 & ((v151 & 1) != 0) | ~((v151 & 1) != 0) & v71;
            v73 = ((v3 & 1) != 0 && v151 == 0) | (~(_BYTE)v3 ^ ~(v151 == 0)) & 1;
            LOBYTE(v4) = -2;
            LOBYTE(v3) = (v73 ^ 1) & ~v73;
            v74 = -1027831003;
            if ((((unsigned __int8)(v3 ^ v72) | (unsigned __int8)(v3 & v72)) & 1) != 0)
                v74 = -1387909944;
            v236 = v74;
        }
        v200 = v235 - 1723233988;
        if (v235 == 1723233988)
            break;
        v199 = v235 - 1872920811;
        if (v235 == 1872920811)
        {
            v246 = v245 < 0x2A;
            v236 = 276231395;
        }
        else
        {
            v198 = v235 - 2063125205;
            if (v235 == 2063125205)
            {
                v5 = ((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ~(v237 & ~v237) ^ ~(~!(v237 & 1) ^ 1);
                v196 = -825629503;
                v195 = !(((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ((unsigned __int8)~(v237 & ~v237) ^ (unsigned __int8)~(~!(v237 & 1) ^ 1)) & 1);
                v194 = 0;
                v193 = (v237 & 0xFE | ((v237 & 1) == 0)) & (~v237 ^ (v237 & 0xFE | ((v237 & 1) == 0)));
                v192 = 0;
                v191 = 0;
                v190 = v238;
                v189 = !v238;
                v6 = ((v193 & 1) != ((((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ((unsigned __int8)~(v237 & ~v237) ^ (unsigned __int8)~(~!(v237 & 1) ^ 1)) & 1) != 0) && (v193 & 1) != 0 && (((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ((unsigned __int8)~(v237 & ~v237) ^ (unsigned __int8)~(~!(v237 & 1) ^ 1)) & 1) != 0) | ~(v193 & 1 ^ ((((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ((unsigned __int8)~(v237 & ~v237) ^ (unsigned __int8)~(~!(v237 & 1) ^ 1)) & 1) != 0)) ^ ~((v193 & 1) != 0 && (((v237 & (unsigned __int8)~v237 & 1) != 0 && (((unsigned __int8)~!(v237 & 1) ^ 1) & 1) != 0) | ((unsigned __int8)~(v237 & ~v237) ^ (unsigned __int8)~(~!(v237 & 1) ^ 1)) & 1) != 0);
                v7 = ~((v189 | ((unsigned __int8)~v189 ^ 0xFE) & 1) == 0) & v189 | ~v189 & ((v189 | ((unsigned __int8)~v189 ^ 0xFE) & 1) == 0);
                v8 = v7 ^ v189 & (~((v189 | ((unsigned __int8)~v189 ^ 0xFE) & 1) == 0) ^ v189) | v7 & v189 & (~((v189 | ((unsigned __int8)~v189 ^ 0xFE) & 1) == 0) ^ v189);
                v9 = ~(v8 & (v8 ^ 0xFE) & 1) & v6 & (v6 ^ 0xFE) & 1 | ~(v6 & (v6 ^ 0xFE) & 1) & v8 & (v8 ^ 0xFE) & 1;
                v10 = ~v189 & v5 | ~v5 & v189;
                v11 = v10 ^ v5 & (~v189 ^ v5) | v10 & v5 & (~v189 ^ v5);
                v188 = 0;
                v12 = (((unsigned __int8)(v11 & ~v11 ^ ~((v11 & 1) == 0) ^ 1) | v11 & ~v11 & ((unsigned __int8)~((v11 & 1) == 0) ^ 1)) & 1) == 0;
                v13 = !v12;
                v14 = !v12 && (v9 & 1) != 0;
                v15 = ~v9 & v13;
                LOBYTE(v3) = ~v13 & v9;
                LOBYTE(v4) = (v3 | v15) ^ v14 | (v3 | v15) & v14;
                v16 = -825629503;
                if ((v4 & 1) != 0)
                    v16 = 444411832;
                v236 = v16;
            }
            else
            {
                v197 = v235 - 2097689902;
                if (v235 == 2097689902)
                {
                    v3 = (unsigned int)(x_11 - 1);
                    v93 = ((((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1) != 0;
                    v137 = -1750281581;
                    LOBYTE(v3) = y_12 < 10 || y_12 >= 10;
                    v94 = ((((unsigned __int8)~(y_12 >= 10) ^ 1) & 1) != 0) & ~((((unsigned __int8)~(y_12 >= 10) ^ 1) & 1) != 0);
                    v136 = (((unsigned __int8)~(y_12 >= 10) ^ 1) & 1) == 0;
                    v95 = (y_12 >= 10 && y_12 < 10) & ~(y_12 >= 10 && y_12 < 10);
                    v96 = ~(v95 ^ v3 | v95 & v3) & (v94 ^ v136 | v94 & v136) | ~(v94 ^ v136 | v94 & v136) & (v95 ^ v3 | v95 & v3);
                    LOBYTE(v3) = !(((unsigned __int8)v3 ^ v136) & 1 | (unsigned __int8)v3 & v136);
                    v97 = ((v3 & 1) != 0 && (v96 & 1) != 0) | ~(_BYTE)v3 ^ ~v96;
                    LOBYTE(v3) = (v93 & (v93 ^ 0xFE)) == 0 && (((v3 & 1) != 0 && (v96 & 1) != 0) | ((unsigned __int8)~(_BYTE)v3 ^ (unsigned __int8)~v96) & 1) != 0;
                    v98 = (v97 & 1) == 0 && (v93 & (v93 ^ 0xFE)) != 0;
                    v135 = v98 ^ v3 | v98 & v3;
                    v134 = 0;
                    v133 = 0;
                    v99 = ~((~(y_12 >= 10) ^ 1) & (y_12 >= 10)) ^ (((((_BYTE)x_11 - 1) * (_BYTE)x_11) & 1) == 0);
                    LOBYTE(v3) = ((v136 ^ !v93) & 1 | (v136 && !v93)) == 0;
                    v100 = (((unsigned __int8)(v3 ^ v99) | (unsigned __int8)(v3 & v99)) & 1) != 0;
                    v101 = ~v100 & ((v135 & 1) == 0) | ~((v135 & 1) == 0) & v100;
                    LOBYTE(v3) = 0;
                    v102 = ((v100 ^ ((v135 & 1) == 0)) & 1 | (v100 && (v135 & 1) == 0)) == 0;
                    LOBYTE(v4) = v102 ^ v101 | v102 & v101;
                    v103 = -1750281581;
                    if ((v4 & 1) != 0)
                        v103 = 977246770;
                    v236 = v103;
                }
            }
        }
    }
    return 0;
}