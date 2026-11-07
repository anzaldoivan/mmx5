#include "types.h"

extern s32 func_80028B18(s32, s32, s32, void*);
extern u8 D_8009A0A0[];
extern s16 D_8009A206;
extern u8 D_800F8BB0_ovl26[];
extern void* D_800F8C44_ovl26[];

void func_800EEE34_ovl26(u8* a0) {
    u8* g = D_8009A0A0;

    if (g[0xF7] == 0) {
        ((void (*)(u8*))D_800F8C44_ovl26[((s8*)a0)[5]])(a0);
        *(u16*)(a0 + 0x14) += 1;
    }
    if (*(s16*)(a0 + 0x1A) == 0 && (u16)(*(u16*)(g + 0xA) - 0x3C0) < 0x140 &&
        (u16)(*(u16*)(g + 0xE) - 0x11E0) < 0xB0 && D_8009A206 >= 0x11B0) {
        func_80028B18(0, 0x3C0, 0x11A0, D_800F8BB0_ovl26);
        *(s16*)(a0 + 0x1A) = 1;
    }
}
