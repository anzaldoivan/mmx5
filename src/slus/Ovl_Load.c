#include "types.h"

extern s32 func_80066D78(s32, s32);
extern s32 CdControlB(s32, s32, u8*);
extern s32 func_80015BCC(void);
extern void func_80014574(s32, s32);

extern u8 D_8009811C;
extern s32 D_800BE9A8;
extern s32 D_800E6360;
extern s32 D_800E5BE4;
extern s32 D_800E6364;
extern u32 D_800E5BF0;
extern u8 D_800E5BE9;
extern s32 D_800E5BEC;
extern PairFB4BC D_800E6188[];
extern s32 D_800E5A30;
extern u8* D_800E5A1C;
extern s32 D_800E5A24;
extern s32 D_800E5A20;
extern s32 D_800E5A18;

void Ovl_Load(s32 idx, s32 buf) {
    // !FAKE: pins a1 to $5 so the table load lands in the argument register (as in Ovl_Load3)
    register s32 a1 asm("$5");
    // !FAKE: pins a0 to $4 so the table load lands in the argument register (as in Ovl_Load3)
    register s32 a0 asm("$4");

    D_800E6360 = D_800BE9A8;
    D_800E6364 = D_800E5BE4;
    if (func_80066D78(1, 0) != 0) {
        CdControlB(9, 0, 0);
    }
    if (D_8009811C != 0x80) {
        D_800E5BF0 = 0;
    }
    D_8009811C = 0;
    D_800E5BE9 = idx;
    D_800E5BEC = buf;
    while (func_80015BCC() & 0x40) {
    }
    a1 = D_800E6188[idx].x;
    a0 = D_800E6188[idx].y;
    D_800E5A30 = 0;
    D_800E5A1C = (u8*)buf;
    D_800E5A24 = a1;
    D_800E5A20 = a0;
    D_800E5A18 = a0;
    func_80014574(a0, a1);
}
