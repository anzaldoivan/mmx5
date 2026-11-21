#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

void func_800F47EC_ovl29(Ent* e) {
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    set_animation(e, 0xC);
    e->state++;
}

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FA2DC_ovl29[];

void func_800F484C_ovl29(u8* obj) {
    s8 state;
    u8* spawn;

    animate_object(obj);
    state = *(s8*)(obj + 0x45);
    if (state != 0) {
        if (state == 10) {
            *(s16*)(obj + 0x7C) = 0xF0;
            obj[6]++;
        }
        func_8004D4F4(4, D_800FA2DC_ovl29, obj);
        spawn = func_8002D1A4();
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0x29;
            spawn[2] = 1;
            *(u8**)(spawn + 0x7C) = obj;
            if (*(s8*)(obj + 0x45) == 10) {
                *(u8**)(obj + 0x80) = spawn;
                spawn[7] = 1;
            } else {
                spawn[7] = obj[0x45] - 1;
            }
        }
        if (obj[0x45] & 1) {
            play_sound(2, 0xAE, spawn);
        } else {
            play_sound(2, 0xAE);
        }
        obj[0x45] = 0;
    }
}

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4930_ovl29(Ent8EF4* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
