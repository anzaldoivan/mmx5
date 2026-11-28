#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);
extern u32* D_80098118;
extern s8 D_800D1C2A;
extern u8 D_800F58CC_ovl20[];

void func_800F3F20_ovl20(u8* o) {
    u8* p;
    u8* q;
    u8 r;

    ((u8**)o)[0xC] = D_800F58CC_ovl20;
    if (((s8*)o)[2] == 0) {
        ((s16*)o)[0x21] = 0x7800;
        ((s16*)o)[0x20] = D_80098118[0] >> 7;
        p = (u8*)D_1F800020.s32s;
        p += ((s32*)p)[0];
        ((u16*)o)[5] = 0x2F0;
        ((u16*)o)[7] = 0xD0;
        ((u8**)o)[0xF] = p;
        set_animation_frame(o, 6, D_800D1C2A);
        r = 2;
    } else {
        if (g_playthrough_state.s[0x2A] == 5) {
            ((s16*)o)[0x21] = 0x7808;
            ((s16*)o)[0x20] = D_80098118[2] >> 7;
            q = (u8*)D_1F800020.s32s;
            q += ((s32*)q)[2];
            ((u8**)o)[0xF] = q;
        } else {
            ((s16*)o)[0x21] = 0x7804;
            ((s16*)o)[0x20] = D_80098118[1] >> 7;
            q = (u8*)D_1F800020.s32s;
            q += ((s32*)q)[1];
            ((u8**)o)[0xF] = q;
        }
        ((u16*)o)[5] = 0x300;
        ((u16*)o)[7] = 0xA8;
        if (g_playthrough_state.s[0x2A] == 5 &&
            (g_playthrough_state.s[0x4A] & 0x10)) {
            set_animation(o, 7);
        } else {
            set_animation(o, g_playthrough_state.s[0x2A]);
        }
        r = 1;
    }
    o[4] = r;
    o[0x16] = 3;
    o[0x14] = 1;
    o[0x15] = 0;
}

extern u32* D_80098118;

void func_800F40B0_ovl20(u8* p) {
    if ((s8)g_playthrough_state.u[0x32] != 0) {
        p[0] &= 0xEF;
    } else {
        p[0] |= 0x10;
    }
    animate_object(p);
    if ((s8)g_playthrough_state.u[0x2A] != *(s8*)(p + 0x54)) {
        if ((s8)g_playthrough_state.u[0x2A] == 5) {
            u32* t = D_80098118;
            *(u16*)(p + 0x42) = 0x7808;
            *(u16*)(p + 0x40) = t[2] >> 7;
            *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[2];
        } else {
            u32* t = D_80098118;
            *(u16*)(p + 0x42) = 0x7804;
            *(u16*)(p + 0x40) = t[1] >> 7;
            *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[1];
        }
        if ((s8)g_playthrough_state.u[0x2A] == 5) {
            if (g_playthrough_state.u[0x4A] & 0x10) {
                set_animation(p, 7);
            } else {
                goto other; // !FAKE: goto kept for the matching branch layout
            }
        } else {
        other:
            set_animation(p, (s8)g_playthrough_state.u[0x2A]);
        }
    }
    func_8002D89C(p);
}
