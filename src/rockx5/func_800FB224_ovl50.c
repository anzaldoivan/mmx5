#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;
extern void func_80016490(s32, s32, void*);

void func_800FB224_ovl50(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        func_80016490(2, 0x57, 0);
        p = &D_8009A1F8;
        *(s32*)(p->pad58 + 4) = 0x1400000;
        *(s32*)p->pad60 = 0x4000000;
        p->unk57 = 1;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
