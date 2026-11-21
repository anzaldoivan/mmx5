#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800FB364_ovl10[];
extern u8 D_800FB370_ovl10[];
extern s16 D_800FB378_ovl10[];

void func_800EF4D8_ovl10(u8* obj) {
    s32 side;
    u8* p;
    u8* q;
    s32 lim;

    p = g_Player;
    if (*(s16*)(p + 0xA) < *(s16*)(obj + 0xA)) {
        side = 0;
        obj[0x15] = 0;
    } else {
        side = 1;
        obj[0x15] = 0x40;
    }
    lim = D_800FB378_ovl10[side];
    q = g_Player;
    if ((*(s16*)(q + 0xA) - *(s16*)(obj + 0xA)) >= 0
            ? (*(s16*)(q + 0xA) - *(s16*)(obj + 0xA)) < lim
            : (*(s16*)(obj + 0xA) - *(s16*)(q + 0xA)) < lim) {
        if (*(s8*)(obj + 2) != 0) {
            *(u8**)(obj + 0x68) = D_800FB364_ovl10;
            set_animation(obj, 3);
        } else {
            *(u8**)(obj + 0x68) = D_800FB370_ovl10;
            set_animation(obj, 0);
        }
        obj[6]++;
    }
}

extern s32 func_8002B5B4(s32);
extern u32* D_80098118;
extern u8 D_800FB2F8_ovl10[];
extern u8 D_800FB334_ovl10[];
extern u8 D_800FB328_ovl10[];
extern u8 D_800FB364_ovl10[];
extern u8 D_800FB370_ovl10[];

void func_800EF5CC_ovl10(u8* a0) {
    s32 i;
    u8* p;
    s32 r0;
    s32 r1;
    s32 off;
    u8* tbl;

    animate_object(a0);
    if (((s8*)a0)[0x45] != 1) {
        return;
    }
    i = 0;
    off = 0;
loop: // !FAKE: goto loop keeps both counters (no loop reversal)
{
    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1C;
        *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(a0 + 0x42);
        p[0x14] = a0[0x14];
        p[0x15] = a0[0x15];
        *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(((s8*)a0)[1])] >> 7;
        r0 = func_8002B5B4(((s8*)a0)[1]);
        r1 = func_8002B5B4(((s8*)a0)[1]);
        *(u16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(s32*)(p + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(((s8*)a0)[1])];
        *(u8**)(p + 0x30) = D_800FB2F8_ovl10;
        if (p[0x15] == 0) {
            *(s32*)(p + 0x20) = 0xFFFF0000;
        } else {
            *(s32*)(p + 0x20) = 0x10000;
        }
        if (((s8*)a0)[2] != 0) {
            tbl = D_800FB334_ovl10;
            *(u16*)(p + 0xE) =
                *(u16*)(a0 + 0xE) + *(u16*)(D_800FB334_ovl10 + off + 2);
            if (p[0x15] != 0) {
                *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA) + *(u16*)(off + tbl);
            } else {
                *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA) - *(u16*)(off + tbl);
            }
        } else {
            tbl = D_800FB328_ovl10;
            *(u16*)(p + 0xE) =
                *(u16*)(a0 + 0xE) + *(u16*)(D_800FB328_ovl10 + off + 2);
            if (p[0x15] == 0) {
                *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA) + *(u16*)(off + tbl);
            } else {
                *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA) - *(u16*)(off + tbl);
            }
        }
        *(u8**)(p + 0x7C) = a0;
        *(s32*)(p + 0x84) = 0;
    }
}
    i++;
    off += 4;
    if (i < 3) {
        goto loop; // !FAKE: goto loop keeps both counters (no loop reversal)
    }
    *(s16*)(a0 + 0x7C) = 0x14;
    a0[6]++;
    if (((s8*)a0)[2] != 0) {
        *(u8**)(a0 + 0x68) = D_800FB364_ovl10;
        set_animation(a0, 5);
    } else {
        *(u8**)(a0 + 0x68) = D_800FB370_ovl10;
        set_animation(a0, 2);
    }
}
