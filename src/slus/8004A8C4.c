#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void func_8004A8C4(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (*(s16*)(obj + 0x8E) >= 4) {
        if (is_off_screen(obj, 0x20, 0x20) == 1) {
            obj[4]++;
        }
        return;
    }
    if ((u16)(*(u16*)(obj + 0xA) - 0x10) > 0x120) {
        (*(s16*)(obj + 0x8E))++;
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        play_sound(1, 0x1B, obj);
    } else if ((u16)(*(u16*)(obj + 0xE) - 0x10) > 0xD0) {
        (*(s16*)(obj + 0x8E))++;
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
        play_sound(1, 0x1B, obj);
    }
    func_8002D9EC(obj, 0x20, 0x20);
}

#define func_80046A6C func_8004A9BC
#include "shared/func_80046A6C.c"
#undef func_80046A6C
