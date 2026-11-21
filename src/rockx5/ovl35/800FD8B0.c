#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800FAD88_ovl09 D_800FF890_ovl35
#define D_800FAD94_ovl09 D_800FF89C_ovl35

#define func_800F53A4_ovl09 func_800FD8B0_ovl35
#include "shared/func_800F53A4_ovl09.c"
#undef func_800F53A4_ovl09
#undef D_800FAD88_ovl09
#undef D_800FAD94_ovl09

#define D_800EEBA0_ovl00 func_800FD964_ovl35
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800FD984_ovl35
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
