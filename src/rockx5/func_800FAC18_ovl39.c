#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 rsin(s32);
extern u8 D_800FEB3C_ovl39[][4];

void func_800FAC18_ovl39(u8* o) {
    s32 s;
    s32 v;
    u8* p;
    u8 t;

    func_800171E8(o, 0);
    s = rsin(*(s16*)(o + 0x80));
    v = s << 4;
    *(s16*)(o + 0x80) = (*(s16*)(o + 0x80) + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 9;
    }
    *(s32*)(o + 0xC) = 0x8200000 - v;
    if (*(s16*)(o + 0x82) != 0) {
        *(s16*)(o + 0x82) -= 1;
        return;
    }
    if (*(s16*)(o + 0xE) == 0x820) {
        p = *(u8**)(o + 0x7C);
        t = p[0x89];
        if (t == 1) {
            o[0x87] = 6;
            o[0x88] = t;
        }
        if (*(s8*)(*(u8**)(o + 0x7C) + 7) != 0x11) {
            o[5] = 7;
        } else {
            o[5] = D_800FEB3C_ovl39[o[0x87]][++o[0x88]];
        }
        o[6] = 0;
        if (*(s8*)(o + 5) == 2) {
            *(s16*)(o + 0x82) = 0xB4;
        }
    }
}
