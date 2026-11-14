#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 D_800FB67C_ovl09;
extern s16 D_800FB680_ovl09;
extern s16 D_8009A0AA;

void func_800F1D4C_ovl09(u8* o) {
    s32 speed;
    s32 jump;
    s32 wait0;
    s32 wait1;
    s32 hit;
    u8* p0;
    u8* p1;
    u8* p2;
    u8* q;

    if (D_800FB67C_ovl09 != 0) {
        speed = 0x50000;
        jump = 0x32000;
        wait0 = 0x1E;
        wait1 = 0xF;
    } else {
        speed = 0x28000;
        jump = 0x19000;
        wait0 = 0x3C;
        wait1 = 0x1E;
    }
    hit = func_800317B8(o);
    *(u16*)(o + 0x42) &= 0x7FFF;
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        D_800FB680_ovl09 = 0x3E;
        o[4]++;
        func_8002D9EC(o, 0x16, 0x16);
        return;
    }
    (*(s16*)(o + 0x7E))++;
    switch (*(s8*)(o + 5)) {
    case 0:
        p0 = *(u8**)(o + 0x80);
        if (*(s8*)(p0 + 5) == 0xB) {
            func_800171E8(o, 0xA);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (hit != 0 || *(s8*)(p0 + 4) == 2) {
            func_800171E8(o, 0xA);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            func_8004FD24(o);
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (++*(s16*)(o + 0x7C) == wait0 || (o[0x70] & 3)) {
            func_800171E8(o, 0xB);
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = -jump;
            *(s16*)(o + 0x7C) = 0;
            o[5]++;
        }
        func_8002D9EC(o, 0x10, 0x10);
        break;
    case 1:
        p1 = *(u8**)(o + 0x80);
        if (*(s8*)(p1 + 5) == 0xB) {
            func_800171E8(o, 0xC);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (hit != 0 || *(s16*)(o + 0x7E) == 0xAA || (o[0x70] & 8) ||
                   *(s8*)(p1 + 4) == 2) {
            func_800171E8(o, 0xC);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            func_8004FD24(o);
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (++*(s16*)(o + 0x7C) == wait1) {
            func_800171E8(o, 9);
            if (D_8009A0AA <= *(s16*)(o + 0xA)) {
                o[0x15] = 0;
                *(s32*)(o + 0x20) = -speed;
            } else {
                o[0x15] = 0x40;
                *(s32*)(o + 0x20) = speed;
            }
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            o[5]++;
        }
        func_8002D9EC(o, 0x10, 0x10);
        break;
    case 2:
        p2 = *(u8**)(o + 0x80);
        if (*(s8*)(p2 + 5) == 0xB) {
            func_800171E8(o, 0xA);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (hit != 0 || *(s16*)(o + 0x7E) == 0xAA ||
                   *(s8*)(p2 + 4) == 2) {
            func_800171E8(o, 0xA);
            *(s32*)(o + 0x50) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s16*)(o + 0x7C) = 0;
            func_8004FD24(o);
            D_800FB680_ovl09 = 0x3E;
            o[5] = 3;
        } else if (++*(s16*)(o + 0x7C) == wait1 || (o[0x70] & 3)) {
            func_800171E8(o, 0xB);
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = -jump;
            *(s16*)(o + 0x7C) = 0;
            o[5]--;
        }
        func_8002D9EC(o, 0x10, 0x10);
        break;
    case 3:
        if (++*(s16*)(o + 0x7C) == 0xA) {
            o[4]++;
        }
        func_8002D9EC(o, 0x10, 0x10);
        break;
    }
    if (D_800FB67C_ovl09 == 0) {
        if (*(s8*)(o + 5) < 3 && (s16)(*(s16*)(o + 0x7E) % 5) == 0) {
            q = func_8002D1A4();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x10;
                q[2] = 0xF;
                *(u8**)(q + 0x7C) = o;
            }
        }
    } else {
        if (*(s8*)(o + 5) < 3 && (s16)(*(s16*)(o + 0x7E) % 3) == 0) {
            q = func_8002D1A4();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x10;
                q[2] = 0xF;
                *(u8**)(q + 0x7C) = o;
            }
        }
    }
    func_80017248(o);
    func_8002DED4(o);
}
