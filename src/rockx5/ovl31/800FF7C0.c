#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800FA220_ovl03 D_800FFC20_ovl31

#define func_800F87D4_ovl03 func_800FF7C0_ovl31
#include "shared/func_800F87D4_ovl03.c"
#undef func_800F87D4_ovl03
#undef D_800FA220_ovl03

#define D_800EEBA0_ovl00 func_800FF844_ovl31
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
