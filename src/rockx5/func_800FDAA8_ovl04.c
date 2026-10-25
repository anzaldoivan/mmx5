#include "types.h"

extern void (*D_80102B70_ovl04[])(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800FDAA8_ovl04(u8* a0) {
    D_80102B70_ovl04[*(s8*)(a0 + 5)](a0);
    if (func_8002D800(a0) != 0 || --*(u16*)(a0 + 0x54) == 0) {
        a0[4] = 2;
    }
    func_8002D9EC(a0, 0x10, 0x10);
}
