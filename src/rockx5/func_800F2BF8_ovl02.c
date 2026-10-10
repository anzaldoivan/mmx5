#include "types.h"

extern s16 D_8009A0AA;
extern void func_8002DED4(Ent2BF8*);

void func_800F2BF8_ovl02(Ent2BF8* a0) {
    if (a0->unk70 & 8) {
        *(s32*)((u8*)a0 + 0x2C) = 0;
        *(s32*)((u8*)a0 + 0x24) = 0;
        if (a0->unkA < D_8009A0AA) {
            a0->unk20 = 0x38000;
            a0->unk5 = 3;
        } else {
            a0->unk20 = -0x38000;
            a0->unk5 = 7;
        }
    }
    func_8002DED4(a0);
}
