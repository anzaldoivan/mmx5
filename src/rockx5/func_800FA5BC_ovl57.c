#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FA5BC_ovl57(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    p->unkF4 = 1;
    *(s32*)&p->padA1[0xB0 - 0xA1] += 0x19999;
    arg0->unk4++;
    if (arg0->unk4 >= 0x78) {
        func_8002385C(0x6D, 0xFF, 0);
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0xC0;
        p->unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
