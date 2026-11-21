#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_800F20BC_ovl12[];
extern u8 D_800F20C0_ovl12[];
extern u8 D_80074EE0[];

void func_800EF48C_ovl12(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);
    s32 t;

    *(u16*)(obj + 0x40) = *(u16*)(parent + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    obj[0x16] = 1;
    obj[0x14] = 0;
    t = parent[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x50) = D_800F20BC_ovl12;
    *(u8**)(obj + 0x54) = D_800F20C0_ovl12;
    *(u8**)(obj + 0x58) = D_80074EE0;
    obj[0x15] = t;
    set_animation(obj, 0xD);
    if (obj[0x15] == 0) {
        *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) - 0x10;
        *(s32*)(obj + 0x20) = 0xFFFB0000;
    } else {
        *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + 0x10;
        *(s32*)(obj + 0x20) = 0x50000;
    }
    if (random_byte() & 1) {
        *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x7C) + 0xE) - 6;
        obj[0x6] = 0;
    } else {
        *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x7C) + 0xE) + 6;
        obj[0x6] = 1;
    }
    obj[0x5C] = 1;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x60] = 6;
    obj[0x5] = 0;
    obj[0x4]++;
}

void func_800EF5E8_ovl12(u8* p) {
    u8* q;
    s16 a;
    s16 b;
    s32 d;

    func_800317B8(p);
    func_80031DD0(p);
    switch (*(s8*)(p + 5)) {
    case 0:
        if (p[0x15] == 0) {
            if (*(s16*)(p + 0xA) < 0x50) {
                if (*(s8*)(p + 6) != 0) {
                    *(s32*)(p + 0x24) = 0x8000;
                } else {
                    *(s32*)(p + 0x24) = -0x8000;
                }
                *(s32*)(p + 0x8C) = 0;
                p[5]++;
            }
        } else if (*(s16*)(p + 0xA) > 0x120) {
            if (*(s8*)(p + 6) != 0) {
                *(s32*)(p + 0x24) = 0x8000;
            } else {
                *(s32*)(p + 0x24) = -0x8000;
            }
            *(s32*)(p + 0x8C) = 0;
            p[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(p + 0x8C) == 0xC) {
            if (p[0x15] == 0) {
                p[0x15] = 0x40;
                *(s32*)(p + 0x20) = 0x50000;
            } else {
                p[0x15] = 0;
                *(s32*)(p + 0x20) = -0x50000;
            }
            p[5]++;
        }
        break;
    case 2:
        if (++*(s32*)(p + 0x8C) == 0x18) {
            *(s32*)(p + 0x24) = 0;
        }
        a = *(s16*)(*(u8**)(p + 0x7C) + 0xA);
        b = *(s16*)(p + 0xA);
        d = a - b;
        if ((d >= 0) ? (d < 0x47) : (b - a < 0x47)) {
            (*(u8**)(p + 0x7C))[7] = 1;
            *(s32*)(p + 0x8C) = 0;
            p[5]++;
        }
        break;
    case 3:
        if (++*(s32*)(p + 0x8C) == 0xB) {
            p[4] = 2;
        }
        break;
    }
    q = *(u8**)(p + 0x7C);
    if (*(s8*)(q + 4) == 2 || *(s8*)(q + 5) == 9) {
        p[4] = 2;
    }
    func_8002D9EC(p, 0x20, 0x10);
    animate_object(p);
    apply_object_motion(p);
}

extern s16 D_8009A0AE;

void func_800EF7EC_ovl12(u8* arg0) {
    u8* p;
    u8* o;

    func_800317B8(arg0);
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if (*(s16*)(arg0 + 0xE) >= D_8009A0AE - 0x12) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 2;
                *(u8**)(p + 0x7C) = arg0;
            }
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 3;
                *(u8**)(p + 0x7C) = arg0;
            }
            *(s32*)(arg0 + 0x50) = 0;
            set_animation(arg0, 0xF);
            *(s32*)(arg0 + 0x24) = 0;
            arg0[5]++;
        }
        break;
    case 1:
        if (*(s8*)(arg0 + 0x46) == 0) {
            arg0[4] = 2;
        }
        break;
    }
    o = *(u8**)(arg0 + 0x7C);
    if (*(s8*)(o + 4) == 2 || *(s8*)(o + 5) == 9) {
        arg0[4] = 2;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
    animate_object(arg0);
    move_object(arg0);
}
