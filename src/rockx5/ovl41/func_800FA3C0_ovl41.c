#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

void func_800FA3C0_ovl41(UnkObj* obj) {
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
    if (obj->unk4 == 0) {
        func_8002385C(5, 0xFF, 0);
        obj->unk1++;
    }
}
