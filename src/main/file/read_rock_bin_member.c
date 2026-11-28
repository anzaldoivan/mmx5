#include "types.h"
#include "mmx5/globals.h"

extern s32 func_80066D78(s32, s32);
extern s32 CdControlB(s32, s32, u8*);
extern s32 get_cd_status(void);
extern void start_cd_read(s32, s32);

extern u8 D_8009811C;
extern s32 D_800E6360;
extern s32 D_800E5BE4;
extern s32 D_800E6364;
extern u32 D_800E5BF0;
extern u8 D_800E5BE9;
extern s32 D_800E5BEC;
extern s32 D_800E5A30;
extern u8* D_800E5A1C;
extern s32 D_800E5A24;
extern s32 D_800E5A20;
extern s32 D_800E5A18;

void read_rock_bin_member(s32 idx, s32 buf) {
    // !FAKE: pins a1 to $5 so the table load lands in the argument register (as in poll_rock_bin_read)
    register s32 a1 asm("$5");
    // !FAKE: pins a0 to $4 so the table load lands in the argument register (as in poll_rock_bin_read)
    register s32 a0 asm("$4");

    D_800E6360 = D_800BE9A8.w;
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
    while (get_cd_status() & 0x40) {
    }
    a1 = g_rock_bin_toc.e[idx].x;
    a0 = g_rock_bin_toc.e[idx].y;
    D_800E5A30 = 0;
    D_800E5A1C = (u8*)buf;
    D_800E5A24 = a1;
    D_800E5A20 = a0;
    D_800E5A18 = a0;
    start_cd_read(a0, a1);
}
