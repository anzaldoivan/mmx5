#include "types.h"

extern void (*D_800F5880_ovl05[])(u8*);

void func_800F3AE8_ovl05(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800F5880_ovl05[*(signed char*)(arg0 + 5)](arg0);
}
