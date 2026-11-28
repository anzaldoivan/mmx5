#include "types.h"

extern void SsSepClose(s32);
extern s32 SsVabClose(s32);
extern s8 D_80093E6C[];
extern s8 D_80093E60[];
extern u8 D_800E8040[];
extern s8 D_800E8028[];

void func_80016384(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if (D_80093E6C[i] != -1) {
            SsSepClose(D_80093E6C[i]);
            D_80093E6C[i] = -1;
        }
    }
    for (i = 0; i < 6; i++) {
        if (D_80093E60[i] != -1) {
            SsVabClose(D_80093E60[i]);
            D_80093E60[i] = -1;
        }
    }
    for (i = 0; i < 4; i++) {
        D_800E8040[i] = 0xFF;
    }
    for (i = 0; i < 24; i++) {
        D_800E8028[i] = -1;
    }
}
