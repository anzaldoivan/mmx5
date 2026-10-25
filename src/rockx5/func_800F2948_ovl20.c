#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);

void func_800F2948_ovl20(u8* obj) {
    if (((s8*)obj)[2] == 3) {
        func_80017248(obj);
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_8002D89C(obj);
    }
}
