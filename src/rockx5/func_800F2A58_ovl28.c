#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8* func_8002D1A4();
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s8 D_800D1C00[];
extern u8 D_8009A0A0[];

void func_800F2A58_ovl28(u8* obj) {
    u8* p;
    s8 st;
    s32 ang;
    s32 t;
    s16 v;
    u8* g;
    u8* g2;

    func_80017248(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    st = D_800D1C00[0x2A];
    if (st == 1) {
        D_800D1C00[0x2A] = 2;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0x23;
            p[2] = st;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            g = D_8009A0A0;
            if (*(s16*)(g + 0xA) > *(s16*)(obj + 0xA)) {
                p[0x15] = 0x40;
            } else {
                p[0x15] = 0;
            }
            *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            g2 = D_8009A0A0;
            ang = ratan2(*(s16*)(g2 + 0xE) - *(s16*)(obj + 0xE),
                         *(s16*)(g2 + 0xA) - *(s16*)(obj + 0xA));
            *(s32*)(p + 0x20) = rcos(ang);
            *(s32*)(p + 0x24) = -rsin(ang);
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (--*(s16*)(obj + 0x7E) == -1) {
        *(u16*)(obj + 0x42) ^= 0x8000;
        obj[0x61] -= 5;
        if ((s8)obj[0x61] >= 0x1A) {
            obj[0x61] = 0;
        }
        t = (s8)obj[0x61];
        v = t < 6;
        if (v) {
            v = 5;
        } else {
            v = t;
        }
        *(s16*)(obj + 0x7E) = v;
    }
    if (D_800D1C00[0x2A] == 2) {
        *(u16*)(obj + 0x42) &= 0x7FFF;
        D_800D1C00[0x2A] = 0;
        obj[5] = 3;
    }
}
