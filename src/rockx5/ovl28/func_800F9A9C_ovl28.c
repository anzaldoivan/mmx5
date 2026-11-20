#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 player_spawn_dash_spark(void* arg0);

void func_800F9A9C_ovl28(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        obj[0x45] = 0;
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = 0xFFFBE000;
        } else {
            *(s32*)(obj + 0x20) = 0x42000;
        }
        play_sound(2, 0x85, obj);
        player_spawn_dash_spark(obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        obj[6]++;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    animate_object(obj);
    apply_object_motion(obj);
}
