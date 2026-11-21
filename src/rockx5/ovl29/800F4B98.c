#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern s16 D_800FA650_ovl29;
extern s16 D_800FA64A_ovl29;

void func_800F4B98_ovl29(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s16*)(obj + 0xE) < D_800FA650_ovl29) {
        *(s16*)(obj + 0xE) = D_800FA650_ovl29;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    if (obj[0x15] == 0) {
        if (!(*(s16*)(obj + 0xA) < D_800FA64A_ovl29 - 0x10)) {
            return;
        }
    } else {
        if (!(D_800FA64A_ovl29 + 0x10 < *(s16*)(obj + 0xA))) {
            return;
        }
    }
    *(s32*)(obj + 0x2C) = 0x1F00;
    obj[6]++;
}

void func_800F4C48_ovl29(u8* obj) {
    u8* child;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 6);
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

extern u8 D_800F9894_ovl29[];
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4D08_ovl29(Ent4D08* obj) {
    animate_object(obj);
    if (obj->unk46 == 0) {
        obj->unk50 = D_800F9894_ovl29;
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
