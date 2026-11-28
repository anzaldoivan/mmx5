#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"
#include "mmx5/ovl11.h"
#include "mmx5/system.h"

#define D_800F96C8_ovl11 D_801016F4_ovl07
#define D_800F9734_ovl11 D_80101760_ovl07

#define func_800EFC78_ovl11 func_800F8D60_ovl07
#include "shared/func_800EFC78_ovl11.c"
#undef func_800EFC78_ovl11
#undef D_800F96C8_ovl11
#undef D_800F9734_ovl11

#define func_800F03E0_ovl11 func_800F94C8_ovl07

#define func_800EFE84_ovl11 func_800F8F6C_ovl07
#include "shared/func_800EFE84_ovl11.c"
#undef func_800EFE84_ovl11
#undef func_800F03E0_ovl11

#include "shared/func_800F9088_ovl07.c"

#define D_800F9748_ovl11 D_80101774_ovl07

#define func_800F0120_ovl11 func_800F9208_ovl07
#include "shared/func_800F0120_ovl11.c"
#undef func_800F0120_ovl11
#undef D_800F9748_ovl11

#define func_800F0330_ovl11 func_800F9418_ovl07
#define func_800F0414_ovl11 func_800F94FC_ovl07

#define func_800F018C_ovl11 func_800F9274_ovl07
#include "shared/func_800F018C_ovl11.c"
#undef func_800F018C_ovl11
#undef func_800F0330_ovl11
#undef func_800F0414_ovl11

#define D_800EEBA0_ovl00 func_800F9310_ovl07
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800F8F6C_ovl07)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F0248_ovl11 func_800F9330_ovl07
#include "shared/func_800F0248_ovl11.c"
#undef func_800F0248_ovl11

#define func_800F0268_ovl11 func_800F9350_ovl07
#include "shared/func_800F0268_ovl11.c"
#undef func_800F0268_ovl11

#define func_800F02C4_ovl11 func_800F93AC_ovl07
#include "shared/func_800F02C4_ovl11.c"
#undef func_800F02C4_ovl11

#define D_800F9730_ovl11 D_8010175C_ovl07
#define func_800EFFA0_ovl11 func_800F9088_ovl07

#define func_800F0330_ovl11 func_800F9418_ovl07
#include "shared/func_800F0330_ovl11.c"
#undef func_800F0330_ovl11
#undef D_800F9730_ovl11
#undef func_800EFFA0_ovl11

#define func_800F03E0_ovl11 func_800F94C8_ovl07
#include "shared/func_800F03E0_ovl11.c"
#undef func_800F03E0_ovl11
