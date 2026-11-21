#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl31.h"
#include "mmx5/ovl03.h"

#define D_800F2058_ovl12 D_800FFBA4_ovl31

#define func_800F0198_ovl12 func_800FEF30_ovl31
#include "shared/func_800F0198_ovl12.c"
#undef func_800F0198_ovl12
#undef D_800F2058_ovl12

#define func_800F7F98_ovl03 func_800FEF84_ovl31
#define D_800F9E6C_ovl03 D_800FF86C_ovl31
#define D_800FA0BC_ovl03 D_800FFABC_ovl31
#define func_800F8084_ovl03 func_800FF070_ovl31
#include "shared/func_800F7F98_ovl03.c"
#undef func_800F7F98_ovl03
#undef func_800F8084_ovl03
