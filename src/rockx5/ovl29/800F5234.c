#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern s32 D_800F9898_ovl29[];

void func_800F5234_ovl29(Obj4EA0* e) {
    ((u8*)e)[0x60] = 8;
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    set_animation(e, 5);
    e->unk50 = D_800F9898_ovl29;
    e->unk6++;
}

extern u8 D_800F989C_ovl29[];
extern u8 D_800F9894_ovl29[];

void func_800F52A8_ovl29(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s8*)(obj + 0x45) == 2) {
        *(u8**)(obj + 0x50) = D_800F989C_ovl29;
    }
    if (obj[0x15] != 0 ? *(s32*)(obj + 0x20) < 0 : *(s32*)(obj + 0x20) >= 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
    }
    if (*(s32*)(obj + 0x24) < 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
        set_animation(obj, 7);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
}

extern u8 D_800F9894_ovl29[];

void func_800F5364_ovl29(u8* obj) {
    u8* child;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 2;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 3;
            *(u8**)(child + 0x50) = obj;
        }
        obj[0x67] = 0;
        play_sound(2, 0xAF, obj);
    }
}

extern u8 D_800FA2E0_ovl29[][6];

void func_800F5434_ovl29(Ent9364* obj) {
    animate_object(obj);
    if (obj->unk46 == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
