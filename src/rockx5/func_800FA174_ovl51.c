#include "types.h"

extern u8 D_800D1F3C;
extern UnkSpawn* func_8002D27C(void);

void func_800FA174_ovl51(UnkObj* obj) {
    u8 v = D_800D1F3C;
    UnkSpawn* s;

    if (v == 2) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = v;
            s->unkA = 0xA0;
            s->unkE = 0x60;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
