/* Shared body (DK-5), from the banked draft of func_800F6780_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern signed char D_800D1C0C;

void DEDUP_NAME(u8* o) {
    s32 r;
    s16 x;
    u32 d;
    s16 c;

    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    r = func_80031DD0(o);
    animate_object(o);
    x = *(s16*)(o + 0xA);
    if ((D_8009A0AA - 4 < x && x < D_8009A0AA + 4) ||
        *(s16*)(o + 0x88) != 0xAA) {
        *(u16*)(o + 0x88) -= 1;
    } else {
        move_object(o);
    }
    if (D_800D1C0C != 0xC) {
        d = *(u16*)(o + 0xA) - 0x1F71;
    } else {
        d = *(u16*)(o + 0xA) - 0xA71;
    }
    if (d >= 0x11F && *(s16*)(o + 0x88) > 0x32) {
        *(s16*)(o + 0x88) = 0x32;
    }
    if (r < 0) {
        o[4] = 6;
        func_8004FD24(o);
        return;
    }
    if (*(s8*)(*(u8**)(o + 0x7C) + 4) == 2) {
        o[3] = 0;
        clear_object_slot(o);
    } else if (is_off_screen(o, 0x40, 0x40) == 1) {
        o[4] = 6;
    } else {
        func_8002D9EC(o, 0x20, 0x20);
    }
    c = *(s16*)(o + 0x88);
    if (c == 50) {
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        set_animation(o, 0x1B);
    } else if (c == 0) {
        o[4] = 6;
    }
}
