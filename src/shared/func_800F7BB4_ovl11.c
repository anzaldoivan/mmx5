/* Shared body (DK-5), from the banked draft of func_800F7BB4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_800F81F4_ovl11(u8* obj);
extern s32 func_80016490(s32, s32, void*);

s32 DEDUP_NAME(u8* obj) {
    s32 ret;
    obj[0x60] = 8;
    obj[0x62] = 0;
    *(s32*)(obj + 0x68) = 0;
    func_800171E8(obj, 1);
    func_80017248(obj);
    func_800F81F4_ovl11(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x40000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
    ret = func_80016490(2, 0x32, obj);
    obj[0x9A] = 1;
    return ret;
}
