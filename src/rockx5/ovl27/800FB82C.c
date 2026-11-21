#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800FB82C_ovl27(u8* obj) {
    switch (((s8*)obj)[2]) {
    case 0:
        set_animation(obj, 0x15);
        obj[0x16] = 4;
        break;
    case 1:
        set_animation(obj, 0x17);
        obj[0x16] = 4;
        break;
    case 2:
        set_animation(obj, 0x16);
        obj[0x16] = 4;
        break;
    case 3:
        set_animation(obj, 0x15);
        obj[0x16] = 4;
        break;
    case 4:
        set_animation(obj, 0x1A);
        obj[0x16] = 5;
        break;
    case 5:
        set_animation(obj, 0x1C);
        obj[0x16] = 5;
        break;
    case 6:
        set_animation(obj, 0x1B);
        obj[0x16] = 5;
        break;
    }
    obj[3] = 1;
    *(s16*)(obj + 0x54) = 0x78;
    obj[5] = 0;
    obj[6] = 0;
    obj[4]++;
}

void func_800FB920_ovl27(u8* obj) {
    u8* q;
    u8* p = *(u8**)(obj + 0x50);

    if (((s8*)p)[3] == 0 ||
        (((s8*)obj)[2] < 4 ? --*(s16*)(obj + 0x54) : p[0x8A]) == 0) {
        obj[3] = 0;
        obj[4]++;
    } else {
        animate_object(obj);
        q = *(u8**)(obj + 0x50);
        *(u16*)(obj + 0xA) = *(u16*)(q + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(q + 0xE);
    }
}

#define D_800EEBA0_ovl00 func_800FB9D0_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
