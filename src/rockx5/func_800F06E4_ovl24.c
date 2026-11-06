#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A427;
extern void func_800EFCFC_ovl24(u8* p);
extern void func_8001CF5C(void);
extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);

void func_800F06E4_ovl24(u8* a0) {
    u8* p = D_800D1C00;
    s32 v;

    if (((s8*)p)[0x27] == 1) {
        v = *(u16*)(p + 0x7E) & 0x8000;
        if (v) {
            v = 4;
        } else {
            v = 2;
        }
        a0[0x45] = v;
    }
    func_800EFCFC_ovl24(a0);
    func_8001CF5C();
    D_800D1C00[0x28] = 1;
    func_800F0C00_ovl24((s32)a0, 6, 1);
    func_800F0C00_ovl24((s32)a0, 8, 1);
    func_800F0C00_ovl24((s32)a0, 7, 1);
    func_800F0C00_ovl24((s32)a0, 9, 1);
    func_800F0C00_ovl24((s32)a0, 0xDB, 1);
    D_8009A427 = 0;
    a0[2]++;
}
