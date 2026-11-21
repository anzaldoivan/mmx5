#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"

#include "shared/func_800EFC00_ovl00.c"

#define D_800EEBA0_ovl00 func_800EFD98_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800EFDB8_ovl00
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
