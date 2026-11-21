#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800FAAC8_ovl28(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    *(u16*)(a0 + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(a0 + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(a0 + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(a0 + 0x3C) = *(s32*)(p + 0x3C);
    a0[0x14] = 0;
    a0[0x16] = 1;
    a0[0x67] = 0;
    a0[0x3] = 0;
    *(s32*)(a0 + 0x68) = 0;
    *(s32*)(a0 + 0x50) = 0;
    *(s32*)(a0 + 0x54) = 0;
    *(s32*)(a0 + 0x58) = 0;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0;
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    a0[0x5C] = 0;
    a0[0x60] = 0;
    a0[0x5] = 0;
    a0[0x4]++;
}

void func_800FAB50_ovl28(u8* o) {
    u8* p;
    u8* q;
    s8 t;
    s32 st;

    p = *(u8**)(o + 0x7C);
    o[0x15] = p[0x15];
    if (o[0x15] == 0) {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) + 0x1E;
    } else {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) - 0x1E;
    }
    q = *(u8**)(o + 0x7C);
    *(u16*)(o + 0xE) = *(u16*)(q + 0xE) + 8;
    st = (s8)o[5];
    switch (st) {
    case 0:
        if ((s8)q[0x45] == 9) {
            set_animation(o, 0x13);
            o[5]++;
        }
        break;
    case 1:
        if (__builtin_abs(*(s32*)(q + 0x20)) != 0x42000 ||
            ((s8*)o)[0x46] == 0) {
            o[5]--;
        }
        func_8002D9EC(o, 0x20, 0x20);
        animate_object(o);
        move_object(o);
        break;
    }
    t = (*(u8**)(o + 0x7C))[4];
    if (t == 2) {
        o[4] = t;
    }
}

#define D_800EEBA0_ovl00 func_800FAC70_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
