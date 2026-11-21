#include "types.h"
#include "mmx5/object.h"
#include "addr.h"

extern void silence_sound(s32, s32);

void func_800F85D4_ovl09(u8* arg0) {
    if (D_1F80004C.bytes[0x84] == 2) {
        silence_sound(2, 0x26);
    }
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x85] |= 1 << (((s8*)arg0)[2] - 1);
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] |= 1 << (((s8*)arg0)[2] - 1);
    clear_object_slot(arg0);
}

extern void silence_sound(s32, s32);

void func_800F866C_ovl09(s32 arg0) {
    silence_sound(2, 0x26);
    clear_object_slot(arg0);
}
