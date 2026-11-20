#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800F9F04_ovl26[];
extern u8 D_8009A244;

void func_800F53E8_ovl26(u8* obj) {
    u8* p;

    animate_object(obj);
    move_object(obj);
    if (obj[0x70] & 3) {
        play_sound(2, 0x63, obj);
        p = D_800F9F04_ovl26;
        func_80028B18(0, 0x8B0, 0x11D0, p);
        func_80028B18(0, 0xA60, 0x11D0, p + 8);
        D_8009A244 = 1;
        set_animation(obj, 0x12);
        func_8002A5C4(0x32, 8, 1);
        *(s16*)(obj + 0x7C) = 0x5A;
        obj[6]++;
    }
}
