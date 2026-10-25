#include "types.h"

extern Blk1BC D_800D1C00;
extern s32 D_8009A420;
extern u16 D_80093F70;

void func_80023788(void) {
    u8* p = 0x801F6000;

    *(s32*)(p + 0) = 0;
    *(s32*)(p + 4) = D_8009A420;
    *(u16*)(p + 8) = D_80093F70;
    *(Blk1BC*)(p + 0xC) = D_800D1C00;
}
