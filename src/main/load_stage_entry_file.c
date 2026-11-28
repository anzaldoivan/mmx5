#include "types.h"
#include "mmx5/globals.h"

extern void SsSepClose(s32);
extern s32 SsSepOpenJ(u8*, s32, s32);
extern void SsSepSetVol(s32, s32, s32, s32);
extern void read_dat_file(s32, s32);
extern void pump_file_loads(void);

extern u8 D_800703C8[];
extern s8 D_80093E60[];
extern s8 D_80093E6C[];
extern s32 D_800A69A8;
extern s32 D_800A69AC[];

void load_stage_entry_file(void) {
    s8* p;
    u8 i;

    for (i = 0; i < 4; i++) {
        p = &D_80093E6C[i];
        if (*p != -1) {
            SsSepClose(*p);
            *p = -1;
        }
    }
    read_dat_file(D_800703C8[g_playthrough_state.s[0x44]], (s32)&D_800A69A8);
    pump_file_loads();
    D_80093E6C[0] = SsSepOpenJ((u8*)&D_800A69A8 + D_800A69A8, D_80093E60[0], 8);
    for (i = 0; i < 8; i++) {
        SsSepSetVol(D_80093E6C[0], i, 0x7F, 0x7F);
    }
    D_80093E6C[1] =
        SsSepOpenJ((u8*)&D_800A69AC[-1] + D_800A69AC[0], D_80093E60[1], 2);
    for (i = 0; i < 2; i++) {
        SsSepSetVol(D_80093E6C[1], i, 0x7F, 0x7F);
    }
}
