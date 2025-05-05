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

__int64 __fastcall rc4(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
	int v4;					// eax
	int v5;					// edi
	char v6;				// r14
	int v7;					// eax
	int v8;					// ecx
	int v9;					// r10d
	unsigned __int8 v10;	// r9
	unsigned __int8 v11;	// bl
	char v12;				// si
	char v13;				// r13
	char v14;				// di
	char v15;				// r11
	unsigned __int8 v16;	// r11
	int v17;				// edi
	bool v18;				// r11
	char v19;				// r8
	char v20;				// r11
	char v21;				// r14
	char v22;				// r11
	int v23;				// eax
	int v24;				// r9d
	bool v25;				// r14
	unsigned __int8 v26;	// r10
	char v27;				// di
	char v28;				// r15
	char v29;				// al
	char v30;				// di
	char v31;				// r11
	char v32;				// cl
	char v33;				// r10
	char v34;				// di
	bool v35;				// al
	bool v36;				// zf
	int v37;				// eax
	int v38;				// r8d
	bool v39;				// r11
	char v40;				// r9
	char v41;				// si
	char v42;				// r9
	bool v43;				// al
	int v44;				// eax
	int v45;				// edi
	char v46;				// si
	char v47;				// r12
	int v48;				// eax
	int v49;				// eax
	int v50;				// r9d
	int v51;				// edi
	char v52;				// r8
	char v53;				// cl
	unsigned __int8 v54;	// si
	unsigned __int8 v55;	// r8
	bool v56;				// r8
	char v57;				// al
	int v58;				// eax
	int v59;				// edx
	char v60;				// si
	char v61;				// r15
	char v62;				// di
	int v63;				// r9d
	int v64;				// esi
	int v65;				// ecx
	char v66;				// dl
	unsigned int v67;		// esi
	int v68;				// r10d
	int v69;				// edi
	char v70;				// r13
	char v71;				// r13
	char v72;				// r12
	char v73;				// dl
	unsigned int v74;		// ecx
	char v75;				// bl
	char v76;				// r13
	char v77;				// r14
	char v78;				// r9
	char v79;				// r9
	char v80;				// r14
	char v81;				// r15
	char v82;				// r9
	char v83;				// r14
	char v84;				// dl
	char v85;				// r8
	char v86;				// dl
	int v87;				// eax
	int v88;				// r8d
	char v89;				// di
	bool v90;				// si
	char v91;				// r12
	bool v92;				// di
	char v93;				// r15
	bool v94;				// si
	int v95;				// eax
	int v96;				// r8d
	unsigned __int8 v97;	// di
	int v98;				// eax
	int v99;				// r8d
	bool v100;				// r15
	char v101;				// r14
	char v102;				// si
	int v103;				// edi
	bool v104;				// r15
	char v105;				// si
	char v106;				// r13
	char v107;				// r8
	bool v108;				// si
	unsigned __int8 v109;	// r9
	bool v110;				// si
	int v111;				// eax
	int v113;				// ecx
	int v114;				// esi
	int v115;				// edi
	int v116;				// r8d
	int v117;				// r9d
	int v118;				// r10d
	int v119;				// r11d
	int inited;				// eax
	_DWORD v121[4];			// [rsp+0h] [rbp-340h] BYREF
	int *v122;				// [rsp+10h] [rbp-330h]
	int v123;				// [rsp+1Ch] [rbp-324h]
	int v124;				// [rsp+20h] [rbp-320h]
	int v125;				// [rsp+24h] [rbp-31Ch]
	int v126;				// [rsp+28h] [rbp-318h]
	int v127;				// [rsp+2Ch] [rbp-314h]
	int v128;				// [rsp+30h] [rbp-310h]
	int v129;				// [rsp+34h] [rbp-30Ch]
	int v130;				// [rsp+38h] [rbp-308h]
	int v131;				// [rsp+3Ch] [rbp-304h]
	int v132;				// [rsp+40h] [rbp-300h]
	unsigned int v133;		// [rsp+44h] [rbp-2FCh]
	int v134;				// [rsp+48h] [rbp-2F8h]
	char v135;				// [rsp+4Fh] [rbp-2F1h]
	int v136;				// [rsp+50h] [rbp-2F0h]
	char v137;				// [rsp+56h] [rbp-2EAh]
	bool v138;				// [rsp+57h] [rbp-2E9h]
	int v139;				// [rsp+58h] [rbp-2E8h]
	char v140;				// [rsp+5Ch] [rbp-2E4h]
	bool v141;				// [rsp+5Dh] [rbp-2E3h]
	char v142;				// [rsp+5Eh] [rbp-2E2h]
	bool v143;				// [rsp+5Fh] [rbp-2E1h]
	char v144;				// [rsp+60h] [rbp-2E0h]
	bool v145;				// [rsp+61h] [rbp-2DFh]
	char v146;				// [rsp+62h] [rbp-2DEh]
	char v147;				// [rsp+63h] [rbp-2DDh]
	int v148;				// [rsp+64h] [rbp-2DCh]
	int v149;				// [rsp+68h] [rbp-2D8h]
	int v150;				// [rsp+6Ch] [rbp-2D4h]
	int v151;				// [rsp+70h] [rbp-2D0h]
	char v152;				// [rsp+75h] [rbp-2CBh]
	char v153;				// [rsp+76h] [rbp-2CAh]
	unsigned __int8 v154;	// [rsp+77h] [rbp-2C9h]
	char v155;				// [rsp+78h] [rbp-2C8h]
	char v156;				// [rsp+79h] [rbp-2C7h]
	char v157;				// [rsp+7Ah] [rbp-2C6h]
	char v158;				// [rsp+7Bh] [rbp-2C5h]
	char v159;				// [rsp+7Ch] [rbp-2C4h]
	char v160;				// [rsp+7Dh] [rbp-2C3h]
	char v161;				// [rsp+7Eh] [rbp-2C2h]
	unsigned __int8 v162;	// [rsp+7Fh] [rbp-2C1h]
	int v163;				// [rsp+80h] [rbp-2C0h]
	char v164;				// [rsp+85h] [rbp-2BBh]
	char v165;				// [rsp+86h] [rbp-2BAh]
	char v166;				// [rsp+87h] [rbp-2B9h]
	unsigned __int8 v167;	// [rsp+88h] [rbp-2B8h]
	char v168;				// [rsp+89h] [rbp-2B7h]
	char v169;				// [rsp+8Ah] [rbp-2B6h]
	char v170;				// [rsp+8Bh] [rbp-2B5h]
	int v171;				// [rsp+8Ch] [rbp-2B4h]
	int v172;				// [rsp+90h] [rbp-2B0h]
	char v173;				// [rsp+97h] [rbp-2A9h]
	char v174;				// [rsp+98h] [rbp-2A8h]
	char v175;				// [rsp+99h] [rbp-2A7h]
	char v176;				// [rsp+9Ah] [rbp-2A6h]
	char v177;				// [rsp+9Bh] [rbp-2A5h]
	char v178;				// [rsp+9Ch] [rbp-2A4h]
	char v179;				// [rsp+9Dh] [rbp-2A3h]
	char v180;				// [rsp+9Eh] [rbp-2A2h]
	bool v181;				// [rsp+9Fh] [rbp-2A1h]
	char v182;				// [rsp+A0h] [rbp-2A0h]
	char v183;				// [rsp+A1h] [rbp-29Fh]
	char v184;				// [rsp+A2h] [rbp-29Eh]
	char v185;				// [rsp+A3h] [rbp-29Dh]
	bool v186;				// [rsp+A4h] [rbp-29Ch]
	char v187;				// [rsp+A5h] [rbp-29Bh]
	char v188;				// [rsp+A6h] [rbp-29Ah]
	char v189;				// [rsp+A7h] [rbp-299h]
	int v190;				// [rsp+A8h] [rbp-298h]
	int v191;				// [rsp+ACh] [rbp-294h]
	int v192;				// [rsp+B0h] [rbp-290h]
	int v193;				// [rsp+B4h] [rbp-28Ch]
	int v194;				// [rsp+B8h] [rbp-288h]
	int v195;				// [rsp+BCh] [rbp-284h]
	int v196;				// [rsp+C0h] [rbp-280h]
	int v197;				// [rsp+C4h] [rbp-27Ch]
	int v198;				// [rsp+C8h] [rbp-278h]
	int v199;				// [rsp+CCh] [rbp-274h]
	int v200;				// [rsp+D0h] [rbp-270h]
	int v201;				// [rsp+D4h] [rbp-26Ch]
	int v202;				// [rsp+D8h] [rbp-268h]
	int v203;				// [rsp+DCh] [rbp-264h]
	int v204;				// [rsp+E0h] [rbp-260h]
	int v205;				// [rsp+E4h] [rbp-25Ch]
	int v206;				// [rsp+E8h] [rbp-258h]
	int v207;				// [rsp+ECh] [rbp-254h]
	int v208;				// [rsp+F0h] [rbp-250h]
	int v209;				// [rsp+F4h] [rbp-24Ch]
	int v210;				// [rsp+F8h] [rbp-248h]
	int v211;				// [rsp+FCh] [rbp-244h]
	int v212;				// [rsp+100h] [rbp-240h]
	int v213;				// [rsp+104h] [rbp-23Ch]
	int v214;				// [rsp+108h] [rbp-238h]
	int v215;				// [rsp+10Ch] [rbp-234h]
	int v216;				// [rsp+110h] [rbp-230h]
	int v217;				// [rsp+114h] [rbp-22Ch]
	int v218;				// [rsp+118h] [rbp-228h]
	int v219;				// [rsp+11Ch] [rbp-224h]
	int v220;				// [rsp+120h] [rbp-220h]
	int v221;				// [rsp+124h] [rbp-21Ch]
	int v222;				// [rsp+128h] [rbp-218h]
	int v223;				// [rsp+12Ch] [rbp-214h]
	int v224;				// [rsp+130h] [rbp-210h]
	int v225;				// [rsp+134h] [rbp-20Ch]
	__int64 v226;			// [rsp+138h] [rbp-208h]
	__int64 v227;			// [rsp+140h] [rbp-200h]
	unsigned __int64 v228;	// [rsp+148h] [rbp-1F8h]
	__int64 v229;			// [rsp+150h] [rbp-1F0h]
	int v230;				// [rsp+15Ch] [rbp-1E4h]
	_BYTE v231[312];		// [rsp+160h] [rbp-1E0h] BYREF
	__int64 v232;			// [rsp+298h] [rbp-A8h]
	__int64 v233;			// [rsp+2A0h] [rbp-A0h]
	unsigned __int64 v234;	// [rsp+2A8h] [rbp-98h]
	__int64 v235;			// [rsp+2B0h] [rbp-90h]
	int *v236;				// [rsp+2B8h] [rbp-88h]
	int *v237;				// [rsp+2C0h] [rbp-80h]
	int *v238;				// [rsp+2C8h] [rbp-78h]
	unsigned __int64 *v239; // [rsp+2D0h] [rbp-70h]
	_BYTE *v240;			// [rsp+2D8h] [rbp-68h]
	__int64 v241;			// [rsp+2E0h] [rbp-60h]
	unsigned __int64 v242;	// [rsp+2E8h] [rbp-58h]
	unsigned __int64 v243;	// [rsp+2F0h] [rbp-50h]
	bool v244;				// [rsp+2FBh] [rbp-45h]
	int v245;				// [rsp+2FCh] [rbp-44h]
	_BYTE *v246;			// [rsp+300h] [rbp-40h]
	unsigned __int64 v247;	// [rsp+308h] [rbp-38h]
	unsigned __int64 v248;	// [rsp+310h] [rbp-30h]

	v230 = -1120819514;
	v229 = a3;
	v228 = a2;
	v227 = a1;
	v226 = a4;
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
																								v225 = v230;
																								v224 = v230 + 2073611748;
																								if (v230 != -2073611748)
																									break;
																								v95 = 1565805369;
																								v96 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
																								v97 = ~((((v96 == 0) & (unsigned __int8)(~(y_10 >= 10) ^ (v96 == 0))) != 0 && ((y_10 < 10) & (unsigned __int8)(~(v96 != 0) ^ (y_10 < 10))) != 0) | (v96 == 0) & (~(y_10 >= 10) ^ (v96 == 0)) ^ (y_10 < 10) & (~(v96 != 0) ^ (y_10 < 10))) ^ (((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) & ((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) ^ 0xFE)) == 0);
																								if ((v97 ^ (((((v96 == 0) & (unsigned __int8)(~(y_10 >= 10) ^ (v96 == 0))) != 0 && ((y_10 < 10) & (unsigned __int8)(~(v96 != 0) ^ (y_10 < 10))) != 0) | (v96 == 0) & (unsigned __int8)(~(y_10 >= 10) ^ (v96 == 0)) ^ (y_10 < 10) & (unsigned __int8)(~(v96 != 0) ^ (y_10 < 10))) != 0 && ((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) & ((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) ^ 0xFE)) != 0)) & 1 | v97 & (((((v96 == 0) & (unsigned __int8)(~(y_10 >= 10) ^ (v96 == 0))) != 0 && ((y_10 < 10) & (unsigned __int8)(~(v96 != 0) ^ (y_10 < 10))) != 0) | (v96 == 0) & (unsigned __int8)(~(y_10 >= 10) ^ (v96 == 0)) ^ (y_10 < 10) & (unsigned __int8)(~(v96 != 0) ^ (y_10 < 10))) != 0 && ((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) & ((((y_10 >= 10) ^ (v96 != 0) | (y_10 >= 10 && v96 != 0)) == 0) ^ 0xFE)) != 0))
																									v95 = 116254003;
																								v230 = v95;
																							}
																							v223 = v225 + 2018133368;
																							if (v225 != -2018133368)
																								break;
																							v230 = -2073611748;
																						}
																						v222 = v225 + 1553168711;
																						if (v225 != -1553168711)
																							break;
																						v136 = -821562026;
																						v135 = 1;
																						*v237 = v245 % 257;
																						v231[*v236] = v231[*v237];
																						v246 = &v231[*v236];
																						v59 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
																						v60 = (v135 ^ 1 | 1) & ~(~(v59 == 0) | ~(~(v135 ^ 1 ^ ((v135 ^ 1) & (y_10 < 10) | (y_10 >= 10))) & (v59 == 0) | ~(v59 == 0) & (v135 ^ 1 ^ ((v135 ^ 1) & (y_10 < 10) | (y_10 >= 10)))));
																						v61 = (v59 == 0) & (~(v135 ^ 1 ^ ((v135 ^ 1) & (y_10 < 10) | (y_10 >= 10))) ^ (v59 == 0));
																						v62 = v60 & (~(v135 & ~(~v61 | ~(v135 & ~(~(v135 ^ 1 ^ ((v135 ^ 1) & (v59 == 0) | (v59 != 0))) | ~(y_10 < 10)))) | v135 & v61 ^ v135 & ~(~(v135 ^ 1 ^ ((v135 ^ 1) & (v59 == 0) | (v59 != 0))) | ~(y_10 < 10))) ^ v60);
																						LOBYTE(v59) = v135 & (v135 & ~(~v61 | ~(v135 & ~(~(v135 ^ 1 ^ ((v135 ^ 1) & (v59 == 0) | (v59 != 0))) | ~(y_10 < 10)))) | v135 & v61 ^ v135 & ~(~(v135 ^ 1 ^ ((v135 ^ 1) & (v59 == 0) | (v59 != 0))) | ~(y_10 < 10))) ^ v135 & v60;
																						v63 = v136;
																						if ((((unsigned __int8)(v135 & ~(~(_BYTE)v59 | ~v62)) | (unsigned __int8)(v135 & v59 ^ v135 & v62)) & 1) != 0)
																							v63 = 1098844606;
																						v230 = v63;
																					}
																					v221 = v225 + 1526665970;
																					if (v225 != -1526665970)
																						break;
																					v50 = *v236;
																					v149 = 257;
																					*v236 = (v50 - 746900618 + 746900619) % 257;
																					v230 = 1203764314;
																				}
																				v220 = v225 + 1181503042;
																				if (v225 != -1181503042)
																					break;
																				v103 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
																				v104 = v103 == 0 && y_10 >= 10 != (v103 == 0);
																				v105 = ~(v103 != 0) ^ 1;
																				v106 = (v103 == 0) & ~(v103 == 0);
																				v107 = ~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) & (v106 ^ v105 | v106 & v105) | ~(v106 ^ v105 | v106 & v105) & ((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10));
																				v108 = v103 != 0 || y_10 >= 10 == (v103 == 0);
																				LOBYTE(v103) = !(v107 & 1);
																				v132 = -2018133368;
																				v109 = ~(v107 & (v107 ^ 0xFE) ^ v103 & v107 & 1 | v107 & (v107 ^ 0xFE) & v103 & v107 & 1) & v104 | ~v104 & (v107 & (v107 ^ 0xFE) ^ v103 & v107 & 1 | v107 & (v107 ^ 0xFE) & v103 & v107 & 1);
																				v110 = !(((unsigned __int8)v103 ^ v108) & 1 | (unsigned __int8)v103 & v108);
																				v111 = -2018133368;
																				if ((((unsigned __int8)(v110 ^ v109) | v110 & v109) & 1) != 0)
																					v111 = 1336249809;
																				v230 = v111;
																			}
																			v219 = v225 + 1120819514;
																			if (v225 != -1120819514)
																				break;
																			v236 = v121;
																			v237 = &v121[-4];
																			v230 = 1219733555;
																		}
																		v218 = v225 + 999850455;
																		if (v225 != -999850455)
																			break;
																		v244 = v242 < v243;
																		v230 = -112543344;
																	}
																	v217 = v225 + 960212645;
																	if (v225 != -960212645)
																		break;
																	v248 = v247 + 1;
																	v230 = 2146295135;
																}
																v216 = v225 + 821562026;
																if (v225 != -821562026)
																	break;
																v113 = v245;
																v114 = v245;
																v115 = v245;
																v116 = v245;
																v117 = v245;
																v118 = v245;
																v119 = v245;
																v131 = 257;
																v130 = v245;
																*v237 = v245 % 257;
																v231[*v236] = v231[*v237];
																v230 = -1553168711;
																v129 = v119;
																v128 = v113;
																v127 = v118;
																v126 = v114;
																v125 = v115;
																v124 = v116;
																v123 = v117;
																v122 = v236;
															}
															v215 = v225 + 792732643;
															if (v225 != -792732643)
																break;
															v242 = *v239;
															v230 = -642875351;
														}
														v214 = v225 + 785312399;
														if (v225 != -785312399)
															break;
														v230 = -999850455;
													}
													v213 = v225 + 642875351;
													if (v225 != -642875351)
														break;
													v17 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
													v18 = v17 == 0;
													LOBYTE(v17) = !((y_10 >= 10 && v17 != 0) | (y_10 >= 10) ^ (v17 != 0));
													v19 = v17 & (v17 ^ 0xFE);
													LOBYTE(v17) = !v18 && y_10 < 10;
													v20 = y_10 >= 10 && v18;
													v21 = ((v20 & 1) != 0 && (v17 & 1) != 0) | ~v20 ^ ~(_BYTE)v17;
													LOBYTE(v17) = !(((v20 & 1) != 0 && (v17 & 1) != 0) | ((unsigned __int8)~v20 ^ (unsigned __int8)~(_BYTE)v17) & 1);
													v172 = 1134889144;
													v22 = ~(((v21 & 1) != 0) ^ v17 & (v17 ^ 1) | ((v21 & 1) != 0) & v17 & (v17 ^ 1)) & v19 & (v19 ^ 0xFE) & 1 | ~(v19 & (v19 ^ 0xFE) & 1) & (((v21 & 1) != 0) ^ v17 & (v17 ^ 1) | ((v21 & 1) != 0) & v17 & (v17 ^ 1));
													v23 = 1134889144;
													if (((((unsigned __int8)v17 ^ !(v19 & 1)) & 1 | (unsigned __int8)v17 & !(v19 & 1)) == 0 && (v22 & 1) != 0) | ((((unsigned __int8)v17 ^ !(v19 & 1)) & 1 | (unsigned __int8)v17 & !(v19 & 1)) == 0) ^ v22 & 1)
														v23 = -181568579;
													v230 = v23;
												}
												v212 = v225 + 315361320;
												if (v225 != -315361320)
													break;
												// inited = init_sbox((__int64)v240, v241);
												*v236 = 0;
												*v237 = 0;
												*v238 = 0;
												*v239 = 0LL;
												*v239 = 0LL;
												v230 = 663008872;
												v121[3] = inited;
											}
											v211 = v225 + 259819118;
											if (v225 != -259819118)
												break;
											v45 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
											v46 = (((y_10 >= 10) ^ (v45 == 0)) & (unsigned __int8)(~(v45 == 0) ^ (y_10 >= 10) ^ (v45 == 0))) == 0;
											v150 = 98793841;
											v47 = !((unsigned __int8)~((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) & (v45 == 0) | (unsigned __int8)~(v45 == 0) & (y_10 < 10) & ((y_10 < 10) ^ 0xFE));
											v48 = 98793841;
											if ((((v47 != 0 && (v46 & 1) != 0) | (unsigned __int8)(v47 ^ v46 & 1)) == 0 && (((unsigned __int8)(~v47 & v46) | (unsigned __int8)(~v46 & v47)) & 1) != 0) | (((v47 != 0 && (v46 & 1) != 0) | (unsigned __int8)(v47 ^ v46 & 1)) == 0) ^ ((unsigned __int8)(~v47 & v46) | (unsigned __int8)(~v46 & v47)) & 1)
												v48 = 378077687;
											v230 = v48;
										}
										v210 = v225 + 181568579;
										if (v225 != -181568579)
											break;
										v243 = v234;
										v24 = (((_BYTE)x_9 - 107 + 106) * (_BYTE)x_9) & 1;
										v25 = v24 == 0;
										LOBYTE(v24) = (v24 == 0) & ~(v24 == 0) ^ ~(v24 != 0) ^ 1 | (v24 == 0) & ~(v24 == 0) & (~(v24 != 0) ^ 1);
										v171 = 1134889144;
										v170 = 0;
										v169 = 0;
										v168 = !v25;
										v167 = v25;
										v166 = ~v167;
										v165 = -2;
										v164 = 1;
										v163 = -785312399;
										v162 = v167;
										v161 = -1;
										v160 = 0;
										v159 = -1;
										v158 = -1;
										v157 = 0;
										v156 = 0;
										v155 = 0;
										v154 = v167;
										v153 = 0;
										v152 = 1;
										v26 = ~((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) & (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0) | ~(((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0) & (y_10 < 10) & ((y_10 < 10) ^ 0xFE);
										v27 = v26 ^ (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0) | v26 & (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0);
										v28 = ((v167 & (unsigned __int8)~v167) != 0 && (((unsigned __int8)~v168 ^ 1) & 1) != 0) | v167 & ~v167 ^ (~v168 ^ 1) & 1;
										v29 = ~!((v26 ^ (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0)) & 1 | v26 & (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0));
										v30 = ~(v27 & ~v27);
										v31 = ((v30 & 1 | !!((v26 ^ (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0)) & 1 | v26 & (((y_10 < 10) & ((y_10 < 10) ^ 0xFE)) != 0 && ((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) != 0 && (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) & 0xFE | (((y_10 < 10) & (unsigned __int8)~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & (unsigned __int8)~(y_10 < 10) & (y_10 >= 10)) == 0)) != 0))) == 0) | v30 ^ v29;
										v32 = ~v31 & v28 | ~v28 & v31;
										v33 = ~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) & v24 | ~(_BYTE)v24 & ((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10));
										v34 = !(((unsigned __int8)(v33 ^ v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24)) | (unsigned __int8)(v33 & v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24))) & 1) | ~!(((unsigned __int8)(v33 ^ v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24)) | (unsigned __int8)(v33 & v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24))) & 1) & 0xFE;
										v35 = !(((unsigned __int8)(v33 ^ v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24)) | (unsigned __int8)(v33 & v24 & (~((y_10 < 10) & ~(y_10 < 10) ^ (y_10 >= 10) | (y_10 < 10) & ~(y_10 < 10) & (y_10 >= 10)) ^ v24))) & 1) && (v32 & 1) != 0;
										v36 = ((v34 & 1 ^ v32 & 1 ^ v35) & 1 | (v34 & 1 ^ v32 & 1) & v35) == 0;
										v37 = 1134889144;
										if (!v36)
											v37 = -785312399;
										v230 = v37;
									}
									v209 = v225 + 112543344;
									if (v225 != -112543344)
										break;
									v38 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
									v39 = v38 == 0;
									v40 = ~((y_10 < 10 && y_10 >= 10 && y_10 < 10) | ~(y_10 < 10) ^ ~(y_10 >= 10 && y_10 < 10)) & v39 & (v39 ^ 0xFE) | ~(v39 & (v39 ^ 0xFE)) & ((y_10 < 10 && y_10 >= 10 && y_10 < 10) | ~(y_10 < 10) ^ ~(y_10 >= 10 && y_10 < 10));
									v41 = !!((y_10 >= 10 && v38 != 0) | (y_10 >= 10) ^ (v38 != 0));
									LOBYTE(v38) = (v40 & 1) == 0;
									v151 = 98793841;
									v42 = ~(v40 & ~v40 ^ v38 | v40 & ~v40 & v38) & v41 | ~v41 & (v40 & ~v40 ^ v38 | v40 & ~v40 & v38);
									v43 = (((v38 & 1) != 0 && (v41 & 1) != 0) | ((unsigned __int8)~(_BYTE)v38 ^ (unsigned __int8)~v41) & 1) == 0;
									v36 = (((v43 & (v43 ^ 0xFE) & 1) != 0 && (v42 & 1) != 0) | v43 & (v43 ^ 0xFE) & 1 ^ v42 & 1) == 0;
									v44 = 98793841;
									if (!v36)
										v44 = -259819118;
									v230 = v44;
								}
								v208 = v225 - 98793841;
								if (v225 != 98793841)
									break;
								v230 = -259819118;
							}
							v207 = v225 - 116254003;
							if (v225 != 116254003)
								break;
							v98 = 1565805369;
							v99 = (((_BYTE)x_9 - 110 + 109) * (_BYTE)x_9) & 1;
							v100 = v99 == 0 && ((unsigned __int8)~(y_10 >= 10) & (v99 == 0) | (unsigned __int8)~(v99 == 0) & (y_10 >= 10)) != 0;
							v101 = (y_10 < 10) & ((y_10 < 10) ^ 0xFE);
							v102 = ~((v101 != 0 && y_10 >= 10 && y_10 < 10) | v101 ^ (y_10 >= 10 && y_10 < 10)) ^ (v99 != 0);
							if ((v102 & 1 ^ v100 ^ v100 & (unsigned __int8)(~v102 ^ v100)) & 1 | (v102 & 1 ^ v100) & v100 & (unsigned __int8)(~v102 ^ v100))
								v98 = -1181503042;
							v230 = v98;
						}
						v206 = v225 - 351933680;
						if (v225 != 351933680)
							break;
						v51 = (((_BYTE)x_9 - 84 + 83) * (_BYTE)x_9) & 1;
						v52 = (v51 == 0) & 0xFE | (v51 != 0);
						v148 = -821562026;
						v147 = 0;
						v146 = -2;
						v145 = v51 != 0;
						v144 = 0;
						v143 = y_10 < 10;
						v142 = 0;
						v141 = y_10 < 10;
						v140 = 0;
						v139 = -1553168711;
						v138 = y_10 < 10;
						v53 = ~((((y_10 < 10 && ((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) != y_10 >= 10 && ((y_10 >= 10) & (unsigned __int8)(~(y_10 < 10 && ((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) ^ (y_10 >= 10))) != 0) | ((unsigned __int8)~((y_10 < 10 && ((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) ^ (y_10 >= 10)) ^ (unsigned __int8)~((y_10 >= 10) & (~(y_10 < 10 && ((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) ^ (y_10 >= 10)))) & 1) != 0) ^ (((unsigned __int8)(~((v52 & 1) == 0) ^ v52 & 1 & ~(v52 & 1) | ~((v52 & 1) == 0) & v52 & 1 & ~(v52 & 1)) & ((unsigned __int8)(~((v52 & 1) == 0) ^ v52 & 1 & ~(v52 & 1) | ~((v52 & 1) == 0) & v52 & 1 & ~(v52 & 1)) ^ 0xFE) & 1) == 0);
						v54 = ~(v52 & (~(y_10 >= 10) ^ v52));
						v55 = ~(~(y_10 >= 10) ^ (v52 == 0));
						v137 = 0;
						v56 = ((((v55 | v54) & 1) == 0) | (v55 ^ v54) & 1) != 0;
						LOBYTE(v51) = v53 & (~!v56 ^ v53);
						v57 = ~!v56 ^ ((v53 & 1) == 0);
						v36 = (((unsigned __int8)(v57 ^ v51) | (unsigned __int8)(v57 & v51)) & 1) == 0;
						v58 = -821562026;
						if (!v36)
							v58 = -1553168711;
						v230 = v58;
					}
					v205 = v225 - 378077687;
					if (v225 != 378077687)
						break;
					v49 = 928509080;
					if (v244)
						v49 = -1526665970;
					v230 = v49;
				}
				v204 = v225 - 663008872;
				if (v225 != 663008872)
					break;
				// v7 = init_sbox((__int64)v240, v241);
				v8 = -315361320;
				*v236 = 0;
				*v237 = 0;
				*v238 = 0;
				*v239 = 0LL;
				*v239 = 0LL;
				v9 = ((-96 - (-95 - (_BYTE)x_9)) * (_BYTE)x_9) & 1;
				v10 = ~((((v9 == 0) & (unsigned __int8)~(v9 == 0) ^ (unsigned __int8)~(v9 != 0) ^ 1) & 1 | (v9 == 0) & (unsigned __int8)~(v9 == 0) & ((unsigned __int8)~(v9 != 0) ^ 1)) == 0);
				v190 = v7;
				v189 = v10 & 1 | !(v10 & 1);
				v188 = 0;
				v187 = 0;
				v186 = !v189;
				v185 = 0;
				v184 = -2;
				v11 = !((y_10 < 10) & 0xFE | (y_10 >= 10)) & (~((y_10 < 10) & 0xFE | (y_10 >= 10)) ^ !((y_10 < 10) & 0xFE | (y_10 >= 10)));
				v183 = (v9 == 0) ^ v186;
				v182 = ~v183;
				v12 = ((v183 != 0 && (v186 & (unsigned __int8)(~(v9 == 0) ^ v186)) != 0) | ((unsigned __int8)~v183 ^ (unsigned __int8)~(v186 & (~(v9 == 0) ^ v186))) & 1) == 0 && ((((unsigned __int8)~(y_10 < 10) & v11 & 1 | (unsigned __int8)~v11 & (y_10 < 10)) != 0 && (v11 & (unsigned __int8)(~(y_10 < 10) ^ v11) & 1) != 0) | ((unsigned __int8)~(~(y_10 < 10) & v11 | ~v11 & (y_10 < 10)) ^ (unsigned __int8)~(v11 & (~(y_10 < 10) ^ v11))) & 1) != 0;
				v13 = ((((unsigned __int8)~(y_10 < 10) & v11 & 1 | (unsigned __int8)~v11 & (y_10 < 10)) != 0 && (v11 & (unsigned __int8)(~(y_10 < 10) ^ v11) & 1) != 0) | ((unsigned __int8)~(~(y_10 < 10) & v11 | ~v11 & (y_10 < 10)) ^ (unsigned __int8)~(v11 & (~(y_10 < 10) ^ v11))) & 1) == 0 && ((v183 != 0 && (v186 & (unsigned __int8)(~(v9 == 0) ^ v186)) != 0) | ((unsigned __int8)~v183 ^ (unsigned __int8)~(v186 & (~(v9 == 0) ^ v186))) & 1) != 0;
				v181 = (((v9 == 0) & (unsigned __int8)~(v9 == 0) ^ (unsigned __int8)~(v9 != 0) ^ 1) & 1 | (v9 == 0) & (unsigned __int8)~(v9 == 0) & ((unsigned __int8)~(v9 != 0) ^ 1)) == 0;
				v180 = 1;
				v179 = 0;
				v178 = 0;
				v14 = (((((y_10 < 10) & 0xFE | (y_10 >= 10)) == 0 && v181) | (((y_10 < 10) & 0xFE | (y_10 >= 10)) == 0) ^ v181) == 0) & ((((((y_10 < 10) & 0xFE | (y_10 >= 10)) == 0 && v181) | (((y_10 < 10) & 0xFE | (y_10 >= 10)) == 0) ^ v181) == 0) ^ 0xFE);
				LOBYTE(v7) = v14 ^ ~(((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) ^ ((v10 & (v10 ^ 0xFE) & 1) == 0) | v14 & (~(((y_10 < 10) & 0xFE | (y_10 >= 10)) != 0) ^ ((v10 & (v10 ^ 0xFE) & 1) == 0));
				v15 = v7 & (v7 ^ 0xFE);
				v177 = 1;
				v176 = 1;
				v175 = 0;
				v174 = 0;
				v173 = 0;
				LOBYTE(v9) = ~((v15 & 1) == 0 && (((v13 & 1) != 0 && (v12 & 1) != 0) | ((unsigned __int8)~v13 ^ (unsigned __int8)~v12) & 1) != 0);
				v16 = ~(~((v15 & 1) == 0) ^ ((((v13 & 1) != 0 && (v12 & 1) != 0) | ((unsigned __int8)~v13 ^ (unsigned __int8)~v12) & 1) == 0));
				if ((((v16 | (unsigned __int8)v9) & 1) == 0) | (v16 ^ (unsigned __int8)v9) & 1)
					v8 = 1121218413;
				v230 = v8;
			}
			v203 = v225 - 685809515;
			if (v225 != 685809515)
				break;
			v231[*v237] = *v246;
			v64 = (unsigned __int8)v231[*v237] + (unsigned __int8)v231[*v236];
			v134 = -1;
			*v238 = v64 % 257;
			v65 = *(unsigned __int8 *)(v235 + *v239);
			v66 = v231[*v238];
			v67 = (v134 ^ 0x7E050B95 | ~v134 & 0x7E050B95) ^ ((v134 ^ 0x7E050B95) & ((v134 ^ 0xD7FABE8 | 0xD7FABE8) & ~(~(v65 & ~v65) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581))) | ((v134 ^ 0xD7FABE8) & v65 & ~v65 | ~(v65 & ~v65) & 0xD7FABE8) ^ ((v134 ^ 0xD7FABE8) & ((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) & 0xD7FABE8)) | ~((v134 ^ 0xD7FABE8 | 0xD7FABE8) & ~(~(v65 & ~v65) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581))) | ((v134 ^ 0xD7FABE8) & v65 & ~v65 | ~(v65 & ~v65) & 0xD7FABE8) ^ ((v134 ^ 0xD7FABE8) & ((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) | ~((v134 ^ 0xDDA7B581 | ~v134 & 0xDDA7B581) ^ ((v134 ^ 0xDDA7B581) & (unsigned __int8)v65 | ~v65 & 0xDDA7B581)) & 0xD7FABE8)) & 0x7E050B95);
			v68 = ~v67 & 0x5F51A4D1 | (v134 ^ 0x5F51A4D1) & v67;
			v69 = v68 & (v134 ^ 0x5F51A4D1 ^ v68);
			LOBYTE(v67) = ~(_BYTE)v134 & v65 | ~*(_BYTE *)(v235 + *v239);
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
			*(_BYTE *)(v235 + *v239) = ~v86 & v74 | ~(_BYTE)v74 & v86;
			v230 = 2134803275;
		}
		v202 = v225 - 928509080;
		if (v225 == 928509080)
			break;
		v201 = v225 - 1098844606;
		if (v225 == 1098844606)
		{
			v230 = 685809515;
		}
		else
		{
			v200 = v225 - 1104335566;
			if (v225 == 1104335566)
			{
				v4 = -315361320;
				v5 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
				v6 = (~(y_10 >= 10) ^ (v5 != 0)) & (~(v5 == 0) ^ ~(y_10 >= 10) ^ (v5 != 0));
				LOBYTE(v5) = ~(y_10 >= 10) ^ (v5 == 0);
				if ((((unsigned __int8)(~(_BYTE)v5 ^ ((v6 & 1) == 0) ^ v6 & (~(_BYTE)v5 ^ v6)) | (unsigned __int8)((~(_BYTE)v5 ^ ((v6 & 1) == 0)) & v6 & (~(_BYTE)v5 ^ v6))) & 1) != 0)
					v4 = 663008872;
				v230 = v4;
			}
			else
			{
				v199 = v225 - 1121218413;
				if (v225 == 1121218413)
				{
					v230 = -792732643;
				}
				else
				{
					v198 = v225 - 1134889144;
					if (v225 == 1134889144)
					{
						v230 = -181568579;
					}
					else
					{
						v197 = v225 - 1203764314;
						if (v225 == 1203764314)
						{
							v245 = (unsigned __int8)v231[*v236] + *v237;
							v230 = 351933680;
						}
						else
						{
							v196 = v225 - 1219733555;
							if (v225 == 1219733555)
							{
								v238 = v121;
								v239 = (unsigned __int64 *)&v121[-4];
								v235 = v227;
								v234 = v228;
								v233 = v229;
								v232 = v226;
								v240 = v231;
								v241 = v229;
								v230 = 1104335566;
							}
							else
							{
								v195 = v225 - 1224336791;
								if (v225 == 1224336791)
								{
									v87 = -2018133368;
									v88 = (((_BYTE)x_9 - 1) * (_BYTE)x_9) & 1;
									v89 = (~(y_10 >= 10) ^ (v88 != 0)) & (~(v88 == 0) ^ ~(y_10 >= 10) ^ (v88 != 0));
									v90 = (v89 & 1) == 0;
									v91 = v89 & ~v89;
									v92 = (((unsigned __int8)~((((y_10 < 10) & (unsigned __int8)~(y_10 < 10)) != 0 && y_10 >= 10) | ~((y_10 < 10) & ~(y_10 < 10)) ^ ~(y_10 >= 10)) ^ (v88 == 0)) & 1) == 0;
									v93 = (v91 ^ v90 | v91 & v90) & 1;
									v94 = !((v92 ^ v90 | (v92 && v90)) & 1);
									if (((v94 & (v94 ^ 0xFE) ^ (unsigned __int8)(v92 ^ v93) | v94 & (v94 ^ 0xFE) & (unsigned __int8)(v92 ^ v93)) & 1) != 0)
										v87 = -2073611748;
									v230 = v87;
								}
								else
								{
									v194 = v225 - 1336249809;
									if (v225 == 1336249809)
									{
										v230 = -792732643;
									}
									else
									{
										v193 = v225 - 1565805369;
										if (v225 == 1565805369)
										{
											v230 = 116254003;
										}
										else
										{
											v192 = v225 - 2134803275;
											if (v225 == 2134803275)
											{
												v247 = *v239;
												v230 = -960212645;
											}
											else
											{
												v191 = v225 - 2146295135;
												if (v225 == 2146295135)
												{
													*v239 = v248;
													v230 = 1224336791;
												}
											}
										}
									}
								}
							}
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
	unsigned char flag[32] = "1111111111111111111111";
	int i;

	rc4(flag, 32, "JustDoIt!", 9);
	for (i = 0; i < 32; i++)
	{
		printf("%02x", flag[i]);
	}
	return 0;
}