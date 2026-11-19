#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800FECD4_ovl39[];

void func_800FE2FC_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0xA9, obj);
        *(u8**)(obj + 0x50) = D_800FECD4_ovl39;
        *(s16*)(obj + 0x8C) = 50;
        obj[5]++;
    }
}
