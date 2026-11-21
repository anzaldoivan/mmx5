#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void func_80032CEC();
#define D_800EEBA0_ovl00 func_80052E04
#define func_8002D720 func_80032CEC
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_80052E24
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
