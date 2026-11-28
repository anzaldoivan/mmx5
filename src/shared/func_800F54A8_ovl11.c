#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

#define G D_1F80004C.bytes
void func_800F54A8_ovl11(u8* arg0) {
    signed char* p;
    u8* d;

    arg0[3] = 0;
    p = *(signed char**)(G + 0x84);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(s16*)(arg0 + 0x7E) = 5;
                *(u16*)(arg0 + 0x42) ^= 0x8000;
            }
            func_8002D9EC(arg0, 0x60, 0x60);
        }
    } else {
        d = g_playthrough_state.u;
        if (*(signed char*)(d + 0xC) != 12) {
            *(signed char*)(d + 0xF) = 0x10;
        } else {
            *(signed char*)(d + 0xF) = -0x80;
            d[*(signed char*)(d + 0x1D) + 0x2C] = 1;
            d[0x1D] += 9;
        }
        D_8009A1F8.t.unk2A = D_8009A1F8.t.unkE;
        g_playthrough_state.u[0x24] = 0;
        *(s32*)(g_playthrough_state.u + 0x20) = 0;
        clear_object_slot(arg0);
    }
}
