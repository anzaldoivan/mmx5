#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern u8 D_800F9894_ovl29[];
extern u8 D_800F988C_ovl29[];

void func_800F54F4_ovl29(u8* obj) {
    u8* child;

    func_800171E8(obj, 13);
    *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    *(u8**)(obj + 0x54) = D_800F988C_ovl29;
    obj[0x60] = 4;
    *(s32*)(obj + 0x24) = 0x40000;
    *(s32*)(obj + 0x2C) = 0x1C00;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    child = func_8002D27C();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x26;
        child[2] = 4;
        *(u8**)(child + 0x50) = obj;
        *(u8**)(obj + 0x80) = child;
    }
    obj[6]++;
}
