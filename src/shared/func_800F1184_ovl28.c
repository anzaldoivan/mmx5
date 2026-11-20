/* Shared body (DK-5), from the banked draft of func_800F1184_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#define g_Player_as_Obj4FE0 (*(Obj4FE0*)&g_Player)

#define G D_1F80004C.bytes
extern s8 func_8002E024(Obj4FE0*, Obj4FE0*);
extern void func_800F09F0_ovl28(Obj4FE0*);

void DEDUP_NAME(Obj4FE0* s) {
    s->unk6++;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0;
    s->unk2C = 0;
    set_animation(s, 1);
    G[0x80] = 20;
    G[0x82] = 0;
    if (g_Player_as_Obj4FE0.unkA - s->unkA > 0) {
        s->unk15 = 0x40;
    }
    G[0x85] = func_8002E024(s, &g_Player_as_Obj4FE0);
    func_800F09F0_ovl28(s);
}
