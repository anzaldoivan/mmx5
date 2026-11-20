#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800FC724_ovl38(u8* obj) {
    if ((s8)obj[0x45] == 2) {
        play_sound(2, 0xA3, obj);
    } else if ((s8)obj[0x45] == 1) {
        set_animation(obj, 0xE);
        *(s16*)(obj + 0x7C) = 0x32;
        *(s16*)(obj + 0x7E) = random_byte() & 3;
        *(s16*)(D_1F80004C.bytes + 0x86) = 0;
        obj[6] = 4;
    }
}
