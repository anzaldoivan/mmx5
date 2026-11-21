#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

void func_800F0B58_ovl08(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) != 0) {
        return;
    }
    obj[0x8A] = 1;
    if (obj[0x15] == 0) {
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            goto hit; // !FAKE: goto kept for the matching branch layout
        }
        goto miss; // !FAKE: goto kept for the matching branch layout
    }
    if (D_8009A0AA < *(s16*)(obj + 0xA)) {
    hit:
        set_animation(obj, 2);
        obj[5] = 4;
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 1;
        return;
    }
miss:
    *(s16*)(obj + 0x7C) = 20;
    obj[6] = 1;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0xFFFC0000;
    } else {
        *(s32*)(obj + 0x20) = 0x40000;
    }
}

void func_800F0C30_ovl08(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (*(s32*)(obj + 0x8C) != 1) {
        *(s32*)(obj + 0x8C) -= 1;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 1);
        *(s32*)(obj + 0x28) = -0x2000;
        obj[6] = 2;
    }
}

void func_800F0CA4_ovl08(u8* obj) {
    if (*(s32*)(obj + 0x8C) != 1) {
        *(s32*)(obj + 0x8C) = *(s32*)(obj + 0x8C) - 1;
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) == 0) {
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(u8*)(obj + 0x88) = 0;
        *(s16*)(obj + 0x7C) = 10;
        *(u8*)(obj + 0x6) = 3;
    }
}

void func_800F0D10_ovl08(Ent0D10* obj) {
    if (obj->unk8C != 1) {
        obj->unk8C--;
    }
    animate_object(obj);
    if (--obj->unk7C == 0) {
        obj->unk89 = 0;
        obj->unk8A = 0;
        if ((obj->unk15 == 0 && D_8009A0AA > obj->unkA) ||
            (obj->unk15 != 0 && D_8009A0AA < obj->unkA)) {
            obj->unk7C = 20;
            obj->unk28 = 0;
            obj->unk24 = 0;
            obj->unk5 = 4;
        } else {
            obj->unk5 = 6;
        }
        obj->unk6 = 0;
    }
}
