/* Shared body (DK-5), from the banked draft of func_800EFB70_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(Obj3DD4*, s32);
extern s8 D_800D1C0F;
extern s16 D_8009A1F8[];

void DEDUP_NAME(Obj3DD4* a) {
    if (D_800D1C0F == 0) {
        if (a->unk7C == 0x28) {
            *(s32*)((u8*)a + 0x94) = D_8009A1F8[0x13];
            D_8009A1F8[0x13] = D_8009A1F8[0x12] - 0x10;
        }
        if (--a->unk7C == 0) {
            func_8003D29C(0x14, 0x40);
        }
        if (**(s8**)((u8*)a + 0x80) == 0) {
            func_80016490(2, 0x47, a);
            func_800171E8(a, 0);
            a->unk24 = 0xFFF80000;
            a->unk6++;
        }
    }
}
