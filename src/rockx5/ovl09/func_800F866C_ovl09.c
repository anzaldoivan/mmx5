#include "types.h"
#include "mmx5/object.h"

extern void silence_sound(s32, s32);

void func_800F866C_ovl09(s32 arg0) {
    silence_sound(2, 0x26);
    clear_object_slot(arg0);
}
