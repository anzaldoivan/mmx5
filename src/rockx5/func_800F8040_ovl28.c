#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_8009A0A0[];
extern u8 D_800FE750_ovl28[];

void func_800F8040_ovl28(u8* o) {
    s8 st;
    s8 tl;
    s16 dx;
    s16 dy;
    s16 ang;
    u8* p;
    u8* q;
    u8* g;
    u8* g2;
    u8* g3;
    u8* g4;

    func_800317B8(o);
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        if (*(s8*)(o + 5) == 0) {
            p = *(u8**)(o + 0x7C);
            p[7]++;
        }
        o[4] = 2;
        return;
    }
    st = *(s8*)(o + 5);
    switch (st) {
    case 0:
        g = D_8009A0A0;
        dx = (*(s16*)(g + 0xA) - *(s16*)(o + 0xA) < 0)
                 ? *(s16*)(o + 0xA) - *(s16*)(g + 0xA)
                 : *(s16*)(g + 0xA) - *(s16*)(o + 0xA);
        g2 = D_8009A0A0;
        dy = (*(s16*)(g2 + 0xE) - *(s16*)(o + 0xE) >= 0)
                 ? *(s16*)(g2 + 0xE) - *(s16*)(o + 0xE)
                 : *(s16*)(o + 0xE) - *(s16*)(g2 + 0xE);
        if (o[0x70] != 0 || dx + dy < 0x30) {
            q = *(u8**)(o + 0x7C);
            q[7]++;
            *(u8**)(o + 0x68) = D_800FE750_ovl28;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(u32*)(o + 0x8C) = 0;
            o[5]++;
        }
        break;
    case 1:
        if (++*(u32*)(o + 0x8C) == 0x78) {
            g3 = D_8009A0A0;
            if (*(s16*)(g3 + 0xA) < *(s16*)(o + 0xA)) {
                o[0x15] = 0;
            } else {
                o[0x15] = 0x40;
            }
            g4 = D_8009A0A0;
            ang = ratan2(*(s16*)(g4 + 0xE) - *(s16*)(o + 0xE),
                         *(s16*)(g4 + 0xA) - *(s16*)(o + 0xA));
            *(s32*)(o + 0x20) = rcos(ang) << 6;
            *(s32*)(o + 0x24) = -rsin(ang) << 6;
            *(u32*)(o + 0x8C) = 0;
            o[0x70] = 0;
            o[5]++;
        }
        break;
    case 2:
        if (++*(u32*)(o + 0x8C) >= 2 && o[0x70] != 0) {
            o[4] = 2;
        }
        break;
    }
    tl = *(s8*)(*(u8**)(o + 0x7C) + 4);
    if (tl == 2) {
        o[4] = tl;
    }
    func_8002D9EC(o, 0x20, 0x20);
    func_80017248(o);
    func_8002DF54(o);
}
