#include "types.h"

extern int func_8002D6FC();
extern void func_8004FD90(u8*, s32, s32, s32);

void func_800F94B0_ovl09(u8* obj) {
    if ((*(u8**)(obj + 0x50))[0x86] == 1) {
        func_8002D6FC(obj);
    } else {
        (*(u16*)(obj + 0x54))++;
        if ((*(u16*)(obj + 0x54) & 7) == 0) {
            func_8004FD90(obj, 1, 3, 0x3F);
        }
    }
}
