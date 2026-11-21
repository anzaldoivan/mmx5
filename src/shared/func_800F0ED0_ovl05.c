#include "types.h"
#include "mmx5/object.h"

void func_800F0ED0_ovl05(u8* arg0) {
    if (arg0[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = 0x60000;
    } else {
        *(s32*)(arg0 + 0x20) = 0xFFFA0000;
    }
    arg0[6]++;
}

extern s32 func_800F0FFC_ovl05(u8* a0);
extern s32 func_8004FC64(u8* a0);

void func_800F0EFC_ovl05(u8* a0) {
    move_object(a0);
    if (func_800F0FFC_ovl05(a0) != 0) {
        a0[3] = 0;
        func_8004FC64(a0);
        a0[4] = 2;
    }
}
