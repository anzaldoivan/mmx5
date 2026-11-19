#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#define g_Player_as_Obj66A0 (*(Obj66A0*)&g_Player)

void func_800F2064_ovl04(Obj66A0* e) {
    s32 d;

    d = g_Player_as_Obj66A0.unkE - e->unkE;
    if (d >= 0 ? d < 0x21 : e->unkE - g_Player_as_Obj66A0.unkE < 0x21) {
        if (e->unk15 == 0 && g_Player_as_Obj66A0.unkA < e->unkA) {
            d = g_Player_as_Obj66A0.unkA - e->unkA;
            if (d >= 0 ? d < 0x61 : e->unkA - g_Player_as_Obj66A0.unkA < 0x61) {
                d = g_Player_as_Obj66A0.unkA - e->unkA;
                if (d >= 0 ? d >= 8 : e->unkA - g_Player_as_Obj66A0.unkA >= 8) {
                    g_Player_as_Obj66A0.unkA += 2;
                }
            }
        } else if (e->unk15 == 0x40 && g_Player_as_Obj66A0.unkA > e->unkA) {
            d = g_Player_as_Obj66A0.unkA - e->unkA;
            if (d >= 0 ? d < 0x61 : e->unkA - g_Player_as_Obj66A0.unkA < 0x61) {
                d = g_Player_as_Obj66A0.unkA - e->unkA;
                if (d >= 0 ? d >= 8 : e->unkA - g_Player_as_Obj66A0.unkA >= 8) {
                    g_Player_as_Obj66A0.unkA -= 2;
                }
            }
        }
    }
    if (--e->unk7C == -1) {
        ((u8*)e)[0x62] = 0;
        D_1F80004C.bytes[0x84] = 0;
        ((u8*)e)[0x60] = 4;
        e->unk5 = 2;
        e->pad6[0] = 0;
    }
}
