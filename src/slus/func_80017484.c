#include "types.h"
#include "addr.h"

extern void LoadImage(void*, void*);
extern u8 D_800C9310;
extern u8 D_800703CC[];
extern u16 D_8009A790[];
extern u16 D_800A11A0[];

void func_80017484(void) {
    if (D_800C9310 != 0) {
        if (D_800C9310 & 1) {
            LoadImage(D_800703CC, D_1F800028);
        }
        if (D_800C9310 & 2) {
            LoadImage(D_800703CC, D_8009A790);
        }
        if (D_800C9310 & 8) {
            LoadImage(D_800703CC, D_800A11A0);
        }
        D_800C9310 = 0;
    }
}
