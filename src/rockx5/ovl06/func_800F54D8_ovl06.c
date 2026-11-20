#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FE918_ovl06[];
extern u8 D_800FE924_ovl06[];

void func_800F54D8_ovl06(u8* p) {
    s32 v;
    u8 t;
    u8* d;
    s8 n;

    if (*(s8*)(p + 6) == 0) {
        p[6]++;
        set_animation(p, 0xA);
    }
    if (p[0x70] & 8) {
        p[5] = 5;
        p[6] = 0;
        return;
    }
    if (!(p[0x8D] & 2)) {
        t = p[0x8A];
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        if (t != 0) {
            v = *(s16*)(p + 0x84) << 8;
            if (!(t & 1)) {
                v = -v;
            }
            *(s32*)(p + 0x20) = v;
        }
        if (*(s32*)(p + 0x24) >= 0 && (p[0x70] & 4)) {
            *(s32*)(p + 0x24) = 0;
        }
        if (*(s8*)(p + 0x46) == 0) {
            n = 8;
            if (*(s32*)(p + 0x24) < 0) {
                n = 4;
            }
            p[5] = n;
        } else {
            if (*(s32*)(p + 0x24) < -0x5E000) {
                *(s32*)(p + 0x24) = -0x5E000;
            }
            apply_object_motion(p);
        }
        n = *(s8*)(p + 0x45);
        if (n == 1) {
            d = D_800FE924_ovl06;
            n = 6;
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        if (n == 2) {
            d = D_800FE918_ovl06;
            n = 5;
        store:
            *(u8**)(p + 0x50) = d;
            p[0x60] = n;
        }
        animate_object(p);
        return;
    }
    animate_object(p);
}
