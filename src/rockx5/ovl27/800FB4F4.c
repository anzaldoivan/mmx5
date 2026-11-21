#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define func_800EF574_ovl09 func_800FB4F4_ovl27
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09

extern s8 D_8009A0A2;
extern u8 D_800D1C49;
extern u8 D_800FDB78_ovl27[];
extern u8 D_800FDB84_ovl27[];

void func_800FB520_ovl27(u8* a0) {
    move_object(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(s32*)(a0 + 0x50) = 0;
        } else if (((s8*)a0)[2] == 2) {
            *(u8**)(a0 + 0x50) = D_800FDB78_ovl27;
        } else {
            *(u8**)(a0 + 0x50) = D_800FDB84_ovl27;
        }
        *(s16*)(a0 + 0x88) = 0x28;
        a0[6] = 2;
    }
}

void func_800FB5BC_ovl27(u8* a0) {
    u8 st = a0[2];

    if ((u8)(st - 2) < 2) {
        if (--*(s16*)(a0 + 0x88) == 0) {
            *(s32*)(a0 + 0x20) = ((s8)st == 2) ? -0x4000 : 0x4000;
            *(s16*)(a0 + 0x88) = 0x40;
            a0[6] = 3;
        }
    }
}

void func_800FB620_ovl27(u8* obj) {
    move_object(obj);
    if (--*(s16*)(obj + 0x88) == 0) {
        obj[4] += 1;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80041AB8.c, AGPL-3.0 (THIRD_PARTY.md). */

extern void (*D_800FDBB8_ovl27[])(s8*);

void func_800FB670_ovl27(s8* arg0) {
    D_800FDBB8_ovl27[arg0[7]](arg0);
}
