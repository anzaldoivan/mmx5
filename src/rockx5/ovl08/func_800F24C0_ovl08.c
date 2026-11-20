#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8003240C(u8* a0);

void func_800F24C0_ovl08(u8* obj) {
    s8 r;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_8002D89C(obj);
    func_8003240C(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        obj[4] = 2;
        *(s32*)(obj + 0x7C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(u16*)(obj + 0xA) += 8;
        *(u16*)(obj + 0xE) += 8;
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
        *(u16*)(obj + 0xA) -= 8;
        *(u16*)(obj + 0xE) -= 8;
        return;
    }
    if (r > 0) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
}
