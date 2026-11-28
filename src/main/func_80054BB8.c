#include "types.h"
#include "mmx5/globals.h"

extern void* D_8007C34C[];

void func_80054BB8(u8* arg0) {
    u8* a1 = g_playthrough_state.u;
    u8* a2 = g_Player;

    ((void (*)(u8*, u8*, u8*))D_8007C34C[((s8*)arg0)[5]])(arg0, a1, a2);
}
