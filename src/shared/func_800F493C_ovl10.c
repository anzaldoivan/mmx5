/* Shared body (DK-5), from the banked draft of func_800F493C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8* func_8002C938();
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    s32 lim;
    u8* parent;
    u8* child;
    s32 cnt;
    s32 n;
    s8 st;
    s8 t;

    lim = 0xC0;
    if (D_800D1C0C != 0xC) {
        lim = 0x480;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    if (func_8002D938(obj, 0x30, 0x80) == 0) {
        func_8002D9EC(obj, 0x30, 0x80);
    } else {
        obj[4] = 2;
    }
    if (*(s8*)(obj + 2) == 3) {
        parent = *(u8**)(obj + 0x50);
        *(s32*)(obj + 8) = *(s32*)(parent + 8);
        *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
        if (parent[0x70] & 8) {
            t = *(s8*)(obj + 0x54);
            cnt = obj[0x54];
            if (t == 0) {
                obj[0x54] = 0x1E;
            } else {
                n = cnt - 1;
                obj[0x54] = n;
                if ((s8)n == 0) {
                    obj[4] = 2;
                }
            }
        }
    }
    if (lim < *(s16*)(obj + 0xE) && *(s8*)(obj + 2) == 1) {
        child = func_8002C938();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x33;
            child[2] = 3;
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 8) = *(s32*)(obj + 8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC) + 0xFFF00000;
            child[0x15] = obj[0x15];
        }
        obj[4] = 2;
    }
    st = *(s8*)(obj + 2);
    if (st == 2 && *(s8*)(obj + 0x45) == 1) {
        obj[4] = st;
    }
}
