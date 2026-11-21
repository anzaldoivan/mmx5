#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FA6B8_ovl50(UnkObj* obj) {
    UnkSpawn* s;

    if (D_80091C44 == 0) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x100;
            s->unkE = 0x7C;
            s->unk54 = 7;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
