#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

void func_800F72A0_ovl29(u8* obj) {
    u8* sub = *(u8**)(obj + 0x7C);

    func_800317B8(obj);
    animate_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (*(s8*)(sub + 5) != 7) {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}

void func_800F7310_ovl29(u8* obj) {
    func_800317B8(obj);
    apply_object_motion(obj);
    animate_object(obj);
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x50) = 0;
        obj[6]++;
        set_animation(obj, 0x20);
    }
    func_8002D9EC(obj, 0x30, 0x30);
}

extern u8 D_800FA4E8_ovl29[];

void func_800F7380_ovl29(u8* obj) {
    s32 v;

    func_800317B8(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[0x60] = 9;
        obj[6]++;
        set_animation(obj, 0x23);
        if (D_800D1C0C.s == 0xC) {
            v = 0x2C8;
            if (obj[0x15] == 0) {
                v = 0x138;
            }
            *(s16*)(obj + 0xA) = v;
        } else {
            v = 0x15A8;
            if (obj[0x15] == 0) {
                v = 0x1418;
            }
            *(s16*)(obj + 0xA) = v;
        }
        *(s16*)(obj + 0xE) += 0x12C;
        *(u8**)(obj + 0x50) = D_800FA4E8_ovl29;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x40000;
        *(s16*)(obj + 0x88) = 0xC8;
        func_8002D9EC(obj, 0x30, 0x80);
        return;
    }
    func_8002D9EC(obj, 0x30, 0x30);
}

void func_800F746C_ovl29(u8* p) {
    s32 t;

    func_800317B8(p);
    move_object(p);
    animate_object(p);
    if (*(s16*)(p + 0xE) - D_8009A206.s < 0x78) {
        *(s32*)(p + 0x24) = 0;
    }
    t = *(u16*)(p + 0x88) - 1;
    *(u16*)(p + 0x88) = t;
    if ((t << 16) == 0) {
        *(s32*)(p + 0x68) = 0;
        *(s32*)(p + 0x24) = 0xFFFC0000;
        p[6]++;
    }
    if (*(s8*)(p + 0x45) == 1) {
        play_sound(2, 0xAE, p);
    }
    if (*(s8*)(p + 0x45) == 2) {
        play_sound(2, 0xAE, p);
    }
    func_8002D9EC(p, 0x30, 0x80);
}

void func_800F7544_ovl29(u8* a0) {
    func_800317B8(a0);
    move_object(a0);
    animate_object(a0);
    ((s32(*)())func_8002D9EC)(a0, 0x30, 0x80);
    if (*(s8*)(a0 + 3) == 0) {
        a0[4]++;
        a0[5] = 0;
        a0[6] = 0;
    }
}
