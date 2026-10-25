#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);

void func_800F59E8_ovl18(u8* obj) {
    if (--obj[0x7C] == 0) {
        func_80016490(5, 0x1F, obj);
        func_800171E8(obj, 1);
        obj[6]++;
    }
}
