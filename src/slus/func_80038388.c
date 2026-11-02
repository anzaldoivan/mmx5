#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_800306E0(u8* a0);
extern void func_80016490(s32, s32, void*);

s32 func_80038388(u8* a0) {
    s32 in;

    if (*(s8*)(a0 + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(a0 + 0x84) != 0) {
        return 0;
    }
    if (*(s8*)(a0 + 0x87) == 0 && !(*(u16*)(a0 + 0x80) & 0x100)) {
        return 0;
    }
    if (*(u16*)(a0 + 0x7C) & 4) {
        *(s32*)(a0 + 0x24) = *(s32*)(a0 + 0x140);
    } else {
        *(s32*)(a0 + 0x24) = -*(s32*)(a0 + 0x140);
    }
    func_8002DF54(a0);
    in = func_800306E0(a0) ^ 0x2E;
    *(s32*)(a0 + 0xC) = *(s32*)(a0 + 0x1C);
    if (in) {
        return 0;
    }
    *(u8*)(a0 + 0x84) = 1;
    *(u8*)(a0 + 0x86) = 1;
    if (*(s32*)(a0 + 0xFC) & 0x10) {
        *(u8*)(a0 + 0x85) = 0xF;
    } else {
        *(u8*)(a0 + 0x85) = 0x1E;
    }
    *(u8*)(a0 + 0x8C) = 1;
    func_80016490(1, 5, a0);
    return 1;
}
