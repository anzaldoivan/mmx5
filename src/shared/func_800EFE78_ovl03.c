/* Shared body (DK-5), from the banked draft of func_800EFE78_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;

void DEDUP_NAME(u8* a0) {
    if (D_8009A197 == 0) {
        animate_object();
        apply_object_motion(a0);
    }
    if (func_80031DD0(a0) < 0) {
        ((s32(*)())func_8004FD24)(a0);
        a0[4]++;
        return;
    }
    if (func_800317B8(a0) != 0) {
        ((s32(*)())func_8004FD24)(a0);
        a0[4] = 2;
        return;
    }
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            goto check;
        }
    }
    *(u16*)(a0 + 0xE) += 0x20;
    ((s32(*)())func_8004FD24)(a0);
    a0[4]++;
    return;
check:
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4]++;
}
