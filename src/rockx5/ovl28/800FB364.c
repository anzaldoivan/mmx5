#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F3B44_ovl08 D_800FE804_ovl28
#define D_800F3B48_ovl08 D_800FE808_ovl28
#define func_800EF6C8_ovl08 func_800FB364_ovl28
#define func_800EF780_ovl08 func_800FB41C_ovl28
#include "shared/func_800EF6C8_ovl08.c"
#undef func_800EF6C8_ovl08
#undef D_800F3B44_ovl08
#undef D_800F3B48_ovl08
#undef func_800EF780_ovl08

#define D_800EEBA0_ovl00 func_800FB4F4_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
