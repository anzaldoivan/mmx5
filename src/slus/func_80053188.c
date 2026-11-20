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
