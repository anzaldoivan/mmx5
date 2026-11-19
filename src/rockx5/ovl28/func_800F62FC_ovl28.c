#include "types.h"
#include "mmx5/globals.h"

extern s32 spawn_wall_jump_visual(u8* obj);

void func_800F62FC_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        spawn_wall_jump_visual(obj);
        obj[6]++;
    }
}
