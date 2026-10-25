/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80016178.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

void func_80012E6C(s32);
void func_80014574(s32, s32);
M2C_UNK func_80014684(M2C_UNK, M2C_UNK, M2C_UNK);
int VSync(int mode);
s32 CdReset(s32);
s32 func_80066D78(s32, s32);
void* func_80066D98(void* func);
s32 CdControlB(M2C_UNK, M2C_UNK, u8*);
extern u8 D_80091D50;
extern s32 D_80091D54;
extern u8 D_8009811C;
extern s32 D_800E5A18;
extern u8* D_800E5A1C;
extern s32 D_800E5A20;
extern s32 D_800E5A24;
extern s32 D_800E5A30;
extern u8 D_800E5BE9;
extern u8 D_800E5BEA;
extern s32 D_800E5BEC;
extern u32 D_800E5BF0;
extern s32 D_800E5C08[][2];

void func_800157D4(void) {
    u8 res[8];
    u8 param[8];
    u8 idx;
    s32 loc;
    // !FAKE: pins a to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 a asm("$4");
    s32 b;
    s32* p;

    param[0] = 0xA0;
    D_80091D54 = 0;
    if (D_8009811C == 2) {
        goto check; // !FAKE: control flow kept from the mmx6 twin
    }
    do {
        {
            if (D_8009811C & 0xC0) {
                if (D_800E5A30 == 0) {
                    idx = D_800E5BE9;
                    loc = D_800E5BEC;
                    if (func_80066D78(1, 0) != 0) {
                        CdControlB(9, 0, 0);
                    }
                    if (D_8009811C != 0x80) {
                        D_800E5BF0 = 0;
                    }
                    D_8009811C = 0;
                    D_800E5BE9 = idx;
                    D_800E5BEC = loc;
                    do {
                        while (CdControlB(1, 0, res) == 0) {
                        }
                    } while (res[0] & 0x40);
                    D_800E5A30 = 0;
                    D_800E5A20 = b =
                        *(volatile s32*)((p = D_800E5C08[idx]) + 1);
                    D_800E5A24 = a = *(volatile s32*)p;
                    D_800E5A1C = (u8*)loc;
                    D_800E5A18 = b;
                    func_80014574(a, 0);
                } else {
                    func_80014684(D_800E5BE9, D_800E5BEA, D_800E5BEC);
                }
            } else {
                if (++D_800E5BF0 >= 0x259) {
                    func_80066D98(0);
                    while (CdReset(0) == 0) {
                    }
                    while (CdControlB(0xE, (s32)param, 0) == 0) {
                    }
                    VSync(3);
                    D_8009811C = 0xC0;
                }
            }
            func_80012E6C(1);
        }
        if (D_8009811C == 2) {
        check:
            if (D_80091D50 == 0) {
                break;
            }
        }
    } while (1);
}
