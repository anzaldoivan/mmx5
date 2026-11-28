#include "types.h"
#include "mmx5/ovl50.h"
#include "mmx5/globals.h"
#define D_800FBC88_ovl50_as_AB ((D_8009A1F8_AB_t*)D_800FBC88_ovl50)

void func_800FA5B0_ovl50(Ovl45State* arg0) {
    UnkSpawn* s;

    if (++arg0->unk4 >= 30) {
        D_8009A1F8.tAB.unkAB = 0;
        if (D_800FBC88_ovl50_as_AB != 0) {
            D_800FBC88_ovl50_as_AB->unk3 = 0;
        }
        D_8009A1F8.tAB.unk8 = 0;
        D_8009A1F8.tAB.unkC = 0;
        D_8009A1F8.tAB.unk3 = 1;
        D_8009A1F8.tAB.unk4C = 1;
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x40;
            s->unkE = 0x44;
            s->unk54 = 6;
        }
        arg0->unk4 = 1;
        arg0->unk1++;
    }
}
