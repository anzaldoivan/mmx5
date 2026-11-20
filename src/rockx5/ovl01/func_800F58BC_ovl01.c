#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_80028A20(s32 a0, s32 a1, s32 a2, s16* a3);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F6110_ovl01(u8* a0);
extern void func_800F6EE8_ovl01(u8* a0);
extern s32 func_800F71E8_ovl01(s32 a0, s32 a1);
extern u8 D_8009A1F8[];
extern u16 D_8009A202;
extern u8 D_8009A244;
extern s8 D_800D1C44;
extern u8 D_800FCD80_ovl01[];
extern u8 D_800FCF84_ovl01[];
extern void* D_800FD268_ovl01[];

static inline void func_800F58BC_ovl01_spawn(u8* obj, s32 x) {
    s16 buf[4];

    buf[0] = x & 0xFFF0;
    buf[1] = 0x230;
    buf[2] = 0x14;
    buf[3] = 0xC;
    func_80028A20(*(s8*)(obj + 0x14), x & 0xFFF0, 0x130, buf);
}

void func_800F58BC_ovl01(u8* obj) {
    u8* scr;
    u8* g;
    u16 a;
    u16 b;
    u8* d;
    u8* e;

    if (!(obj[2] & 0xF) && *(void**)(obj + 0x54) == 0 &&
        func_800F71E8_ovl01(D_800D1C44, 9) != 0) {
        *(void**)(obj + 0x54) = D_800FCD80_ovl01;
    }
    scr = D_1F80004C.bytes;
    if (scr[0x8A] == 0) {
        d = g_Player;
        if (*(s16*)(d + 0xA) >= *(s16*)(obj + 0xA) - 0x180) {
            scr[0x8A] = 1;
            if ((*(s8*)(obj + 2) & 0xF) < 4) {
                D_8009A1F8[0x47] = 1;
                *(s16*)(D_8009A1F8 + 0x24) = *(u16*)(obj + 0xA) - 0xDC;
            }
        }
    }
    e = g_Player;
    if (e[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800FD268_ovl01[*(s8*)(obj + 5)])(obj);
    }
    if (func_80031DD0(obj) < 0) {
        obj[3] = 0;
        func_8004D4F4(4, D_800FCF84_ovl01, obj);
        g = D_8009A1F8;
        g[0x47] = 1;
        *(s16*)(g + 0x24) = 0x2340;
        if ((obj[2] & 0xF) == 2) {
            func_800F6EE8_ovl01(obj);
            *(s16*)(g + 0x2A) = 0x60;
        }
        *(s16*)(obj + 0x7E) = 0;
        obj[4] = 5;
        D_1F80004C.bytes[0x87] = 1;
        func_800F6110_ovl01(obj);
        func_800F58BC_ovl01_spawn(obj, *(u16*)(g + 0xA));
        return;
    }
    b = *(u16*)(D_1F80004C.bytes + 0x88);
    a = *(u16*)(obj + 0x42);
    if ((b ^ a) & 0x8000) {
        if (a & 0x8000) {
            func_800F58BC_ovl01_spawn(obj, D_8009A202);
        } else {
            D_8009A244 = 1;
        }
    }
    *(u16*)(D_1F80004C.bytes + 0x88) = *(u16*)(obj + 0x42);
    func_8002D9EC(obj, 0x40, 0x20);
}
