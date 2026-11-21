#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl06.h"
#include "addr.h"

void func_800FAD30_ovl06(u8* obj) {
    apply_object_motion(obj);
    func_8002FB58(obj);
    animate_object(obj);
    if (obj[0x70] & 4) {
        set_animation(obj, 5);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[6]++;
    }
}

extern void start_pad_vibration(s32);

void func_800FAD98_ovl06(Ent08D8* obj) {
    apply_object_motion(obj);
    func_8002FB58(obj);
    animate_object(obj);
    if (obj->unk70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1000;
        obj->unk6 = obj->unk6 + 1;
    }
}

extern void start_pad_vibration(s32);

void func_800FAE14_ovl06(ObjFA284* o) {
    apply_object_motion(o);
    func_8002FB58(o);
    animate_object(o);
    if (o->flags70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, o);
        o->timer = 0x14;
        o->step++;
    }
}

void func_800FAE88_ovl06(ObjFA284* o) {
    animate_object(o);
    if (--o->timer == -1) {
        *(s16*)(D_1F80004C.bytes + 0x8E) = 0x3C;
        D_1F80004C.bytes[0x8A] = 0;
        D_1F80004C.bytes[0x8B] = 0;
        func_800F9180_ovl06(o);
    }
}
