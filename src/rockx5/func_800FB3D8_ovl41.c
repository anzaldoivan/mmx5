#include "types.h"

extern u8 D_80091C44;
extern UnkSpawn* func_8002D27C(void);

void func_800FB3D8_ovl41(UnkObj* obj) {
    UnkSpawn* s;

    if (D_80091C44 == 0) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 2;
            s->unkA = 0xA0;
            s->unkE = 0x60;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
