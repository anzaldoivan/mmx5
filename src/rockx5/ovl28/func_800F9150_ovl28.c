#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);
extern void func_80044DD0(s32 a0);

void func_800F9150_ovl28(u8* obj) {
    if (obj[0x70] & 8) {
        silence_sound(2, 0x90);
        func_80044DD0(0);
        set_animation(obj, 2);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
