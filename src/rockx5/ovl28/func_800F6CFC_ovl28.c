#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void func_800F6CFC_ovl28(u8* obj) {
    animate_object(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0xC0, 0x40);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x77, obj);
        obj[5]++;
    }
}
