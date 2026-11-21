#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F00AC_ovl01(u8* obj) {
    s32 st;
    s32 one;

    animate_object(obj);
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        if (*(s8*)(obj + 2) == 4 && *(s32*)(obj + 0x8C) == 0) {
            obj[5] = 7;
            obj[6] = 0;
            return;
        }
        st = *(s32*)(obj + 0x80);
        if (st != 0) {
            one = 1;
            if (st == one) {
                one =
                    0; // !FAKE: dead store ends the st == one equivalence (C0070)
                *(s32*)(obj + 0x80) = 2;
                set_animation(obj, 1);
                obj[0x60] = 4;
                *(s32*)(obj + 0x84) = st;
                obj[5] = 5;
                return;
            }
            one = 0; // !FAKE: dead store ends the st == one equivalence (C0070)
            if (obj[0x15] != 0) {
                *(s32*)(obj + 0x20) = 0x40000;
            } else {
                *(s32*)(obj + 0x20) = 0xFFFC0000;
            }
            *(s32*)(obj + 0x84) = 1;
            obj[5] = 5;
            obj[6] = 3;
            return;
        }
        obj[5] = 2;
        return;
    }
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x80) != 2) {
        if (obj[0x15] == 0) {
            if (obj[0x70] & 2) {
                obj[0x15] = 0x40;
                *(s32*)(obj + 0x20) = 0x28000;
            }
        } else if (obj[0x70] & 1) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0xFFFD8000;
        }
    }
}
