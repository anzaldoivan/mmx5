#include "types.h"

extern void (*D_801017D0_ovl04[])(u8*);
extern u8 D_801017BC_ovl04[];
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8002D89C(u8*);

void func_800F3B5C_ovl04(u8* obj) {
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(8, D_801017BC_ovl04, obj);
        *(signed char*)(obj + 5) = 3;
        obj[3] = 0;
    } else {
        D_801017D0_ovl04[*(signed char*)(obj + 5)](obj);
        if (*(signed char*)(obj + 5) == 2) {
            func_8002D89C(obj);
        }
    }
}
