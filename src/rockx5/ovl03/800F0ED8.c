#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"

#define D_800F524C_ovl05 D_800F98FC_ovl03
#define func_800F08F8_ovl05 func_800F0ED8_ovl03
#define func_800F0990_ovl05 func_800F0F70_ovl03
#include "shared/func_800F08F8_ovl05.c"
#undef func_800F08F8_ovl05
#undef D_800F524C_ovl05
#undef func_800F0990_ovl05

#define D_800EEC60_ovl00 func_800F0FA0_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800F5360_ovl05 D_800F9A10_ovl03
#define D_800F5364_ovl05 D_800F9A14_ovl03
#define D_800F5368_ovl05 D_800F9A18_ovl03
#define D_800F536C_ovl05 D_800F9A1C_ovl03
#define D_800F5370_ovl05 D_800F9A20_ovl03
#define func_800F09C8_ovl05 func_800F0FA8_ovl03
#define D_800F5374_ovl05 D_800F9A24_ovl03
#define D_800F538C_ovl05 D_800F9A3C_ovl03
#define func_800F0BCC_ovl05 func_800F11AC_ovl03
#include "shared/func_800F09C8_ovl05.c"
#undef func_800F09C8_ovl05
#undef D_800F5360_ovl05
#undef D_800F5364_ovl05
#undef D_800F5368_ovl05
#undef D_800F536C_ovl05
#undef D_800F5370_ovl05
#undef func_800F0BCC_ovl05
