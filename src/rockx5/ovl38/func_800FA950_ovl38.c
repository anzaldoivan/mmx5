#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];
extern u8 D_800FD58C_ovl38[];
extern u8 D_800FD590_ovl38[];

void func_800FA950_ovl38(u8* obj) {
    u8 flags;

    flags = obj[0x70];
    if (flags & 8) {
        set_animation(obj, 3);
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
        *(u8**)(obj + 0x68) = D_800FD57C_ovl38;
        if (D_1F80004C.bytes[0x91] == 0 && D_800D1CA2 / 2 >= ((s8*)obj)[0x5C] &&
            (random_byte() & 1)) {
            obj[5] = 9;
        } else {
            obj[5] = 3;
        }
        obj[6] = 0;
        return;
    }
    if (obj[0x15] == 0) {
        if (flags & 2) {
            obj[0x15] = 0x40;
            set_animation(obj, 7);
            *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
            *(u8**)(obj + 0x54) = D_800FD590_ovl38;
            *(s16*)(obj + 0x7C) = 10;
            obj[6] = 0;
            return;
        }
    } else if (flags & 1) {
        obj[0x15] = 0;
        set_animation(obj, 7);
        *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
        *(u8**)(obj + 0x54) = D_800FD590_ovl38;
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 0;
        return;
    }
    move_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 8;
        func_800FCC24_ovl38(obj, 5);
    }
}
