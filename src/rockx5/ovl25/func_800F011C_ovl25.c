#include "types.h"

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;
extern D_8009A1F8_t D_8009A1F8;

void func_800F011C_ovl25(Ovl25State* arg0) {
    D_8009A1F8.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8 + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.unk5E >= 0x1380) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}
