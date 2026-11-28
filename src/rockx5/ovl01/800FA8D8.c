#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"
#include "mmx5/ovl01.h"

#include "shared/func_800FA8D8_ovl01.c"

#include "shared/func_800FA908_ovl01.c"

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

#include "shared/func_800FAA0C_ovl01.c"

#define D_8007BD4C D_800FDB68_ovl01

#define func_800532E0 func_800FAB00_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FAB3C_ovl01.c"

#include "shared/func_800FAC00_ovl01.c"

#include "shared/func_800FAC80_ovl01.c"

#include "shared/func_800FAD14_ovl01.c"

#include "shared/func_800FADE4_ovl01.c"

#include "shared/func_800FAE28_ovl01.c"

#include "shared/func_800FAEF8_ovl01.c"

#include "shared/func_800FAF3C_ovl01.c"

#include "shared/func_800FAFDC_ovl01.c"

#include "shared/func_800FB050_ovl01.c"

#include "shared/func_800FB0EC_ovl01.c"

#include "shared/func_800FB188_ovl01.c"

#include "shared/func_800FB214_ovl01.c"

#define func_800EFCD8_ovl03 func_800FB308_ovl01
#include "shared/func_800EFCD8_ovl03.c"
#undef func_800EFCD8_ovl03
