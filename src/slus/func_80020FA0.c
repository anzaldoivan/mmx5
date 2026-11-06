#include "types.h"

extern s32 DrawSync(s32);
extern void MoveImage(void*, s32, s32);
extern void func_8001A028(s32);
extern u8 D_800710FC[];
extern u8 D_80071104[];

void func_80020FA0(s8* arg0) {
    if (arg0[1] == 0) {
        MoveImage(D_800710FC, 0x240, 0);
        DrawSync(0);
        if (arg0[0xC] == 0xB && arg0[0x44] != 0) {
            func_8001A028(8);
        }
        if (arg0[0xC] == 0xC) {
            if (arg0[0x44] != 0) {
                func_8001A028(9);
            }
        }
        MoveImage(D_80071104, 0x140, 0xB0);
        DrawSync(0);
        ((u8*)arg0)[1]++;
        return;
    }
    arg0[0xD] = 1;
    arg0[0] = 8;
    arg0[1] = 0;
}
