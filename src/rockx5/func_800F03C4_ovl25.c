#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern D_8009A1F8_t D_8009A1F8;
extern u8 D_800F1EF4_ovl25[];
extern u8 D_800F1CF4_ovl25[];

void func_800F03C4_ovl25(Ovl25State* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    *(s32*)((u8*)p + 0x5C) += 0x8000;
    p->unkA0 = 1;
    if (p->unk5E >= 0x1B20) {
        func_8002C3CC(D_800F1EF4_ovl25, D_800F1CF4_ovl25, 0x100, ++arg0->unk4,
                      0x40);
        func_8002C338(0x90, D_800F1EF4_ovl25, 0x10);
        if (arg0->unk4 >= 0x41) {
            *(s16*)((u8*)p + 0xB2) = 0xA00;
            p->unkF4 = 1;
            arg0->unk4 = 0;
            ((u8*)arg0)[1]++;
        }
    }
}
