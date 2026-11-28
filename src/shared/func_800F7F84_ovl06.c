#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

#define G D_1F80004C.bytes
void func_800F7F84_ovl06(u8* arg0) {
    signed char* p;

    arg0[3] = 0;
    p = *(signed char**)(G + 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(s16*)(arg0 + 0x7E) = 5;
                *(u16*)(arg0 + 0x42) ^= 0x8000;
            }
            func_8002D9EC(arg0, 0x60, 0x60);
        }
    } else {
        D_8009A1F8.t.unk2A = D_8009A1F8.t.unkE;
        g_playthrough_state.u[0x24] = 0;
        *(s32*)(g_playthrough_state.u + 0x20) = 0;
        if (*(signed char*)(g_playthrough_state.u + 0xC) != 12) {
            *(signed char*)(g_playthrough_state.u + 0xF) = 0x10;
        } else {
            *(signed char*)(g_playthrough_state.u + 0xF) = -0x80;
            g_playthrough_state
                .u[*(signed char*)(g_playthrough_state.u + 0x1D) + 0x2C] = 1;
            g_playthrough_state.u[0x1D] += 9;
        }
        clear_object_slot(arg0);
    }
}
