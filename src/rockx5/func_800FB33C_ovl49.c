#include "types.h"

extern u8 D_80091C44;
extern UnkSpawn* func_8002D27C(void);

void func_800FB33C_ovl49(UnkObj* obj) {
    UnkSpawn* s;

    if (D_80091C44 == 0) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x100;
            s->unkE = 0x7C;
            s->unk54 = 10;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
