/* Shared body (DK-5), from the banked draft of func_800F6924_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* o) {
    u8 f;
    s16 t;

    move_object(o);
    animate_object(o);
    ((s32(*)())func_8002FB58)(o);
    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    f = o[0x70];
    if ((f & 2) || (f & 1)) {
        play_sound(2, 0x2E, o);
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
    }
    if (*(s32*)(o + 0x70) & 0xC) {
        play_sound(2, 0x2E, o);
        *(s32*)(o + 0x24) = -*(s32*)(o + 0x24);
    }
    if (func_80031DD0(o) < 0) {
        o[4] = 9;
        func_8004FD24(o);
        return;
    }
    if ((*(s8**)(o + 0x7C))[4] == 2) {
        o[3] = 0;
        clear_object_slot(o);
    } else if (is_off_screen(o, 0x60, 0x60) == 1) {
        o[4] = 9;
    } else {
        func_8002D9EC(o, 0x20, 0x20);
    }
    t = --*(u16*)(o + 0x88);
    if (t == 0) {
        o[4] = 9;
    } else if (t == 50) {
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x24) = 0;
        set_animation(o, 0x22);
    }
}
