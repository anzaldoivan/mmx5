/* Shared body (DK-5), from the banked draft of func_800F7738_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj8002CD14* DEDUP_CALLEE(Obj8002CD14* p, s32 backward);
extern Ent6E78 D_80101D60_ovl04[][37];

void DEDUP_NAME(u8* o) {
    u8* c;
    u8* e;
    s32 i;
    s8 n;
    Ent6E78* b;

    b = D_80101D60_ovl04[0];
    n = o[2];
    e = (u8*)&b[o[0x82] * 37 + n];
    if (e[2] == 0) {
        o[6] = 2;
        return;
    }
    if (n == 0) {
        return;
    }
    if (*(s16*)(o + 0xA) - *(s16*)(o + 0x80) < 0x20) {
        return;
    }
    for (i = 0;
         i < (u8)(*(u32*)&D_80101D60_ovl04[0][o[0x82] * 37 + (s8)o[2]] >> 16);
         i++) {
        c = (u8*)DEDUP_CALLEE((Obj8002CD14*)o, 0);
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 7;
            *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
            *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
            *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
            *(u16*)(c + 0x42) = *(u16*)(o + 0x42);
            c[2] = (u8)(o[2] - 1) - i;
            *(u16*)(c + 0xA) = *(u16*)(o + 0xA) - 0x20;
            *(s32*)(c + 0xC) = 0;
            *(s32*)(c + 0x20) = *(s32*)(o + 0x20);
            *(s32*)(c + 0x24) = 0;
            *(s32*)(c + 0x7C) = *(s32*)(o + 0x7C);
            c[0x82] = o[0x82];
            *(u16*)(c + 0x80) = *(u16*)(o + 0x80);
        }
        o[6] = 2;
    }
}
