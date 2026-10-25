#include "types.h"

extern Obj800F7734* func_8002D27C(void);

void func_800F7734_ovl26(Obj800F7734* e, u8 arg1) {
    Obj800F7734* o;

    o = func_8002D27C();
    if (o != 0) {
        o->unk0 = 0x41;
        o->unk1 = 0x29;
        o->unk2 = arg1;
        o->unk40 = e->unk40;
        o->unk42 = e->unk42 & 0x7FFF;
        o->unk30 = e->unk30;
        o->unk3C = e->unk3C;
        o->unk14 = e->unk14;
        o->unk50 = e->unk7C;
        o->unk15 = e->unk15;
        o->unk54 = e;
    }
}
