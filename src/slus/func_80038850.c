#include "types.h"

extern s32 func_8003F154(u8* self);
extern s32 func_80043D04(u8* self);
extern s32 func_800414F0(u8* self);
extern void func_8003ABD0(u8* self);

static inline s32 func_80038850_dir(u8* self) {
    if (*(s8*)(self + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(self + 0x87) == 0 && !(*(u16*)(self + 0x80) & 0x100)) {
        return 0;
    }
    if (*(u16*)(self + 0x7C) & 1) {
        self[0x15] = 0x40;
    }
    if (*(u16*)(self + 0x7C) & 2) {
        self[0x15] = 0;
    }
    if (self[0x15] != 0) {
        if (self[0x89] & 1) {
            return 0;
        }
        *(s32*)(self + 0x20) = *(s32*)(self + 0x114);
    } else {
        if (self[0x89] & 2) {
            return 0;
        }
        *(s32*)(self + 0x20) = -*(s32*)(self + 0x114);
    }
    return 1;
}

s32 func_80038850(u8* self) {
    s32 ret;

    if (*(s8*)(self + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(self + 0x86) != 0) {
        return 0;
    }
    if (*(s8*)(self + 2) == 0) {
        ret = func_8003F154(self);
    } else {
        ret = func_80043D04(self);
    }
    if (ret != 0) {
        return 1;
    }
    if (*(s8*)(self + 2) == 0) {
        if (self[0x92] != 0) {
            return 0;
        }
        if (self[0xFA] != 1 && self[0xFA] != 4) {
            return 0;
        }
    }
    if (func_80038850_dir(self) == 0) {
        return 0;
    }
    if (*(s8*)(self + 2) != 0) {
        if (func_800414F0(self) != 0) {
            return 1;
        }
    }
    func_8003ABD0(self);
    return 1;
}
