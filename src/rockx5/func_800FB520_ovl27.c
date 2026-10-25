#include "types.h"

extern void func_8002DF54(u8* a0);
extern s8 D_8009A0A2;
extern u8 D_800D1C49;
extern u8 D_800FDB78_ovl27[];
extern u8 D_800FDB84_ovl27[];

void func_800FB520_ovl27(u8* a0) {
    func_8002DF54(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(s32*)(a0 + 0x50) = 0;
        } else if (((s8*)a0)[2] == 2) {
            *(u8**)(a0 + 0x50) = D_800FDB78_ovl27;
        } else {
            *(u8**)(a0 + 0x50) = D_800FDB84_ovl27;
        }
        *(s16*)(a0 + 0x88) = 0x28;
        a0[6] = 2;
    }
}
