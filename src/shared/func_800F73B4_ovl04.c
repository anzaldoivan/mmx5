/* Shared body (DK-5), from the banked draft of func_800F73B4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_800326BC(u8* a0);
extern void func_800F64F8_ovl04(s32, void*, u8*, s32);
extern void func_8002DF54(u8* a0);
extern void func_80032F70(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);
extern s32 func_8003240C(u8* a0);
extern s32 func_8002D89C(u8* obj);
extern signed char D_800D1C0C;
extern u8 D_8009A0A0[];
extern u8 D_801026A0_ovl04[];
extern void* D_801026B4_ovl04[];

extern Ent73B4 D_80101D60_ovl04[][37];

void DEDUP_NAME(u8* o) {
    s32 lo;
    s32 hi;
    s32 spd;
    u8* p;
    u8* q;
    s32 t;
    s32 c;
    u8* g;
    u8* h;
    u8* r;

    if (D_800D1C0C != 12) {
        lo = 0x1540;
        hi = 0x16E0;
    } else {
        lo = 0x430;
        hi = 0x5D0;
    }
    spd = 0xB0;
    c = ((signed char*)*(u8**)(o + 0x7C))[4];
    p = *(u8**)(o + 0x7C);
    if (c == 2 || (c == 3 && ((signed char*)p)[5] != 2)) {
        func_80016490(2, 0x15, o);
        func_800F64F8_ovl04(3, D_801026A0_ovl04, o, 0);
        o[4] = 2;
        return;
    }
    g = D_8009A0A0;
    if (((signed char*)g)[0xF3] != 0 && (g[0xFA] == 2 || g[0xFA] == 3)) {
        func_800326BC(o);
        return;
    }
    if (((signed char*)o)[2] < 100) {
        p = *(u8**)(o + 0x7C);
        if (((signed char*)p)[5] == 2) {
            func_80016490(2, 0x15, o);
            func_800F64F8_ovl04(4, D_801026A0_ovl04, o, 0);
            o[4] = 2;
            return;
        }
        if (((signed char*)p)[0x90] > 0) {
            t = *(s32*)(p + 0x98);
            *(s32*)(o + 0x20) = t;
            if (t > 0xFFFF) {
                *(s32*)(o + 0x20) = 0x10000;
            }
        } else {
            *(s32*)(o + 0x20) = 0xFFFF0000;
        }
        q = *(u8**)(o + 0x7C);
        if (((signed char*)q)[5] == 3 || ((signed char*)q)[5] == 6 ||
            (*(u32*)(q + 4) & 0xFFFF00) == 0x30500) {
            *(s32*)(o + 0x20) = 0;
            if (*(s16*)(o + 0xA) <= lo || *(s16*)(o + 0xA) >= hi) {
                func_8002D6FC(o);
                return;
            }
        }
    }
    func_8002DF54(o);
    ((void (*)(u8*))D_801026B4_ovl04[((signed char*)o)[6]])(o);
    func_800326BC(o);
    func_80032F70(o);
    func_80017248(o);
    if (o[0x83] == 0 && *(s16*)(o + 0xA) >= hi - 0x40) {
        o[0x83] = 1;
        *(s32*)(o + 0x54) = 0;
        func_80016490(2, 0x15, o);
        func_800F64F8_ovl04(4, D_801026A0_ovl04, o, 0);
    }
    if (((signed char*)o)[0x60] == 0x7F) {
        func_800317B8(o);
    }
    if (D_80101D60_ovl04[o[0x82]][((signed char*)o)[2]].x3 == 0 &&
        ((signed char*)o)[2] < 100) {
        r = D_8009A0A0;
        spd = 0x80;
        if (((*(s16*)(r + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(r + 0xA))
                 : (*(s16*)(r + 0xA) - *(s16*)(o + 0xA))) > 0x40) {
            if (func_8002D938(o, 0x80, 0x20) == 0) {
                func_8002D89C(o);
                if (o[0x83] != 0) {
                    o[3] = 0;
                }
                return;
            }
            func_8002D6FC(o);
            return;
        }
    }
    h = D_8009A0A0;
    if (h[0xF8] == 0) {
        func_8003240C(o);
    }
    if (func_8002D938(o, spd, 0x20) == 0) {
        func_8002D89C(o);
        if (o[0x83] != 0) {
            o[3] = 0;
        }
        return;
    }
    func_8002D6FC(o);
}
