#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define func_800F6EEC_ovl09 func_800FF3F8_ovl35
#include "shared/func_800F6EEC_ovl09.c"
#undef func_800F6EEC_ovl09

#define D_800EEBA0_ovl00 func_800FF4CC_ovl35
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
