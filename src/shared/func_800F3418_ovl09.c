/* Shared body (DK-5), from the banked draft of func_800F3418_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FAB9C_ovl09[];
extern u8 D_800FABA0_ovl09[];
extern u8 D_800FABA4_ovl09[];
extern u8 D_800FAD58_ovl09[][6];

void DEDUP_NAME(u8* obj) {
    s32 r;

    if (++*(s16*)(obj + 0x7C) & 1) {
        obj[0x47] = obj[0x90];
        animate_object(obj);
        apply_object_motion(obj);
        *(s16*)(obj + 0x8C) = *(s16*)(obj + 0xA);
        *(s16*)(obj + 0x8E) = *(s16*)(obj + 0xE);
        *(s16*)(obj + 0xA) = *(s16*)(obj + 0x84);
        *(s16*)(obj + 0xE) = *(s16*)(obj + 0x88);
        if (*(s16*)(obj + 0x7C) < 30) {
            *(u8**)(obj + 0x50) = 0;
        } else {
            *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
        }
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        if (*(s16*)(obj + 0x7C) >= 41) {
            *(u8**)(obj + 0x54) = D_800FABA4_ovl09;
            if (*(s16*)(obj + 0x7E) < 4) {
                set_animation(obj, 4);
                *(u8**)(obj + 0x50) = D_800FABA0_ovl09;
                if (D_800D1CA2 / 2 < *(signed char*)(obj + 0x5C)) {
                    if (obj[0x15] == 0) {
                        *(s32*)(obj + 0x20) = -0x20000;
                    } else {
                        *(s32*)(obj + 0x20) = 0x20000;
                    }
                } else {
                    if (obj[0x15] == 0) {
                        *(s32*)(obj + 0x20) = -0x40000;
                    } else {
                        *(s32*)(obj + 0x20) = 0x40000;
                    }
                }
                r = random_byte();
                (*(s16*)(obj + 0x7E))++;
                obj[6]--;
                *(s16*)(obj + 0x7C) = (r % 5 + 3) * 10;
            } else {
                set_animation(obj, 0);
                *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
                obj[5] = D_800FAD58_ovl09[obj[0x96]][obj[0x97]++];
                obj[6] = 0;
            }
        }
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        animate_object(obj);
        obj[0x90] = obj[0x47];
        obj[0x47] = 9;
        *(s16*)(obj + 0xA) = *(s16*)(obj + 0x8C);
        *(s16*)(obj + 0xE) = *(s16*)(obj + 0x8E);
        apply_object_motion(obj);
        if (*(s16*)(obj + 0x7C) < 30) {
            *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
            if (*(s32*)(obj + 0x20) < 0) {
                obj[0x15] = 0;
            } else {
                obj[0x15] = 0x40;
            }
            func_8002D9EC(obj, 0x40, 0x40);
        } else {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(u8**)(obj + 0x50) = 0;
        }
    }
}
