#include "types.h"

extern void* D_800703B4[];
extern u8 D_80091D50;
extern u8 D_800E5208;
extern u16 D_800E5A44;
extern u16 D_800E5A46;
extern Rec5A58 D_800E5A58[];

void func_800152B8(void) {
    while (D_800E5A58[D_800E5208].unk0 != 0) {
        ((void (*)(void))D_800703B4[D_800E5A58[D_800E5208].unk1])();
        D_800E5A58[D_800E5208].unk0 = 0;
        D_800E5208++;
        if (D_800E5208 == 0x20) {
            D_800E5208 = 0;
        }
        D_800E5A44++;
    }
    if (D_800E5A46 == D_800E5A44) {
        D_80091D50 = 0;
    }
}
