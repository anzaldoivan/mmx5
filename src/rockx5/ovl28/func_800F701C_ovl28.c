#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

void func_800F701C_ovl28(u8* obj) {
    if (*(s8*)(obj + 6) == 4) {
        play_sound(2, 0x6C, obj);
    }
    clear_object_slot(obj);
}
