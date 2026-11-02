#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern s8 D_800D1C0C;
extern s8 D_800D1C0F;

void func_80029184(u8* o) {
    u8* p;
    u8* p1;
    u8* p2;
    u8* p4;
    s16 lim;

    if (*(s16*)(o + 0x1C) < *(s16*)(o + 0xA)) {
        *(s16*)(o + 0xA) = *(u16*)(o + 0x1C);
        if (D_800D1C0C == 5 && (s8)D_8009A0A0[0xD5] != 0) {
            goto skip; // !FAKE: goto kept for the matching branch layout
        }
        lim = *(u16*)(o + 0x1C) + 0x140;
        p1 = D_8009A0A0;
        if (*(s16*)(p1 + 0xA) + 8 >= lim) {
            *(s16*)(p1 + 0xA) = *(u16*)(o + 0x1C) + 0x138;
        }
    }
    if (*(s16*)(o + 0x1E) >= *(s16*)(o + 0xA)) {
        *(s16*)(o + 0xA) = *(u16*)(o + 0x1E);
        if (D_800D1C0C == 5 && (s8)D_8009A0A0[0xD5] != 0) {
            goto skip; // !FAKE: goto kept for the matching branch layout
        }
        p2 = D_8009A0A0;
        if (*(s16*)(p2 + 0xA) - 8 < *(s16*)(o + 0x1E)) {
            *(s16*)(p2 + 0xA) = *(u16*)(o + 0x1E) + 8;
        }
    }
skip:
    p = D_8009A0A0;
    if (*(s16*)(p + 0xE) < 0 && D_800D1C0F == 0) {
        *(s16*)(p + 0xE) = 0;
    }
    if (*(s16*)(o + 0x20) < *(s16*)(o + 0xE)) {
        *(s16*)(o + 0xE) = *(u16*)(o + 0x20);
        lim = *(u16*)(o + 0x20) + 0x100;
        p4 = D_8009A0A0;
        if (*(s16*)(p4 + 0xE) - 8 >= lim) {
            u8 t = p4[0x5C];
            u8* q = D_800D1C00;
            *(s8*)(p4 + 0x5C) = -0x80;
            *(s32*)(q + 0xB8) += t & 0x7F;
        }
    } else if (*(s16*)(o + 0x22) >= *(s16*)(o + 0xE)) {
        *(s16*)(o + 0xE) = *(u16*)(o + 0x22);
    }
}
