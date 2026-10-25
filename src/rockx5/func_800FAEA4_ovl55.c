#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern void func_80016490(s32, s32, void*);
extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DDC;

void func_800FAEA4_ovl55(Ovl45State* e) {
    if (++e->unk4 == 40) {
        func_80016490(2, 0x57, 0);
    }
    if (e->unk4 >= 61) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DDC = 0xFFFF;
        e->unk1++;
    }
}
