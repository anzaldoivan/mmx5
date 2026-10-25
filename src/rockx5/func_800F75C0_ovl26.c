#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F75C0_ovl26(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if ((state == 0 || state == 2) && ((s8*)obj)[0x45] != 0) {
        func_800171E8(obj, 0x11);
    }
}
