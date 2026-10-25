#include "types.h"

extern void (*D_800FA1F4_ovl26[])(u8*);
extern u8 D_800F962C_ovl26[];
extern u8 D_800F9630_ovl26[];

void func_800F5544_ovl26(u8* p) {
    D_800FA1F4_ovl26[*(s8*)(p + 6)](p);
    if (p[0x47] == 0x29) {
        *(u8**)(p + 0x50) = D_800F962C_ovl26;
    } else {
        *(u8**)(p + 0x50) = D_800F9630_ovl26;
    }
    if (p[0x70] & 8) {
        p[0x67] = 0;
    } else {
        if (*(s32*)(p + 0x24) < 0) {
            *(s8*)(p + 0x67) = -1;
        } else {
            *(s8*)(p + 0x67) = 1;
        }
    }
}
