#include "types.h"

extern s32 D_8009A0A8;

void func_800FD758_ovl39(u8* obj) {
    *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
    if (--*(s16*)(obj + 0x82) == 0) {
        obj[6]++;
    }
}
