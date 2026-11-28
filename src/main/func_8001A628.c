/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001ACC4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

int VSync(int mode);
void ResetGraph(s32);
void SetDispMask(s32);
s32 DrawSync(s32);
void ClearImage(Ovl50Pos*, s32, s32, s32);
void SetDefDispEnv(void*, s32, s32, s32, s32);

extern u8 g_draw_info_buffers[];
#define DB_DISP(i) (*(DbDispEnv*)(g_draw_info_buffers + (i) * 0xB0))
extern DbDispEnv D_800E80D0[];

void func_8001A628(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Ovl50Pos rect;

    D_800E80D0[0] = DB_DISP(0);
    D_800E80D0[1] = DB_DISP(1);
    ResetGraph(0);
    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk4 = 0x1E0;
    rect.unk6 = 0x1E0;
    VSync(0);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    SetDispMask(1);
    SetDefDispEnv(g_draw_info_buffers, 0, 0, arg0, arg1);
    SetDefDispEnv(g_draw_info_buffers + 0xB0, 0, 0xF0, arg0, arg1);
    {
        // !FAKE: pins one to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 one asm("$3") = 1;
        g_draw_info_buffers[0xC1] = one;
        g_draw_info_buffers[0x11] = one;
    }
    g_draw_info_buffers[0xC0] = 0;
    g_draw_info_buffers[0x10] = 0;
}
#undef DB_DISP
