#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800F1C64_ovl10(u8* arg0);

void func_800F1A50_ovl10(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x29, 0);
        func_800171E8(obj, 4);
        func_800F1C64_ovl10(obj);
        obj[6]++;
    }
}
