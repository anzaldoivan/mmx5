#include "types.h"

extern u8 D_800D1F3C;
extern UnkSpawn* func_8002D27C(void);

void func_800FB730_ovl49(UnkObj* obj) {
    UnkSpawn* s;

    if (D_800D1F3C == 2) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x40;
            s->unkE = 0x7C;
            s->unk54 = 11;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
