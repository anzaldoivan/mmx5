#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80077534[];

void func_8004EB7C(u8* obj) {
    u8* p = D_8009A420;

    *(s16*)(obj + 0x40) = 0x1D00;
    *(s32*)(obj + 0x3C) = D_801F300C + (s32)D_801F3000;
    *(u8**)(obj + 0x30) = D_80077534;
    *(s8*)(obj + 0x14) = -1;
    obj[0x15] = 0;
    *(s16*)(obj + 0x42) = 0x780A;
    *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 3 + 2];
    obj[0x54] = p[7];
    obj[0x16] = 0x10;
    obj[4]++;
    set_animation(obj, 0);
    func_8002D89C(obj);
}
