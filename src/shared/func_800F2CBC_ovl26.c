/* Shared body (DK-5), from the banked draft of func_800F2CBC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u16 D_800FA0A4_ovl26[][2];
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* o) {
    u8* c;
    u8* p;
    s32 a;
    s32 v;
    s32 w;
    s32 y;

    func_80017248(o);
    if (--*(s16*)(o + 0x7C) != 0) {
        return;
    }
    c = func_8002D1A4();
    if (c != 0) {
        c[0] = 0x41;
        c[1] = 0x17;
        c[2] = 0x10;
        c[0x15] = 0;
        *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
        *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
        *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
        *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
        if (o[0x15] != 0) {
            v = *(u16*)(o + 0xA) -
                (D_800FA0A4_ovl26[D_1F80004C.bytes[0x94]][0] - 0x80);
            *(s16*)(c + 0xA) = v;
        } else {
            w = *(u16*)(o + 0xA) - 0x80;
            *(s16*)(c + 0xA) = D_800FA0A4_ovl26[D_1F80004C.bytes[0x94]][0] + w;
        }
        y = *(u16*)(o + 0xE) - 0x76;
        *(s16*)(c + 0xE) = D_800FA0A4_ovl26[D_1F80004C.bytes[0x94]][1] + y;
        *(s32*)(c + 0x20) = 0;
        *(s32*)(c + 0x24) = 0;
        *(u8**)(c + 0x7C) = o;
        p = D_8009A0A0;
        a = ratan2(*(s16*)(p + 0xE) - *(s16*)(c + 0xE),
                   *(s16*)(p + 0xA) - *(s16*)(c + 0xA));
        *(s32*)(c + 0x20) = rcos(a) * 96;
        *(s32*)(c + 0x24) = -rsin(a) * 96;
    }
    *(s16*)(o + 0x7C) = 0x28;
    o[6]++;
}
