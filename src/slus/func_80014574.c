#include "types.h"

extern s32 CdIntToPos(s32, void*);
extern s32 func_80066D78(s32, s32);
extern s32 CdControl(s32, u8*, u8*);
extern int VSync(int mode);
extern void* func_80066D98(void* func);
extern u8 D_8009811C;
extern s32 D_800E5A24;
extern s32 D_800E5A30;
extern s32 D_800E5A40;
extern u8 D_800E5A48;
extern void func_80014A30(void);
extern void func_80015C00(void);

void func_80014574(void) {
    u8 param;

    param = 0xA0;
    D_8009811C = 0;
    D_800E5A40 = 0;
    CdIntToPos(D_800E5A24, &D_800E5A48);
    D_800E5A24 -= 1;
    for (;;) {
        if (func_80066D78(1, 0) != 0) {
            continue;
        }
        if (CdControl(0xE, &param, 0) == 0) {
            continue;
        }
        VSync(3);
        if (CdControl(2, &D_800E5A48, 0) != 0) {
            break;
        }
    }
    if (D_800E5A30 == 0) {
        func_80066D98(func_80015C00);
    } else {
        func_80066D98(func_80014A30);
    }
    while (CdControl(6, 0, 0) == 0) {
    }
    D_8009811C = 1;
}
