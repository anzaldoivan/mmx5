#include "types.h"

extern void func_800132F8(s8 arg);
extern D_8009A1F8_t D_8009A1F8;
extern u16 D_800C9320;

void func_800F056C_ovl25(Ovl25State* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    if (p->unk5E < 0x1C01) {
        p->unkA0 = 1;
        *(s32*)((u8*)p + 0x5C) += 0x8000;
    }
    if (D_800C9320 != 0) {
        func_800132F8(8);
        ((u8*)arg0)[1] = 10;
    }
}
