#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5528_ovl04(u8* o) {
    s32 base;

    if (--*(s16*)(o + 0x7C) == 0) {
        o[5] = 5;
        *(s8*)(o + 0x90) *= -1;
        o[0x8F] ^= 1;
        if (o[0x8F] == 0) {
            set_animation(o, 3);
            base = 0;
            o[5] = 4;
            o[6] = 0;
        } else {
            base = 4;
        }
        o[0x91] = random_byte() & 0xF;
        if (o[0x91] < 5) {
            o[0x91] = base;
        } else if (o[0x91] < 8) {
            o[0x91] = base + 1;
        } else if (o[0x91] < 11) {
            o[0x91] = base + 2;
        } else {
            o[0x91] = base + 3;
        }
    }
    animate_object(o);
}

extern signed char D_800D1C0C;

void func_800F55F8_ovl04(u8* obj) {
    s32 lim = 0xB0;

    if (D_800D1C0C != 12) {
        lim = 0xA0;
    }
    animate_object(obj);
    if (*(s16*)(obj + 0xE) < lim) {
        *(s16*)(obj + 0xE) += 1;
    } else if (lim < *(s16*)(obj + 0xE)) {
        *(s16*)(obj + 0xE) -= 1;
    } else {
        if (*(signed char*)(obj + 0x46) == 0) {
            set_animation(obj, 3);
        }
        *(s32*)(obj + 0x98) = 0;
        *(s16*)(obj + 0x7C) = 30;
        obj[6]++;
    }
}

void func_800F56A0_ovl04(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        *(s32*)(obj + 0x98) = 0;
        obj[5] = 5;
        obj[6] = 0;
    }
}
