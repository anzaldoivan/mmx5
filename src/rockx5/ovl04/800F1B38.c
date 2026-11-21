#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"

extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u32* D_80098118;
extern u8 D_8009A1F8[];
extern u8 D_80101568_ovl04[];
extern u8 D_8010156C_ovl04[];
extern u8 D_80101570_ovl04[];
extern u8 D_80101610_ovl04[];

void func_800F1B38_ovl04(u8* obj) {
    s32 a;
    s32 b;
    s32 d;
    u8* p;
    u8* q;

    obj[0x5C] = 0xF;
    obj[0x60] = 4;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x14] = g_Player[0x14];
    *(u8**)(obj + 0x30) = D_80101610_ovl04;
    obj[0x16] = 2;
    *(u8**)(obj + 0x68) = D_80101570_ovl04;
    *(u8**)(obj + 0x54) = D_8010156C_ovl04;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x50) = D_80101568_ovl04;
    obj[0x62] = 0;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    set_animation(obj, 1);
    *(s16*)(D_1F80004C.bytes + 0x80) = 0;
    D_1F80004C.bytes[0x84] = 0;
    *(s16*)(D_1F80004C.bytes + 0x82) = 0x20;
    if (((s8*)obj)[2] >= 2) {
        *(s32*)(obj + 0x10) = 0;
        *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(((s8*)obj)[1])] >> 7;
        a = func_8002B5B4(((s8*)obj)[1]);
        b = func_8002B5B4(((s8*)obj)[1]);
        *(s16*)(obj + 0x42) =
            ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
        *(s32*)(obj + 0x3C) = (s32)D_1F800020.u32s +
                              D_1F800020.u32s[func_8002B5B4(((s8*)obj)[1])];
        p = D_8009A1F8;
        if (*(s16*)(g_Player + 0xA) - *(s16*)(p + 0xA) >= 0xA1) {
            d = (random_byte() & 0xF) + 0x38;
            *(s16*)(obj + 0xA) = *(u16*)(p + 0xA) - d;
        } else {
            d = (random_byte() & 0xF) + 0x178;
            *(s16*)(obj + 0xA) = *(u16*)(p + 0xA) + d;
        }
        if (((s8*)obj)[2] == 2) {
            u8* q2 = D_8009A1F8;
            *(s16*)(obj + 0xE) = *(u16*)(q2 + 0xE) + 0x14;
        } else if (((s8*)obj)[2] == 3) {
            q = D_8009A1F8;
            *(s16*)(obj + 0xE) = *(u16*)(q + 0xE) + 0xDC;
        }
    }
    obj[4] = 1;
    obj[5] = 2;
    obj[6] = 0;
}

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_80101640_ovl04[];
extern void* D_80101664_ovl04[];

void func_800F1D98_ovl04(u8* obj) {
    u8* g;
    s16 x;

    if (func_80031DD0(obj) < 0) {
        func_8004D4F4(5, D_80101640_ovl04, obj);
        func_80054440(obj, 0x11);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 6;
        return;
    }
    g = g_Player;
    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        if (--*(u16*)(D_1F80004C.bytes + 0x82) == 0xFFFF) {
            *(u16*)(D_1F80004C.bytes + 0x82) = 0x20;
            if (D_1F80004C.bytes[0x84] == 0) {
                x = *(s16*)(obj + 0xA);
                if (*(s16*)(g + 0xA) < x) {
                    obj[0x15] = 0;
                } else if (x < *(s16*)(g + 0xA)) {
                    obj[0x15] = 0x40;
                }
            }
        }
        ((void (*)(u8*))D_80101664_ovl04[(s8)obj[5]])(obj);
        animate_object(obj);
        if ((s8)obj[5] == 2) {
            obj[0x60] = 4;
            obj[0x62] = 0;
        } else {
            obj[0x62] = 3;
            obj[0x60] = 0;
        }
        if ((s8)g_Player[0xCA] == 0 && func_800317B8(obj) != 0 &&
            (s8)g_Player[0xCA] != 0) {
            obj[5] = 4;
            obj[6] = 0;
        }
    } else {
        obj[0x60] = 4;
        obj[0x62] = 0;
        func_800317B8(obj);
    }
    if (is_off_screen(obj, 0xA0, 0x40) == 0) {
        func_8002D9EC(obj, 0x70, 0x20);
        return;
    }
    obj[4] = 3;
}
