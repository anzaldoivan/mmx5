#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define g_Player_as_Obj66A0 (*(Obj66A0*)&g_Player)

void func_800F1F88_ovl04(Obj66A0* e) {
    s32 d;

    if (e->unk15 == 0) {
        e->unk20 = -0x8000;
    } else {
        e->unk20 = 0x8000;
    }
    d = g_Player_as_Obj66A0.unkE - e->unkE;
    if (d >= 0 ? d >= 4 : e->unkE - g_Player_as_Obj66A0.unkE >= 4) {
        if (g_Player_as_Obj66A0.unkE >= e->unkE) {
            e->unk24 = -0x10000;
        } else {
            e->unk24 = 0x10000;
        }
    } else {
        e->unk24 = 0;
    }
    move_object(e);
    if (--e->unk7C == -1) {
        e->unk5 = 3;
        e->pad6[0] = 0;
    }
}
