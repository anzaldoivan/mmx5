#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F1BDC_ovl26(u8* o) {
    set_animation(o, 0);
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s16*)(o + 0x7C) = 0x3C;
    if (D_8009A0AA - D_8009A1F8.h[5] >= 0xA1) {
        o[0x15] = 0x40;
        D_1F80004C.scr84->unk84 = 0;
        *(s16*)(o + 0xA) = D_8009A1F8.h[5] + 0x40;
        o[6]++;
    } else {
        o[0x15] = 0;
        D_1F80004C.scr84->unk84 = 1;
        *(s16*)(o + 0xA) = D_8009A1F8.h[5] + 0x100;
        o[6]++;
    }
}
