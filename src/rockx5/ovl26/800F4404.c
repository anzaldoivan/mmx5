#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/system.h"

void func_800F4404_ovl26(u8* o) {
    animate_object();
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}

void func_800F443C_ovl26(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0x1A);
        obj[6]++;
    }
}

extern s8 D_800FA683_ovl26;

void func_800F4494_ovl26(u8* obj) {
    u8* child;

    animate_object(obj);
    if (obj[0x47] == 0x31 && D_1F80004C.bytes[0x93] == 0) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x17;
            child[2] = 0x11;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            if (D_1F80004C.bytes[0x96] == 0) {
                child[0x15] = 0;
                *(u16*)(child + 0xA) = 0xA10;
            } else {
                child[0x15] = 0x40;
                *(u16*)(child + 0xA) = 0x910;
            }
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            *(u8**)(child + 0x7C) = obj;
        }
        D_1F80004C.bytes[0x93] = 1;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 7);
        *(s32*)(obj + 0x2C) = 0x4000;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        D_800FA683_ovl26 = 0;
    }
}

extern s8 D_800FA683_ovl26;

void func_800F45CC_ovl26(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (D_800FA683_ovl26 == 0 && *(s16*)(obj + 0xE) >= 0x1240) {
        D_800FA683_ovl26 = 1;
    }
    if (*(s16*)(obj + 0xE) >= 0x1260) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        set_animation(obj, 8);
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
    }
}

void func_800F4658_ovl26(u8* obj) {
    u8 state;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        if (*(s8*)(obj + 0x5C) >= D_800D1CA2 / 2 ||
            (u32)(random_byte() & 0xF) < 8) {
            state = 8;
        } else {
            state = 9;
        }
        obj[5] = state;
        obj[6] = 0;
    }
}
