#include "types.h"
#include "mmx5/globals.h"

extern void* D_800FB654_ovl00[];
extern void* D_800FB664_ovl00[];
extern void* D_800FB674_ovl00[];
extern void* D_800FB684_ovl00[];

void func_800F9B4C_ovl00(u8* a0) {
    if (*(s32*)(a0 + 0x84) == 0 && a0[0x70] == 0) {
        func_8002F8FC(a0);
    }
    switch ((s8)a0[2]) {
    case 0:
    case 1:
        ((void (*)(u8*))D_800FB654_ovl00[(s8)a0[4]])(a0);
        break;
    case 2:
        ((void (*)(u8*))D_800FB664_ovl00[(s8)a0[4]])(a0);
        break;
    case 3:
        ((void (*)(u8*))D_800FB674_ovl00[(s8)a0[4]])(a0);
        break;
    case 4:
        ((void (*)(u8*))D_800FB684_ovl00[(s8)a0[4]])(a0);
        break;
    }
}
