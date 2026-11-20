#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800FE198_ovl28[][3];
extern s32 D_8009A0A8;
extern void func_800F6A8C_ovl28(u8* obj);
extern s32 player_spawn_dash_spark(void* arg0);

#define G D_1F80004C.bytes
void func_800F5884_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    if (*(s16*)(obj + 0x7E) != 0) {
        animate_object(obj);
        (*(s16*)(obj + 0x7E))--;
        return;
    }
    play_sound(2, 0x71, obj);
    obj[0x9A] = 1;
    if (D_800FE198_ovl28[G[0x89]][G[0x8A] + 1] == 5) {
        set_animation(obj, 8);
    } else {
        set_animation(obj, 3);
    }
    *(s32*)(obj + 0x28) = -0x3000;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x1E;
    if (*(s32*)(obj + 0x8) < D_8009A0A8) {
        *(s32*)(obj + 0x20) = 0x68000;
        obj[0x15] = 0x40;
    } else {
        *(s32*)(obj + 0x20) = 0xFFF98000;
        obj[0x15] = 0;
    }
    player_spawn_dash_spark(obj);
    obj[6]++;
}
