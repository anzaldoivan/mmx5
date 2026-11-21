#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

extern void (*D_800FAE64_ovl09[])(Ent62C8*);

void func_800F62C8_ovl09(Ent62C8* e) {
    if (e->unk94 < 0x50) {
        e->unk94 = 0x64;
    }
    D_800FAE64_ovl09[e->unk6](e);
    func_8002D9EC(e, 0x64, 0x64);
}

extern void silence_sound(s32, s32);
extern u8 D_800FAB9C_ovl09[];
extern u8 D_800FABA4_ovl09[];

void func_800F6334_ovl09(u8* obj) {
    silence_sound(2, 0x26);
    set_animation(obj, 2);
    *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
    *(u8**)(obj + 0x54) = D_800FABA4_ovl09;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x8000;
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}
