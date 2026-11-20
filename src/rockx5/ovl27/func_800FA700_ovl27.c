#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800FA700_ovl27(u8* obj) {
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x89] = 0;
    play_sound(2, 0x67, obj);
    set_animation(obj, 0x12);
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    obj[5] = 3;
    obj[6] = 0;
}
