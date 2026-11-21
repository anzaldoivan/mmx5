#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"
#include "addr.h"

#define D_8007BD4C D_800FEF68_ovl33

#define func_800532E0 func_800FD2B8_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FAD30_ovl06 func_800FD2F4_ovl33
#define func_800FAD98_ovl06 func_800FD35C_ovl33
#define func_800FAE14_ovl06 func_800FD3D8_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FAE88_ovl06 func_800FD44C_ovl33
#include "shared/func_800FAD30_ovl06.c"
#undef func_800FAD30_ovl06
#undef func_800FAD98_ovl06
#undef func_800FAE14_ovl06
#undef func_800FAE88_ovl06
