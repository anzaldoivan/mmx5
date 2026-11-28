#include "types.h"

extern s16 D_80101DFC_ovl07[][4];

s32 func_800FD788_ovl07(u8* o, u8 idx, u8 mode) {
    if (mode == 0) {
        s32 t = (u16)D_80101DFC_ovl07[idx][2] + (*(u16**)(o + 0x84))[1];
        if ((s16)(t + 0x18) < *(s16*)(o + 0xE)) {
            *(s16*)(o + 0x94) =
                (u16)D_80101DFC_ovl07[idx][3] + (*(u16**)(o + 0x84))[1] + 8;
            return 1;
        }
        *(s16*)(o + 0x94) = t - 8;
        return 3;
    } else {
        s32 t = (u16)D_80101DFC_ovl07[idx][0] + (*(u16**)(o + 0x84))[0];
        if ((s16)(t + 0x18) < *(s16*)(o + 0xA)) {
            *(s16*)(o + 0x92) =
                (u16)D_80101DFC_ovl07[idx][1] + (*(u16**)(o + 0x84))[0] + 8;
            return 0;
        }
        *(s16*)(o + 0x92) = t - 8;
        return 2;
    }
}
