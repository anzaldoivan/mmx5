#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800FB43C_ovl10 D_800FDB18_ovl28
#define D_800FB458_ovl10 D_800FDB34_ovl28
#define func_800F0068_ovl10 func_800F1954_ovl28
#define D_800FB45C_ovl10 D_800FDB38_ovl28
#define D_800FB474_ovl10 D_800FDB50_ovl28
#define func_800F0110_ovl10 func_800F19FC_ovl28
#include "shared/func_800F0068_ovl10.c"
#undef func_800F0068_ovl10
#undef D_800FB43C_ovl10
#undef D_800FB458_ovl10
#undef func_800F0110_ovl10
#undef D_800FB45C_ovl10
#undef D_800FB474_ovl10

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F1A88_ovl28
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F01BC_ovl10 func_800F1AA8_ovl28
#include "shared/func_800F01BC_ovl10.c"
#undef func_800F01BC_ovl10

#define D_800EEC60_ovl00 func_800F1B68_ovl28
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
