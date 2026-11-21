#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "addr.h"

extern u8 D_800FB2D0_ovl09[];
extern u8 D_800FB2DC_ovl09[];

void func_800F8920_ovl09(u8* obj) {
    set_animation(obj, 1);
    obj[0x62] = 2;
    obj[0x60] = 8;
    *(u8**)(obj + 0x50) = D_800FB2D0_ovl09;
    *(u8**)(obj + 0x68) = D_800FB2DC_ovl09;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = -0x20000;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0;
    obj[6]++;
}

void func_800F8998_ovl09(u8* a0) {
    move_object(a0);
    switch (D_1F80004C.bytes[0x84]) {
    case 1:
        if (*(s16*)(a0 + 0xE) >= 0x898) {
            *(s16*)(a0 + 0xE) = 0x898;
            a0[6]++;
        }
        break;
    case 2:
        if (*(s16*)(a0 + 0xE) >= 0x8D0) {
            *(s16*)(a0 + 0xE) = 0x8D0;
            a0[6]++;
        }
        break;
    case 3:
        if (*(s16*)(a0 + 0xE) >= 0x908) {
            *(s16*)(a0 + 0xE) = 0x908;
            a0[6]++;
        }
        break;
    }
}

void func_800F8A68_ovl09(u8* arg0) {
    u8* p;

    if (arg0[0x47] == 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        p[0x85] |= 1 << (((s8*)arg0)[2] - 1);
        arg0[6]++;
    }
}

void func_800F8AB8_ovl09(u8* o) {
    o[0x62] = 0;
    *(s32*)(o + 0x50) = 0;
    o[5] = 3;
    o[6] = 0;
}
