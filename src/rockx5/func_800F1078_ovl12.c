#include "types.h"

extern s32 func_8002F8FC(u8* a0);
extern void* D_800F20D0_ovl12[];
extern void* D_800F20DC_ovl12[];
extern void* D_800F20E8_ovl12[];
extern void* D_800F20F4_ovl12[];

void func_800F1078_ovl12(u8* a0) {
    if (*(s32*)(a0 + 0x84) == 0 && a0[0x70] == 0) {
        func_8002F8FC(a0);
    }
    a0[3] = 0;
    switch ((s8)a0[2]) {
    case 0:
        ((void (*)(u8*))D_800F20D0_ovl12[(s8)a0[4]])(a0);
        break;
    case 1:
        ((void (*)(u8*))D_800F20DC_ovl12[(s8)a0[4]])(a0);
        break;
    case 2:
    case 3:
        ((void (*)(u8*))D_800F20E8_ovl12[(s8)a0[4]])(a0);
        break;
    case 4:
        ((void (*)(u8*))D_800F20F4_ovl12[(s8)a0[4]])(a0);
        break;
    }
}
