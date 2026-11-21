#include "types.h"
#include "mmx5/ovl18.h"
#include "mmx5/ovl04.h"
#include "mmx5/object.h"
#include "addr.h"

#define D_80101480_ovl04 D_800F790C_ovl18
#define func_800F0FF4_ovl04 func_800F1824_ovl18
#define func_800F06BC_ovl04 func_800F0EEC_ovl18
#define func_800F07E0_ovl04 func_800F1010_ovl18
#include "shared/func_800F06BC_ovl04.c"
#undef func_800F06BC_ovl04
#undef func_800F07E0_ovl04
