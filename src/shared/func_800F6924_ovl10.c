/* Shared body (DK-5), from the banked draft of func_800F6924_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern int func_8002D6FC();
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* o) {
    u8 f;
    s16 t;

    func_8002DF54(o);
    func_80017248(o);
    func_8002FB58(o);
    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    f = o[0x70];
    if ((f & 2) || (f & 1)) {
        func_80016490(2, 0x2E, o);
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
    }
    if (*(s32*)(o + 0x70) & 0xC) {
        func_80016490(2, 0x2E, o);
        *(s32*)(o + 0x24) = -*(s32*)(o + 0x24);
    }
    if (func_80031DD0(o) < 0) {
        o[4] = 9;
        func_8004FD24(o);
        return;
    }
    if ((*(s8**)(o + 0x7C))[4] == 2) {
        o[3] = 0;
        func_8002D6FC(o);
    } else if (func_8002D938(o, 0x60, 0x60) == 1) {
        o[4] = 9;
    } else {
        func_8002D9EC(o, 0x20, 0x20);
    }
    t = --*(u16*)(o + 0x88);
    if (t == 0) {
        o[4] = 9;
    } else if (t == 50) {
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x24) = 0;
        func_800171E8(o, 0x22);
    }
}
