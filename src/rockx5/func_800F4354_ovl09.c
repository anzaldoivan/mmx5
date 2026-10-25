#include "types.h"

extern s32 func_8002F8FC(u8* a0);
extern void* D_800FB0E8_ovl09[];
extern void* D_800FB0F4_ovl09[];
extern void* D_800FB100_ovl09[];
extern void* D_800FB10C_ovl09[];
extern void* D_800FB118_ovl09[];
extern void* D_800FB124_ovl09[];
extern void* D_800FB130_ovl09[];
extern void* D_800FB13C_ovl09[];

void func_800F4354_ovl09(u8* a0) {
    if (*(s32*)(a0 + 0x84) == 0 && a0[0x70] == 0) {
        func_8002F8FC(a0);
    }
    a0[3] = 0;
    switch ((s8)a0[2]) {
    case 1:
        ((void (*)(u8*))D_800FB0E8_ovl09[(s8)a0[4]])(a0);
        break;
    case 2:
        ((void (*)(u8*))D_800FB0F4_ovl09[(s8)a0[4]])(a0);
        break;
    case 3:
        ((void (*)(u8*))D_800FB100_ovl09[(s8)a0[4]])(a0);
        break;
    case 4:
        ((void (*)(u8*))D_800FB10C_ovl09[(s8)a0[4]])(a0);
        break;
    case 5:
        ((void (*)(u8*))D_800FB118_ovl09[(s8)a0[4]])(a0);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        ((void (*)(u8*))D_800FB124_ovl09[(s8)a0[4]])(a0);
        break;
    case 14:
        ((void (*)(u8*))D_800FB130_ovl09[(s8)a0[4]])(a0);
        break;
    case 15:
        ((void (*)(u8*))D_800FB13C_ovl09[(s8)a0[4]])(a0);
        break;
    }
}
