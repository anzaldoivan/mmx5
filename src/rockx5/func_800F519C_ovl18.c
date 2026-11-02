#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D33C(u8* p, s32 backward);
extern void func_8002DED4(u8* obj);

void func_800F519C_ovl18(u8* obj) {
    u8* p;

    if (--*(s16*)(obj + 0x7C) == 0x5A) {
        *(s32*)(obj + 0x28) = -*(s32*)(obj + 0x28);
        *(s32*)(obj + 0x2C) = -*(s32*)(obj + 0x2C);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[0x80] < 5) {
            *(s16*)(obj + 0x7C) = 0xB4;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            func_800171E8(obj, 0);
            obj[5] = 2;
        } else {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0x20000;
            func_800171E8(obj, 3);
            obj[5] = 4;
            *(u8**)(obj + 0x84) = 0;
        }
    }
    if (!(*(u16*)(obj + 0x7C) & 3)) {
        p = func_8002D33C(*(u8**)(obj + 0x84), 0);
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0xE;
            *(u8**)(p + 0x50) = obj;
            *(s32*)(p + 8) = *(s32*)(obj + 8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            p[2] = obj[0x45];
            *(u8**)(obj + 0x84) = p;
        }
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
