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
__int64 __fastcall init_sbox(__int64 a1, __int64 a2)
{
    unsigned __int8 v2;   // r9
    unsigned __int8 v3;   // r14
    bool v4;              // al
    bool v5;              // di
    char v6;              // si
    char v7;              // r9
    unsigned __int8 v8;   // di
    char v9;              // r12
    unsigned __int8 v10;  // r14
    char v11;             // r14
    char v12;             // al
    bool v13;             // si
    unsigned __int8 v14;  // di
    int v15;              // eax
    int v16;              // r8d
    bool v17;             // bl
    bool v18;             // al
    char v19;             // r10
    char v20;             // al
    char v21;             // r10
    char v22;             // r9
    char v23;             // bl
    unsigned __int8 v24;  // r15
    unsigned __int8 v25;  // cl
    char v26;             // al
    bool v27;             // si
    bool v28;             // al
    bool v29;             // cl
    char v30;             // r9
    bool v31;             // si
    char v32;             // r15
    unsigned __int8 v33;  // r9
    bool v34;             // al
    bool v35;             // zf
    int v36;              // eax
    int v37;              // edi
    bool v38;             // si
    char v39;             // al
    char v40;             // bl
    unsigned __int8 v41;  // si
    char v42;             // r11
    bool v43;             // al
    char v44;             // si
    unsigned __int8 v45;  // r10
    int v46;              // eax
    int v47;              // r9d
    bool v48;             // di
    bool v49;             // r8
    unsigned __int8 v50;  // cl
    unsigned __int8 v51;  // al
    char v52;             // si
    int v53;              // eax
    int v54;              // r11d
    bool v55;             // di
    char v56;             // si
    char v57;             // r15
    char v58;             // r8
    char v59;             // bl
    char v60;             // r9
    unsigned __int8 v61;  // al
    bool v62;             // r8
    char v63;             // r8
    bool v64;             // di
    int v65;              // eax
    char v66;             // r8
    char v67;             // al
    char v68;             // bl
    char v69;             // r10
    unsigned __int8 v70;  // r10
    char v71;             // r15
    char v72;             // r10
    char v73;             // al
    char v74;             // di
    char v75;             // al
    char v76;             // si
    char v77;             // al
    char v78;             // r8
    char v79;             // r8
    int v80;              // eax
    int v81;              // r8d
    char v82;             // r10
    unsigned __int8 v83;  // r9
    unsigned __int8 v84;  // r10
    char v85;             // r12
    bool v86;             // r9
    unsigned __int8 v87;  // r13
    char v88;             // al
    bool v89;             // r9
    char v90;             // bl
    char v91;             // r9
    char v92;             // r10
    char v93;             // al
    char v94;             // r10
    unsigned __int8 v95;  // di
    char v96;             // r9
    unsigned __int8 v97;  // al
    int v98;              // eax
    int v99;              // r8d
    char v100;            // r10
    char v101;            // al
    char v102;            // si
    char v103;            // r11
    unsigned __int8 v104; // r15
    unsigned __int8 v105; // r10
    bool v106;            // di
    char v107;            // si
    char v108;            // di
    int v109;             // eax
    int v110;             // eax
    int v111;             // edi
    bool v112;            // r11
    char v113;            // si
    unsigned __int8 v114; // r15
    char v115;            // r14
    char v116;            // r9
    int v117;             // eax
    unsigned __int8 v118; // r8
    char v119;            // di
    char v120;            // r8
    char v121;            // r11
    bool v122;            // si
    int v123;             // eax
    __int64 v124;         // rcx
    int v125;             // edi
    char v126;            // r8
    char v127;            // di
    char v128;            // bl
    char v129;            // cl
    char v130;            // r8
    char v131;            // dl
    char v132;            // cl
    int v133;             // r8d
    char v134;            // di
    char v135;            // r11
    char v136;            // r9
    unsigned __int8 v137; // al
    unsigned __int8 v138; // r9
    char v139;            // r12
    bool v140;            // r9
    bool v141;            // r9
    unsigned __int8 v142; // r9
    char v143;            // r15
    char v144;            // r10
    char v145;            // al
    bool v146;            // r10
    char v147;            // r13
    char v148;            // r15
    bool v149;            // r10
    char v150;            // di
    char v151;            // al
    char v152;            // r9
    int v153;             // eax
    int v154;             // edi
    char v155;            // r15
    char v156;            // si
    char v157;            // bl
    char v158;            // al
    char v159;            // r11
    char v160;            // cl
    char v161;            // al
    char v162;            // r11
    bool v163;            // cl
    unsigned __int8 v164; // bl
    bool v165;            // al
    bool v166;            // si
    bool v167;            // cl
    char v168;            // bl
    char v169;            // si
    unsigned __int8 v170; // r10
    bool v171;            // al
    int v172;             // eax
    int v173;             // eax
    int v174;             // esi
    int v175;             // r8d
    bool v176;            // bl
    bool v177;            // r10
    char v178;            // bl
    unsigned __int8 v179; // r11
    char v180;            // si
    bool v181;            // r10
    bool v182;            // cl
    char v183;            // r15
    char v184;            // r10
    bool v185;            // cl
    bool v186;            // di
    char v187;            // cl
    bool v188;            // si
    char v189;            // r14
    unsigned __int8 v190; // r9
    bool v191;            // al
    int v192;             // eax
    int v193;             // r8d
    bool v194;            // r15
    char v195;            // di
    unsigned __int8 v196; // al
    unsigned __int8 v197; // di
    char v198;            // bl
    char v199;            // r10
    char v200;            // r14
    unsigned __int8 v201; // r15
    unsigned __int8 v202; // di
    char v203;            // di
    char v204;            // r11
    bool v205;            // al
    char v206;            // dl
    int v207;             // eax
    _DWORD v209[4];       // [rsp+0h] [rbp-290h] BYREF
    int *v210;            // [rsp+10h] [rbp-280h]
    int v211;             // [rsp+1Ch] [rbp-274h]
    char v212;            // [rsp+22h] [rbp-26Eh]
    char v213;            // [rsp+23h] [rbp-26Dh]
    bool v214;            // [rsp+24h] [rbp-26Ch]
    char v215;            // [rsp+25h] [rbp-26Bh]
    char v216;            // [rsp+26h] [rbp-26Ah]
    unsigned __int8 v217; // [rsp+27h] [rbp-269h]
    char v218;            // [rsp+28h] [rbp-268h]
    char v219;            // [rsp+29h] [rbp-267h]
    char v220;            // [rsp+2Ah] [rbp-266h]
    bool v221;            // [rsp+2Bh] [rbp-265h]
    char v222;            // [rsp+2Ch] [rbp-264h]
    char v223;            // [rsp+2Dh] [rbp-263h]
    bool v224;            // [rsp+2Eh] [rbp-262h]
    bool v225;            // [rsp+2Fh] [rbp-261h]
    char v226;            // [rsp+30h] [rbp-260h]
    char v227;            // [rsp+31h] [rbp-25Fh]
    char v228;            // [rsp+32h] [rbp-25Eh]
    char v229;            // [rsp+33h] [rbp-25Dh]
    char v230;            // [rsp+34h] [rbp-25Ch]
    char v231;            // [rsp+35h] [rbp-25Bh]
    char v232;            // [rsp+36h] [rbp-25Ah]
    char v233;            // [rsp+37h] [rbp-259h]
    int v234;             // [rsp+38h] [rbp-258h]
    unsigned __int8 v235; // [rsp+3Eh] [rbp-252h]
    bool v236;            // [rsp+3Fh] [rbp-251h]
    int v237;             // [rsp+40h] [rbp-250h]
    char v238;            // [rsp+45h] [rbp-24Bh]
    bool v239;            // [rsp+46h] [rbp-24Ah]
    char v240;            // [rsp+47h] [rbp-249h]
    bool v241;            // [rsp+48h] [rbp-248h]
    char v242;            // [rsp+49h] [rbp-247h]
    char v243;            // [rsp+4Ah] [rbp-246h]
    char v244;            // [rsp+4Bh] [rbp-245h]
    char v245;            // [rsp+4Ch] [rbp-244h]
    bool v246;            // [rsp+4Dh] [rbp-243h]
    char v247;            // [rsp+4Eh] [rbp-242h]
    char v248;            // [rsp+4Fh] [rbp-241h]
    int v249;             // [rsp+50h] [rbp-240h]
    int v250;             // [rsp+54h] [rbp-23Ch]
    char v251;            // [rsp+5Bh] [rbp-235h]
    char v252;            // [rsp+5Ch] [rbp-234h]
    char v253;            // [rsp+5Dh] [rbp-233h]
    char v254;            // [rsp+5Eh] [rbp-232h]
    char v255;            // [rsp+5Fh] [rbp-231h]
    char v256;            // [rsp+60h] [rbp-230h]
    char v257;            // [rsp+61h] [rbp-22Fh]
    bool v258;            // [rsp+62h] [rbp-22Eh]
    char v259;            // [rsp+63h] [rbp-22Dh]
    int v260;             // [rsp+64h] [rbp-22Ch]
    char v261;            // [rsp+6Ah] [rbp-226h]
    char v262;            // [rsp+6Bh] [rbp-225h]
    unsigned __int8 v263; // [rsp+6Ch] [rbp-224h]
    bool v264;            // [rsp+6Dh] [rbp-223h]
    char v265;            // [rsp+6Eh] [rbp-222h]
    unsigned __int8 v266; // [rsp+6Fh] [rbp-221h]
    int v267;             // [rsp+70h] [rbp-220h]
    char v268;            // [rsp+74h] [rbp-21Ch]
    char v269;            // [rsp+75h] [rbp-21Bh]
    char v270;            // [rsp+76h] [rbp-21Ah]
    char v271;            // [rsp+77h] [rbp-219h]
    char v272;            // [rsp+78h] [rbp-218h]
    char v273;            // [rsp+79h] [rbp-217h]
    char v274;            // [rsp+7Ah] [rbp-216h]
    bool v275;            // [rsp+7Bh] [rbp-215h]
    int v276;             // [rsp+7Ch] [rbp-214h]
    int v277;             // [rsp+80h] [rbp-210h]
    char v278;            // [rsp+87h] [rbp-209h]
    int v279;             // [rsp+88h] [rbp-208h]
    char v280;            // [rsp+8Ch] [rbp-204h]
    bool v281;            // [rsp+8Dh] [rbp-203h]
    char v282;            // [rsp+8Eh] [rbp-202h]
    bool v283;            // [rsp+8Fh] [rbp-201h]
    char v284;            // [rsp+90h] [rbp-200h]
    bool v285;            // [rsp+91h] [rbp-1FFh]
    char v286;            // [rsp+92h] [rbp-1FEh]
    char v287;            // [rsp+93h] [rbp-1FDh]
    int v288;             // [rsp+94h] [rbp-1FCh]
    char v289;            // [rsp+9Ah] [rbp-1F6h]
    bool v290;            // [rsp+9Bh] [rbp-1F5h]
    char v291;            // [rsp+9Ch] [rbp-1F4h]
    char v292;            // [rsp+9Dh] [rbp-1F3h]
    bool v293;            // [rsp+9Eh] [rbp-1F2h]
    char v294;            // [rsp+9Fh] [rbp-1F1h]
    int v295;             // [rsp+A0h] [rbp-1F0h]
    char v296;            // [rsp+A6h] [rbp-1EAh]
    char v297;            // [rsp+A7h] [rbp-1E9h]
    int v298;             // [rsp+A8h] [rbp-1E8h]
    bool v299;            // [rsp+ADh] [rbp-1E3h]
    unsigned __int8 v300; // [rsp+AEh] [rbp-1E2h]
    char v301;            // [rsp+AFh] [rbp-1E1h]
    char v302;            // [rsp+B0h] [rbp-1E0h]
    char v303;            // [rsp+B1h] [rbp-1DFh]
    char v304;            // [rsp+B2h] [rbp-1DEh]
    char v305;            // [rsp+B3h] [rbp-1DDh]
    char v306;            // [rsp+B4h] [rbp-1DCh]
    char v307;            // [rsp+B5h] [rbp-1DBh]
    char v308;            // [rsp+B6h] [rbp-1DAh]
    char v309;            // [rsp+B7h] [rbp-1D9h]
    bool v310;            // [rsp+B8h] [rbp-1D8h]
    bool v311;            // [rsp+B9h] [rbp-1D7h]
    char v312;            // [rsp+BAh] [rbp-1D6h]
    char v313;            // [rsp+BBh] [rbp-1D5h]
    int v314;             // [rsp+BCh] [rbp-1D4h]
    char v315;            // [rsp+C2h] [rbp-1CEh]
    unsigned __int8 v316; // [rsp+C3h] [rbp-1CDh]
    char v317;            // [rsp+C4h] [rbp-1CCh]
    char v318;            // [rsp+C5h] [rbp-1CBh]
    char v319;            // [rsp+C6h] [rbp-1CAh]
    bool v320;            // [rsp+C7h] [rbp-1C9h]
    int v321;             // [rsp+C8h] [rbp-1C8h]
    char v322;            // [rsp+CFh] [rbp-1C1h]
    char v323;            // [rsp+D0h] [rbp-1C0h]
    char v324;            // [rsp+D1h] [rbp-1BFh]
    char v325;            // [rsp+D2h] [rbp-1BEh]
    char v326;            // [rsp+D3h] [rbp-1BDh]
    char v327;            // [rsp+D4h] [rbp-1BCh]
    char v328;            // [rsp+D5h] [rbp-1BBh]
    char v329;            // [rsp+D6h] [rbp-1BAh]
    char v330;            // [rsp+D7h] [rbp-1B9h]
    int v331;             // [rsp+D8h] [rbp-1B8h]
    char v332;            // [rsp+DCh] [rbp-1B4h]
    char v333;            // [rsp+DDh] [rbp-1B3h]
    char v334;            // [rsp+DEh] [rbp-1B2h]
    char v335;            // [rsp+DFh] [rbp-1B1h]
    int v336;             // [rsp+E0h] [rbp-1B0h]
    char v337;            // [rsp+E5h] [rbp-1ABh]
    unsigned __int8 v338; // [rsp+E6h] [rbp-1AAh]
    char v339;            // [rsp+E7h] [rbp-1A9h]
    int v340;             // [rsp+E8h] [rbp-1A8h]
    char v341;            // [rsp+EEh] [rbp-1A2h]
    char v342;            // [rsp+EFh] [rbp-1A1h]
    char v343;            // [rsp+F0h] [rbp-1A0h]
    unsigned __int8 v344; // [rsp+F1h] [rbp-19Fh]
    char v345;            // [rsp+F2h] [rbp-19Eh]
    char v346;            // [rsp+F3h] [rbp-19Dh]
    int v347;             // [rsp+F4h] [rbp-19Ch]
    char v348;            // [rsp+F9h] [rbp-197h]
    char v349;            // [rsp+FAh] [rbp-196h]
    char v350;            // [rsp+FBh] [rbp-195h]
    char v351;            // [rsp+FCh] [rbp-194h]
    char v352;            // [rsp+FDh] [rbp-193h]
    unsigned __int8 v353; // [rsp+FEh] [rbp-192h]
    char v354;            // [rsp+FFh] [rbp-191h]
    char v355;            // [rsp+100h] [rbp-190h]
    char v356;            // [rsp+101h] [rbp-18Fh]
    char v357;            // [rsp+102h] [rbp-18Eh]
    char v358;            // [rsp+103h] [rbp-18Dh]
    char v359;            // [rsp+104h] [rbp-18Ch]
    char v360;            // [rsp+105h] [rbp-18Bh]
    char v361;            // [rsp+106h] [rbp-18Ah]
    char v362;            // [rsp+107h] [rbp-189h]
    char v363;            // [rsp+108h] [rbp-188h]
    char v364;            // [rsp+109h] [rbp-187h]
    char v365;            // [rsp+10Ah] [rbp-186h]
    char v366;            // [rsp+10Bh] [rbp-185h]
    char v367;            // [rsp+10Ch] [rbp-184h]
    char v368;            // [rsp+10Dh] [rbp-183h]
    char v369;            // [rsp+10Eh] [rbp-182h]
    unsigned __int8 v370; // [rsp+10Fh] [rbp-181h]
    int v371;             // [rsp+110h] [rbp-180h]
    int v372;             // [rsp+114h] [rbp-17Ch]
    int v373;             // [rsp+118h] [rbp-178h]
    int v374;             // [rsp+11Ch] [rbp-174h]
    int v375;             // [rsp+120h] [rbp-170h]
    int v376;             // [rsp+124h] [rbp-16Ch]
    int v377;             // [rsp+128h] [rbp-168h]
    int v378;             // [rsp+12Ch] [rbp-164h]
    int v379;             // [rsp+130h] [rbp-160h]
    int v380;             // [rsp+134h] [rbp-15Ch]
    int v381;             // [rsp+138h] [rbp-158h]
    int v382;             // [rsp+13Ch] [rbp-154h]
    int v383;             // [rsp+140h] [rbp-150h]
    int v384;             // [rsp+144h] [rbp-14Ch]
    int v385;             // [rsp+148h] [rbp-148h]
    int v386;             // [rsp+14Ch] [rbp-144h]
    int v387;             // [rsp+150h] [rbp-140h]
    int v388;             // [rsp+154h] [rbp-13Ch]
    int v389;             // [rsp+158h] [rbp-138h]
    int v390;             // [rsp+15Ch] [rbp-134h]
    int v391;             // [rsp+160h] [rbp-130h]
    int v392;             // [rsp+164h] [rbp-12Ch]
    int v393;             // [rsp+168h] [rbp-128h]
    int v394;             // [rsp+16Ch] [rbp-124h]
    int v395;             // [rsp+170h] [rbp-120h]
    int v396;             // [rsp+174h] [rbp-11Ch]
    int v397;             // [rsp+178h] [rbp-118h]
    int v398;             // [rsp+17Ch] [rbp-114h]
    int v399;             // [rsp+180h] [rbp-110h]
    int v400;             // [rsp+184h] [rbp-10Ch]
    int v401;             // [rsp+188h] [rbp-108h]
    int v402;             // [rsp+18Ch] [rbp-104h]
    int v403;             // [rsp+190h] [rbp-100h]
    int v404;             // [rsp+194h] [rbp-FCh]
    int v405;             // [rsp+198h] [rbp-F8h]
    int v406;             // [rsp+19Ch] [rbp-F4h]
    int v407;             // [rsp+1A0h] [rbp-F0h]
    int v408;             // [rsp+1A4h] [rbp-ECh]
    int v409;             // [rsp+1A8h] [rbp-E8h]
    int v410;             // [rsp+1ACh] [rbp-E4h]
    int v411;             // [rsp+1B0h] [rbp-E0h]
    int v412;             // [rsp+1B4h] [rbp-DCh]
    int v413;             // [rsp+1B8h] [rbp-D8h]
    int v414;             // [rsp+1BCh] [rbp-D4h]
    int v415;             // [rsp+1C0h] [rbp-D0h]
    int v416;             // [rsp+1C4h] [rbp-CCh]
    int v417;             // [rsp+1C8h] [rbp-C8h]
    int v418;             // [rsp+1CCh] [rbp-C4h]
    __int64 v419;         // [rsp+1D0h] [rbp-C0h]
    __int64 v420;         // [rsp+1D8h] [rbp-B8h]
    int v421;             // [rsp+1E0h] [rbp-B0h]
    bool v422;            // [rsp+1E6h] [rbp-AAh]
    bool v423;            // [rsp+1E7h] [rbp-A9h]
    __int64 *v424;        // [rsp+1E8h] [rbp-A8h]
    __int64 *v425;        // [rsp+1F0h] [rbp-A0h]
    int *v426;            // [rsp+1F8h] [rbp-98h]
    int *v427;            // [rsp+200h] [rbp-90h]
    void *s;              // [rsp+208h] [rbp-88h]
    _BYTE *v429;          // [rsp+210h] [rbp-80h]
    int *v430;            // [rsp+218h] [rbp-78h]
    int v431;             // [rsp+224h] [rbp-6Ch]
    bool v432;            // [rsp+22Ah] [rbp-66h]
    char v433;            // [rsp+22Bh] [rbp-65h]
    int v434;             // [rsp+22Ch] [rbp-64h]
    int v435;             // [rsp+230h] [rbp-60h]
    char v436;            // [rsp+237h] [rbp-59h]
    __int64 v437;         // [rsp+238h] [rbp-58h]
    int v438;             // [rsp+244h] [rbp-4Ch]
    int v439;             // [rsp+248h] [rbp-48h]
    int v440;             // [rsp+24Ch] [rbp-44h]
    bool v441;            // [rsp+253h] [rbp-3Dh]
    int v442;             // [rsp+254h] [rbp-3Ch]
    __int64 v443;         // [rsp+258h] [rbp-38h]
    int v444;             // [rsp+260h] [rbp-30h]
    int v445;             // [rsp+264h] [rbp-2Ch]

    v422 = ((((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1) == 0;
    v423 = y_8 < 10;
    v421 = 2107132900;
    v420 = a1;
    v419 = a2;
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
                                                                                                                                                                    v418 = v421;
                                                                                                                                                                    v417 = v421 + 2092120317;
                                                                                                                                                                    if (v421 != -2092120317)
                                                                                                                                                                        break;
                                                                                                                                                                    *v424 = v420;
                                                                                                                                                                    *v425 = v419;
                                                                                                                                                                    *v426 = 0;
                                                                                                                                                                    *v427 = 0;
                                                                                                                                                                    v421 = -974703665;
                                                                                                                                                                }
                                                                                                                                                                v416 = v418 + 2083240005;
                                                                                                                                                                if (v418 != -2083240005)
                                                                                                                                                                    break;
                                                                                                                                                                v99 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                                                                                                                                                                v288 = -1402552412;
                                                                                                                                                                v287 = 0;
                                                                                                                                                                v286 = 0;
                                                                                                                                                                v285 = v99 != 0;
                                                                                                                                                                v284 = 0;
                                                                                                                                                                v100 = (v99 == 0) & ((v99 == 0) ^ 0xFE);
                                                                                                                                                                v283 = y_8 >= 10;
                                                                                                                                                                v282 = 0;
                                                                                                                                                                v281 = y_8 >= 10;
                                                                                                                                                                v280 = 0;
                                                                                                                                                                v279 = 1334548432;
                                                                                                                                                                v101 = ~((((unsigned __int8)~v100 ^ 1) & 1) == 0 && ((y_8 < 10 != ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) && y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) | ((unsigned __int8)~((y_8 < 10) ^ ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) ^ (unsigned __int8)~(y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) & 1) != 0);
                                                                                                                                                                v102 = ~(((y_8 < 10 != ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) && y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) | ((unsigned __int8)~((y_8 < 10) ^ ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) ^ (unsigned __int8)~(y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) & 1) == 0 && (((unsigned __int8)~v100 ^ 1) & 1) != 0);
                                                                                                                                                                v103 = (((((y_8 < 10 != ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) && y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0) | ((unsigned __int8)~((y_8 < 10) ^ ((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) ^ (unsigned __int8)~(y_8 < 10 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | !(((unsigned __int8)~(y_8 >= 10) ^ 1) & 1)) == 0)) & 1) != 0 || (((unsigned __int8)~v100 ^ 1) & 1) == 0) | v101 & 1) == 0) | v102 ^ v101;
                                                                                                                                                                v278 = v99 == 0;
                                                                                                                                                                v104 = ~((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0);
                                                                                                                                                                v105 = ((((((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0 && (v278 & 1) != 0) | (v104 ^ (unsigned __int8)~v278) & 1) == 0) & (((((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0 && (v278 & 1) != 0) | (v104 ^ (unsigned __int8)~v278) & 1) == 0) ^ 0xFE)) != 0 && ((v104 ^ ((v278 & 1) == 0)) & 1) != 0) | ~(((((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0 && (v278 & 1) != 0) | (v104 ^ (unsigned __int8)~v278) & 1) == 0) & (((((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0 && (v278 & 1) != 0) | (v104 ^ (unsigned __int8)~v278) & 1) == 0) ^ 0xFE)) ^ ~(v104 ^ ((v278 & 1) == 0));
                                                                                                                                                                v106 = (((v105 & (unsigned __int8)~v105 & 1) != 0 && (((unsigned __int8)~((v105 & 1) == 0) ^ 1) & 1) != 0) | ((unsigned __int8)~(v105 & ~v105) ^ (unsigned __int8)~(~((v105 & 1) == 0) ^ 1)) & 1) == 0;
                                                                                                                                                                v107 = v103 & (~(!v106 & (!v106 ^ 0xFE)) ^ v103);
                                                                                                                                                                v108 = ~(!v106 & (!v106 ^ 0xFE)) & v103 | ~v103 & !v106 & (!v106 ^ 0xFE);
                                                                                                                                                                v109 = -1402552412;
                                                                                                                                                                if (((v108 & 1) != 0 && (v107 & 1) != 0) | v108 & 1 ^ v107 & 1)
                                                                                                                                                                    v109 = 1334548432;
                                                                                                                                                                v421 = v109;
                                                                                                                                                            }
                                                                                                                                                            v415 = v418 + 2047036085;
                                                                                                                                                            if (v418 != -2047036085)
                                                                                                                                                                break;
                                                                                                                                                            v424 = a1;
                                                                                                                                                            *(_BYTE *)(v424 + *v426) = v433;
                                                                                                                                                            v124 = v425;
                                                                                                                                                            v125 = v426;
                                                                                                                                                            v277 = 9;
                                                                                                                                                            v434 = *(unsigned __int8 *)(v124 + v125 % 9);
                                                                                                                                                            v435 = *v430;
                                                                                                                                                            v421 = 964813949;
                                                                                                                                                        }
                                                                                                                                                        v414 = v418 + 1992913953;
                                                                                                                                                        if (v418 != -1992913953)
                                                                                                                                                            break;
                                                                                                                                                        v424 = (__int64 *)&v209[-4];
                                                                                                                                                        v16 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                                                                                                                                                        v17 = v16 == 0;
                                                                                                                                                        LOBYTE(v16) = v16 != 0;
                                                                                                                                                        v347 = -515335841;
                                                                                                                                                        v346 = 0;
                                                                                                                                                        v345 = 0;
                                                                                                                                                        v344 = ((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0;
                                                                                                                                                        v343 = ~v344;
                                                                                                                                                        v342 = 0;
                                                                                                                                                        v341 = -2;
                                                                                                                                                        v340 = -1154394225;
                                                                                                                                                        v339 = v344 | ~v344 ^ 0xFE;
                                                                                                                                                        v18 = (v344 | ((unsigned __int8)~v344 ^ 0xFE) & 1) == 0;
                                                                                                                                                        v19 = (y_8 < 10) & (~(y_8 < 10) ^ (y_8 < 10)) ^ v18;
                                                                                                                                                        v20 = v19 ^ v18 & (~((y_8 < 10) & (~(y_8 < 10) ^ (y_8 < 10))) ^ v18) | v19 & v18 & (~((y_8 < 10) & (~(y_8 < 10) ^ (y_8 < 10))) ^ v18);
                                                                                                                                                        v21 = v20 & (~((v17 & (v17 ^ 0xFE)) == 0) ^ v20);
                                                                                                                                                        v22 = (v20 & 1) == 0 && (v17 & (v17 ^ 0xFE)) != 0;
                                                                                                                                                        v23 = ((v22 & 1) != 0 && (v21 & 1) != 0) | ~v22 ^ ~v21;
                                                                                                                                                        v24 = ((y_8 < 10) & 0xFE | (y_8 >= 10)) & ~((y_8 < 10) & 0xFE | (y_8 >= 10));
                                                                                                                                                        v338 = (v16 & 1) == 0;
                                                                                                                                                        v25 = (((((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0 && (v16 & 1) == 0) | ((unsigned __int8)~v344 ^ (unsigned __int8)~v338) & 1) == 0) & ((((((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0 && (v16 & 1) == 0) | ((unsigned __int8)~v344 ^ (unsigned __int8)~v338) & 1) == 0) ^ 0xFE);
                                                                                                                                                        v26 = v25 ^ ((v24 ^ v344) & 1 | v24 & v344) ^ ((((unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1) != 0 && (v16 & 1) == 0) | v16 & ~(_BYTE)v16 & 1 ^ v338) | v25 & (((v24 ^ v344) & 1 | v24 & v344) ^ ((((unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1) != 0 && (v16 & 1) == 0) | v16 & ~(_BYTE)v16 & 1 ^ v338));
                                                                                                                                                        v27 = !((v25 ^ ((v24 ^ v344) & 1 | (unsigned __int8)(v24 & v344)) ^ ((((unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1) != 0 && (v16 & 1) == 0) | (unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1 ^ v338)) & 1 | v25 & (((v24 ^ v344) & 1 | (unsigned __int8)(v24 & v344)) ^ ((((unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1) != 0 && (v16 & 1) == 0) | (unsigned __int8)v16 & (unsigned __int8)~(_BYTE)v16 & 1 ^ v338)));
                                                                                                                                                        v337 = v26 & ~v26 ^ v27 | v26 & ~v26 & v27;
                                                                                                                                                        v28 = !(((v22 & 1) != 0 && (v21 & 1) != 0) | ((unsigned __int8)~v22 ^ (unsigned __int8)~v21) & 1);
                                                                                                                                                        v29 = !(((v337 & 1) != 0) & (((v337 & 1) != 0) ^ 0xFE));
                                                                                                                                                        v30 = v28 & (((v22 & 1) != 0 && (v21 & 1) != 0) | (~v22 ^ ~v21) & 1);
                                                                                                                                                        v31 = (((v337 & 1) != 0) & (((v337 & 1) != 0) ^ 0xFE)) != 0;
                                                                                                                                                        v32 = ((v23 & 1) != 0 && (v30 & 1) != 0) | ((v23 & 1) != 0) ^ v30 & 1;
                                                                                                                                                        LOBYTE(v16) = v31 ^ v29 & ((v337 & 1) != 0) & (((v337 & 1) != 0) ^ 0xFE) | v31 & v29 & ((v337 & 1) != 0) & (((v337 & 1) != 0) ^ 0xFE);
                                                                                                                                                        v33 = ~(_BYTE)v16 & v32 | ~v32 & v16;
                                                                                                                                                        v34 = ((v29 ^ v28 | (v29 && v28)) & 1) == 0;
                                                                                                                                                        v35 = (((unsigned __int8)(v34 ^ v33) | v34 & v33) & 1) == 0;
                                                                                                                                                        v36 = -515335841;
                                                                                                                                                        if (!v35)
                                                                                                                                                            v36 = -1154394225;
                                                                                                                                                        v421 = v36;
                                                                                                                                                    }
                                                                                                                                                    v413 = v418 + 1948666725;
                                                                                                                                                    if (v418 != -1948666725)
                                                                                                                                                        break;
                                                                                                                                                    v81 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                                                                                                                                                    v295 = -1402552412;
                                                                                                                                                    v294 = -1;
                                                                                                                                                    v293 = v81 == 0;
                                                                                                                                                    v292 = 0;
                                                                                                                                                    v291 = 1;
                                                                                                                                                    v82 = v81 == 0 && (((v81 != 0) ^ 0xFE) & 1) != 0;
                                                                                                                                                    v83 = ~(v81 == 0 && (((v81 != 0) ^ 0xFE) & 1) != 0 && v81 != 0);
                                                                                                                                                    v84 = ~(~v82 & (v81 != 0) | ~(v81 != 0) & v82);
                                                                                                                                                    v85 = (((v84 | v83) & 1) == 0) | v84 ^ v83;
                                                                                                                                                    v86 = y_8 >= 10 || ((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0;
                                                                                                                                                    v87 = (~(y_8 >= 10) ^ 1) & 1 & ~((~(y_8 >= 10) ^ 1) & 1);
                                                                                                                                                    v290 = (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0;
                                                                                                                                                    v88 = (y_8 < 10 && ((y_8 < 10) & 0xFE | (y_8 >= 10)) != 0) & ~(y_8 < 10 && ((y_8 < 10) & 0xFE | (y_8 >= 10)) != 0);
                                                                                                                                                    v89 = ((v86 ^ v290) & 1 | (v86 && v290)) == 0;
                                                                                                                                                    v289 = ~(v88 ^ (y_8 >= 10 || ((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0) | v88 & (y_8 >= 10 || ((y_8 < 10) & 0xFE | (y_8 >= 10)) == 0)) ^ (((v87 ^ v290) & 1 | v87 & v290) == 0);
                                                                                                                                                    v90 = ((v89 & (v89 ^ 0xFE) & 1) != 0 && (v289 & 1) != 0) | v89 & (v89 ^ 0xFE) & 1 ^ v289 & 1;
                                                                                                                                                    v91 = v90 & (~((v85 & 1) == 0) ^ v90);
                                                                                                                                                    v92 = v85 & (~((v90 & 1) == 0) ^ v85);
                                                                                                                                                    v93 = v92 ^ v91 | v92 & v91;
                                                                                                                                                    v94 = ~((~(y_8 >= 10) ^ 1) & 1) ^ (v81 == 0);
                                                                                                                                                    v95 = v94 ^ (!v290 && v81 != 0) | v94 & (!v290 && v81 != 0);
                                                                                                                                                    LOBYTE(v81) = (((v95 & (unsigned __int8)~v95 & 1) != 0 && !(v95 & 1)) | ((unsigned __int8)~(v95 & ~v95) ^ (unsigned __int8)~!(v95 & 1)) & 1) != 0;
                                                                                                                                                    v96 = ~(_BYTE)v81 & v93 | ~v93 & v81;
                                                                                                                                                    v97 = ~((((v95 & (unsigned __int8)~v95 & 1) != 0 && !(v95 & 1)) | ((unsigned __int8)~(v95 & ~v95) ^ (unsigned __int8)~!(v95 & 1)) & 1) != 0 && (v93 & 1) != 0);
                                                                                                                                                    v35 = (((((v96 & 1) == 0) | v97 & 1) == 0) | ((unsigned __int8)~v96 ^ v97) & 1) == 0;
                                                                                                                                                    v98 = -1402552412;
                                                                                                                                                    if (!v35)
                                                                                                                                                        v98 = -2083240005;
                                                                                                                                                    v421 = v98;
                                                                                                                                                }
                                                                                                                                                v412 = v418 + 1935592185;
                                                                                                                                                if (v418 != -1935592185)
                                                                                                                                                    break;
                                                                                                                                                v421 = -1223444022;
                                                                                                                                            }
                                                                                                                                            v411 = v418 + 1640398397;
                                                                                                                                            if (v418 != -1640398397)
                                                                                                                                                break;
                                                                                                                                            v441 = v440 <= 256;
                                                                                                                                            v154 = (((_BYTE)x_7 - 48 + 47) * (_BYTE)x_7) & 1;
                                                                                                                                            v155 = (v154 == 0) & ~(v154 == 0) ^ ~(v154 != 0) ^ 1 | (v154 == 0) & ~(v154 == 0) & (~(v154 != 0) ^ 1);
                                                                                                                                            v267 = -1028518991;
                                                                                                                                            v266 = ~(v154 != 0);
                                                                                                                                            v265 = -2;
                                                                                                                                            LOBYTE(v154) = ((v154 != 0) | (v266 ^ 0xFE) & 1) == 0;
                                                                                                                                            v156 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) & (~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) ^ ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1));
                                                                                                                                            v264 = y_8 >= 10;
                                                                                                                                            v263 = ~(y_8 >= 10);
                                                                                                                                            v262 = 0;
                                                                                                                                            v261 = -2;
                                                                                                                                            v260 = -409903006;
                                                                                                                                            v259 = (y_8 >= 10) | v263 ^ 0xFE;
                                                                                                                                            v258 = ((unsigned __int8)~((v155 & 1) == 0) & (unsigned __int8)(~v155 ^ ~((v155 & 1) == 0)) & 1) == 0;
                                                                                                                                            v257 = -1;
                                                                                                                                            v256 = 0;
                                                                                                                                            v255 = -1;
                                                                                                                                            v254 = ~(~((v155 & 1) == 0) & (~v155 ^ ~((v155 & 1) == 0)) & (~((v155 & 1) == 0) & (~v155 ^ ~((v155 & 1) == 0)) ^ 0xFE));
                                                                                                                                            v253 = ~((v155 & 1) == 0) & (~v155 ^ ~((v155 & 1) == 0)) & (~((v155 & 1) == 0) & (~v155 ^ ~((v155 & 1) == 0)) ^ 0xFE);
                                                                                                                                            v252 = 0;
                                                                                                                                            v251 = 0;
                                                                                                                                            v157 = ~((v154 & 1) != 0) & v253 | v254 & ((v154 & 1) != 0);
                                                                                                                                            LOBYTE(v154) = !(!(v154 & 1) ^ v258 | (!(v154 & 1) && v258));
                                                                                                                                            v158 = v154 ^ v157 | v154 & v157;
                                                                                                                                            v159 = ~(((y_8 >= 10) | (v263 ^ 0xFE) & 1) == 0) & v156 | ~v156 & (((y_8 >= 10) | (v263 ^ 0xFE) & 1) == 0);
                                                                                                                                            v160 = v159 ^ v156 & (~(((y_8 >= 10) | (v263 ^ 0xFE) & 1) == 0) ^ v156) | v159 & v156 & (~(((y_8 >= 10) | (v263 ^ 0xFE) & 1) == 0) ^ v156);
                                                                                                                                            LOBYTE(v154) = (v158 & 1) == 0 && (v160 & 1) != 0;
                                                                                                                                            v161 = !(v160 & 1) && (v158 & 1) != 0;
                                                                                                                                            v162 = ((v161 & 1) != 0 && (v154 & 1) != 0) | ~v161 ^ ~(_BYTE)v154;
                                                                                                                                            v163 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && ((v263 ^ 1) & 1) != 0) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (v263 ^ 1) & 1) == 0;
                                                                                                                                            v164 = ~(((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && ((v263 ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (v263 ^ 1) & 1) & (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && ((v263 ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (v263 ^ 1) & 1) ^ 0xFE)) & v155 & (v155 ^ 0xFE) | ~(v155 & (v155 ^ 0xFE)) & ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && ((v263 ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (v263 ^ 1) & 1) & (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && ((v263 ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (v263 ^ 1) & 1) ^ 0xFE);
                                                                                                                                            v165 = !((v163 ^ ((v155 & 1) == 0)) & 1 | (v163 && (v155 & 1) == 0));
                                                                                                                                            v166 = (((unsigned __int8)~(((v165 ^ v164) & 1 | v165 & v164) == 0) ^ 1) & 1) != 0;
                                                                                                                                            v167 = (((unsigned __int8)~(((v165 ^ v164) & 1 | v165 & v164) == 0) ^ 1) & 1) == 0;
                                                                                                                                            v168 = v166 & (v166 ^ 0xFE);
                                                                                                                                            v169 = ((v162 & 1) != 0) ^ !(v162 & 1) & v162 & 1 | ((v162 & 1) != 0) & !(v162 & 1) & v162 & 1;
                                                                                                                                            v170 = ~v168 & v169 | ~v169 & v168;
                                                                                                                                            v171 = !((v167 ^ !(v162 & 1)) & 1 | (v167 && !(v162 & 1)));
                                                                                                                                            v35 = (((unsigned __int8)(v171 ^ v170) | v171 & v170) & 1) == 0;
                                                                                                                                            v172 = -1028518991;
                                                                                                                                            if (!v35)
                                                                                                                                                v172 = -409903006;
                                                                                                                                            v421 = v172;
                                                                                                                                        }
                                                                                                                                        v410 = v418 + 1631958492;
                                                                                                                                        if (v418 != -1631958492)
                                                                                                                                            break;
                                                                                                                                        v445 = *v426;
                                                                                                                                        v193 = ((28 - (90 - (_BYTE)x_7 - 61)) * (_BYTE)x_7) & 1;
                                                                                                                                        v194 = v193 != 0;
                                                                                                                                        v234 = -280196341;
                                                                                                                                        v233 = 1;
                                                                                                                                        v232 = -1;
                                                                                                                                        v231 = 0;
                                                                                                                                        v230 = -1;
                                                                                                                                        v229 = 1;
                                                                                                                                        v228 = 0;
                                                                                                                                        v227 = 0;
                                                                                                                                        v226 = 0;
                                                                                                                                        v225 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ ((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) == 0;
                                                                                                                                        v195 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ ((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0;
                                                                                                                                        v224 = v193 == 0;
                                                                                                                                        v223 = -1;
                                                                                                                                        v222 = 0;
                                                                                                                                        v221 = v193 == 0;
                                                                                                                                        v220 = 1;
                                                                                                                                        v219 = 0;
                                                                                                                                        v218 = 0;
                                                                                                                                        v217 = ~(v193 == 0);
                                                                                                                                        v216 = 0;
                                                                                                                                        v215 = -2;
                                                                                                                                        v214 = ((v193 == 0) | (v217 ^ 0xFE) & 1) == 0;
                                                                                                                                        v213 = 0;
                                                                                                                                        v212 = -1;
                                                                                                                                        v196 = ~(v195 & (~(y_8 < 10 && ((y_8 < 10) & 0xFE | (y_8 >= 10)) != 0) ^ v195));
                                                                                                                                        v197 = ~(~(y_8 < 10 && ((y_8 < 10) & 0xFE | (y_8 >= 10)) != 0) & v195 | ~v195 & (y_8 < 10 && ((y_8 < 10) & 0xFE | (y_8 >= 10)) != 0));
                                                                                                                                        v198 = (((v197 | v196) & 1) == 0) | v197 ^ v196;
                                                                                                                                        v199 = ~(v198 & ~v198 ^ ((v198 & 1) == 0) | v198 & ~v198 & ((v198 & 1) == 0)) & ((((!v194 | ((unsigned __int8)~!v194 ^ 0xFE) & 1) == 0 && (!v194 & 0xFE | v194) != 0) | ((unsigned __int8)~((!v194 | ((unsigned __int8)~!v194 ^ 0xFE) & 1) == 0) ^ (unsigned __int8)~(!v194 & 0xFE | v194)) & 1) == 0) | ~((((!v194 | ((unsigned __int8)~!v194 ^ 0xFE) & 1) == 0 && (!v194 & 0xFE | v194) != 0) | ((unsigned __int8)~((!v194 | ((unsigned __int8)~!v194 ^ 0xFE) & 1) == 0) ^ (unsigned __int8)~(!v194 & 0xFE | v194)) & 1) == 0) & (v198 & ~v198 ^ ((v198 & 1) == 0) | v198 & ~v198 & ((v198 & 1) == 0));
                                                                                                                                        v200 = ~(((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) & (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) ^ 0xFE)) & v194 & (v194 ^ 0xFE) | ~(v194 & (v194 ^ 0xFE)) & ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) & (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & ~(y_8 < 10) ^ (~(y_8 >= 10) ^ 1) & 1) ^ 0xFE);
                                                                                                                                        v201 = (!((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ ((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) && v193 == 0) | (~!((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && (((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ ((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) ^ v217) & 1;
                                                                                                                                        v202 = ((((v201 ^ 1) & (unsigned __int8)~v201 & 1) != 0 && (v200 & 1) != 0) | (v201 ^ 1) & ~v201 & 1 ^ v200 & 1) & ~((((v201 ^ 1) & (unsigned __int8)~v201 & 1) != 0 && (v200 & 1) != 0) | (v201 ^ 1) & ~v201 & 1 ^ v200 & 1);
                                                                                                                                        v203 = ((v202 ^ (((((v201 ^ 1) & (unsigned __int8)~v201 & 1) != 0 && (v200 & 1) != 0) | (v201 ^ 1) & (unsigned __int8)~v201 & 1 ^ v200 & 1) == 0)) & 1 | v202 & (((((v201 ^ 1) & (unsigned __int8)~v201 & 1) != 0 && (v200 & 1) != 0) | (v201 ^ 1) & (unsigned __int8)~v201 & 1 ^ v200 & 1) == 0)) != 0;
                                                                                                                                        v204 = ~(v203 & ~v203 ^ !(v203 & 1) | v203 & ~v203 & !(v203 & 1)) & ((v199 & 1) == 0) | ~((v199 & 1) == 0) & (v203 & ~v203 ^ !(v203 & 1) | v203 & ~v203 & !(v203 & 1));
                                                                                                                                        v205 = (!(v203 & 1) ^ ((v199 & 1) == 0) | (!(v203 & 1) && (v199 & 1) == 0)) == 0;
                                                                                                                                        v206 = v205 ^ v204 | v205 & v204;
                                                                                                                                        v207 = -280196341;
                                                                                                                                        if ((v206 & 1) != 0)
                                                                                                                                            v207 = 1591658554;
                                                                                                                                        v421 = v207;
                                                                                                                                    }
                                                                                                                                    v409 = v418 + 1572388293;
                                                                                                                                    if (v418 != -1572388293)
                                                                                                                                        break;
                                                                                                                                    v66 = (~((((-37 - (-36 - (_BYTE)x_7)) * (_BYTE)x_7) & 1) != 0) ^ 1) & 1;
                                                                                                                                    v298 = -2092120317;
                                                                                                                                    v297 = (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (y_8 >= 10)) & (unsigned __int8)(~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)))) == 0;
                                                                                                                                    v67 = ((y_8 < 10) & 0xFE | (y_8 >= 10)) & (~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10))) & ~(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10))));
                                                                                                                                    v296 = ~(v67 ^ !(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (unsigned __int8)(~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10)))) | v67 & !(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (unsigned __int8)(~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10))))) ^ ((((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (y_8 >= 10)) & (unsigned __int8)(~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)))) != 0);
                                                                                                                                    v68 = ~!(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (unsigned __int8)(~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10)))) ^ ~v297;
                                                                                                                                    v69 = ~(((!(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (unsigned __int8)(~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10)))) && (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (y_8 >= 10)) & (unsigned __int8)(~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)))) == 0) | v68 & 1) == 0) ^ ~v296;
                                                                                                                                    v70 = (((!(((y_8 < 10) & 0xFE | (y_8 >= 10)) & (unsigned __int8)(~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10)))) && (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (y_8 >= 10)) & (unsigned __int8)(~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)))) == 0) | v68 & 1) == 0 && (v296 & 1) != 0) | v69;
                                                                                                                                    v71 = (v70 & 1) == 0 && v66 != 0;
                                                                                                                                    v72 = ((v71 & 1) != 0 && (v70 & (unsigned __int8)(~!v66 ^ v70) & 1) != 0) | ~v71 ^ ~(v70 & (~!v66 ^ v70));
                                                                                                                                    v73 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ v66;
                                                                                                                                    v74 = v73 ^ v66 & (~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ v66) | v73 & v66 & (~((((y_8 < 10) & (unsigned __int8)~(y_8 < 10)) != 0 && y_8 >= 10) | (y_8 < 10) & ~(y_8 < 10) ^ (y_8 >= 10)) ^ v66);
                                                                                                                                    v75 = (((unsigned __int8)(v74 & ~v74) ^ ((v74 & 1) == 0)) & 1 | (unsigned __int8)(v74 & ~v74) & ((v74 & 1) == 0)) != 0;
                                                                                                                                    v76 = v75 & (~v75 ^ v75);
                                                                                                                                    v77 = !(((v76 & 1) == 0) ^ ((v72 & 1) == 0) | ((v76 & 1) == 0 && (v72 & 1) == 0));
                                                                                                                                    v78 = ~(~(v76 & (v76 ^ 0xFE)) & v72 & (v72 ^ 0xFE) | ~(v72 & (v72 ^ 0xFE)) & v76 & (v76 ^ 0xFE));
                                                                                                                                    v79 = ((((v77 & 1) == 0) | v78 & 1) == 0) | ~v77 ^ v78;
                                                                                                                                    v80 = -2092120317;
                                                                                                                                    if ((v79 & 1) != 0)
                                                                                                                                        v80 = -1935592185;
                                                                                                                                    v421 = v80;
                                                                                                                                }
                                                                                                                                v408 = v418 + 1571430583;
                                                                                                                                if (v418 != -1571430583)
                                                                                                                                    break;
                                                                                                                                v174 = *(unsigned __int8 *)(v443 + v444) + v442 + 318764950 + *((char *)s + *v426) - 558389272 + 239624322;
                                                                                                                                v250 = 257;
                                                                                                                                *v427 = v174 % 257;
                                                                                                                                *v429 = *(_BYTE *)(*v424 + *v426);
                                                                                                                                *(_BYTE *)(*v424 + *v426) = *(_BYTE *)(*v424 + *v427);
                                                                                                                                *(_BYTE *)(*v424 + *v427) = *v429;
                                                                                                                                v421 = 2061798250;
                                                                                                                            }
                                                                                                                            v407 = v418 + 1402552412;
                                                                                                                            if (v418 != -1402552412)
                                                                                                                                break;
                                                                                                                            v421 = -2083240005;
                                                                                                                        }
                                                                                                                        v406 = v418 + 1223444022;
                                                                                                                        if (v418 != -1223444022)
                                                                                                                            break;
                                                                                                                        memset(s, 0, 0x12CuLL);
                                                                                                                        *v429 = 0;
                                                                                                                        *v430 = rand();
                                                                                                                        *v426 = 0;
                                                                                                                        v421 = 1733890684;
                                                                                                                    }
                                                                                                                    v405 = v418 + 1177232967;
                                                                                                                    if (v418 != -1177232967)
                                                                                                                        break;
                                                                                                                    v430 = &v209[-4];
                                                                                                                    *v424 = v420;
                                                                                                                    *v425 = v419;
                                                                                                                    *v426 = 0;
                                                                                                                    *v427 = 0;
                                                                                                                    v54 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                                                                                                                    v55 = ((v54 == 0) & ((v54 == 0) ^ 0xFE)) == 0;
                                                                                                                    v314 = -221949946;
                                                                                                                    v313 = 0;
                                                                                                                    v312 = 0;
                                                                                                                    v311 = ((v54 == 0) & ((v54 == 0) ^ 0xFE)) != 0;
                                                                                                                    v56 = ((v54 == 0) & 0xFE | (v54 != 0)) & (~(v54 == 0) ^ ((v54 == 0) & 0xFE | (v54 != 0)));
                                                                                                                    v310 = v55;
                                                                                                                    v309 = ~((y_8 < 10) & ((y_8 < 10) ^ 0xFE));
                                                                                                                    v308 = -1;
                                                                                                                    v307 = 0;
                                                                                                                    v306 = y_8 >= 10 && y_8 < 10;
                                                                                                                    v305 = 0;
                                                                                                                    v304 = -1;
                                                                                                                    v303 = 1;
                                                                                                                    v302 = 0;
                                                                                                                    v301 = 0;
                                                                                                                    v57 = ((v56 & 1) != 0) ^ v305 | ((v56 & 1) != 0) & v305;
                                                                                                                    v300 = ~!v55;
                                                                                                                    v299 = ((v56 == 0 && !v55) | ((unsigned __int8)~(v56 == 0) ^ v300) & 1) == 0;
                                                                                                                    v58 = v299 & (v299 ^ 0xFE) ^ (~v57 & v310 & (v310 ^ 0xFE) & 1 | ~(v310 & (v310 ^ 0xFE) & 1) & v57) | v299 & (v299 ^ 0xFE) & (~v57 & v310 & (v310 ^ 0xFE) & 1 | ~(v310 & (v310 ^ 0xFE) & 1) & v57);
                                                                                                                    v59 = ((((unsigned __int8)~v306 & (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) | (unsigned __int8)(~(((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) & v306)) != 0 && y_8 >= 10 && y_8 < 10 && ((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) | (unsigned __int8)((~v306 & (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) | ~(((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) & v306) ^ (y_8 >= 10 && y_8 < 10 && ((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0))) != 0;
                                                                                                                    v60 = ~v59 & v58 & (v58 ^ 0xFE) | ~(v58 & (v58 ^ 0xFE)) & v59;
                                                                                                                    v61 = (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0) ^ v55;
                                                                                                                    v62 = ((v61 ^ v55 & ((y_8 < 10) & ((y_8 < 10) ^ 0xFE) ^ v55) | v61 & v55 & ((y_8 < 10) & ((y_8 < 10) ^ 0xFE) ^ v55)) & 1) != 0;
                                                                                                                    v63 = !v62 & (!v62 ^ 0xFE);
                                                                                                                    v64 = (((v63 & 1) == 0) ^ ((v60 & 1) == 0) | ((v63 & 1) == 0 && (v60 & 1) == 0)) == 0;
                                                                                                                    v65 = -221949946;
                                                                                                                    if ((v64 && (((unsigned __int8)(v63 & ~v63) ^ ((v63 & 1) == 0)) & 1 | (unsigned __int8)(v63 & ~v63) & ((v63 & 1) == 0)) != ((v60 & 1) == 0)) | v64 ^ (((unsigned __int8)(v63 & ~v63) ^ ((v63 & 1) == 0)) & 1 | (unsigned __int8)(v63 & ~v63) & ((v63 & 1) == 0)) ^ ((v60 & 1) == 0))
                                                                                                                        v65 = -1572388293;
                                                                                                                    v421 = v65;
                                                                                                                }
                                                                                                                v404 = v418 + 1159420264;
                                                                                                                if (v418 != -1159420264)
                                                                                                                    break;
                                                                                                                v421 = 178420324;
                                                                                                                v211 = v431;
                                                                                                            }
                                                                                                            v403 = v418 + 1154394225;
                                                                                                            if (v418 != -1154394225)
                                                                                                                break;
                                                                                                            v421 = -473821347;
                                                                                                        }
                                                                                                        v402 = v418 + 1028518991;
                                                                                                        if (v418 != -1028518991)
                                                                                                            break;
                                                                                                        v421 = -1640398397;
                                                                                                        v209[3] = v440;
                                                                                                    }
                                                                                                    v401 = v418 + 974703665;
                                                                                                    if (v418 != -974703665)
                                                                                                        break;
                                                                                                    v47 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                                                                                                    v48 = v47 != 0;
                                                                                                    v331 = -221949946;
                                                                                                    LOBYTE(v47) = ~(v47 == 0) & (~(v47 != 0) ^ ~(v47 == 0));
                                                                                                    v330 = 1;
                                                                                                    v329 = 0;
                                                                                                    v328 = 0;
                                                                                                    v327 = -1;
                                                                                                    v326 = ((y_8 < 10) & 0xFE | (y_8 >= 10)) & (~(y_8 < 10) ^ ((y_8 < 10) & 0xFE | (y_8 >= 10)));
                                                                                                    v325 = 0;
                                                                                                    v324 = 0;
                                                                                                    v323 = -1;
                                                                                                    v322 = -1;
                                                                                                    v321 = -1177232967;
                                                                                                    v320 = !((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0));
                                                                                                    v319 = 1;
                                                                                                    v318 = 0;
                                                                                                    v317 = 0;
                                                                                                    v316 = !!((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0)) & (!!((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0)) ^ 0xFE);
                                                                                                    v49 = (((!((!v326 && !((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0))) | !v326 ^ v320) & (!((!v326 && !((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0))) | !v326 ^ v320) ^ 0xFE)) != 0 && ((unsigned __int8)~(v326 != 0) & v316 & 1 | (unsigned __int8)~v316 & (v326 != 0)) != 0) | (!((!v326 && !((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0))) | !v326 ^ v320) & (!((!v326 && !((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0))) | !v326 ^ v320) ^ 0xFE) ^ (unsigned __int8)(~(v326 != 0) & v316 | ~v316 & (v326 != 0))) & 1) == 0;
                                                                                                    v50 = ~v49 & !((unsigned __int8)v47 & ((unsigned __int8)v47 ^ 0xFE) & 1) | ~!((unsigned __int8)v47 & ((unsigned __int8)v47 ^ 0xFE) & 1) & v49;
                                                                                                    v51 = ~((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0)) ^ !v48;
                                                                                                    v315 = 0;
                                                                                                    v52 = ((v51 ^ v48 & (~((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0)) ^ v48) | v51 & v48 & (unsigned __int8)(~((y_8 < 10) & ((y_8 < 10) ^ 0xFE) & 0xFE | (((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) == 0)) ^ v48)) & 1) == 0;
                                                                                                    LOBYTE(v47) = ~(~v52 & v50 | ~v50 & v52);
                                                                                                    v53 = -221949946;
                                                                                                    if (((v47 & 1 | ((v50 & (unsigned __int8)(~v52 ^ v50) & 1) == 0)) == 0) | ((unsigned __int8)v47 ^ (unsigned __int8)~(v50 & (~v52 ^ v50))) & 1)
                                                                                                        v53 = -1177232967;
                                                                                                    v421 = v53;
                                                                                                }
                                                                                                v400 = v418 + 881524680;
                                                                                                if (v418 != -881524680)
                                                                                                    break;
                                                                                                v37 = (((_BYTE)x_7 - 7 + 6) * (_BYTE)x_7) & 1;
                                                                                                v38 = v37 != 0;
                                                                                                v336 = -2092120317;
                                                                                                v335 = -1;
                                                                                                v334 = -1;
                                                                                                v333 = 0;
                                                                                                v39 = ~(~(y_8 >= 10) & (~(y_8 < 10) ^ ~(y_8 >= 10)) & (~(v37 != 0) ^ ~(y_8 >= 10) & (~(y_8 < 10) ^ ~(y_8 >= 10))));
                                                                                                v40 = (((((unsigned __int8)~(y_8 >= 10) & (unsigned __int8)(~(y_8 < 10) ^ ~(y_8 >= 10)) & 1) != 0 || v37 != 0) | v39 & 1) == 0) | ~(((unsigned __int8)~(y_8 >= 10) & (unsigned __int8)(~(y_8 < 10) ^ ~(y_8 >= 10)) & 1) == 0 && v37 == 0) ^ v39;
                                                                                                LOBYTE(v37) = ~(~(y_8 >= 10) ^ 1) ^ (v37 == 0);
                                                                                                v41 = ~((((unsigned __int8)~(y_8 >= 10) ^ 1) & 1) != 0 && v38);
                                                                                                v42 = ((((v37 & 1) == 0) | v41 & 1) == 0) | ~(_BYTE)v37 ^ v41;
                                                                                                v43 = (((((v37 & 1) == 0) | v41 & 1) == 0) | ((unsigned __int8)~(_BYTE)v37 ^ v41) & 1) == 0;
                                                                                                v44 = ~((((unsigned __int8)(v42 & ~v42) ^ v43) & 1 | (unsigned __int8)(v42 & ~v42) & v43) == 0);
                                                                                                v332 = 1;
                                                                                                LOBYTE(v37) = v40 & (~(v44 & 1 & (~v44 ^ v44 & 1)) ^ v40);
                                                                                                v45 = ~(~(v44 & 1 & (~v44 ^ v44 & 1)) ^ ((v40 & 1) == 0));
                                                                                                v46 = -2092120317;
                                                                                                if (((v45 & 1 | ((v37 & 1) == 0)) == 0) | (v45 ^ (unsigned __int8)~(_BYTE)v37) & 1)
                                                                                                    v46 = -974703665;
                                                                                                v421 = v46;
                                                                                            }
                                                                                            v399 = v418 + 682511160;
                                                                                            if (v418 != -682511160)
                                                                                                break;
                                                                                            v442 = *v427;
                                                                                            v443 = *v424;
                                                                                            v444 = *v426;
                                                                                            v421 = -1571430583;
                                                                                        }
                                                                                        v398 = v418 + 515335841;
                                                                                        if (v418 != -515335841)
                                                                                            break;
                                                                                        v421 = -1992913953;
                                                                                    }
                                                                                    v397 = v418 + 511527591;
                                                                                    if (v418 != -511527591)
                                                                                        break;
                                                                                    *((_BYTE *)s + v437) = v436;
                                                                                    v421 = -387550938;
                                                                                }
                                                                                v396 = v418 + 475132287;
                                                                                if (v418 != -475132287)
                                                                                    break;
                                                                                *v426 = 0;
                                                                                v421 = 2142669068;
                                                                            }
                                                                            v395 = v418 + 473821347;
                                                                            if (v418 != -473821347)
                                                                                break;
                                                                            v425 = (__int64 *)v209;
                                                                            v426 = v209;
                                                                            v427 = v209;
                                                                            s = v209;
                                                                            v429 = &v209[-4];
                                                                            v421 = -881524680;
                                                                        }
                                                                        v394 = v418 + 409903006;
                                                                        if (v418 != -409903006)
                                                                            break;
                                                                        v173 = 1557430424;
                                                                        if (v441)
                                                                            v173 = -682511160;
                                                                        v421 = v173;
                                                                    }
                                                                    v393 = v418 + 387550938;
                                                                    if (v418 != -387550938)
                                                                        break;
                                                                    v438 = *v426;
                                                                    v421 = -285388621;
                                                                }
                                                                v392 = v418 + 295311636;
                                                                if (v418 != -295311636)
                                                                    break;
                                                                v431 = *v426;
                                                                v421 = -1948666725;
                                                            }
                                                            v391 = v418 + 285388621;
                                                            if (v418 != -285388621)
                                                                break;
                                                            v439 = -(-v438 - 1544119826 + 1544119825);
                                                            v421 = 871851890;
                                                        }
                                                        v390 = v418 + 280196341;
                                                        if (v418 != -280196341)
                                                            break;
                                                        v421 = -1631958492;
                                                        v210 = v426;
                                                    }
                                                    v389 = v418 + 221949946;
                                                    if (v418 != -221949946)
                                                        break;
                                                    *v424 = v420;
                                                    *v425 = v419;
                                                    *v426 = 0;
                                                    *v427 = 0;
                                                    v421 = -1177232967;
                                                }
                                                v388 = v418 + 190106336;
                                                if (v418 != -190106336)
                                                    break;
                                                v421 = 1733890684;
                                            }
                                            v387 = v418 + 93637996;
                                            if (v418 != -93637996)
                                                break;
                                            *v426 = 1522333211 - (1522333210 - v445);
                                            v421 = 1413396805;
                                        }
                                        v386 = v418 - 178420324;
                                        if (v418 != 178420324)
                                            break;
                                        v117 = -1159420264;
                                        v432 = v431 <= 256;
                                        v118 = ((((_BYTE)x_7 - 27 + 26) * (_BYTE)x_7) & 1) == 0;
                                        v119 = ((y_8 >= 10) ^ v118) & (~v118 ^ (y_8 >= 10) ^ v118);
                                        v120 = ~((y_8 < 10) & ((y_8 < 10) ^ 0xFE)) ^ ((v118 & (v118 ^ 0xFE) & 1) == 0);
                                        v121 = ~(v120 & (v120 ^ 0xFE)) ^ ((v119 & 1) == 0);
                                        v122 = (((v120 & 1) == 0 && (v119 & 1) == 0) | ((unsigned __int8)~((v120 & 1) == 0) ^ (unsigned __int8)~((v119 & 1) == 0)) & 1) == 0;
                                        if (((v122 & (v122 ^ 0xFE) & 1) != 0 && (v121 & 1) != 0) | ((unsigned __int8)~(v122 & (v122 ^ 0xFE)) ^ (unsigned __int8)~v121) & 1)
                                            v117 = 1915768531;
                                        v421 = v117;
                                    }
                                    v385 = v418 - 245152517;
                                    if (v418 != 245152517)
                                        break;
                                    v433 = *v426;
                                    v421 = -2047036085;
                                }
                                v384 = v418 - 856850146;
                                if (v418 != 856850146)
                                    break;
                                v133 = ((-106 - (-105 - (_BYTE)x_7)) * (_BYTE)x_7) & 1;
                                v134 = (v133 == 0) & ~(v133 == 0) ^ (v133 != 0) | (v133 == 0) & ~(v133 == 0) & (v133 != 0);
                                v135 = ((v134 & 1) != 0) & (((v134 & 1) != 0) ^ 0xFE);
                                v136 = ((v133 == 0) & 0xFE | (v133 != 0)) & (~(v133 == 0) ^ ((v133 == 0) & 0xFE | (v133 != 0)));
                                v276 = -1028518991;
                                v137 = ~(v135 & (~v136 ^ v135));
                                v138 = ~(~v136 & v135 | ~v135 & v136);
                                v139 = (((v138 | v137) & 1) == 0) | v138 ^ v137;
                                v140 = y_8 >= 10 || (((y_8 >= 10) ^ 0xFE) & 1) == 0;
                                v275 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) == 0;
                                v274 = (y_8 < 10 && (((y_8 >= 10) ^ 0xFE) & 1) != 0) & ((y_8 < 10 && (((y_8 >= 10) ^ 0xFE) & 1) != 0) ^ 0xFE);
                                v273 = 0;
                                v272 = -1;
                                v271 = ~(((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) != 0);
                                v141 = ((v140 ^ v275) & 1 | (v140 && v275)) == 0;
                                v142 = ~(v141 & (v141 ^ 0xFE));
                                v143 = ((v142 & 1 | (v274 == (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) != 0))) == 0) | v142 ^ ~(v274 ^ (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) != 0));
                                v144 = v139 & (~((((v142 & 1 | (v274 == (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) != 0))) == 0) | (v142 ^ (unsigned __int8)~(v274 ^ (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) & (unsigned __int8)(~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) ^ (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)))) != 0))) & 1) == 0) ^ v139);
                                v145 = v144 ^ ((v139 & 1) == 0 && (v143 & 1) != 0) | v144 & ((v139 & 1) == 0 && (v143 & 1) != 0);
                                v146 = (((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) == 0;
                                v147 = ((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) & ~((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1));
                                v148 = ~(v147 ^ v146 | v147 & v146) & (v134 & ~v134 ^ (v134 == 0) | v134 & ~v134 & (v134 == 0)) | ~(v134 & ~v134 ^ (v134 == 0) | v134 & ~v134 & (v134 == 0)) & (v147 ^ v146 | v147 & v146);
                                LOBYTE(v133) = ((v146 ^ (v134 == 0)) & 1 | (v146 && v134 == 0)) == 0;
                                v149 = (((v133 & 1) != 0 && (v148 & 1) != 0) | v133 & 1 ^ v148 & 1) != 0;
                                v270 = v145;
                                v269 = 0;
                                v268 = 0;
                                v150 = v145 & (~(~v149 & (~(v149 & 0xFE | !v149) ^ ~v149)) ^ v145);
                                v151 = ~(~v149 & (~(v149 & 0xFE | !v149) ^ ~v149)) ^ ((v145 & 1) == 0);
                                v152 = ((v151 & 1) != 0 && (v150 & 1) != 0) | v151 & 1 ^ v150 & 1;
                                v153 = -1028518991;
                                if ((v152 & 1) != 0)
                                    v153 = -1640398397;
                                v421 = v153;
                            }
                            v383 = v418 - 871851890;
                            if (v418 != 871851890)
                                break;
                            *v426 = v439;
                            v421 = -190106336;
                        }
                        v382 = v418 - 964813949;
                        if (v418 != 964813949)
                            break;
                        v126 = ((~(~(_BYTE)v434 | 0x98) ^ ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67) | ~(~(_BYTE)v434 | 0x98) & ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67)) & 0x98 | ~(~(~(_BYTE)v434 | 0x98) ^ ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67) | ~(~(_BYTE)v434 | 0x98) & ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67)) & 0x67) & v435 | ~(_BYTE)v435 & ~((~(~(_BYTE)v434 | 0x98) ^ ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67) | ~(~(_BYTE)v434 | 0x98) & ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67)) & 0x98 | ~(~(~(_BYTE)v434 | 0x98) ^ ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67) | ~(~(_BYTE)v434 | 0x98) & ~(~((v434 & 0xA7 | ~(_BYTE)v434 & 0x58) ^ 0xA7) | 0x67)) & 0x67);
                        v127 = v126 & (~(_BYTE)v435 ^ v126);
                        v128 = v435 & ~(_BYTE)v435 & 0x39 | ~(v435 & ~(_BYTE)v435) & 0xC6;
                        v129 = ((~(~(v435 & ~(_BYTE)v435) | v435) | v128 ^ (~(_BYTE)v435 & 0x39 | v435 & 0xC6)) & 0x68 | ~(~(~(v435 & ~(_BYTE)v435) | v435) | v128 ^ (~(_BYTE)v435 & 0x39 | v435 & 0xC6)) & 0x97) ^ 0x68;
                        v130 = v129 ^ ~(_BYTE)v434 | v129 & ~(_BYTE)v434;
                        v131 = v127 & (~((v130 & 0x64 | ~v130 & 0x9B) ^ 0x64) ^ v127);
                        v132 = (((v130 & 0x64 | ~v130 & 0x9B) ^ 0x64) & 0xE0 | ~((v130 & 0x64 | ~v130 & 0x9B) ^ 0x64) & 0x1F) ^ (v127 & 0xE0 | ~v127 & 0x1F);
                        v436 = v132 ^ v131 | v132 & v131;
                        v437 = *v426;
                        v421 = -511527591;
                    }
                    v381 = v418 - 1092101868;
                    if (v418 != 1092101868)
                        break;
                    v123 = -475132287;
                    if (v432)
                        v123 = 245152517;
                    v421 = v123;
                }
                v380 = v418 - 1334548432;
                if (v418 != 1334548432)
                    break;
                v110 = -1159420264;
                v111 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                v112 = v111 == 0;
                v113 = ((y_8 >= 10) ^ (v111 != 0) | (y_8 >= 10 && v111 != 0)) == 0;
                LOBYTE(v111) = ~((y_8 < 10) & (~(v111 != 0) ^ (y_8 < 10)));
                v114 = ~(v112 & (~(y_8 >= 10) ^ v112));
                v115 = (((v114 | (unsigned __int8)v111) & 1) == 0) | v114 ^ v111;
                LOBYTE(v111) = ((((v114 | (unsigned __int8)v111) & 1) == 0) | (v114 ^ (unsigned __int8)v111) & 1) != 0 && (v113 & 1) != 0;
                v116 = ~v115 & v113 | ~v113 & v115;
                if (((v116 & 1) != 0 && (v111 & 1) != 0) | v116 & 1 ^ v111 & 1)
                    v110 = 178420324;
                v421 = v110;
            }
            v379 = v418 - 1413396805;
            if (v418 != 1413396805)
                break;
            v440 = *v426;
            v421 = 856850146;
        }
        v378 = v418 - 1557430424;
        if (v418 == 1557430424)
            break;
        v377 = v418 - 1591658554;
        if (v418 == 1591658554)
        {
            v421 = -93637996;
        }
        else
        {
            v376 = v418 - 1733890684;
            if (v418 == 1733890684)
            {
                v421 = -295311636;
            }
            else
            {
                v375 = v418 - 1915768531;
                if (v418 == 1915768531)
                {
                    v421 = 1092101868;
                }
                else
                {
                    v374 = v418 - 2061798250;
                    if (v418 == 2061798250)
                    {
                        v175 = (((_BYTE)x_7 - 1) * (_BYTE)x_7) & 1;
                        v176 = v175 == 0;
                        LOBYTE(v175) = v175 != 0;
                        v249 = -280196341;
                        v248 = -1;
                        v247 = -1;
                        v246 = (v175 & 1) == 0;
                        v245 = 0;
                        v244 = 0;
                        v243 = 0;
                        v242 = -2;
                        v177 = (!v176 | ((unsigned __int8)~!v176 ^ 0xFE) & 1) == 0;
                        v178 = ((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) != 0) & (((((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) != 0) ^ 0xFE);
                        v241 = y_8 >= 10;
                        v240 = 0;
                        v239 = y_8 >= 10;
                        v238 = 0;
                        v237 = -1631958492;
                        v236 = y_8 >= 10 || y_8 < 10;
                        v179 = v177 ^ ((v175 & 1) != 0) & (((v175 & 1) != 0) ^ 0xFE);
                        v180 = v179 ^ (v177 && (((v175 & 1) != 0) & (((v175 & 1) != 0) ^ 0xFE)) != 0) | v179 & (v177 && (((v175 & 1) != 0) & (((v175 & 1) != 0) ^ 0xFE)) != 0);
                        v181 = ((v179 ^ (v177 && (((v175 & 1) != 0) & (((v175 & 1) != 0) ^ 0xFE)) != 0)) & 1 | v179 & (v177 && (((v175 & 1) != 0) & (((v175 & 1) != 0) ^ 0xFE)) != 0)) == 0;
                        v182 = v246;
                        v183 = (((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1)) & ~(((y_8 < 10) & ~(y_8 < 10) ^ ~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & ~(y_8 < 10) & (~(y_8 >= 10) ^ 1));
                        v235 = !(((unsigned __int8)(!v236 ^ v178 ^ v178 & (~!v236 ^ v178)) | (unsigned __int8)((!v236 ^ v178) & v178 & (~!v236 ^ v178))) & 1) ^ (v180 & ~v180 ^ v181 | v180 & ~v180 & v181) & 1;
                        LOBYTE(v175) = ~(v183 ^ !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) | v183 & !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1))) ^ ((v175 & 1) != 0);
                        v184 = (((!(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) && v182) | !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) ^ v182) == 0 && (v175 & 1) != 0) | ~(((!(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) && v182) | !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) ^ v182) == 0) ^ ~(_BYTE)v175;
                        v185 = ((((!(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) && v182) | !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) ^ v182) == 0 && (v175 & 1) != 0) | ((unsigned __int8)~(((!(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) && v182) | !(((y_8 < 10) & (unsigned __int8)~(y_8 < 10) ^ (unsigned __int8)~(y_8 >= 10) ^ 1) & 1 | (y_8 < 10) & (unsigned __int8)~(y_8 < 10) & ((unsigned __int8)~(y_8 >= 10) ^ 1)) ^ v182) == 0) ^ (unsigned __int8)~(_BYTE)v175) & 1) == 0;
                        v186 = (((unsigned __int8)(v184 & ~v184 ^ v185) | (unsigned __int8)(v184 & ~v184) & v185) & 1) == 0;
                        v187 = !v186 & (!v186 ^ 0xFE);
                        v188 = v187 == 0;
                        v189 = v187 & ~v187;
                        v190 = ~(((v189 & 1) != 0 && v188) | ~v189 ^ ~v188) & (((v235 & (unsigned __int8)~v235 & 1) != 0 && (v235 & 1) == 0) | v235 & ~v235 & 1 ^ ((v235 & 1) == 0)) | ~(((v235 & (unsigned __int8)~v235 & 1) != 0 && (v235 & 1) == 0) | v235 & ~v235 & 1 ^ ((v235 & 1) == 0)) & (((v189 & 1) != 0 && v188) | ~v189 ^ ~v188);
                        v191 = ((v187 == 0) ^ ((v235 & 1) == 0) | (v187 == 0 && (v235 & 1) == 0)) == 0;
                        v35 = ((v191 ^ v190) & 1 | v191 & v190) == 0;
                        v192 = -280196341;
                        if (!v35)
                            v192 = -1631958492;
                        v421 = v192;
                    }
                    else
                    {
                        v373 = v418 - 2107132900;
                        if (v418 == 2107132900)
                        {
                            v371 = -515335841;
                            v370 = ~v422;
                            v369 = -2;
                            v368 = v422 | v370 ^ 0xFE;
                            v367 = !v422;
                            v366 = 0;
                            v365 = (((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) == 0;
                            v364 = ~((v422 & (v422 ^ 0xFE)) == 0);
                            v363 = 0;
                            v362 = 0;
                            v361 = v422 & (v422 ^ 0xFE) & (v422 & (v422 ^ 0xFE) ^ 0xFE);
                            v360 = 0;
                            v359 = -1;
                            v358 = ~((((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) != 0);
                            v357 = ~v365;
                            v356 = v365;
                            v355 = 0;
                            v2 = !(((v422 & (v422 ^ 0xFE)) == 0 && (((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) == 0) | (unsigned __int8)(((v422 & (v422 ^ 0xFE)) == 0) ^ v365)) & (!(((v422 & (v422 ^ 0xFE)) == 0 && (((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) == 0) | (unsigned __int8)(((v422 & (v422 ^ 0xFE)) == 0) ^ v365)) ^ 0xFE);
                            v354 = v2 ^ v361 ^ ((((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) != 0) | v2 & (v361 ^ ((((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) != 0));
                            v353 = v423 & ~v423;
                            v352 = 0;
                            v351 = -2;
                            v350 = -1;
                            v3 = v353;
                            v4 = (!v423 | ((unsigned __int8)~!v423 ^ 0xFE) & 1) == 0;
                            v5 = !((v2 ^ (unsigned __int8)(v361 ^ ((((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) != 0))) & 1 | (unsigned __int8)(v2 & (v361 ^ ((((v422 | (v370 ^ 0xFE) & 1) == 0) & (((v422 | (v370 ^ 0xFE) & 1) == 0) ^ 0xFE)) != 0)))) && ((v4 ^ ((((v3 ^ !v423) & 1 | v3 & !v423) == 0) | ((unsigned __int8)(v3 ^ !v423) | v3 & !v423) & 0xFE) | v4 & ((((v3 ^ !v423) & 1 | v3 & !v423) == 0) | ((unsigned __int8)(v3 ^ !v423) | v3 & !v423) & 0xFE)) & 1) != 0;
                            v6 = v354 & (~(((v4 ^ ((((v3 ^ !v423) & 1 | v3 & !v423) == 0) | ((unsigned __int8)(v3 ^ !v423) | v3 & !v423) & 0xFE) | v4 & ((((v3 ^ !v423) & 1 | v3 & !v423) == 0) | ((unsigned __int8)(v3 ^ !v423) | v3 & !v423) & 0xFE)) & 1) == 0) ^ v354);
                            v7 = v6 ^ v5 | v6 & v5;
                            v8 = (((unsigned __int8)~!v423 ^ 1) & 1) == 0;
                            v9 = v367 & ~v367;
                            v10 = (((v8 ^ v422) & 1 | v8 & v422) == 0 && ((unsigned __int8)~v8 & (unsigned __int8)(v9 ^ v422 | v9 & v422) & 1 | (unsigned __int8)(~(v9 ^ v422 | v9 & v422) & v8)) != 0) | (((v8 ^ v422) & 1 | v8 & v422) == 0) ^ (~v8 & (v9 ^ v422 | v9 & v422) & 1 | ~(v9 ^ v422 | v9 & v422) & v8);
                            v11 = ((v10 & (unsigned __int8)~v10 & 1) != 0 && (((unsigned __int8)~(v10 == 0) ^ 1) & 1) != 0) | v10 & ~v10 & 1 ^ (~(v10 == 0) ^ 1) & 1;
                            v349 = 0;
                            v348 = 0;
                            v12 = v11 & (~v11 ^ v11);
                            v13 = (v12 & 1) != 0 && (v7 & 1) != 0;
                            v14 = ~v12 & v7 | ~v7 & v12;
                            v15 = -515335841;
                            if ((((unsigned __int8)(v14 ^ v13) | v14 & v13) & 1) != 0)
                                v15 = -1992913953;
                            v421 = v15;
                        }
                        else
                        {
                            v372 = v418 - 2142669068;
                            if (v418 == 2142669068)
                                v421 = 1413396805;
                        }
                    }
                }
            }
        }
    }
    return 0LL;
}

int main()
{
    unsigned char sbox[257];
    unsigned char key[9] = "JustDoIt!";
    init_sbox(sbox, key);
    for (int i = 0; i < 257; i++)
    {
        printf("%d ", sbox[i]);
    }
}