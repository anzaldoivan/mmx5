#include "types.h"
#include "addr.h"

extern u8 D_8009A0FC;
s32 func_8002E198(void);

void func_800F2B0C_ovl04(u8* a0) {
    s16 old = D_1F80004C.scr80->unk80;

    if (D_8009A0FC & 0x7F) {
        D_1F80004C.scr80->unk80 += func_8002E198();
    }
    if (old != D_1F80004C.scr80->unk80) {
        *(u16*)(a0 + 0x42) |= 0x8000;
    }
    if (D_1F80004C.scr80->unk80 >= 8) {
        a0[4] = 4;
        a0[5] = 0;
    }
}
