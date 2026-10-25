#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern s16 D_800FB784_ovl41[];
extern s16 D_800FB79C_ovl41[];
extern u8 D_800FB7E0_ovl41[];
extern void func_8002385C(s32, s32, s32);
extern void func_80028C10(s32, s32, s32, void*);

void func_800FB148_ovl41(UnkObj* obj) {
    D_8009A1F8_t* p;

    if (obj->unk4 == 0) {
        func_8002385C(0xA, 0xFF, 0);
        p = &D_8009A1F8;
        *(u16*)((u8*)p + 0xB2) = 0x200;
        p->unkB6 = 0;
        p->unkF4 = 1;
        obj->unk6 = 0x14;
        p->unkA = 0x260;
        p->unkE = 8;
        ((u8*)p)[3] = 1;
        ((u8*)p)[0x4C] = 1;
        p->unk5E = 0x260;
        p->unk62 = 0;
        p->unk57 = 1;
        p->unkA0 = 1;
        func_80028C10(D_800FB784_ovl41[0], D_800FB79C_ovl41[4],
                      D_800FB79C_ovl41[5], D_800FB7E0_ovl41);
        obj->unk1++;
        obj->unk4 = 0;
    }
}
