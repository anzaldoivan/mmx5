#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80071940[];
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u8 D_800D1F20[];

void func_8002906C(void) {
    u8* o;
    u32 i;
    u8* p;

    o = D_8009A1F8.u;
    for (i = 0; i < 3; i++) {
        o[0] = 1;
        o[3] = 1;
        o[0x44] = 1;
        ((s8*)o)[0x52] = -1;
        o[0x4D] = 0;
        o[0x4F] = 0;
        o[0x4E] = D_800D1DBC - 1;
        o[0x50] = D_800D1DBD - 1;
        o += 0x54;
    }
    p = &D_80071940[g_playthrough_state.s[0xC] * 20 +
                    g_playthrough_state.s[0xD] * 10];
    D_800D1F20[0] = *p++;
    D_800D1F20[1] = *p++;
    D_800D1F20[2] = *p++;
    D_800D1F20[3] = *p++;
    D_8009A1F8.u[0x4B] = *p++;
    D_8009A1F8.u[0x4A] = *p++;
    D_8009A1F8.u[0x9F] = *p++;
    D_8009A1F8.u[0x9E] = *p++;
    D_8009A1F8.u[0xF3] = *p++;
    D_8009A1F8.u[0xF2] = *p++;
}
