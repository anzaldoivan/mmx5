/* Shared body (DK-5), from the banked draft of func_800F6358_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 func_8002D800(u8* a0);

void DEDUP_NAME(u8* o) {
    if (func_8002D800(o) == 0) {
        if (((s8*)o)[2] >= 6) {
            if (*(s32*)(o + 0x24) > 0x20000) {
                *(s32*)(o + 0x24) = 0x20000;
            }
            if (((s8*)*(u8**)(o + 0x50))[0x90] > 0) {
                *(s32*)(o + 0x20) = 0;
            } else {
                *(s32*)(o + 0x20) = 0xFFFF0000;
            }
            if (((s8*)o)[2] == 8) {
                *(s32*)(o + 0x20) = 0x10000;
            }
        }
        ((s32(*)())apply_object_motion)(o);
        if (((s8*)o)[2] == 0) {
            o[3] ^= 1;
        } else {
            if ((u8)(((s8*)o)[2] - 4) < 2) {
                *(s32*)(o + 0x20) = *(s32*)(*(u8**)(o + 0x50) + 0x98);
            }
            animate_object(o);
            if (o[0x47] == 0x34 || ((s8*)o)[0x45] == 0x10) {
                clear_object_slot(o);
                return;
            }
        }
        if (((s8*)o)[3] != 0) {
            func_8002D9EC(o, 0x30, 0x40);
        }
    } else {
        clear_object_slot(o);
    }
}
