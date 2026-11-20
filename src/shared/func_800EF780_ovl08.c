/* Shared body (DK-5), from the banked draft of func_800EF780_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
s32 func_8004FC64(u8* a0);

void DEDUP_NAME(u8* a0) {
    s32 state;

    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    if (func_800317B8(a0) != 0) {
        state = 2;
        goto store;
    }
    if (func_80031DD0(a0) < 0) {
        state = 2;
        goto store;
    }
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            goto check;
        }
    }
    func_8004FC64(a0);
    a0[4]++;
    return;
check:
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    state = a0[4] + 1;
store:
    a0[4] = state;
}
