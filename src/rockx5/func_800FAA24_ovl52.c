#include "types.h"

extern u8 D_80091C44;
extern u8 D_800FB360_ovl52[];
extern u8 D_800FB160_ovl52[];
extern s32 D_800FB964_ovl52;

extern void func_80016490(s32, s32, void*);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800FAA24_ovl52(u8* e) {
    if (D_80091C44 == 0) {
        *(s16*)(e + 4) = 0;
        func_80016490(2, 0x53, 0);
        func_8002C3CC(D_800FB360_ovl52, D_800FB160_ovl52, 0x100, *(s16*)(e + 4),
                      0x78);
        func_8002C338(0x60, D_800FB360_ovl52, 0x10);
        D_800FB964_ovl52 = 0;
        e[1]++;
    }
}
