/* Adapted from mmx6 @a8f96d1 src/shared/SLUS_013.95/func_8001494C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern s32 CdControlB(s32, s32, u8*);
extern s32 CdReset(s32);
extern int VSync(int mode);
extern void func_80012E6C(s32);
extern void func_80014574(s32, s32);
extern u8 func_80015BCC(void);
extern s32 func_80066D78(s32, s32);
extern void* func_80066D98(void* func);
extern u8 D_80091D50;
extern s32 D_80091D54;
extern u8 D_8009811C;
extern s32* D_800BE9A8;
extern s32 D_800E5A18;
extern u8* D_800E5A1C;
extern s32 D_800E5A20;
extern s32 D_800E5A24;
extern s32 D_800E5A30;
extern s32 D_800E5BE4;
extern u8 D_800E5BE9;
extern s32 D_800E5BEC;
extern u32 D_800E5BF0;
extern s32* D_800E6360;
extern s32 D_800E6364;
extern s32 D_800E6188[][2];

// Inlined twin of the PC port's rock_bin lookup: stores the member lba, returns its size.
static inline s32 func_80014064_lookup(u8 idx, s32* out) {
    *out = D_800E6188[idx][0];
    return D_800E6188[idx][1];
}

void Cd_Unk_80014064(void) {
    u8 sp10;
    u8 idx;
    s32 p;

    sp10 = 0xA0;
    D_80091D54 = 0;
    while (D_8009811C != 2 || D_80091D50 != 0) {
        if (D_8009811C & 0xC0) {
            idx = D_800E5BE9;
            p = D_800E5BEC;
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
            D_800E5BEC = p;
            do {
            } while (func_80015BCC() & 0x40);
            D_800E5A30 = 0;
            D_800E5A20 = func_80014064_lookup(idx, &D_800E5A24);
            D_800E5A1C = (u8*)p;
            D_800E5A18 = D_800E5A20;
            ((void (*)(void))func_80014574)();
        } else if (++D_800E5BF0 >= 0x259U) {
            func_80066D98(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (s32)&sp10, 0) == 0) {
            }
            VSync(3);
            D_8009811C = 0xC0;
        }
        func_80012E6C(1);
    }
    D_800BE9A8 = D_800E6360;
    D_800E5BE4 = D_800E6364;
}
