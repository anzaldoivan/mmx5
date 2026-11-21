#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F3FE0_ovl08[])(u8* obj);

void func_800F2CB4_ovl08(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    animate_object(obj);
    func_8002D9EC(obj, 0x80, 0x80);
    D_800F3FE0_ovl08[*(s8*)(obj + 5)](obj);
}

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F2D1C_ovl08
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
