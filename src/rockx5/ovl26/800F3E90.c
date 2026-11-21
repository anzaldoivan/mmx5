#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/system.h"

#include "shared/func_800F3E90_ovl26.c"

extern u8* alloc_class3_slot(void);
extern s8 D_800D1C0F;
extern signed char D_8009A0A5;
extern u8 D_8009A1F8[];

void func_800F3EC8_ovl26(u8* a0) {
    u8* g;
    u8* p;

    if (D_800D1C0F == 0 && D_8009A0A5 == 0x14) {
        g = D_8009A1F8;
        *(s32*)(a0 + 0x90) = (s8)g[0x48];
        g[0x48] = 1;
        g[0x47] = 2;
        func_8003D29C(0x1D, 0x40);
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x84) = p;
        }
        *(s16*)(a0 + 0x7C) = 0xA0;
        a0[6]++;
    }
}

extern s32 func_80044DE0();
extern u8 D_8009A1F8[];

void func_800F3F78_ovl26(u8* a0) {
    u8* g;

    if (func_80044DE0(a0) == 0) {
        g = D_8009A1F8;
        *(s16*)(g + 0x26) = 0x8B0;
        if ((s8)++a0[0x5C] == D_800D1CA2) {
            D_1F80004C.bytes[0x95] = D_800D1CA2;
            g[0x48] = 8;
            *(s32*)(a0 + 0x8C) = 0;
            *(s32*)(a0 + 0x90) = 0;
            D_1F80004C.bytes[0x8D] = 1;
            ((s32(*)())func_8003D2C4)();
            a0[6]++;
        }
    }
}

void func_800F4014_ovl26(u8* obj) {
    D_1F80004C.bytes[0x94] = (u32)random_byte() % 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 1;
    obj[6]++;
}

extern u16 D_800F9F24_ovl26[][32];

void func_800F407C_ovl26(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7E) == 0 && (c = func_8002D1A4()) != 0) {
        c[0] = 0x41;
        c[1] = 0x17;
        c[2] = o[0x7C];
        c[0x15] = 0;
        *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
        *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
        *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
        *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
        *(s16*)(c + 0xA) = 0x8A0;
        *(u16*)(c + 0xE) =
            D_800F9F24_ovl26[D_1F80004C.bytes[0x94]][*(s16*)(o + 0x7C) * 2];
        *(s32*)(c + 0x20) = 0x60000;
        *(s32*)(c + 0x28) = 0;
        *(s32*)(c + 0x24) = 0;
        *(s32*)(c + 0x2C) = 0;
        *(u8**)(c + 0x7C) = o;
        c[0x94] = D_1F80004C.bytes[0x94];
        if (*(s16*)(o + 0x7C) == 0xF) {
            o[6]++;
            return;
        }
        *(s16*)(o + 0x7C) += 1;
        *(s16*)(o + 0x7E) = 0x23;
    }
}

void func_800F41A0_ovl26(u8* arg0) {
    if (((s8*)arg0)[7] == 0x10) {
        arg0[7] = 0;
        arg0[6]++;
    }
}

void func_800F41C8_ovl26(u8* o) {
    if (*(s8*)(o + 7) == 2) {
        o[5] = 3;
        o[6] = 0;
    }
}
