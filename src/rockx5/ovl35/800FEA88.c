#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

#define func_800F657C_ovl09 func_800FEA88_ovl35
#include "shared/func_800F657C_ovl09.c"
#undef func_800F657C_ovl09

#define func_800F0D00_ovl12 func_800FEB0C_ovl35
#include "shared/func_800F0D00_ovl12.c"
#undef func_800F0D00_ovl12

#define func_800F6700_ovl09 func_800FEC0C_ovl35
#include "shared/func_800F6700_ovl09.c"
#undef func_800F6700_ovl09

#define func_800F6888_ovl09 func_800FED94_ovl35
#include "shared/func_800FECE4_ovl35.c"
#undef func_800F6888_ovl09

#define D_800EEBA0_ovl00 func_800FEE70_ovl35
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
