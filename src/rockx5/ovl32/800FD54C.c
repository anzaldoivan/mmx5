#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800FD54C_ovl32
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F7938_ovl04 func_800FD56C_ovl32
#include "shared/func_800F7938_ovl04.c"
#undef func_800F7938_ovl04

#define D_800EEC60_ovl00 func_800FD660_ovl32
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_80101D58_ovl04 D_800FE584_ovl32

#define func_800F7A34_ovl04 func_800FD668_ovl32
#include "shared/func_800F7A34_ovl04.c"
#undef func_800F7A34_ovl04
