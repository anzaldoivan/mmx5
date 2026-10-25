#include "types.h"
#include "addr.h"

extern s32 LoadImage(void*, void*);
extern u8 D_800718D8[];
extern s32 D_800E92F8;

void func_800289D8(void) {
    if (D_800E92F8 == 1) {
        LoadImage(D_800718D8, D_1F800044);
        D_800E92F8 = 2;
    }
}
