#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern s16 D_8009A202;

void func_800F44AC_ovl06(u8* obj) {
    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    obj[0x89]++;
    obj[0x89] %= 120;
    move_object(obj);
    if (*(s16*)(obj + 0xA) - D_8009A202 >= 0x51) {
        *(s32*)(obj + 8) = *(s32*)(obj + 0x18);
    }
}
