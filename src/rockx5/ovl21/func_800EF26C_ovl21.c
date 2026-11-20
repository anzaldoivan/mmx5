#include "types.h"

extern void (*D_800EFA68_ovl21[])(u8*);

void func_800EF26C_ovl21(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800EFA68_ovl21[*(signed char*)(arg0 + 4)](arg0);
}
