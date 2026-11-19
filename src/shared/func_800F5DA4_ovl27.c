/* Shared body (DK-5), from the banked draft of func_800F5DA4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
s32 func_8004FC64(u8* a0);

void DEDUP_NAME(u8* a0) {
    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    func_800317B8(a0);
    if (a0[0x70] != 0) {
        goto block;
    }
    ((s32(*)())func_8002F8FC)(a0);
    if (a0[0x70] != 0) {
    block:
        func_8004FC64(a0);
        a0[4]++;
        return;
    }
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4]++;
}
