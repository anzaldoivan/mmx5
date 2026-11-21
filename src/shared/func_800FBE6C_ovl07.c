#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);

void func_800FBE6C_ovl07(u8* obj) {
    set_animation(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    *(s16*)(obj + 0x7C) = 50;
    obj[6]++;
}

void func_800FBECC_ovl07(u8* obj) {
    if (*(u16*)(obj + 0x7C) & 0x1F) {
        func_800FC9E0_ovl07(obj);
    }
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x92] = 0;
        func_800FB030_ovl07(obj);
    }
}
