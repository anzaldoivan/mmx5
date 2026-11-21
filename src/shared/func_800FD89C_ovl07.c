#include "types.h"
#include "mmx5/globals.h"

extern void* D_80101E54_ovl07[];

void func_800FD89C_ovl07(u8* o) {
    if (*(s8*)(*(u8**)(o + 0x7C) + 4) == 2) {
        o[4] = 2;
        return;
    }
    *(s32*)(o + 0x18) = *(s32*)(o + 8);
    *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
    func_8002D9EC(o, 0x10, 0x10);
    ((void (*)(u8*))D_80101E54_ovl07[*(s8*)(o + 5)])(o);
    if (*(s8*)(o + 2) < 4 && func_800317B8(o) != 0) {
        o[4] = 2;
        return;
    }
    if (o[0x8D] != 0) {
        if (func_80031DD0(o) < 0) {
            ((s32(*)())func_8004FD24)(o);
            o[4] = 2;
            return;
        }
        if (--*(s16*)(o + 0x90) == -1) {
            o[4] = 3;
        }
    }
}
