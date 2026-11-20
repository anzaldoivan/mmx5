#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_800FCD04_ovl38(u8* obj, s32 arg1);

void func_800FBCAC_ovl38(u8* obj) {
    u8* scr;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(s16*)(D_1F80004C.bytes + 0x84) = 0;
        func_800FCD04_ovl38(obj, 0);
        play_sound(2, 0xA2, obj);
    } else {
        scr = D_1F80004C.bytes;
        if (*(s16*)(scr + 0x84) == 1) {
            *(s16*)(scr + 0x84) = 0;
            *(s16*)(obj + 0x7C) = 2;
            obj[6]++;
        }
    }
}
