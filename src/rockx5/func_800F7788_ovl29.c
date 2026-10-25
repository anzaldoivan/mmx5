#include "types.h"

extern void (*D_800FA534_ovl29[])(u8*);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);

void func_800F7788_ovl29(u8* obj) {
    if (func_80031DD0(obj) < 0) {
        obj[5] = 0;
        obj[4]++;
        func_8004FD24(obj);
    } else {
        D_800FA534_ovl29[*(signed char*)(obj + 5)](obj);
    }
}
