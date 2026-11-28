#include "types.h"
#include "mmx5/globals.h"

#define D_800D1C00_as_D1C00 (*(D1C00*)&g_playthrough_state)

void func_8003CFA8(s8* arg0) {
    if (arg0[0xEA] == 0) {
        if (arg0[0x5C] < (s8)(D_800D1C00_as_D1C00.unk47[arg0[2]] / 3)) {
            arg0[0xEA] = 0x78;
        }
    }
}
