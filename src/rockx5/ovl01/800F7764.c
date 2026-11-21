#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F7764_ovl01(u8* obj) {
    set_animation(obj, 7);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x8C) = 0x32;
    obj[6]++;
}

extern s32 D_8009A0A8;

void func_800F77B0_ovl01(u8* p) {
    s32 g;
    u8 c;

    if (--*(s16*)(p + 0x8C) == -1) {
        g = D_8009A0A8;
        c = p[6];
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = 0xFFFE0000;
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s32*)(p + 0x8) = g;
        p[6] = c + 1;
    }
}

void func_800F7804_ovl01(u8* a0) {
    move_object(a0);
    if (is_off_screen(a0, 0x300, -0x10) == 0) {
        a0[6]++;
    }
}

extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FD2D0_ovl01[];

void func_800F7850_ovl01(u8* a0) {
    move_object(a0);
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            return;
        }
    }
    func_8004FD24(a0);
    func_8004D4F4(2, D_800FD2D0_ovl01, a0);
    a0[4] = 3;
}
