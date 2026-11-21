#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/system.h"

extern u8 D_800F52C4_ovl05[];
extern u8 D_800F52C8_ovl05[];

void func_800EFF4C_ovl05(ObjEFF4C* arg0) {
    if (D_1F80004C.scr84->unk84 == 0) {
        arg0->unk54 = D_800F52C4_ovl05;
        set_animation(arg0, 1);
        arg0->unk7C = 0x3C;
    } else {
        arg0->unk54 = D_800F52C8_ovl05;
        set_animation(arg0, 0);
        arg0->unk7C = 0x28;
    }
    arg0->unk6++;
}

extern s8 D_800D1C44;
extern u8 D_800F52C4_ovl05[];

void func_800EFFCC_ovl05(u8* arg0) {
    if (!(random_byte() & 1)) {
        if (D_800D1C44 == 0) {
            if (D_1F80004C.scr84->unk84 != 0) {
                arg0[5] = 6;
            } else {
                arg0[5] = 8;
            }
        } else if (D_1F80004C.scr84->unk84 == 0) {
            arg0[5] = 8;
        } else {
            arg0[5] = 7;
        }
    } else if (D_1F80004C.scr84->unk84 == 0) {
        arg0[5] = 4;
    } else {
        *(void**)(arg0 + 0x54) = D_800F52C4_ovl05;
        arg0[5] = 3;
    }
    arg0[6] = 0;
}
