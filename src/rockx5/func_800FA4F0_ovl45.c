#include "types.h"

extern u8 D_8009A1F8[];
extern UnkSpawn* func_8002D27C(void);

void func_800FA4F0_ovl45(Ovl45State* s) {
    u8* p = D_8009A1F8;
    UnkSpawn* c;

    *(s32*)(p + 0x60) += 0xCCCCC;
    *(s32*)(p + 0xB4) += 0xCCCCC;
    if (++s->unk4 >= 20) {
        *(s16*)(p + 0x62) = 0x100;
        *(s16*)(p + 0xB6) = 0x200;
        c = func_8002D27C();
        if (c != 0) {
            c->unk0 = 0x41;
            c->unk1 = 0x1D;
            c->unk2 = 0;
            c->unkA = 0x40;
            c->unkE = 0x44;
            c->unk54 = 5;
        }
        s->unk4 = 1;
        s->unk1++;
    }
}
