#include "types.h"
#include "mmx5/ovl04.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/ovl11.h"
#include "mmx5/system.h"

#define func_800F03E0_ovl11 func_800F365C_ovl04

#define func_800EFE84_ovl11 func_800F3100_ovl04
#include "shared/func_800EFE84_ovl11.c"
#undef func_800EFE84_ovl11
#undef func_800F03E0_ovl11

#define func_800F94C8_ovl07 func_800F365C_ovl04

#define func_800F9088_ovl07 func_800F321C_ovl04
#include "shared/func_800F9088_ovl07.c"
#undef func_800F9088_ovl07
#undef func_800F94C8_ovl07

#define D_800F9748_ovl11 D_8010175C_ovl04

#define func_800F0120_ovl11 func_800F339C_ovl04
#include "shared/func_800F0120_ovl11.c"
#undef func_800F0120_ovl11
#undef D_800F9748_ovl11

#define func_800F0330_ovl11 func_800F35AC_ovl04
#define func_800F0414_ovl11 func_800F3690_ovl04

#define func_800F018C_ovl11 func_800F3408_ovl04
#include "shared/func_800F018C_ovl11.c"
#undef func_800F018C_ovl11
#undef func_800F0330_ovl11
#undef func_800F0414_ovl11

#define D_800EEBA0_ovl00 func_800F34A4_ovl04
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800F3100_ovl04)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F0248_ovl11 func_800F34C4_ovl04
#include "shared/func_800F0248_ovl11.c"
#undef func_800F0248_ovl11

#define func_800F0268_ovl11 func_800F34E4_ovl04
#include "shared/func_800F0268_ovl11.c"
#undef func_800F0268_ovl11

#define func_800F02C4_ovl11 func_800F3540_ovl04
#include "shared/func_800F02C4_ovl11.c"
#undef func_800F02C4_ovl11

#define D_800F9730_ovl11 D_80101744_ovl04
#define func_800EFFA0_ovl11 func_800F321C_ovl04

#define func_800F0330_ovl11 func_800F35AC_ovl04
#include "shared/func_800F0330_ovl11.c"
#undef func_800F0330_ovl11
#undef D_800F9730_ovl11
#undef func_800EFFA0_ovl11

#define func_800F03E0_ovl11 func_800F365C_ovl04
#include "shared/func_800F03E0_ovl11.c"
#undef func_800F03E0_ovl11
