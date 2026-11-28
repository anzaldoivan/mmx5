#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

#define D_800D1C00_as_Blk1BC (*(Blk1BC*)&g_playthrough_state)
extern u16 D_80093F70;

void func_80023788(void) {
    u8* p = 0x801F6000;

    *(s32*)(p + 0) = 0;
    *(s32*)(p + 4) = D_8009A420_as_s32;
    *(u16*)(p + 8) = D_80093F70;
    *(Blk1BC*)(p + 0xC) = D_800D1C00_as_Blk1BC;
}
