#include "types.h"
#include "mmx5/globals.h"

void func_800FE2D4_ovl04(u8* arg0) {
    u8* p = g_playthrough_state.u;

    if (p[0x28] & arg0[0x93]) {
        arg0[0x95] = ~arg0[0x93];
        arg0[0x96] = 0xFF;
        arg0[5]++;
    }
    if (((s8*)p)[0x28] == 0 && (p[0x29] & arg0[0x93])) {
        arg0[0x95] = 0xFF;
        arg0[0x96] = ~arg0[0x93];
        arg0[5]++;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
}

#include "shared/func_800FE370_ovl04.c"
