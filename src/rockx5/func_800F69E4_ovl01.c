#include "types.h"

extern void func_800F6D48_ovl01(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800F69E4_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        func_800F6D48_ovl01(obj);
        obj[6]++;
        func_800171E8(obj, 4);
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        func_80017248(obj);
    }
}
