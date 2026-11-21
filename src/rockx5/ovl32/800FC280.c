#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_80101CE8_ovl04 D_800FE514_ovl32
#define D_80101CEC_ovl04 D_800FE518_ovl32
#define D_80101CF0_ovl04 D_800FE51C_ovl32
#define D_80101CF4_ovl04 D_800FE520_ovl32
#define D_80101CF8_ovl04 D_800FE524_ovl32
#define func_800F664C_ovl04 func_800FC280_ovl32
#define D_80101D24_ovl04 D_800FE550_ovl32
#define func_800F67F0_ovl04 func_800FC424_ovl32
#define D_80101D40_ovl04 D_800FE56C_ovl32
#define func_800F697C_ovl04 func_800FC5B0_ovl32
#include "shared/func_800F664C_ovl04.c"
#undef func_800F664C_ovl04
#undef D_80101CE8_ovl04
#undef D_80101CEC_ovl04
#undef D_80101CF0_ovl04
#undef D_80101CF4_ovl04
#undef D_80101CF8_ovl04
#undef func_800F67F0_ovl04
#undef D_80101D24_ovl04
#undef func_800F697C_ovl04
#undef D_80101D40_ovl04

#define D_800EEC60_ovl00 func_800FC60C_ovl32
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define func_800F69E0_ovl04 func_800FC614_ovl32
#define func_800F6A00_ovl04 func_800FC634_ovl32
#define func_800F6A34_ovl04 func_800FC668_ovl32
#include "shared/func_800F69E0_ovl04.c"
#undef func_800F69E0_ovl04
#undef func_800F6A00_ovl04
#undef func_800F6A34_ovl04

#define D_800EEBA0_ovl00 func_800FC6E4_ovl32
#define func_8002D720 move_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
