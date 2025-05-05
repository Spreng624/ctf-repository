#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _BYTE unsigned char
#define LOBYTE(x) ((x))

int main()
{

    unsigned char flag;
    unsigned char v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v11;

    unsigned char v133, v134, v135, v136, v137, v138, v139, v140, v141, v142, v143, v144, v145, v146, v147, v148, v149, v150, v151, v152, v153, v154, v155, v156, v157, v158, v159, v160, v161, v162, v163, v164, v165, v166, v167, v168, v169, v170, v171, v172, v173, v174;
    unsigned char *v236, *v237, *v246, *v238, *S_box[256];

    // *v237 = v245 % 257;
    // v231[*v236] = v231[*v237];

    v246 = &S_box[*v236];
    // v245 = (unsigned __int8)S_box[*v236] + *v237;

    S_box[*v237] = S_box[*v236];

    v64 = (unsigned __int8)S_box[*v237] + (unsigned __int8)S_box[*v236];
    v134 = -1;
    *v238 = v64 % 257;
    v65 = flag;

    v66 = S_box[*v238];

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
}