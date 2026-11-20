/* Shared body (DK-5), from the banked draft of func_800F67F0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern void (*D_80101D24_ovl04[])(u8*);

void DEDUP_NAME(u8* obj) {
    s8 st;
    s8 v;
    u8 f;

    st = *(s8*)(obj + 2);
    if (st == 1) {
        if (func_80031DD0(obj) < 0 || (*(s8**)(obj + 0x7C))[4] == 2) {
            ((s32(*)())func_8004FD24)(obj);
            obj[4] = 2;
            return;
        }
    } else if (st == 0) {
        v = (*(s8**)(obj + 0x7C))[4];
        if (v == 2) {
            obj[0x8F] = 8;
            set_animation(obj, 0xE);
            obj[4] = v;
            return;
        }
    } else if (st == 2) {
        s8 w = (*(s8**)(obj + 0x7C))[4];
        if (w == 2) {
            obj[4] = w;
            return;
        }
    }
    func_800317B8(obj);
    f = obj[0x71] | obj[0x70];
    obj[0x71] = f;
    obj[0x93] = f;
    D_80101D24_ovl04[*(s8*)(obj + 5)](obj);
    if (*(s8*)(obj + 2) != 2) {
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D89C(obj);
        } else {
            obj[4] = 2;
        }
        if ((*(u32*)(obj + 4) & 0xFFFF00) == 0x20200) {
            obj[3] = 0;
        }
    } else {
        if (is_off_screen(obj, 0x80, 0x20) != 0) {
            clear_object_slot(obj);
        }
    }
}
