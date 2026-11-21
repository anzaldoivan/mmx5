#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"

#define D_800FA870_ovl00 D_800FCBAC_ovl27
#define D_800FA8A8_ovl00 D_800FCBE4_ovl27
#define func_800F0C28_ovl00 func_800F1A4C_ovl27
#define func_800EFC00_ovl00 func_800F0A24_ovl27
#define func_800EFCD8_ovl00 func_800F0AFC_ovl27
#define func_800EFD50_ovl00 func_800F0B74_ovl27
#include "shared/func_800EFC00_ovl00.c"
#undef func_800EFC00_ovl00
#undef D_800FA870_ovl00
#undef D_800FA8A8_ovl00
#undef func_800F0C28_ovl00
#undef func_800EFCD8_ovl00
#undef func_800EFD50_ovl00

#define D_800EEBA0_ovl00 func_800F0BBC_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F0BDC_ovl27
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
