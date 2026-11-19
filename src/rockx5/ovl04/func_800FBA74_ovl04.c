#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s32 D_80102C1C_ovl04[][4];
extern u16 D_80102CDC_ovl04[][4];

static inline u8* func_800FBA74_ovl04_spawn(u8* o, s32 kind) {
    u8* p;

    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x18;
        p[2] = kind;
        *(u8**)(p + 0x50) = o;
    }
    return p;
}

void func_800FBA74_ovl04(u8* o) {
    s32 idx;
    s32 kind;
    u32 r;
    s32 x;

    if (*(s16*)(o + 0x88) != 0) {
        if (--*(s16*)(o + 0x88) != 0) {
            return;
        }
    }
    if (*(s8*)(o + 0x8C) == 1 && !(D_8009A420_as_s32 & 1)) {
        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = random_byte() & 3;
        }
        idx = D_80102C1C_ovl04[*(s8*)(o + 0x91)][*(s8*)(o + 0x90)];
        kind = 6;
        r = random_byte();
        if (r & 4) {
            kind = 4;
        }
        if (*(s16*)(o + 0xE) >= 0x371 && kind >= 6) {
            kind = 4;
        }
        {
            u8* p = func_800FBA74_ovl04_spawn(o, kind);

            if (p != 0) {
                x = *(u16*)(o + 0xA) + D_80102CDC_ovl04[idx][0];
                *(s16*)(p + 0xA) = x;
                *(s16*)(p + 0xE) = *(u16*)(o + 0xE) + D_80102CDC_ovl04[idx][2];
                if (r & 1) {
                    *(s16*)(p + 0xA) = x - 8;
                } else if (r & 2) {
                    *(s16*)(p + 0xA) = x + 8;
                }
            }
        }
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 t;

            t = random_byte();
            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(t % 3) + 8;
        }
    } else if (*(s8*)(o + 0x8C) == 0 && !(D_8009A420_as_s32 & 7)) {
        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = random_byte() & 3;
        }
        idx = D_80102C1C_ovl04[*(s8*)(o + 0x91)][*(s8*)(o + 0x90)];
        kind = 6;
        r = random_byte();
        if (r & 4) {
            kind = 4;
        }
        if (*(s16*)(o + 0xE) >= 0x371 && kind >= 6) {
            kind = 4;
        }
        {
            u8* p = func_800FBA74_ovl04_spawn(o, kind);

            if (p != 0) {
                x = *(u16*)(o + 0xA) + D_80102CDC_ovl04[idx][0];
                *(s16*)(p + 0xA) = x;
                *(s16*)(p + 0xE) = *(u16*)(o + 0xE) + D_80102CDC_ovl04[idx][2];
                if (r & 1) {
                    *(s16*)(p + 0xA) = x - 8;
                } else if (r & 2) {
                    *(s16*)(p + 0xA) = x + 8;
                }
            }
        }
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 t;

            t = random_byte();
            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(t % 51) + 40;
        }
    } else if (*(s8*)(o + 0x8C) == -1 && !(D_8009A420_as_s32 & 1)) {
        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = random_byte() & 3;
        }
        idx = D_80102C1C_ovl04[*(s8*)(o + 0x91)][*(s8*)(o + 0x90)];
        kind = 6;
        r = random_byte();
        if (r & 4) {
            kind = 4;
        }
        if (*(s16*)(o + 0xE) >= 0x371 && kind >= 6) {
            kind = 4;
        }
        {
            u8* p = func_800FBA74_ovl04_spawn(o, kind);

            if (p != 0) {
                x = *(u16*)(o + 0xA) + D_80102CDC_ovl04[idx][0];
                *(s16*)(p + 0xA) = x;
                *(s16*)(p + 0xE) = *(u16*)(o + 0xE) + D_80102CDC_ovl04[idx][2];
                if (r & 1) {
                    *(s16*)(p + 0xA) = x - 8;
                } else if (r & 2) {
                    *(s16*)(p + 0xA) = x + 8;
                }
            }
        }
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 t;

            t = random_byte();
            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(t % 51) + 40;
        }
    }
}
