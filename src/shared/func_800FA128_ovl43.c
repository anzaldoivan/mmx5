#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1F3C;
extern void SetDispMask(s32);

void func_800FA128_ovl43(UnkObj* obj) {
    u8 v = D_800D1F3C;
    UnkSpawn* s;

    if (v == 2) {
        SetDispMask(1);
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
