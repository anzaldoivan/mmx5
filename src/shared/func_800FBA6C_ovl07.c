/* Shared body (DK-5), from the banked draft of func_800FBA6C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);

void DEDUP_NAME(u8* obj) {
    s8 v;
    u8* p;

    if (--*(s16*)(obj + 0x7E) == -1) {
        *(s16*)(obj + 0x7E) = 3;
        play_sound(2, 0x24, obj);
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 0);
    }
    v = *(s8*)(obj + 0x45);
    if (v == 1) {
        p = D_1F80004C.bytes;
        if (p[0x92] == 0) {
            p[0x92] = v;
            func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 1);
        }
    }
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0x7C) = 100;
        obj[6]++;
    }
    animate_object(obj);
}
