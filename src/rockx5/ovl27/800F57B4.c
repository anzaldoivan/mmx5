#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl27.h"
#include "mmx5/globals.h"
#include "addr.h"

#include "shared/func_800F57B4_ovl27.c"

extern void func_800F5B44_ovl27(Obj5820*, s32);
#include "shared/func_800F5820_ovl27.c"

#define D_8007BD4C D_800FD458_ovl27

#define func_800532E0 func_800F58A8_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F58E4_ovl27.c"

extern void func_800F5B44_ovl27(Obj5820*, s32);
#include "shared/func_800F5950_ovl27.c"
