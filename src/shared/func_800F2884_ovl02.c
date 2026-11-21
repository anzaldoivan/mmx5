#include "types.h"
#include "addr.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"

void func_800F2884_ovl02(u8* arg0) {
    s8 temp_a1;

    temp_a1 = *(s8*)(arg0 + 0x45);
    if (temp_a1 == 1) {
        D_1F80004C.bytes[0x82] = temp_a1;
        arg0[6]++;
    }
}

#define SCR D_1F80004C.bytes

void func_800F28BC_ovl02(ObjFE130* arg0) {
    if (arg0->unk45 == 2) {
        play_sound(2, 0x24, arg0);
        func_800F2AB4_ovl02(arg0, 0x10);
    } else if (arg0->unk45 == 3) {
        arg0->unk5 = 2;
        arg0->unk6 = 0;
    } else if (arg0->unk45 == 4) {
        SCR[0x82] = 0;
    }
}
