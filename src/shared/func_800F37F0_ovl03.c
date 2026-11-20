/* Shared body (DK-5), from the banked draft of func_800F37F0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* o) {
    s32 k = 0x2000;

    if (++*(s16*)(o + 0x7C) == 50) {
        if (o[0x8F] == 4) {
            *(s16*)(o + 0x7C) = 0;
            o[6] += 2;
        } else {
            switch (o[0x8E]) {
            case 0:
                if ((random_byte() & 0xF) < 8) {
                    o[0x8E] = 1;
                    *(s32*)(o + 0x84) = k;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 2;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = -0x2000;
                }
                break;
            case 1:
                if ((random_byte() & 0xF) < 8) {
                    o[0x8E] = 0;
                    *(s32*)(o + 0x84) = -0x2000;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 3;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = -0x2000;
                }
                break;
            case 2:
                if ((random_byte() & 0xF) < 4) {
                    o[0x8E] = 3;
                    *(s32*)(o + 0x84) = k;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 0;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = k;
                }
                break;
            case 3:
                if ((random_byte() & 0xF) < 4) {
                    o[0x8E] = 2;
                    *(s32*)(o + 0x84) = -0x2000;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 1;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = k;
                }
                break;
            }
            *(s16*)(o + 0x7C) = -1;
            o[6]++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}
