#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern s32 func_8002DF78(void);
extern void func_8002385C(s32, s32, s32);

void func_800FAA90_ovl41(UnkObj* obj) {
    D_8009A1F8_t* p;

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
    if (obj->unk4 == 0) {
        func_8002385C(7, 0xFF, 0);
        obj->unk1++;
    }
}
