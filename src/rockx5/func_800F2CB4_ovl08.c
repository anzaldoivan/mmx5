#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_800F3FE0_ovl08[])(u8* obj);

void func_800F2CB4_ovl08(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_80017248(obj);
    func_8002D9EC(obj, 0x80, 0x80);
    D_800F3FE0_ovl08[*(s8*)(obj + 5)](obj);
}
