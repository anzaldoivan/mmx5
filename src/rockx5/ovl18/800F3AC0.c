#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl18.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"

#define func_800F2850_ovl02 func_800F3AC0_ovl18
#include "shared/func_800F2850_ovl02.c"
#undef func_800F2850_ovl02

#define func_800F2884_ovl02 func_800F3AF4_ovl18
#define func_800F2AB4_ovl02 func_800F3D24_ovl18
#define func_800F28BC_ovl02 func_800F3B2C_ovl18
#include "shared/func_800F2884_ovl02.c"
#undef func_800F2884_ovl02
#undef func_800F28BC_ovl02
#undef func_800F2AB4_ovl02

#define D_8007BD4C D_800F7B00_ovl18

#define func_800532E0 func_800F3BA8_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
