#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_80074E40[];
extern u8 D_800FA7C0_ovl09[];
extern u8 D_800FA7C4_ovl09[];

void func_800EFCC4_ovl09(u8* obj) {
    obj[0x4] = 1;
    *(u8**)(obj + 0x58) = D_80074E40;
    obj[0x70] = 0;
    obj[0x60] = 3;
    *(u8**)(obj + 0x68) = D_800FA7C0_ovl09;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    obj[0x5] = 0;
    *(u8**)(obj + 0x50) = D_800FA7C4_ovl09;
    obj[0x15] = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s16*)(obj + 0x88) = 0x12;
    obj[0x3] = 1;
    obj[0x16] = 1;
    set_animation(obj, 2);
}

void func_800EFD44_ovl09(u8* obj) {
    s8* p = *(s8**)(obj + 0x7C);

    if (p[7] > 0) {
        p[7]--;
    }
    clear_object_slot(obj);
}
