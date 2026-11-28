#include "types.h"
#include "mmx5/ovl20.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F3D38_ovl20
#define func_8002D720 func_8002D89C
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800D1C00_as_D1C00_800F3D58 (*(D1C00_800F3D58*)&g_playthrough_state)
extern s32 D_800F51F0_ovl20[];

void func_800F3D58_ovl20(u8* a0) {
    if (D_800F51F0_ovl20[((s8*)a0)[2]] &
        D_800D1C00_as_D1C00_800F3D58.mask[D_800D1C00_as_D1C00_800F3D58.idx]) {
        func_8002D89C(a0);
    } else {
        a0[3] = 0;
    }
}
#undef D_800D1C00_as_D1C00_800F3D58

void func_800F3DC8_ovl20(u8* a0) {
    *(s16*)(a0 + 0xA) = D_800F5724_ovl20.s[g_playthrough_state.s[0x32]][0];
    *(s16*)(a0 + 0xE) = D_800F5724_ovl20.s[g_playthrough_state.s[0x32]][1];
    func_8002D89C(a0);
}

extern s32 D_800F51F0_ovl20[];
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F3E24_ovl20(u8* a0) {
    u8* p = g_playthrough_state.u;

    set_animation_frame(a0, 1, ((s8*)p)[0x32]);
    if (D_800F51F0_ovl20[((s8*)p)[0x32]] & *(s32*)(p + 0x84)) {
        func_8002D89C(a0);
    } else {
        a0[3] = 0;
    }
}

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F3EA0_ovl20(u8* a0) {
    s8* p = (s8*)g_playthrough_state.u;
    s8 mode = p[0x30];

    if (mode == 4) {
        set_animation_frame(a0, 5, p[0x31]);
    } else if (mode == 2) {
        set_animation_frame(a0, 5, p[0x31] + 5);
    } else {
        set_animation_frame(a0, 5, 8);
    }
    func_8002D89C(a0);
}
