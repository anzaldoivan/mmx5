#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern s32 D_800F9898_ovl29[];
extern s16 D_800FA64A_ovl29;

void func_800F39DC_ovl29(u8* obj) {
    s32 v;
    u8* p;

    if (*(s16*)(obj + 0xA) > D_800FA64A_ovl29) {
        obj[0x15] = 0;
    } else {
        obj[0x15] = 0x40;
    }
    func_800171E8(obj, 3);
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 2;
        *(u8**)(p + 0x50) = obj;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 3;
        *(u8**)(p + 0x50) = obj;
    }
    obj[0x67] = 1;
    func_80016490(2, 0xAC, obj);
    v = 0xFFFB0000;
    if (obj[0x15] != 0) {
        v = 0x50000;
    }
    *(s32*)(obj + 0x20) = v;
    *(s32*)(obj + 0x24) = 0x30000;
    *(s32*)(obj + 0x2C) = -0x800;
    *(s32*)(obj + 0x28) = 0;
    *(s32**)(obj + 0x50) = D_800F9898_ovl29;
    obj[6]++;
}
