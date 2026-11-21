#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"

extern void func_800F90AC_ovl09(u8* obj);

void func_800F8B0C_ovl09(u8* obj) {
    set_animation(obj, 0xC);
    func_800F90AC_ovl09(obj);
    obj[6]++;
}

extern u8 D_800FB2DC_ovl09[];
extern void func_800F8F80_ovl09(u8*);
extern void func_800F8FE4_ovl09(u8*, s16, s16, u8);

void func_800F8B48_ovl09(u8* a0) {
    s32 v = ((s8*)a0)[0x45];

    if (v == 1) {
        *(u8**)(a0 + 0x68) = D_800FB2DC_ovl09;
        D_1F80004C.bytes[0x86] = v;
        *(s16*)(a0 + 0x7C) = 0x60;
        func_800F8F80_ovl09(a0);
        func_800F8FE4_ovl09(a0, *(s16*)(a0 + 0xA), *(s16*)(a0 + 0xE), 1);
        play_sound(2, 0x26, 0);
        a0[6]++;
    }
}

extern void silence_sound(s32, s32);
extern void func_800F8ED0_ovl09(u8*, s32);
extern void func_800F8FE4_ovl09(u8*, s16, s16, u8);

void func_800F8BCC_ovl09(u8* p) {
    if (--*(s16*)(p + 0x7C) == 0) {
        if (D_1F80004C.bytes[0x84] == 2) {
            silence_sound(2, 0x26);
        }
        play_sound(2, 0x25, 0);
        func_800F8ED0_ovl09(p, 0);
        func_800F8ED0_ovl09(p, 1);
        func_800F8FE4_ovl09(p, *(s16*)(p + 0xA), *(s16*)(p + 0xE), 2);
        *(s16*)(p + 0x7C) = 0x84;
        p[6]++;
    }
}

void func_800F8C7C_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        D_1F80004C.bytes[0x86] = 0;
        set_animation(obj, 0xD);
        obj[5] = 4;
        obj[6] = 0;
    }
}
