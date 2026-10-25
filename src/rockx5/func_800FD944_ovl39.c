#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800FD944_ovl39(u8* a0) {
    func_8002DF54(a0);
    if ((*(s32*)(a0 + 0x20) > 0 && *(s16*)(a0 + 0xA) >= 0x1278) ||
        (*(s32*)(a0 + 0x20) < 0 && *(s16*)(a0 + 0xA) < 0x11A9)) {
        *(s16*)(a0 + 0x82) = 0x3C;
        a0[6]++;
    }
}
