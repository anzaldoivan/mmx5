#include "types.h"
#include "mmx5/object.h"

void func_800FD944_ovl39(u8* a0) {
    move_object(a0);
    if ((*(s32*)(a0 + 0x20) > 0 && *(s16*)(a0 + 0xA) >= 0x1278) ||
        (*(s32*)(a0 + 0x20) < 0 && *(s16*)(a0 + 0xA) < 0x11A9)) {
        *(s16*)(a0 + 0x82) = 0x3C;
        a0[6]++;
    }
}
