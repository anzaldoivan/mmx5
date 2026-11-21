#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl03.h"

#define D_800F2058_ovl12 D_800FA1A4_ovl03

#define func_800F0198_ovl12 func_800F7F44_ovl03
#include "shared/func_800F0198_ovl12.c"
#undef func_800F0198_ovl12
#undef D_800F2058_ovl12

#include "shared/func_800F7F98_ovl03.c"
