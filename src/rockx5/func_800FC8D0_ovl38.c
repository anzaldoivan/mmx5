#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);

void func_800FC8D0_ovl38(u8* obj) {
    s8 v = *(s8*)(obj + 0x45);

    if (v == 2) {
        func_80016490(2, 0xA3, obj);
    } else if (v == 1) {
        func_800171E8(obj, 3);
        obj[5] = 3;
        obj[6] = 0;
    }
}
