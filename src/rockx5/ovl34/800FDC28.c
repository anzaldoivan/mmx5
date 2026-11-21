#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_80100008_ovl34

#define func_800EEA80_ovl05 func_800FDC28_ovl34
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_80101E54_ovl07 D_80100018_ovl34

#define func_800FD89C_ovl07 func_800FDC64_ovl34
#include "shared/func_800FD89C_ovl07.c"
#undef func_800FD89C_ovl07
#undef D_80101E54_ovl07

#define D_800EEBA0_ovl00 func_800FDD68_ovl34
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800FD9C0_ovl07 func_800FDD88_ovl34
#include "shared/func_800FD9C0_ovl07.c"
#undef func_800FD9C0_ovl07
