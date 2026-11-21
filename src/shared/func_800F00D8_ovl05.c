#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern u8 D_800F52D0_ovl05[];

void func_800F00D8_ovl05(u8* obj) {
    *(u8**)(obj + 0x68) = D_800F52D0_ovl05;
    set_animation(obj, 4);
    obj[0x67] = 1;
    *(s32*)(D_1F80004C.bytes + 0x80) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x24) = 0x20000;
    obj[6]++;
}

extern u8 D_800F52CC_ovl05[];

void func_800F0138_ovl05(Obj0138* arg0) {
    move_object(arg0);
    if (arg0->unk70 & 4) {
        arg0->unk2C = 0x1500;
        arg0->unk68 = D_800F52CC_ovl05;
        set_animation(arg0, 2);
        D_1F80004C.scr3594->unk84 = 0;
        arg0->unk6++;
    } else if (D_1F80004C.scr3594->unk82 - arg0->unkE >= 0xC0) {
        arg0->unk5 = 5;
        arg0->unk6 = 0;
    }
}

extern u8 D_800F52CC_ovl05[];

void func_800F01DC_ovl05(Obj01DC* arg0) {
    if (arg0->unk45 == 2) {
        arg0->unk24 = 0xE0000;
        arg0->unk68 = D_800F52CC_ovl05;
    }
    apply_object_motion(arg0);
    if (arg0->unk45 == 1) {
        arg0->unk68 = D_800F52CC_ovl05;
        arg0->unk24 = 0;
        arg0->unk2C = 0;
        arg0->unk20 = 0;
        arg0->unk28 = 0;
        arg0->unk67 = 0;
        arg0->unk5 = 2;
        arg0->unk6 = 0;
    }
}
