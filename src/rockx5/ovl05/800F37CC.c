#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8003240C(u8*);

void func_800F37CC_ovl05(u8* a0) {
    s32 r;

    func_8002D89C(a0);
    func_8003240C(a0);
    r = func_80031DD0(a0);
    if (r < 0) {
        a0[4]++;
        *(s32*)(a0 + 0x7C) = 0;
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    } else if (r > 0) {
        *(u16*)(a0 + 0x42) |= 0x8000;
    } else {
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    }
}

extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;
extern u8 D_800F5964_ovl05[];

void func_800F3890_ovl05(u8* obj) {
    s32 y;

    if (D_800F5964_ovl05[1] != 0) {
        y = *(s16*)(obj + 0xA);
        if (y - 0x40 <= D_800F5960_ovl05 || y <= D_800F5962_ovl05 + 0x40) {
            animate_object(obj);
            func_8002D9EC(obj, 0xA0, 0xA0);
            return;
        }
    }
    obj[3] = 0;
}
