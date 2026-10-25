#include "types.h"

extern UnkSpawn* func_8002D27C(void);

void func_800FA75C_ovl52(UnkObj* obj) {
    UnkSpawn* s;

    s = func_8002D27C();
    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 0x1D;
        s->unk2 = 0;
        s->unkA = 0x40;
        s->unkE = 0x44;
        s->unk54 = 9;
    }
    obj->unk4 = 1;
    obj->unk1++;
}
