/* Shared body (DK-5), from the banked draft of func_800F136C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void (*D_800F9918_ovl11[])(u8*);

void DEDUP_NAME(u8* a0) {
    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    if (D_8009A197 == 0) {
        D_800F9918_ovl11[*(s8*)(a0 + 5)](a0);
        animate_object(a0);
        apply_object_motion(a0);
    }
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0 ||
        ((*(u8*)(a0 + 0x70) != 0 ||
          (((s32(*)())func_8002FB58)(a0), *(u8*)(a0 + 0x70) != 0)) &&
         *(u8*)(a0 + 0x93) == 1)) {
        ((s32(*)())func_8004FD24)(a0);
        *(u8*)(a0 + 4) += 1;
        return;
    }
    *(u8*)(a0 + 0x70) = 0;
    if (__builtin_abs(*(s32*)(a0 + 0x20)) > 0x40000) {
        *(s32*)(a0 + 0x28) = 0;
    }
    if (is_off_screen(a0, 0x40, 0x20) == 0) {
        func_8002D9EC(a0, 0x20, 0x20);
        return;
    }
    *(u8*)(a0 + 4) += 1;
}
