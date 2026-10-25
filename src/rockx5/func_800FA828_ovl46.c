#include "types.h"

extern UnkSpawn* func_8002D27C(void);

void func_800FA828_ovl46(UnkObj* obj) {
    UnkSpawn* s;

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
