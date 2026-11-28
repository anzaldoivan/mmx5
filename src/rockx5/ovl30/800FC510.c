#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"
#include "mmx5/ovl30.h"
#include "mmx5/ovl01.h"

#define func_800FA8D8_ovl01 func_800FC510_ovl30
#include "shared/func_800FA8D8_ovl01.c"
#undef func_800FA8D8_ovl01

#define func_800FA908_ovl01 func_800FC540_ovl30
#include "shared/func_800FA908_ovl01.c"
#undef func_800FA908_ovl01

extern u8 D_800FD7B8_ovl30[];
extern u8 D_800FD7BC_ovl30[];

void func_800FC56C_ovl30(u8* o) {
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
        *(u8**)(o + 0x50) = D_800FD7B8_ovl30;
        break;
    case 4:
    case 5:
    case 6:
        *(u8**)(o + 0x50) = 0;
        *(u8**)(o + 0x54) = D_800FD7BC_ovl30;
        break;
    case 15:
        play_sound(2, 9, o);
        *(u8**)(o + 0x50) = D_800FD7B8_ovl30;
        break;
    }
}

#define D_800FD9CC_ovl01 D_800FDBB4_ovl30
#define func_800FB418_ovl01 func_800FD050_ovl30

#define func_800FAA0C_ovl01 func_800FC644_ovl30
#include "shared/func_800FAA0C_ovl01.c"
#undef func_800FAA0C_ovl01
#undef D_800FD9CC_ovl01
#undef func_800FB418_ovl01

#define D_8007BD4C D_800FDD50_ovl30

#define func_800532E0 func_800FC738_ovl30
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FDAB0_ovl01 D_800FDC98_ovl30

#define func_800FAB3C_ovl01 func_800FC774_ovl30
#include "shared/func_800FAB3C_ovl01.c"
#undef func_800FAB3C_ovl01
#undef D_800FDAB0_ovl01

#define func_800FAC00_ovl01 func_800FC838_ovl30
#include "shared/func_800FAC00_ovl01.c"
#undef func_800FAC00_ovl01

#define func_800FAC80_ovl01 func_800FC8B8_ovl30
#include "shared/func_800FAC80_ovl01.c"
#undef func_800FAC80_ovl01

#define D_800FD608_ovl01 D_800FD7F0_ovl30

#define func_800FAD14_ovl01 func_800FC94C_ovl30
#include "shared/func_800FAD14_ovl01.c"
#undef func_800FAD14_ovl01
#undef D_800FD608_ovl01

#define func_800FADE4_ovl01 func_800FCA1C_ovl30
#include "shared/func_800FADE4_ovl01.c"
#undef func_800FADE4_ovl01

#define func_800FAE28_ovl01 func_800FCA60_ovl30
#include "shared/func_800FAE28_ovl01.c"
#undef func_800FAE28_ovl01

#define func_800FAEF8_ovl01 func_800FCB30_ovl30
#include "shared/func_800FAEF8_ovl01.c"
#undef func_800FAEF8_ovl01

#define D_800FD608_ovl01 D_800FD7F0_ovl30
#define D_800FDB88_ovl01 D_800FDD70_ovl30

#define func_800FAF3C_ovl01 func_800FCB74_ovl30
#include "shared/func_800FAF3C_ovl01.c"
#undef func_800FAF3C_ovl01
#undef D_800FD608_ovl01
#undef D_800FDB88_ovl01

#define D_800FD600_ovl01 D_800FD7E8_ovl30
#define D_800FD604_ovl01 D_800FD7EC_ovl30
#define D_800FD608_ovl01 D_800FD7F0_ovl30

#define func_800FAFDC_ovl01 func_800FCC14_ovl30
#include "shared/func_800FAFDC_ovl01.c"
#undef func_800FAFDC_ovl01
#undef D_800FD600_ovl01
#undef D_800FD604_ovl01
#undef D_800FD608_ovl01

#define func_800FB050_ovl01 func_800FCC88_ovl30
#include "shared/func_800FB050_ovl01.c"
#undef func_800FB050_ovl01

#define func_800FB0EC_ovl01 func_800FCD24_ovl30
#include "shared/func_800FB0EC_ovl01.c"
#undef func_800FB0EC_ovl01

#define func_800FB188_ovl01 func_800FCDC0_ovl30
#include "shared/func_800FB188_ovl01.c"
#undef func_800FB188_ovl01

#define D_800FD578_ovl01 D_800FD760_ovl30
#define D_800FD57C_ovl01 D_800FD764_ovl30
#define func_800FB308_ovl01 func_800FCF40_ovl30

#define func_800FB214_ovl01 func_800FCE4C_ovl30
#include "shared/func_800FB214_ovl01.c"
#undef func_800FB214_ovl01
#undef D_800FD578_ovl01
#undef D_800FD57C_ovl01
#undef func_800FB308_ovl01

#define func_800EFCD8_ovl03 func_800FCF40_ovl30
#include "shared/func_800EFCD8_ovl03.c"
#undef func_800EFCD8_ovl03
