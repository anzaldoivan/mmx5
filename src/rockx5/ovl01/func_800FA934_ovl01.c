#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800FD5D0_ovl01[];
extern u8 D_800FD5D4_ovl01[];

void func_800FA934_ovl01(u8* o) {
    s8 state;

    if (*(s16*)(o + 0x7C) < 30) {
        *(s16*)(o + 0x7C) += 1;
        return;
    }
    o[0x94] = 0;
    animate_object(o);
    state = o[0x45] - 1;
    switch (state) {
    case 0:
        o[6] = 5;
        *(s16*)(o + 0x7E) = 0x6C;
        break;
    case 1:
    case 2:
    case 3:
        *(u8**)(o + 0x50) = D_800FD5D0_ovl01;
        break;
    case 4:
    case 5:
    case 6:
        *(u8**)(o + 0x50) = 0;
        *(u8**)(o + 0x54) = D_800FD5D4_ovl01;
        break;
    case 15:
        play_sound(2, 9, o);
        *(u8**)(o + 0x50) = D_800FD5D0_ovl01;
        break;
    }
}
