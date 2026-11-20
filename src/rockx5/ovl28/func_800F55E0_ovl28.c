#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_80044DE0();

void func_800F55E0_ovl28(u8* obj) {
    animate_object(obj);
    if (func_80044DE0() == 0) {
        obj[7] = 2;
        if (*(s16*)(obj + 0x7E) != 0) {
            *(s16*)(obj + 0x7E) -= 1;
        } else {
            set_animation(obj, 0xC);
            obj[6]++;
        }
    }
}
