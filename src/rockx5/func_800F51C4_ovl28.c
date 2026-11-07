#include "types.h"
#include "addr.h"

extern s8 D_800D1C0F;
extern s8 D_8009A0A5;
extern u8 D_8009A1F8[];
extern u8 D_800FEA5C_ovl28;
extern void func_8003D29C(s32, s32);
extern u8* func_8002D144(void);

void func_800F51C4_ovl28(u8* a0) {
    u8* b;
    u8* p;

    if (D_800D1C0F == 0 && D_8009A0A5 == 20) {
        b = D_8009A1F8;
        D_800FEA5C_ovl28 = b[0x48];
        b[0x48] = 1;
        b[0x47] = 2;
        func_8003D29C(0x1D, 0x40);
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(a0 + 0xE);
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        *(u16*)(a0 + 0x7C) = 0x40;
        a0[6]++;
    }
}
