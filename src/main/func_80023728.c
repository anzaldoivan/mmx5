#include "types.h"
#include "mmx5/globals.h"

#define D_800D1C00_as_Blk1BC (*(Blk1BC*)&g_playthrough_state)

void func_80023728(void) {
    u8* p = 0x801F61C8;

    D_800D1C00_as_Blk1BC = *(Blk1BC*)p;
}
