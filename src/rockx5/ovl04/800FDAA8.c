#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_80102B70_ovl04[])(u8* a0);
extern s32 func_8002D800(u8* a0);

void func_800FDAA8_ovl04(u8* a0) {
    D_80102B70_ovl04[*(s8*)(a0 + 5)](a0);
    if (func_8002D800(a0) != 0 || --*(u16*)(a0 + 0x54) == 0) {
        a0[4] = 2;
    }
    func_8002D9EC(a0, 0x10, 0x10);
}

#define D_800EEBA0_ovl00 func_800FDB30_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
