#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);
extern u8 D_8009A420[];
extern u8 D_8009A427;
extern u16 D_800C931C[];
extern s8 D_800F5F7A_ovl24;
extern s8 D_800F5F80_ovl24;

void func_800EF028_ovl24(s32 arg0) {
    u16* pad;

    if (D_800C931C[2] & 0x5000) {
        if (D_800F5F80_ovl24 != 0) {
            func_80016490(0, 0xC, 0);
        }
        D_8009A420[7] ^= 1;
    }
    pad = D_800C931C;
    if (D_800F5F80_ovl24 != 0) {
        if (!(pad[2] & 0x40)) {
            return;
        }
        func_80016490(0, 0x22, 0);
        if (D_8009A427 == 0) {
            D_800F5F7A_ovl24 = 1;
        } else {
            goto two; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        if (!(pad[2] & 0x8FF)) {
            return;
        }
        if (D_8009A427 == 0) {
            D_800F5F7A_ovl24 = 1;
        } else {
        two: // !FAKE: label kept for the matching branch layout
            D_800F5F7A_ovl24 = 2;
        }
    }
    func_800F0C00_ovl24(arg0, 0xDE, 1);
    ((u8*)arg0)[2]++;
}
