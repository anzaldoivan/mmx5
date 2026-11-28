#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A197;
extern void (*D_8007BD38[])(u8* obj);

void func_80053188(u8* obj) {
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        obj[4] = 3;
        return;
    }
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_8007BD38[(signed char)obj[5]](obj);
        animate_object(obj);
    }
    if (((s8*)obj)[3] != 0) {
        if (func_800317B8(obj) != 0) {
            set_animation(obj, 3);
            obj[4] = 2;
        }
        if (obj[0x85] != 0) {
            if (func_80031DD0(obj) < 0) {
                set_animation(obj, 3);
                obj[4] = 2;
            }
        }
    }
}

void func_80053280(u8* obj) {
    animate_object(obj);
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (*(s8*)(obj + 0x45) != 0) {
        func_8002D760(obj);
    }
}

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800532C0
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
