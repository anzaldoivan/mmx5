/* Shared body (DK-5), from the banked draft of func_800F81AC_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u8 D_800F9E68_ovl03[];
extern u8 D_800F9E6C_ovl03[];

void DEDUP_NAME(u8* p) {
    u8* g = g_Player;

    if (((signed char*)g)[0xCA] != 0) {
        g[0xCA] = 0;
    }
    set_animation(p, 0xB);
    p[0x62] = 0;
    *(u8**)(p + 0x50) = D_800F9E68_ovl03;
    func_8002C218();
    D_800D50DE = 0;
    D_800C9310 |= 1;
    D_8009A42E = 0;
    D_80093E68 = 0;
    *(u8**)(p + 0x54) = D_800F9E6C_ovl03;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0x20000;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s16*)(p + 0x7C) = 0;
    p[0x6]++;
    animate_object(p);
    apply_object_motion(p);
}
