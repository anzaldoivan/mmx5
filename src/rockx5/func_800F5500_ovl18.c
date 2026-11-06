#include "types.h"

extern s32 func_8002E024(void*, void*);
extern void func_8002E058(void*, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_800F5500_ovl18(u8* obj) {
    s32 vy;
    s32 vx;

    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 0x5A;
        func_8002E058(obj, func_8002E024(obj, D_8009A0A0));
        vx = *(s32*)(obj + 0x20);
        vy = *(s32*)(obj + 0x24);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = -((vx * 0x2D) >> 8);
        *(s32*)(obj + 0x2C) = -((vy * 0x2D) >> 8);
        func_800171E8(obj, 1);
        obj[5] = 3;
        *(s32*)(obj + 0x84) = 0;
        obj[0x80]++;
        func_80016490(2, 0x9D, obj);
    }
    func_80017248(obj);
}
