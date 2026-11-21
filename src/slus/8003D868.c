#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/system.h"

extern void silence_sound(s32, s32);
extern void start_pad_vibration(s32);
extern u8 D_800D1C00[];

void func_8003D868(u8* p) {
    u8* g;

    silence_sound(1, 5);
    silence_sound(1, 7);
    start_pad_vibration(0);
    if (((s8*)p)[0xD5] != 0) {
        p[3] = 0;
        p[0xD7] = 1;
    } else {
        g = D_800D1C00;
        g[0x12] = 1;
        g[0x13] = 1;
        g[0x14] = 1;
        g[0x15] = 1;
        g[0x16] = 1;
        g[0x17] = 1;
        g[0x18] = 1;
        g[0x19] = 1;
        g[0x1A] = 1;
        p[0xD7] = 8;
        func_8003B33C(p, 0x21);
    }
    p[5]++;
}

extern void func_8003D9A8(u8*);
extern u8 D_800D1C00[];

void func_8003D914(u8* p) {
    u8* g;

    if (--((s8*)p)[0xD7] == 0) {
        g = D_800D1C00;
        g[0x12] = 0;
        g[0x13] = 0;
        g[0x14] = 0;
        g[0x15] = 0;
        g[0x16] = 0;
        g[0x17] = 0;
        g[0x18] = 0;
        g[0x19] = 0;
        g[0x1A] = 0;
        p[3] = 0;
        play_sound(3, 0xC, p);
        p[0xD7] = 0;
        p[0xD6] = 0;
        p[5]++;
        func_8003D9A8(p);
    }
}

extern void func_8003DAA4(s32 arg0);
extern void func_8003DAF4(s32 arg0);

void func_8003D9A8(u8* obj) {
    u32 i;
    s8 state;
    s32 t;
    s32 m;

    if (!(obj[0xD7] & 3)) {
        i = 0;
        do {
            i++;
            t = random_byte() & 0x1F;
            m = -0x80;
            func_8003DAA4(t | m);
            m = 0; // !FAKE: dead second set of m stops loop.c hoisting the constant
        } while (i < 4);
    }
    state = *(s8*)(obj + 0xD6);
    if (state != 3) {
        if (*(s8*)(obj + 0xD7) == 0) {
            func_8003DAF4(state);
            if (*(s8*)(obj + 0xD6) == 2) {
                func_8003DAF4(3);
            }
            obj[0xD7] = 0x12;
            obj[0xD6]++;
            return;
        }
        obj[0xD7]--;
        return;
    }
    obj[0xD7] = 0x14;
    obj[5]++;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003DACC.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003DA7C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD7) != 0) {
        M2C_FIELD(arg0, s8*, 0xD7) = (s8)((u8)M2C_FIELD(arg0, s8*, 0xD7) - 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s8*, 5) = 0;
}
