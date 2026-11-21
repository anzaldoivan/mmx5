#include "types.h"
#include "mmx5/graphics.h"

void func_800F0E24_ovl04(Obj3DD4* arg0) {
    set_animation(arg0, 0xC);
    arg0->unk20 = -0x30000;
    arg0->unk24 = 0;
    arg0->unk7C = 0x28;
    arg0->unk6++;
}

void func_800F0E6C_ovl04(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        arg0[0x15] = 0;
        *(s16*)(arg0 + 0x7C) = 3;
        arg0[6]++;
    }
}
