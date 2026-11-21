#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

void func_800F889C_ovl00(u8* obj) {
    set_animation(obj, 2);
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F88E0_ovl00(Obj88E0* obj) {
    if (obj->flag46 == 0) {
        obj->unk28 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F8934_ovl00(u8* obj) {
    u8* p = g_Player;
    s32 y;

    if (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA) < 0x50) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s16*)(obj + 0x7C) = 50;
        obj[6]++;
    }
    if (*(s32*)(obj + 0x20) > 0x3FFFF) {
        *(s32*)(obj + 0x28) = 0;
    }
    y = *(s16*)(obj + 0xE) + 0x30;
    if (y < *(s16*)(p + 0xE)) {
        *(s16*)(obj + 0xE) += 1;
    } else if (*(s16*)(p + 0xE) < y) {
        *(s16*)(obj + 0xE) -= 1;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F89EC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
            set_animation(obj, 3);
            obj[6] += 3;
        } else {
            *(s16*)(obj + 0x7C) = 10;
            obj[6]++;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}

#include "shared/func_800F8A78_ovl00.c"

extern u8 D_800FB448_ovl00[][6];

void func_800F8ADC_ovl00(Ent9364* obj) {
    if (obj->unk46 == 0) {
        obj->unk5 = D_800FB448_ovl00[obj->unk8D][obj->unk8E++];
        obj->unk6 = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F8B54_ovl00(Obj8B54* obj) {
    if (obj->flag46 == 0) {
        set_animation(obj, 1);
        obj->timer = 10;
        obj->count = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

#include "shared/func_800F8BB4_ovl00.c"
