#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC398_ovl38(u8* arg0) {
    set_animation(arg0, 9);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    func_800FCAA0_ovl38(arg0);
    arg0[6]++;
}

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);

void func_800FC3F8_ovl38(ObjFC3F8* arg0) {
    s32 state = arg0->unk45;

    if (state == 1) {
        D_1F80004C.bytes[0x92] = state;
        func_800FCB74_ovl38(arg0, 0);
        play_sound(2, 0x9F, arg0);
        state = 0x32;
        arg0->unk7C = state;
    } else if (state == 2) {
        set_animation(arg0, 9);
        func_800FCAA0_ovl38(arg0);
        arg0->unk6++;
    }
}

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);

void func_800FC484_ovl38(ObjFC3F8* arg0) {
    s32 state = arg0->unk45;

    if (state == 1) {
        func_800FCB74_ovl38(arg0, 1);
        play_sound(2, 0x9F, arg0);
        state = 0x32;
        arg0->unk7C = state;
    } else if (state == 2) {
        set_animation(arg0, 9);
        func_800FCAA0_ovl38(arg0);
        arg0->unk6++;
    }
}

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);

void func_800FC504_ovl38(ObjFC3F8* arg0) {
    s8 state = arg0->unk45;

    if (state == 1) {
        func_800FCB74_ovl38(arg0, 0);
        func_800FCB74_ovl38(arg0, 2);
        play_sound(2, 0x9F, arg0);
    } else if (state == 2) {
        set_animation((u8*)arg0, 3);
        arg0->unk6++;
    }
}

/* Standalone twin of func_800F28B4_ovl00 (src/shared/func_800F28B4_ovl00.c): flag byte 0x92. */

#define G D_1F80004C.bytes
void func_800FAC40_ovl38(void);

void func_800FC580_ovl38(void) {
    if (G[0x92] == 0) {
        func_800FAC40_ovl38();
    }
}
