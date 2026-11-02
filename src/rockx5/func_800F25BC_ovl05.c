#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8002D720(u8* arg0);
extern u8 D_800F5964_ovl05[];
extern u8 D_8009A1F8[];
extern u8 D_800F56E4_ovl05[];

void func_800F25BC_ovl05(u8* a0) {
    u8* p;
    u8* q;

    func_80031DD0(a0);
    if (((s8*)a0)[6] == 0) {
        p = D_8009A1F8;
        if (*(s16*)(p + 0xA) < *(s16*)(a0 + 0xA) - 0x130) {
            return;
        }
        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA) - 0x130;
        *(s16*)(p + 0x26) = *(s16*)(a0 + 0xA) - 0x130;
        *(s16*)(p + 0x24) = *(s16*)(a0 + 0xA) - 0x130;
        a0[6]++;
        return;
    }
    if (D_800F5964_ovl05[0] != 0) {
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004FD90(a0, 1, 0, 0x7F);
        func_8004D4F4(9, D_800F56E4_ovl05, a0);
        *(s16*)(a0 + 0xE) -= 100;
        func_8004D4F4(9, D_800F56E4_ovl05, a0);
        *(s16*)(a0 + 0xE) -= 200;
        func_8004D4F4(9, D_800F56E4_ovl05, a0);
        q = D_8009A1F8;
        *(s16*)(q + 0x26) = *(s16*)(a0 + 0x7C);
        *(s16*)(q + 0x24) = *(s16*)(a0 + 0x7E);
        func_8002D720(a0);
    }
}
