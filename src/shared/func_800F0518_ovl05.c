#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F0518_ovl05(u8* obj) {
    set_animation(obj, 5);
    D_1F80004C.bytes[0x86] = 3;
    obj[6]++;
}

extern void func_800F08F8_ovl05(ObjFE130*, s32);
extern u8 D_800F52C0_ovl05[];
extern u8 D_800F52BC_ovl05[];

void func_800F055C_ovl05(ObjFE130* arg0) {
    if (arg0->unk45 == 1) {
        if (--D_1F80004C.obj0470->unk86 == 0) {
            set_animation(arg0, 0);
            arg0->unk5 = 2;
            arg0->unk6 = 0;
        }
    } else if (arg0->unk45 == 2) {
        func_800F08F8_ovl05(arg0, 0);
    } else if (arg0->unk45 == 3) {
        arg0->unk50 = D_800F52C0_ovl05;
    } else if (arg0->unk45 == 4) {
        arg0->unk50 = D_800F52BC_ovl05;
    }
}
