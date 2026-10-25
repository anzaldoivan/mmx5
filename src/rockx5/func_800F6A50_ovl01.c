#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800F6A50_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        func_800171E8(obj, 3);
        obj[6]++;
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        func_80017248(obj);
    }
}
