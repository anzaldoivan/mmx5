#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/sound.h"

extern u8* alloc_class3_slot(void);

void func_800F9E98_ovl27(u8* a0) {
    u8* base = D_8009A1F8.u;
    u8* p;

    base[0x48] = 1;
    base[0x47] = 1;
    *(s16*)(base + 0x24) = 0x12A0;
    *(s16*)(base + 0x26) = 0x12A0;
    *(s16*)(base + 0x28) = 0;
    *(s16*)(base + 0x2A) = 0;
    p = alloc_class3_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x18;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
        a0[6]++;
    }
}

extern signed char D_8009A0A5;

void func_800F9F20_ovl27(u8* a0) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        if ((*(s8**)(D_1F80004C.bytes + 0x80))[1] != 0x18) {
            p = g_playthrough_state.u;
            p[0x2A] = 1;
            p[0x2B] = 0;
            a0[6]++;
        }
    }
}

extern s32 func_80024548(s32);

void func_800F9F84_ovl27(u8* a0) {
    u8* p = g_playthrough_state.u;

    if (((s8*)p)[0x2B] != 0) {
        a0[0x5C] = 0;
        p[0x25] = 0;
        *(u8**)(p + 0x20) = a0;
        p[0xA2] = 0x40;
        func_80024548(1);
        p[0xA2] &= 0xFC;
        a0[6]++;
    }
}

#define func_800EFFE4_ovl04 func_800F9FFC_ovl27
#include "shared/func_800EFFE4_ovl04.c"
#undef func_800EFFE4_ovl04

extern void func_80044DD0(s32 a0);
extern u8 D_800D1C24;

void func_800FA010_ovl27(u8* o) {
    D_800D1C24 = 1;
    func_80044DD0(0);
    o[6]++;
}

extern s32 func_80044DE0(void);
extern void func_800FAD04_ovl27(u8* o, s32 a, s32 b);

void func_800FA050_ovl27(u8* o) {
    if (func_80044DE0() == 0) {
        func_800FAD04_ovl27(o, 4, 1);
        *(s16*)(o + 0x7C) = 2;
        o[6]++;
    }
}

#include "shared/func_800FA09C_ovl27.c"

extern u8 D_800FDABC_ovl27[];

void func_800FA12C_ovl27(u8* arg0) {
    s8* p;

    ((s32(*)())func_80028B18)(1, 0x12A0, 0x20, D_800FDABC_ovl27);
    p = g_playthrough_state.s;
    D_8009A298.s = 1;
    D_1F80004C.bytes[0x84] = p[0xA2] / 4;
    D_1F80004C.bytes[0x85] = p[0xA2] / 4;
    D_1F80004C.bytes[0x86] = p[0xA2] / 4;
    D_1F80004C.bytes[0x87] = p[0xA2] / 4;
    arg0[5] = 3;
    arg0[6] = 0;
}
