#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void silence_sound(s32, s32);

void func_8004A1C0(u8* obj) {
    u8* p;

    silence_sound(1, 0x18);
    p = g_Player;
    p[0x98]--;
    p[0x99]--;
    clear_object_slot(obj);
}
