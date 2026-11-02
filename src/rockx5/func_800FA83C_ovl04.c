#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern u32 func_8002DF78(void);
extern s32 func_800F033C_ovl04(void);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800FA83C_ovl04(u8* o) {
    u8 f;
    s32 v;
    u32 r;
    s32 m;
    u8* g;
    s32 t;
    u8* g2;
    u8* h2;

    if (func_800F033C_ovl04() != 0) {
        g = D_8009A1F8;
        m = *(s16*)(g + 0xA);
        if (m == 0x280 || m == 0x3EE || m == 0x620) {
            *(s8*)(o + 0x8C) = 1;
            o[0x97] = 1;
            v = func_8002DF78() & 1;
            *(s16*)(o + 0x88) = v + 8;
            func_8002A600(0x3C, 3, 2);
        } else if (m == 0x37A || m == 0x54E) {
            *(s8*)(o + 0x8C) = -1;
            o[0x97] = 0;
            r = func_8002DF78();
            v = (u8)(r % 20) + 20;
            *(s16*)(o + 0x88) = v;
            func_8002A600(0x1E, 2, 2);
        }
        if (*(s8*)(o + 0x8C) == 1) {
            *(s32*)(o + 0x84) += 0x10000;
        } else if (*(s8*)(o + 0x8C) == -1) {
            *(s32*)(o + 0x84) -= 0x4000;
        }
        t = (s32)D_800D1C00;
        if (*(s8*)(t + 0x27) != 0) {
            *(s32*)(o + 0x84) += 0xFFFF0000;
            *(u8*)(t + 0x27) = 0;
        }
        if (*(s32*)(o + 0x84) > 0x4FFFFF) {
            *(s32*)(o + 0x84) = 0x500000;
            *(s8*)(o + 0x8C) = 0;
        } else if (*(s32*)(o + 0x84) < 0) {
            *(s32*)(o + 0x84) = 0;
            *(s8*)(o + 0x8C) = 0;
        }
        t = o[0x97];
        g2 = D_8009A1F8;
        if (t != 0 && (m = *(u16*)(g2 + 0x34)) == 0) {
            if (t == 1) {
                func_8002A600(0x1E, 2, 2);
                m = o[0x97];
                m++;
                o[0x97] = m;
            } else if (t == 2) {
                func_8002A600(0x1E, 1, 2);
                o[0x97] = 0;
            }
        }
        h2 = D_800D1C00;
        f = h2[0x26];
        if (!(f & 2) && (f & 1) && *(s8*)(o + 0x8C) == 0) {
            if (*(s16*)(o + 0x8A) == 0 || --*(s16*)(o + 0x8A) == 0) {
                *(s16*)(o + 0x8A) = 0x28;
                func_8002A600(8, 2, 1);
            }
        }
    }
}
