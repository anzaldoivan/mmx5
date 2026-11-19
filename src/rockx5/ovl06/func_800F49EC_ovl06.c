#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_800FE4D0_ovl06[];
extern u8 D_800FE4D4_ovl06[];
extern u8 D_800FE62C_ovl06[];
extern u8 D_8009A244;

void func_800F49EC_ovl06(u8* obj) {
    if (*(s16*)(obj + 0x7C) == 0) {
        move_object(obj);
        if (*(s16*)(obj + 0xA) < 0xBA0) {
            obj[6] = 2;
        }
    } else if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        obj[0x8D] = 0;
        *(u8**)(obj + 0x50) = D_800FE4D0_ovl06;
        *(u8**)(obj + 0x54) = D_800FE4D4_ovl06;
        func_80028B18(0, 0xC80, 0xE0, D_800FE62C_ovl06);
        D_8009A244 = 1;
    }
}
