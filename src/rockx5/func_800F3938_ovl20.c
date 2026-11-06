#include "types.h"
#include "addr.h"

extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u32* D_80098118;
extern u8 D_800F56D8_ovl20[];
extern u16 D_800F56DC_ovl20[][2];

void func_800F3938_ovl20(u8* o) {
    s32* p;

    ((s16*)o)[0x21] = 0x7800;
    ((s16*)o)[0x20] = *D_80098118 >> 7;
    p = D_1F800020.s32s;
    ((u8**)o)[0xF] = (u8*)p + *p;
    ((u8**)o)[0xC] = D_800F56D8_ovl20;
    func_80017214(o, 0, o[2] & 7);
    ((u16*)o)[5] = D_800F56DC_ovl20[((s8*)o)[2]][0];
    ((u16*)o)[7] = D_800F56DC_ovl20[((s8*)o)[2]][1];
    ((s16*)o)[0x21] = 0x78C4;
    o[0x16] = 3;
    o[0x14] = 1;
    o[0x15] = 0;
    o[4]++;
    func_8002D9EC(o, 0x20, 0x20);
}
