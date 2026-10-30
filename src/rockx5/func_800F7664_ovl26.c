#include "types.h"

extern Obj800F20CC* func_8002D27C(void);

void func_800F7664_ovl26(Obj800F7734* parent, s16 x, s16 y, u8 arg3) {
    Obj800F20CC* s;
    u8 v14;

    s = func_8002D27C();
    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 0x29;
        s->unk2 = arg3;
        s->unk40 = parent->unk40;
        s->unk42 = parent->unk42 & 0x7FFF;
        s->unk30 = parent->unk30;
        s->unk3C = parent->unk3C;
        v14 = parent->unk14;
        s->unkA = x;
        s->unk8 = 0;
        s->unkE = y;
        s->unkC = 0;
        s->unk14 = v14;
        s->unk50 = (void*)parent->unk7C;
        s->unk15 = parent->unk15;
    }
}
