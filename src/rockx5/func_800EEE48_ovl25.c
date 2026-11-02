#include "types.h"

extern s8 D_8009A424;
extern u8 D_800D1F3C;
extern u8 D_8009A2A3;
extern u8 D_800F0EF4_ovl25[];
extern u8 D_800F0CF4_ovl25[];
extern u8 D_800F12F4_ovl25[];
extern u8 D_800F10F4_ovl25[];
extern u8 D_800F16F4_ovl25[];
extern u8 D_800F14F4_ovl25[];
extern u8 D_800F1AF4_ovl25[];
extern u8 D_800F18F4_ovl25[];
extern u8 D_800F1EF4_ovl25[];
extern u8 D_800F1CF4_ovl25[];
extern u8 D_800F22F4_ovl25[];
extern u8 D_800F20F4_ovl25[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);

void func_800EEE48_ovl25(u8* arg0) {
    if (D_8009A424 == 0) {
        if (((s8*)arg0)[2] == 0) {
            if (D_800D1F3C == 2) {
                arg0[2]++;
            }
        } else {
            (*(u16*)(arg0 + 4))++;
            if (*(s16*)(arg0 + 4) >= 0x3D) {
                func_8002C3CC(D_800F0EF4_ovl25, D_800F0CF4_ovl25, 0x100, 0, 0);
                func_8002C338(0x50, D_800F0EF4_ovl25, 0x10);
                func_8002C3CC(D_800F12F4_ovl25, D_800F10F4_ovl25, 0x100, 0, 0);
                func_8002C338(0x60, D_800F12F4_ovl25, 0x10);
                func_8002C3CC(D_800F16F4_ovl25, D_800F14F4_ovl25, 0x100, 0, 0);
                func_8002C338(0x70, D_800F16F4_ovl25, 0x10);
                func_8002C3CC(D_800F1AF4_ovl25, D_800F18F4_ovl25, 0x100, 0, 0);
                func_8002C338(0x80, D_800F1AF4_ovl25, 0x10);
                func_8002C3CC(D_800F1EF4_ovl25, D_800F1CF4_ovl25, 0x100, 0, 0);
                func_8002C338(0x90, D_800F1EF4_ovl25, 0x10);
                func_8002C3CC(D_800F22F4_ovl25, D_800F20F4_ovl25, 0x100, 0, 0);
                func_8002C338(0xA0, D_800F22F4_ovl25, 0x10);
                D_8009A2A3 = 1;
                arg0[2] = 0;
                arg0[1]++;
            }
        }
    }
}
