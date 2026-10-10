#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_80091C44;
extern s32 func_8002DF78(void);
extern UnkSpawn* func_8002D27C(void);

void func_800FA244_ovl41(UnkObj* obj) {
    D_8009A1F8_t* p;
    UnkSpawn* s;

    if (--obj->unk6 == 0) {
        D_8009A1F8.unkB6 |= 0x200;
        obj->unk6 = (func_8002DF78() % 6 + 6) * 10;
    } else if (obj->unk6 == 6 && func_8002DF78() % 3 == 1) {
        D_8009A1F8.unkB6 |= 0x200;
    } else {
        D_8009A1F8.unkB6 &= ~0x200;
    }
    p = &D_8009A1F8;
    p->unkF4 = 1;
    if (D_80091C44 == 0) {
        p->unkB6 = 0;
        p->unk5E = 0;
        p->unk62 = 0;
        p->unkA0 = 1;
        p->unk57 = 1;
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0xA0;
            s->unkE = 0x5C;
            s->unk54 = 0;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
