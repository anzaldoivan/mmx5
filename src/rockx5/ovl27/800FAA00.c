#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800FD6F4_ovl27[];
extern u8 D_800FD6F0_ovl27[];

void func_800FAA00_ovl27(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 2) {
        play_sound(2, 0x6B, a0);
    }
    if (*(s8*)(a0 + 0x45) == 1) {
        *(void**)(a0 + 0x50) = D_800FD6F4_ovl27;
        *(void**)(a0 + 0x54) = D_800FD6F0_ovl27;
        *(s32*)(a0 + 0x68) = 0;
        *(s16*)(a0 + 0x7C) = 0x28;
        a0[6]++;
    }
}

extern void func_800FAF38_ovl27(u8* arg0);
extern s8 D_800D1C44;

void func_800FAA7C_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0x11);
        D_1F80004C.bytes[0x8A] = 1;
        func_800FAF38_ovl27(obj);
        *(s16*)(obj + 0x7C) = 0x78;
        if (D_800D1C44 != 0) {
            *(s16*)(obj + 0x7E) = 9;
        } else {
            *(s16*)(obj + 0x7E) = 5;
        }
        obj[6]++;
    }
}

extern void func_800FAF38_ovl27(u8* arg0);
extern s8 D_800D1C44;

void func_800FAB0C_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        D_1F80004C.bytes[0x8A] = 0;
        set_animation(obj, 0xF);
        obj[6]++;
    } else if (--*(s16*)(obj + 0x7E) == 0) {
        s16 t;
        func_800FAF38_ovl27(obj);
        t = 9;
        if (D_800D1C44 == 0) {
            t = 5;
        }
        *(s16*)(obj + 0x7E) = t;
    }
}

#define func_800FA980_ovl27 func_800FABAC_ovl27
#include "shared/func_800FA980_ovl27.c"
#undef func_800FA980_ovl27
