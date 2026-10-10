#include "types.h"

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;
extern u8 D_800F0EF4_ovl25[];
extern u8 D_800F0CF4_ovl25[];
extern D_8009A1F8_t D_8009A1F8;

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);

void func_800EF140_ovl25(Ovl25State* arg0) {
    D_8009A1F8.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8 + 0x5C) += D_800F0CE4_ovl25 << 15;
    arg0->unk4++;
    func_8002C3CC(D_800F0EF4_ovl25, D_800F0CF4_ovl25, 0x100, arg0->unk4,
                  0x40 / D_800F0CE6_ovl25);
    func_8002C338(0x50, D_800F0EF4_ovl25, 0x10);
    if (arg0->unk4 > 0x40 / D_800F0CE6_ovl25) {
        *(s16*)((u8*)&D_8009A1F8 + 0xB2) = 0x200;
        D_8009A1F8.unkF4 = 1;
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}
