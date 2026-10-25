#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_800F53E0_ovl20[])(u8* obj);

void func_800F1FE8_ovl20(u8* obj) {
    func_80017248(obj);
    D_800F53E0_ovl20[*(s8*)(obj + 5)](obj);
    func_8002D9EC(obj, 0x80, 0x20);
}
