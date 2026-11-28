#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80076E5C[];
extern u8 D_8007B490[];

void func_80045208(u8* obj) {
    u8* p;
    u8* q;
    u8* b;
    u32 r;
    s32 t;

    obj[0] = 1;
    obj[3] = 1;
    obj[0x64] = 1;
    *(u8**)(obj + 0x50) = D_80076E5C;
    p = D_1F800014;
    *(u8**)(obj + 0x38) = p + *(s32*)(p + 0x2C);
    q = D_1F80001C.bytes;
    *(u8**)(obj + 0x3C) = q + *(s32*)(q + 0x18);
    *(u8**)(obj + 0x30) = D_8007B490;
    *(s16*)(obj + 0x40) = 0x540;
    *(s16*)(obj + 0x42) = 0x7802;
    obj[0x16] = 1;
    obj[0x15] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    if (((s8*)obj)[2] == 0) {
        u8* b1;

        *(s32*)(obj + 0x24) = 0xFFF40000;
        b1 = D_8009A1F8.u;
        *(s16*)(obj + 0xE) = *(s16*)(b1 + 0xE) - 0x20;
        set_animation(obj, 2);
    } else {
        u8* b2;

        *(s32*)(obj + 0x24) = 0xC0000;
        b2 = D_8009A1F8.u;
        *(s16*)(obj + 0xE) = *(s16*)(b2 + 0xE) + 0x110;
        set_animation(obj, 1);
    }
    *(s32*)(obj + 0x2C) = 0;
    r = random_byte();
    b = D_8009A1F8.u;
    t = *(u16*)(b + 0xA) + 8;
    obj[5] = 0;
    obj[4]++;
    *(s16*)(obj + 0xA) = (u8)(r % 20) * 16 + t;
}
