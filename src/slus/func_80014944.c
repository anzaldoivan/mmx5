#include "types.h"

extern s32 CdIntToPos(s32, void*);
extern s32 CdControlB(s32, s32, u8*);
extern s32 func_80066D78(s32, s32);
extern s32 CdControl(s32, u8*, u8*);
extern int VSync(int mode);
extern u8 D_8009811C;
extern s32 D_800E5A24;
extern s32 D_800E5A40;
extern u8 D_800E5A48;

void func_80014944(void) {
    u8 result[8];
    u8 param;

    param = 0xA0;
    D_800E5A40 = 0;
    CdIntToPos(D_800E5A24, &D_800E5A48);
    for (;;) {
        do {
            while (CdControlB(1, 0, result) == 0) {
            }
        } while (result[0] & 0x40);
        while (func_80066D78(1, 0) != 0) {
        }
        if (CdControl(0xE, &param, 0) == 0) {
            continue;
        }
        VSync(3);
        if (CdControl(2, &D_800E5A48, 0) != 0) {
            break;
        }
    }
    while (CdControl(6, 0, 0) == 0) {
    }
    D_8009811C = 1;
}
