#include "types.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern u8 D_80101810_ovl07[];
extern u8 D_8010180C_ovl07[];

void func_800FC45C_ovl07(u8* obj) {
    u8* p;
    s32 c;
    s32 n;

    func_800FC9E0_ovl07(obj);
    set_animation(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    p = D_1F80004C.bytes;
    if (p[0x91] & 8) {
        p[0x92] = 0;
        set_animation(obj, 0xF);
        c = (s32)D_80101810_ovl07;
        *(s32*)(obj + 0x54) = c;
        n = (s32)D_8010180C_ovl07;
        *(s32*)(obj + 0x50) = n;
        obj[6] = 2;
    } else {
        n = obj[6];
        c = -0x2000;
        *(s32*)(obj + 0x24) = c;
        c = 0x1000;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = c;
        n++;
        obj[6] = n;
    }
}
