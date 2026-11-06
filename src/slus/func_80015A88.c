#include "types.h"

extern s32 func_80066D78(s32, s32);
extern s32 CdControlB(s32, s32, u8*);
extern s32 func_80014574(s32, s32);
extern u8 D_8009811C;
extern u32 D_800E5BF0;
extern u8 D_800E5BE9;
extern s32 D_800E5BEC;
extern s32 D_800E5C08[][2];
extern s32 D_800E5A30;
extern u8* D_800E5A1C;
extern s32 D_800E5A20;
extern s32 D_800E5A24;
extern s32 D_800E5A18;

void func_80015A88(s32 arg0, s32 arg1) {
    u8 buf[8];
    s32* p;
    // !FAKE: pins a to $4 so the table load lands in the argument register (as in func_800157D4)
    register s32 a asm("$4");
    // !FAKE: pins b to $5 so the table load lands in the argument register (as in Ovl_Load3)
    register s32 b asm("$5");

    if (func_80066D78(1, 0) != 0) {
        CdControlB(9, 0, 0);
    }
    if (D_8009811C != 0x80) {
        D_800E5BF0 = 0;
    }
    D_8009811C = 0;
    D_800E5BE9 = arg0;
    D_800E5BEC = arg1;
    do {
        while (CdControlB(1, 0, buf) == 0) {
        }
    } while (buf[0] & 0x40);
    p = D_800E5C08[arg0];
    a = p[1];
    b = p[0];
    D_800E5A30 = 0;
    D_800E5A1C = (u8*)arg1;
    D_800E5A20 = a;
    D_800E5A24 = b;
    D_800E5A18 = a;
    func_80014574(a, b);
}
