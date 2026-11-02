#include "types.h"

extern u8 D_80091C45;
extern s16 D_8007B814[][6];
extern s16 D_8007B846;
extern s16 D_8007B852;

void func_80051370(u8* p) {
    if (D_80091C45 != 4) {
        return;
    }
    switch (*(s8*)(p + 2)) {
    case 1:
        *(s16*)(p + 0x1A) += 4;
        *(s16*)(p + 0x22) += 4;
        *(s16*)(p + 0x2A) += 4;
        *(s16*)(p + 0x32) += 4;
        if (*(s16*)(p + 0x1A) < D_8007B846 + *(s16*)(p + 0x48)) {
            return;
        }
        p[5]++;
        break;
    case 2:
        *(s16*)(p + 0x1A) -= 4;
        *(s16*)(p + 0x22) -= 4;
        *(s16*)(p + 0x2A) -= 4;
        *(s16*)(p + 0x32) -= 4;
        if (*(s16*)(p + 0x1A) > D_8007B852 + *(s16*)(p + 0x48)) {
            return;
        }
        p[5]++;
        break;
    case 3:
    case 4:
        *(s16*)(p + 0x1A) += 4;
        *(s16*)(p + 0x22) += 4;
        *(s16*)(p + 0x2A) -= 4;
        *(s16*)(p + 0x32) -= 4;
        if (*(s16*)(p + 0x1A) <
            D_8007B814[*(s8*)(p + 2) + 3][1] + *(s16*)(p + 0x48)) {
            return;
        }
        p[4]++;
        break;
    }
}
