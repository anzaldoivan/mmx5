#include "types.h"
#include "mmx5/ovl34.h"
#include "mmx5/ovl07.h"
#include "addr.h"

#define D_80101C10_ovl07 D_800FFE6C_ovl34

#define func_800FB5A4_ovl07 func_800FBEFC_ovl34
#include "shared/func_800FB5A4_ovl07.c"
#undef func_800FB5A4_ovl07
#undef D_80101C10_ovl07

#define D_800F4844_ovl05 D_800FFE74_ovl34

#define func_800EEA80_ovl05 func_800FC054_ovl34
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
