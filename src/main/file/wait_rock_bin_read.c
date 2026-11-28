/* Adapted from mmx6 @a8f96d1 src/shared/SLUS_013.95/func_8001494C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

extern s32 CdControlB(s32, s32, u8*);
extern s32 CdReset(s32);
extern int VSync(int mode);
extern void task_yield(s32);
extern void start_cd_read(s32, s32);
extern u8 get_cd_status(void);
extern s32 func_80066D78(s32, s32);
extern void* func_80066D98(void* func);
extern u8 D_80091D50;
extern s32 D_80091D54;
extern u8 D_8009811C;
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

// Inlined twin of the PC port's rock_bin lookup: stores the member lba, returns its size.
static inline s32 func_80014064_lookup(u8 idx, s32* out) {
    *out = g_rock_bin_toc.w[idx][0];
    return g_rock_bin_toc.w[idx][1];
}

void wait_rock_bin_read(void) {
    u8 sp10;
    u8 idx;
    s32 p;

    sp10 = 0xA0;
    D_80091D54 = 0;
    while (D_8009811C != 2 || D_80091D50 != 0) {
        if (D_8009811C & 0xC0) {
            idx = D_800E5BE9;
            p = D_800E5BEC;
            D_800E6360 = D_800BE9A8.pw;
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
            } while (get_cd_status() & 0x40);
            D_800E5A30 = 0;
            D_800E5A20 = func_80014064_lookup(idx, &D_800E5A24);
            D_800E5A1C = (u8*)p;
            D_800E5A18 = D_800E5A20;
            ((void (*)(void))start_cd_read)();
        } else if (++D_800E5BF0 >= 0x259U) {
            func_80066D98(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (s32)&sp10, 0) == 0) {
            }
            VSync(3);
            D_8009811C = 0xC0;
        }
        task_yield(1);
    }
    D_800BE9A8.pw = D_800E6360;
    D_800E5BE4 = D_800E6364;
}
