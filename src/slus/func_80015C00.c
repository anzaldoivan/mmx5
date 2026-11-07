#include "types.h"

extern s32 func_80066D78(s32, s32);
extern void* func_80066D98(void* func);
extern s32 CdControlB(s32, s32, u8*);
extern s32 func_80014464(void);
extern s32 CdControl(s32, u8*, u8*);
extern u8 D_8009811C;
extern s32 D_800E5A40;
extern s32 D_800E5A18;
extern s32 D_800E5BD8;
extern s32 D_800E5BE4;
extern s32 D_800BE9A8;
extern s32 D_8009E790;

void func_80015C00(void) {
    if (D_8009811C != 0) {
        D_800E5A40++;
        if (func_80066D78(1, 0) != 1) {
        err: // !FAKE: label kept for the matching branch layout
            func_80066D98(0);
            CdControlB(9, 0, 0);
            D_8009811C = 0x80;
        } else if (func_80014464() == -1) {
            goto err; // !FAKE: goto kept for the matching branch layout
        } else if (D_800E5A18 == 0) {
            func_80066D98(0);
            D_8009811C = 0;
            while (CdControl(9, 0, 0) == 0) {
            }
            D_8009811C = 2;
            D_800BE9A8 = D_800E5BD8;
            D_8009E790 = D_800E5BE4;
        }
    }
}
