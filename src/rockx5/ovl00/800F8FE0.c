#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F8FE0_ovl00(Obj5524* arg0) {
    set_animation(arg0, 1);
    arg0->timer7C = 10;
    arg0->timer7E = 0;
    arg0->state6++;
}

#define func_800F8BB4_ovl00 func_800F9020_ovl00
#include "shared/func_800F8BB4_ovl00.c"
#undef func_800F8BB4_ovl00
