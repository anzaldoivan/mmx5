#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"

#define func_800F2850_ovl02 func_800F52B0_ovl07
#include "shared/func_800F2850_ovl02.c"
#undef func_800F2850_ovl02

#define func_800F2884_ovl02 func_800F52E4_ovl07
#define func_800F2AB4_ovl02 func_800F5514_ovl07
#define func_800F28BC_ovl02 func_800F531C_ovl07
#include "shared/func_800F2884_ovl02.c"
#undef func_800F2884_ovl02
#undef func_800F28BC_ovl02
#undef func_800F2AB4_ovl02

#define D_8007BD4C D_80101288_ovl07

#define func_800532E0 func_800F5398_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
