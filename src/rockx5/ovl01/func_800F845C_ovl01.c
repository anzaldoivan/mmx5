#include "types.h"

void func_800F845C_ovl01(Ent2CE8* arg0) {
    Ent2CE8* parent = arg0->unk7C;

    arg0->unk60 = 0x7F;
    arg0->unk50 = parent->unk50;
    arg0->unk15 = parent->unk15;
    arg0->unkA = parent->unkA;
    arg0->unkE = parent->unkE;
    arg0->unk3 = 0;
    arg0->unk4++;
}
