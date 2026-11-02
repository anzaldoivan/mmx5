#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern s16 D_8009A0AA;
extern s32 D_800F9898_ovl29[];
extern s16 D_800FA64A_ovl29;

void func_800F3AE4_ovl29(u8* obj) {
    u8* p;

    obj[0x8B] = 0x40;
    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x24) = 0x60000;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0x3000;
    *(s32**)(obj + 0x50) = D_800F9898_ovl29;
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
    if (*(s16*)(obj + 0xA) < D_800FA64A_ovl29) {
        obj[0x8C] = 1;
    } else {
        obj[0x8C] = 0;
    }
    obj[6]++;
}
