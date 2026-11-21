#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "addr.h"

void func_800F768C_ovl11(u8* obj) {
    u8 m;

    obj[0x60] = 4;
    obj[0x62] = 0;
    set_animation(obj, 1);
    animate_object(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    m = (u32)random_byte() % 3;
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
    *(s16*)(obj + 0x7C) = (0x70 - (m << 4)) >> 1;
}

void func_800F7724_ovl11(Ent7724* e) {
    u32 r;

    if (e->unkA > D_8009A0AA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    move_object(e);
    animate_object(e);
    if (--e->unk7C == 0) {
        set_animation(e, 2);
        e->unk7C = 90;
        r = random_byte();
        e->unk6++;
        e->unk7E = (u8)(r % 3) + 2;
    }
}

void func_800F77E8_ovl11(Obj77E8* obj) {
    animate_object(obj);
    if (--obj->timer == 0) {
        if (obj->x > D_8009A0AA) {
            obj->flip = 0;
        } else {
            obj->flip = 0x40;
        }
        set_animation(obj, 9);
        obj->state++;
    }
}

void func_800F7868_ovl11(u8* obj) {
    s8 state;
    u8* child;

    if (*(s8*)(obj + 0x45) == 0x10) {
        play_sound(2, 0x33, obj);
    }
    animate_object(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 5;
            child[2] = state;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            child[0x15] = obj[0x15];
            if (obj[0x15] == 0) {
                *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                *(s32*)(child + 0x20) = 0xFFFE0000;
            } else {
                *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) + 0x30;
                *(s32*)(child + 0x20) = 0x20000;
            }
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE) + 0x40;
            *(s32*)(child + 0x28) = 0;
            *(s32*)(child + 0x24) = 0;
            *(s32*)(child + 0x2C) = 0x4000;
            *(u8**)(child + 0x7C) = obj;
        }
        obj[6]++;
    }
}

void func_800F7998_ovl11(Ob7998* obj) {
    animate_object(obj);
    if (--obj->count != 0) {
        obj->state = 2;
        obj->timer = 90;
    } else {
        obj->vy = -0x20000;
        obj->vx = 0;
        obj->unk2C = 0;
        obj->timer = 90;
        obj->state++;
    }
}

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F7A0C_ovl11(u8* obj) {
    if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x50) {
        *(s16*)(obj + 0xA) += 1;
        return;
    }
    if (D_800FA058_ovl11 + 0x50 < *(s16*)(obj + 0xA)) {
        *(s16*)(obj + 0xA) -= 1;
        return;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        set_animation(obj, 1);
    }
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
        return;
    }
    move_object(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 30;
        obj[6]++;
    }
}

extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes
void func_800F7AE8_ovl11(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        obj[6] = 0;
    }
}
