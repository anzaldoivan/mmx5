#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F9748_ovl11[])(u8*);

void func_800F0120_ovl11(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800F9748_ovl11[(signed char)arg0[4]](arg0);
    if (*(s8*)(arg0 + 2) == 0) {
        func_8002FB58(arg0);
    }
}
