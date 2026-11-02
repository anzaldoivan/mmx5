#include "types.h"

extern void func_8002ABA4(u8*);
extern void func_8002AC34(u8*);
extern s32 func_8002DF78(void);
extern s32 func_8003D29C(s32, s32);
extern void func_800FA350_ovl04(u8*);
extern void func_800FA83C_ovl04(void);
extern u8 D_8009A1F8[];
extern s32 D_8009A420;
extern u8 D_800D1C00[];
extern u8 D_80102AD0_ovl04[];

void func_800FAAA0_ovl04(u8* o) {
    u8* g;
    u8* h;
    u8* k;
    s16 y;
    s32 r;
    s32 t;
    s32 v;

    if (D_800D1C00[0x26] & 1) {
        func_800FA83C_ovl04();
        func_800FA350_ovl04(o);
        if (*(u16*)(D_800D1C00 + 0x28) == 0) {
            g = D_8009A1F8;
            y = *(s16*)(g + 0xA);
            if (y < 0x620) {
                if (o[0x8D] == 0 || --o[0x8D] == 0) {
                    r = func_8002DF78() & 0xF;
                    D_800D1C00[0x28] = D_80102AD0_ovl04[r * 2];
                    D_800D1C00[0x29] = (&D_80102AD0_ovl04[r * 2])[1];
                    o[0x8D] = 0xB4;
                }
            } else if (y < 0x9FF) {
                if (y == 0x78F || y == 0x858 || y == 0x8B4 || y == 0x92A ||
                    y == 0x9A8 || y == 0x9E8) {
                    D_800D1C00[0x28] = 0x30;
                }
            }
        }
    }
    if (D_800D1C00[0x26] & 2) {
        func_8003D29C(0x14, 0);
        o[5]++;
    }
    h = D_8009A1F8;
    t = *(s16*)(o + 0x86);
    *(s16*)(o + 0xA) = *(u16*)(h + 0xA) + t;
    if (((s8*)D_800D1C00)[0x2B] == 2) {
        if (D_8009A420 & 2) {
            v = *(u16*)(h + 0xE) + 0x76;
        } else {
            v = *(u16*)(h + 0xE) + 0x7A;
        }
    } else {
        v = *(u16*)(h + 0xE) + 0x78;
    }
    *(s16*)(o + 0xE) = v;
    k = D_8009A1F8;
    if (*(u16*)(k + 0x34) & 0x10) {
        func_8002ABA4(k);
    }
    if (*(u16*)(k + 0x34) & 1) {
        func_8002AC34(k);
    }
}
