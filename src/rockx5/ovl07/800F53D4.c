#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

#define func_800F2974_ovl02 func_800F53D4_ovl07
#define func_800F29A8_ovl02 func_800F5408_ovl07
#define func_800F2AB4_ovl02 func_800F5514_ovl07
#define func_800F29E4_ovl02 func_800F5444_ovl07
#include "shared/func_800F2974_ovl02.c"
#undef func_800F2974_ovl02
#undef func_800F29A8_ovl02
#undef func_800F29E4_ovl02
#undef func_800F2AB4_ovl02

#define func_800F1B34_ovl10 func_800F54C0_ovl07
#include "shared/func_800F1B34_ovl10.c"
#undef func_800F1B34_ovl10

#define D_800F46E8_ovl02 D_8010120C_ovl07

#define func_800F2AB4_ovl02 func_800F5514_ovl07
#include "shared/func_800F2AB4_ovl02.c"
#undef func_800F2AB4_ovl02
