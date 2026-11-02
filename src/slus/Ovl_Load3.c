#include "types.h"

extern s32 func_80066D78(s32, s32);
extern s32 CdControlB(s32, u8*, u8*);
extern s32 func_80015BCC(void);
extern void func_80014574(s32, s32);
extern void* func_80066D98(void* func);
extern s32 CdReset(s32);
extern int VSync(int mode);

extern u8 D_8009811C;
extern u8 D_80091D50;
extern s32 D_800E6360;
extern s32 D_800BE9A8;
extern s32 D_800E6364;
extern s32 D_800E5BE4;
extern u8 D_800E5BE9;
extern u32 D_800E5BF0;
extern s32 D_800E5BEC;
extern PairFB4BC D_800E6188[];
extern s32 D_800E5A30;
extern u8* D_800E5A1C;
extern s32 D_800E5A24;
extern s32 D_800E5A20;
extern s32 D_800E5A18;

s32 Ovl_Load3(void) {
    u8 sp10;
    // !FAKE: pins buf to $17 so the table offset takes $16
    register s32 buf asm("$17");
    u8 idx;
    // !FAKE: pins a1 to $5 so the table load lands in the argument register (as in func_800157D4)
    register s32 a1 asm("$5");
    // !FAKE: pins a0 to $4 so the table load lands in the argument register (as in func_800157D4)
    register s32 a0 asm("$4");

    sp10 = 0xA0;
    if (D_8009811C == 2 && D_80091D50 == 0) {
        D_800BE9A8 = D_800E6360;
        D_800E5BE4 = D_800E6364;
        return 1;
    }
    if (D_8009811C & 0xC0) {
        idx = D_800E5BE9;
        buf = 0x800FA000;
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
        return 0;
    }
    if (++D_800E5BF0 >= 0x259) {
        func_80066D98(0);
        while (CdReset(0) == 0) {
        }
        while (CdControlB(0xE, &sp10, 0) == 0) {
        }
        VSync(3);
        D_8009811C = 0xC0;
    }
    return 0;
}
