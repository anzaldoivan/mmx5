/* Shared body (DK-5), from the banked draft of func_800F4E2C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800F9E68_ovl03[];
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(u8* obj) {
    u8* p;

    p = g_Player;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    g_Player[0xCA] = 0;
    if ((s16)((s16)(*(u16*)(obj + 0x7C))++ % 40) == 0) {
        play_sound(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 1;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        *(u8**)(obj + 0x50) = D_800F9E68_ovl03;
        obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
        obj[6] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
