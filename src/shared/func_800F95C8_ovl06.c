/* Shared body (DK-5), from the banked draft of func_800F95C8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent657C* e) {
    ((u8*)e)[0x9A] = 0;
    g_Player[0xCA] = 0;
    func_8003D29C(0x14, g_Player[0x15]);
    e->unk5 = 1;
    e->unk42 &= 0x7FFF;
    set_animation(e, 4);
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    func_8002D9EC(e, 0x60, 0x60);
}
