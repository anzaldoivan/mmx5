#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 D_8009A0A8;

void func_800FA03C_ovl28(u8* obj) {
    s32 d = D_8009A0A8;

    func_8003D29C(0x14, (*(s32*)(obj + 8) >= d) << 6);
    obj[5] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 8);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    if (*(s32*)(obj + 0x24) > 0) {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s32*)(obj + 0x2C) = 0x4200;
    func_8002D9EC(obj, 0x30, 0x30);
}
