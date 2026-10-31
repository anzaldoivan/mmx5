/* Shared body (DK-5), from the banked draft of func_800F67F0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_80101D24_ovl04[])(u8*);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);
extern void func_8002D6FC(u8* obj);

void DEDUP_NAME(u8* obj) {
    s8 st;
    s8 v;
    u8 f;

    st = *(s8*)(obj + 2);
    if (st == 1) {
        if (func_80031DD0(obj) < 0 || (*(s8**)(obj + 0x7C))[4] == 2) {
            func_8004FD24(obj);
            obj[4] = 2;
            return;
        }
    } else if (st == 0) {
        v = (*(s8**)(obj + 0x7C))[4];
        if (v == 2) {
            obj[0x8F] = 8;
            func_800171E8(obj, 0xE);
            obj[4] = v;
            return;
        }
    } else if (st == 2) {
        s8 w = (*(s8**)(obj + 0x7C))[4];
        if (w == 2) {
            obj[4] = w;
            return;
        }
    }
    func_800317B8(obj);
    f = obj[0x71] | obj[0x70];
    obj[0x71] = f;
    obj[0x93] = f;
    D_80101D24_ovl04[*(s8*)(obj + 5)](obj);
    if (*(s8*)(obj + 2) != 2) {
        if (func_8002D938(obj, 0x20, 0x20) == 0) {
            func_8002D89C(obj);
        } else {
            obj[4] = 2;
        }
        if ((*(u32*)(obj + 4) & 0xFFFF00) == 0x20200) {
            obj[3] = 0;
        }
    } else {
        if (func_8002D938(obj, 0x80, 0x20) != 0) {
            func_8002D6FC(obj);
        }
    }
}
