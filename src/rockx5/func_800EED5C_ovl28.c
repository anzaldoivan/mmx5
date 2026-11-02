#include "types.h"
#include "addr.h"

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern u8 D_800FEA1C_ovl28[];

void func_800EED5C_ovl28(u8* arg0) {
    s32 one; // s32: a QImode 1 would be CSEd into s0 across the call
    s32 c;   // s32: sets the 0x1F before its lui (v1/v0 order)
    u8* p;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    D_80093DD0[2] |= 0x10000000;
    *(s16*)(arg0 + 0x16) = 0;
    c = 0x1F;
    D_800D50DE = c;
    D_8009A42E = 0x3E0;
    D_80093E68 = 0x7C00;
    p = D_8009A1F8;
    *(s16*)(p + 0xB2) = 0x1900;
    *(s16*)(p + 0xB6) = 0x260;
    one = 1;
    p[0xF4] = one;
    p[0xAB] = 0;
    *(Blk20*)D_800FEA1C_ovl28 = *(Blk20*)(D_1F800028 + 0x8E0);
    arg0[6]++;
}
