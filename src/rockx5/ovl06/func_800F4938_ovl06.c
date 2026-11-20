#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800FE624_ovl06[];
extern u8 D_8009A244;

void func_800F4938_ovl06(u8* obj) {
    if (*(s16*)(obj + 0x7C) == 0) {
        apply_object_motion(obj);
    } else {
        *(s16*)(obj + 0x7C) -= 1;
    }
    if (obj[0x70] & 1) {
        func_80028B18(0, 0xC80, 0xE0, D_800FE624_ovl06);
        D_8009A244 = 1;
        play_sound(2, 0x1D, obj);
        func_8002A5C4(0x28, 4, 2);
        *(s16*)(obj + 0x7C) = 0x3C;
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        obj[6]++;
    }
}
