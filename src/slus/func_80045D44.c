#include "types.h"

extern u8 D_80078C80[];
extern s8 D_8007A438[];
extern s8 D_8007A638[];
extern X4_S16Pair D_80076ECC[];

void func_80045D44(u8* arg0, u8* arg1, s8 arg2) {
    s16 dx;
    s16 dy;
    s32 i;

    i = arg1[0x47] * 2;
    if (D_80078C80[arg1[0x17]] == 0) {
        dx = D_8007A438[i];
        dy = D_8007A438[i + 1];
    } else {
        dx = D_8007A638[i];
        dy = D_8007A638[i + 1];
    }
    if (arg0[0x15] != 0) {
        *(s16*)(arg0 + 0xA) = *(s16*)(arg1 + 0xA) - dx;
        *(s16*)(arg0 + 0xA) -= D_80076ECC[arg2].lo;
    } else {
        *(s16*)(arg0 + 0xA) = dx + *(s16*)(arg1 + 0xA);
        *(s16*)(arg0 + 0xA) += D_80076ECC[arg2].lo;
    }
    *(s16*)(arg0 + 0xE) = dy + *(s16*)(arg1 + 0xE);
    *(s16*)(arg0 + 0xE) += D_80076ECC[arg2].hi;
}
