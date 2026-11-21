#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl18.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define func_800F2974_ovl02 func_800F3BE4_ovl18
#define func_800F29A8_ovl02 func_800F3C18_ovl18
#define func_800F2AB4_ovl02 func_800F3D24_ovl18
#define func_800F29E4_ovl02 func_800F3C54_ovl18
#include "shared/func_800F2974_ovl02.c"
#undef func_800F2974_ovl02
#undef func_800F29A8_ovl02
#undef func_800F29E4_ovl02
#undef func_800F2AB4_ovl02

#define func_800F1B34_ovl10 func_800F3CD0_ovl18
#include "shared/func_800F1B34_ovl10.c"
#undef func_800F1B34_ovl10

#define D_800F46E8_ovl02 D_800F7A84_ovl18

#define func_800F2AB4_ovl02 func_800F3D24_ovl18
#include "shared/func_800F2AB4_ovl02.c"
#undef func_800F2AB4_ovl02
#undef D_800F46E8_ovl02

#define func_800F2B54_ovl02 func_800F3DC4_ovl18
#include "shared/func_800F2B54_ovl02.c"
#undef func_800F2B54_ovl02
