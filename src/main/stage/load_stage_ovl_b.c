#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void wait_rock_bin_read(void);
extern void read_rock_bin_member(s32, s32);
extern void setup_file_load(s32, s32, s32);
extern void wait_for_file_load(s32, s32);
extern u8 D_8006FC54[];
extern s32 D_80073E3C;
extern s32 D_8009A758;
extern u8 D_800D1598;
extern u8 g_ovl_idx_stage_b[];

void load_stage_ovl_b(void) {
    s32 saved;
    s32 idx;
    u8* buf;

    saved = D_800BE9A8.w;
    read_rock_bin_member(g_ovl_idx_stage_b[g_playthrough_state.s[0x1D] - 2],
                         0x800FA000);
    wait_rock_bin_read();
    setup_file_load(D_8006FC54[g_playthrough_state.s[0x1D] - 2], 4, D_8009A758);
    wait_for_file_load(0, 1);
    idx = g_playthrough_state.s[0x1D] - 2;
    buf = D_1F800030 + ((idx << 7) + 0xCA0);
    if (idx == 7) {
        load_palette(0x138, buf, 4);
    }
    if (g_playthrough_state.s[0x1D] == 2) {
        load_palette(0x134, buf, 4);
    } else {
        load_palette(0x13C, buf, 4);
    }
    if (g_playthrough_state.s[0x1D] - 2 == 1) {
        D_80073E3C = 0x80003;
    } else {
        D_80073E3C = 0;
    }
    D_800BE9A8.w = saved;
    D_800D1598 = g_playthrough_state.s[0x1D];
}
