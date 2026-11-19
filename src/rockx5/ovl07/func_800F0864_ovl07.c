#include "types.h"

extern s32 D_80100818_ovl07[];
extern s32 D_80100810_ovl07[];

void func_800F0864_ovl07(u8* p) {
    u16 m;

    p[0x80] &= 0xFE;
    m = *(u16*)(p + 0x8A);
    if (m & 3) {
        if (m & 1) {
            if (*(s32*)(p + 0x20) < D_80100818_ovl07[p[0x7D]]) {
                *(s32*)(p + 0x20) = D_80100818_ovl07[p[0x7D]];
                *(s32*)(p + 0x28) = 0;
            }
            p[0x7C] = 1;
        } else if (m & 2) {
            if (*(s32*)(p + 0x20) >= D_80100810_ovl07[p[0x7D]]) {
                *(s32*)(p + 0x20) = D_80100810_ovl07[p[0x7D]];
                *(s32*)(p + 0x28) = 0;
            }
            p[0x7C] = 0;
        }
    } else {
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        p[0x7C] = 1;
        p[0x80] &= 0xFE;
    }
}
