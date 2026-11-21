#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FBF98_ovl38(u8* arg0) {
    func_800FCAA0_ovl38(arg0);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    if (arg0[0x15] == 0) {
        if (*(s16*)(arg0 + 0xA) < 0x11A0) {
            set_animation(arg0, 3);
            arg0[6] = 3;
            return;
        }
    } else if (*(s16*)(arg0 + 0xA) > 0x1280) {
        set_animation(arg0, 3);
        arg0[6] = 3;
        return;
    }
    set_animation(arg0, 4);
    arg0[6]++;
}

extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];
extern u8 D_800FD588_ovl38[];

void func_800FC048_ovl38(u8* p) {
    if (*(s8*)(p + 0x45) != 0) {
        *(u8**)(p + 0x50) = D_800FD580_ovl38;
        *(u8**)(p + 0x54) = D_800FD584_ovl38;
        *(u8**)(p + 0x68) = D_800FD588_ovl38;
        if (p[0x15] == 0) {
            *(s32*)(p + 0x20) = -0x28000;
        } else {
            *(s32*)(p + 0x20) = 0x28000;
        }
        *(s32*)(p + 0x28) = 0x3200;
        *(s32*)(p + 0x24) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s16*)(p + 0x7C) = 8;
        play_sound(2, 0xA1, p);
        p[6]++;
    }
}

extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern void func_800FCE6C_ovl38(u8* a0);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC0E8_ovl38(u8* arg0) {
    u8 t = arg0[0x15];

    if ((t == 0 && (arg0[0x70] & 2)) || (t == 0x40 && (arg0[0x70] & 1))) {
        set_animation(arg0, 3);
        *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
        *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
        *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
        arg0[6]++;
        return;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s16*)(arg0 + 0x7C) = 8;
        func_800FCC24_ovl38(arg0, 4);
    }
    func_800FCE6C_ovl38(arg0);
}

extern void func_800FAC40_ovl38();
#define D_800EEBA0_ovl00 func_800FC1BC_ovl38
#define func_8002D720 func_800FAC40_ovl38
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
