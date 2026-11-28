#include "types.h"
#include "mmx5/globals.h"

extern s32 load_stage(void);

void func_80020B80(u8* obj) {
    u8* g = g_playthrough_state.u;

    obj[0] = 6;
    g[0x26] = obj[0xC];
    g[0x27] = obj[0xD];
    obj[0xC] = 0xD;
    obj[0xD] = 1;
    if (((s8*)g)[0x26] >= 10) {
        obj[0x41] = 9;
    } else {
        obj[0x41] = g[0x26];
    }
    load_stage();
}
