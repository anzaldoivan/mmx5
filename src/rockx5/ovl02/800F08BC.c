#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

#define func_800EFAAC_ovl03 func_800F08BC_ovl02
#include "shared/func_800EFAAC_ovl03.c"
#undef func_800EFAAC_ovl03

#define func_800EFAD8_ovl03 func_800F08E8_ovl02
#define D_800F959C_ovl03 D_800F44D8_ovl02
#define D_800F95A4_ovl03 D_800F44E0_ovl02
#define func_800EFB20_ovl03 func_800F0930_ovl02
#include "shared/func_800EFAD8_ovl03.c"
#undef func_800EFAD8_ovl03
#undef func_800EFB20_ovl03
#undef D_800F959C_ovl03
#undef D_800F95A4_ovl03

#define D_800FA778_ovl09 D_800F45F4_ovl02

void func_800F0AE8_ovl02(X4_Obj*);
#define func_800EF37C_ovl09 func_800F09A8_ovl02
#define animate_object func_800F0AE8_ovl02
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef animate_object
