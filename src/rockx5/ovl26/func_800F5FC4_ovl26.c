#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F5FC4_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        move_object(obj);
        if (*(s16*)(obj + 0xE) <=
            D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo) {
            *(s16*)(obj + 0xE) =
                D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo;
            set_animation(obj, 0);
            obj[6]++;
        }
    }
}
