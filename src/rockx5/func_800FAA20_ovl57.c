#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FAA20_ovl57(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        p = &D_8009A1F8;
        arg0->unk1++;
        arg0->unk4 = 0;
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0;
        p->unkB6 = 0x100;
        p->unkF4 = 1;
        p->pad0[3] = 0;
        p->unk57 = 0;
        func_8002385C(0x73, 0xFF, 0);
    }
}
