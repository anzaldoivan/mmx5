#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800FED30_ovl07(u8* o) {
    s8 st = o[6];
    u8 r;

    if (st == 0) {
        *(s32*)(o + 0x24) = -0xA0000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x2C) = 0;
        o[6]++;
    } else if (st == 1) {
        if (D_800D1C0C.s != 12) {
            if (*(s16*)(o + 0xE) < 0x519) {
                move_object(o);
            } else {
                r = random_byte() & 7;
                o[0x54] = r;
                if (r == 0) {
                    o[0x54] = st;
                }
                o[6]++;
            }
        } else {
            if (*(s16*)(o + 0xE) < 0xD9) {
                move_object(o);
            } else {
                r = random_byte() & 7;
                o[0x54] = r;
                if (r == 0) {
                    o[0x54] = st;
                }
                o[6]++;
            }
        }
    } else if (st == 2) {
        if (--((s8*)o)[0x54] == 0) {
            set_animation(o, 11);
            o[6]++;
        } else {
            move_object(o);
        }
    } else if (st == 3) {
        if (((s8*)o)[0x45] != 0) {
            o[4] = 2;
            o[3] = 0;
            return;
        }
    }
    func_8002D9EC(o, 0x20, 0x20);
    animate_object(o);
}
