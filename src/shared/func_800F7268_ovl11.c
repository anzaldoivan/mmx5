#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern s32 func_8002DFB0(void);
extern void func_800F81F4_ovl11(u8* obj);

void func_800F7268_ovl11(u8* obj) {
    set_animation(obj, 1);
    animate_object(obj);
    obj[0x60] = 8;
    obj[0x62] = 0;
    func_800F81F4_ovl11(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s16*)(obj + 0x7C) = (func_8002DFB0() % 32 + 0x50) / 2;
    if (*(s16*)(obj + 0x7C) > 0x100) {
        D_1F80004C.bytes[0x91] = 1;
    } else {
        D_1F80004C.bytes[0x91] = 0;
    }
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F7334_ovl11(Ent7334* e) {
    if (e->x < D_800FA056_ovl11) {
        e->x += 2;
    } else if (D_800FA058_ovl11 < e->x) {
        e->x -= 2;
    }
    move_object(e);
    animate_object(e);
    if (--e->timer == 0) {
        set_animation(e, 2);
        e->timer = 90;
        e->state++;
    }
}

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F73D4_ovl11(Obj73D4* o) {
    apply_object_motion(o);
    animate_object(o);
    if (o->x <= D_800FA056_ovl11 - 0x18) {
        o->x = D_800FA056_ovl11 - 0x18;
    } else if (o->x >= D_800FA058_ovl11 + 0x18) {
        o->x = D_800FA058_ovl11 + 0x18;
    }
    if (o->flags & 8) {
        set_animation(o, 0);
        o->timer = 0x14;
        o->state = 5;
        o->unk24 = 0;
        o->unk2C = 0;
        if (o->facing == 0) {
            o->vx = -0x40000;
        } else {
            o->vx = 0x40000;
        }
        set_animation(o, 4);
        o->vy = -0x1999;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_80050650(s32, s16, s16, s16, s16, s32);

#define S16(p, o) (*(s16*)((p) + (o)))
#define S32(p, o) (*(s32*)((p) + (o)))
void func_800F749C_ovl11(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (!(D_8009A420_as_s32 & 1)) {
        func_80050650(0x11, S16(obj, 0xA) - 0x10, S16(obj, 0xE) + 0x28,
                      S16(obj, 0xA) + 0x10, S16(obj, 0xE) + 0x28, 1);
    }
    if ((S32(obj, 0x20) < 0 ? -S32(obj, 0x20) : S32(obj, 0x20)) < 0x4000 ||
        --S16(obj, 0x7C) == 0) {
        set_animation(obj, 0);
        obj[0x62] = 0;
        S16(obj, 0x7C) = 0x1E;
        obj[6]++;
    }
}
