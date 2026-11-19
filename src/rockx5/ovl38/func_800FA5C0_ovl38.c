#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];
extern u8 D_800FD58C_ovl38[];
extern u8 D_800FD590_ovl38[];

void func_800FA5C0_ovl38(u8* obj) {
    u8 flags;

    flags = obj[0x70];
    if (flags & 4) {
        set_animation(obj, 3);
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
        *(u8**)(obj + 0x68) = D_800FD57C_ovl38;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1800;
        obj[6] = 3;
        return;
    }
    if (obj[0x15] == 0) {
        if (flags & 2) {
            obj[0x15] = 0x40;
            set_animation(obj, 8);
            *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
            *(u8**)(obj + 0x54) = D_800FD590_ovl38;
            *(s16*)(obj + 0x7C) = 10;
            obj[6] = 2;
            return;
        }
    } else if (flags & 1) {
        obj[0x15] = 0;
        set_animation(obj, 8);
        *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
        *(u8**)(obj + 0x54) = D_800FD590_ovl38;
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 2;
        return;
    }
    move_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 8;
        func_800FCC24_ovl38(obj, 5);
    }
}
