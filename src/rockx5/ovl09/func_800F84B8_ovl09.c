#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s16 D_8009A202;

void func_800F84B8_ovl09(u8* a0) {
    u8* p = g_Player;

    if (p[0x15] == 0) {
        if (*(s16*)(p + 0xA) - D_8009A202 > 0xA0) {
            return;
        }
    } else {
        if (*(s16*)(p + 0xA) - D_8009A202 < 0xA0) {
            return;
        }
    }
    func_8003D29C(0x14, 0x40);
    D_1F80004C.bytes[0x86] = 1;
    *(s16*)(a0 + 0x7C) = 3;
    a0[5]++;
}
