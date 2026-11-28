#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_800F5974_ovl20

#define func_800EEA80_ovl05 func_800F472C_ovl20
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F4768_ovl20(u8* a0) {
    if ((u32)(g_playthrough_state.u[1] - 8) < 2) {
        a0[3] = 0;
        return;
    }
    if (((s8*)a0)[2] == 0) {
        if (g_playthrough_state.u[0xCB] & 1) {
            set_animation_frame(a0, 0, 1);
        } else {
            set_animation_frame(a0, 0, 0);
        }
    } else {
        if (g_playthrough_state.u[0xCB] & 1) {
            set_animation_frame(a0, 1, 1);
        } else {
            set_animation_frame(a0, 1, 0);
        }
    }
    func_8002D9EC(a0, 0x80, 0x40);
}

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F4830_ovl20(u8* a0) {
    u8* p = g_playthrough_state.u;
    s32 v = ((s8*)p)[1];
    s32 a2;

    if (v == 8) {
        a2 = 1;
        if (p[0xCB] & 1) {
            a2 = 3;
        }
    } else if (v == 9) {
        a2 = 2;
        if (p[0xCB] & 1) {
            a2 = 4;
        }
    } else {
        a2 = 0;
    }
    set_animation_frame(a0, 3, a2);
    func_8002D9EC(a0, 0x80, 0x40);
}

void func_800F48C8_ovl20(u8* a0) {
    if (D_800D1C30.s != 0) {
        clear_object_slot();
    } else {
        func_8002D9EC(a0, 0x80, 0x40);
    }
}

extern u16 D_800F596C_ovl20[][2];

void func_800F4908_ovl20(u8* a0) {
    u8* p = g_playthrough_state.u;

    if (((s8*)p)[0x30] != 0) {
        clear_object_slot();
    } else {
        *(u16*)(a0 + 0xA) = D_800F596C_ovl20[((s8*)p)[0x31]][0];
        *(u16*)(a0 + 0xE) = D_800F596C_ovl20[((s8*)p)[0x31]][1] + 5;
        func_8002D9EC(a0, 0x80, 0x40);
    }
}
