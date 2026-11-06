#include "types.h"

extern s32 D_80100810_ovl07[];
extern s32 D_80100818_ovl07[];

void func_800EFF18_ovl07(u8* obj) {
    u16 flags;
    s32 cur;
    s32 lim;

    flags = *(u16*)(obj + 0x8A);
    if ((flags & 3) || obj[0x7D] != 0) {
        if (flags & 1) {
            cur = *(s32*)(obj + 0x20);
            if (cur == 0) {
                *(s32*)(obj + 0x28) = 0x2000;
            } else {
                lim = D_80100818_ovl07[obj[0x7D]];
                if (cur >= lim) {
                    *(s32*)(obj + 0x20) = lim;
                    *(s32*)(obj + 0x28) = 0;
                }
            }
            obj[0x7C] = 1;
            return;
        }
        if (flags & 2) {
            cur = *(s32*)(obj + 0x20);
            if (cur == 0) {
                *(s32*)(obj + 0x28) = -0x2000;
            } else {
                lim = D_80100810_ovl07[obj[0x7D]];
                if (cur < lim) {
                    *(s32*)(obj + 0x20) = lim;
                    *(s32*)(obj + 0x28) = 0;
                }
            }
            obj[0x7C] = 0;
        }
    } else {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x7C] = 1;
    }
}
