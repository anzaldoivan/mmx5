#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

void func_800FAFB8_ovl41(UnkObj* obj) {
    D_8009A1F8_t* p;

    if (--obj->unk6 == 0) {
        D_8009A1F8.t.unkB6 |= 0x200;
        obj->unk6 = (random_byte() % 6 + 6) * 10;
    } else if (obj->unk6 == 6 && random_byte() % 3 == 1) {
        D_8009A1F8.t.unkB6 |= 0x200;
    } else {
        D_8009A1F8.t.unkB6 &= ~0x200;
    }
    p = &D_8009A1F8.t;
    p->unkF4 = 1;
    *(s32*)((u8*)p + 0x60) += 0x88888;
    *(s32*)((u8*)p + 0xB4) += 0x88888;
    if (++obj->unk4 >= 30) {
        func_8002385C(9, 0xFF, 0);
        p->unk62 = 0x100;
        p->unkB6 = 0x100;
        p->unkA0 = 1;
        p->unkF4 = 1;
        obj->unk4 = 0;
        obj->unk1++;
    }
}
