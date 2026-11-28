#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/ovl08.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/ovl11.h"
#include "mmx5/system.h"

#define D_800F4844_ovl05 D_800F3D90_ovl08

#define func_800EEA80_ovl05 func_800F0DE4_ovl08
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F0E20_ovl08.c"

#include "shared/func_800F0EB8_ovl08.c"

#define D_800EEBA0_ovl00 func_800F0FA4_ovl08
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800F96C8_ovl11 D_800F3D9C_ovl08
#define D_800F9734_ovl11 D_800F3E08_ovl08

#define func_800EFC78_ovl11 func_800F0FC4_ovl08
#include "shared/func_800EFC78_ovl11.c"
#undef func_800EFC78_ovl11
#undef D_800F96C8_ovl11
#undef D_800F9734_ovl11

#define func_800F03E0_ovl11 func_800F172C_ovl08

#define func_800EFE84_ovl11 func_800F11D0_ovl08
#include "shared/func_800EFE84_ovl11.c"
#undef func_800EFE84_ovl11
#undef func_800F03E0_ovl11

#define func_800F94C8_ovl07 func_800F172C_ovl08

#define func_800F9088_ovl07 func_800F12EC_ovl08
#include "shared/func_800F9088_ovl07.c"
#undef func_800F9088_ovl07
#undef func_800F94C8_ovl07

#define D_800F9748_ovl11 D_800F3E1C_ovl08

#define func_800F0120_ovl11 func_800F146C_ovl08
#include "shared/func_800F0120_ovl11.c"
#undef func_800F0120_ovl11
#undef D_800F9748_ovl11

#define func_800F0330_ovl11 func_800F167C_ovl08
#define func_800F0414_ovl11 func_800F1760_ovl08

#define func_800F018C_ovl11 func_800F14D8_ovl08
#include "shared/func_800F018C_ovl11.c"
#undef func_800F018C_ovl11
#undef func_800F0330_ovl11
#undef func_800F0414_ovl11

#define D_800EEBA0_ovl00 func_800F1574_ovl08
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800F11D0_ovl08)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F0248_ovl11 func_800F1594_ovl08
#include "shared/func_800F0248_ovl11.c"
#undef func_800F0248_ovl11

#define func_800F0268_ovl11 func_800F15B4_ovl08
#include "shared/func_800F0268_ovl11.c"
#undef func_800F0268_ovl11

#define func_800F02C4_ovl11 func_800F1610_ovl08
#include "shared/func_800F02C4_ovl11.c"
#undef func_800F02C4_ovl11

#define D_800F9730_ovl11 D_800F3E04_ovl08
#define func_800EFFA0_ovl11 func_800F12EC_ovl08

#define func_800F0330_ovl11 func_800F167C_ovl08
#include "shared/func_800F0330_ovl11.c"
#undef func_800F0330_ovl11
#undef D_800F9730_ovl11
#undef func_800EFFA0_ovl11

#define func_800F03E0_ovl11 func_800F172C_ovl08
#include "shared/func_800F03E0_ovl11.c"
#undef func_800F03E0_ovl11
