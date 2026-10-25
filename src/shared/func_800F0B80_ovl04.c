/* Shared body (DK-5), from the banked draft of func_800F0B80_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_801014AC_ovl04[])(u8*);
extern u8 D_80101478_ovl04[];
extern void func_800F1080_ovl04(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    u8 state;

    if (D_8009A197 == 0 || *(signed char*)(obj + 2) != 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_801014AC_ovl04[*(signed char*)(obj + 5)](obj);
        func_800F1080_ovl04(obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_80101478_ovl04, obj);
        func_80054440(obj, 0xC);
        state = 2;
    } else {
        if (func_8002D938(obj, 0x40, 0x40) == 0) {
            func_8002D9EC(obj, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    obj[4] = state;
}
