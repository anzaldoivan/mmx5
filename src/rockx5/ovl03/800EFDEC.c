#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#include "shared/func_800EFDEC_ovl03.c"

#define D_800EEBA0_ovl00 func_800EFF74_ovl03
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800EFF94_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
