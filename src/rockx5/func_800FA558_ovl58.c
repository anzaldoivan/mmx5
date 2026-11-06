#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_800FBC00_ovl58[];
extern u8 D_800FBA00_ovl58[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA558_ovl58(UnkObj* arg0) {
    u8* p = D_8009A1F8;

    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0x22222;
    if (++arg0->unk4 >= 60) {
        *(s32*)(p + 0x60) = 0x800000;
        func_8002385C(0x5E, 0xFF, 0);
        arg0->unk4 = 0;
        func_8002C3CC(D_800FBC00_ovl58, D_800FBA00_ovl58, 0x100, 0x3C, 0x3C);
        func_8002C338(0x60, D_800FBC00_ovl58, 0x10);
        arg0->unk1++;
    }
}
