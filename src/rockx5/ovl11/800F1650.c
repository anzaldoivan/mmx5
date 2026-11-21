#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#include "shared/func_800F1650_ovl11.c"

#define D_800EEBA0_ovl00 func_800F17C8_ovl11
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F17E8_ovl11
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
