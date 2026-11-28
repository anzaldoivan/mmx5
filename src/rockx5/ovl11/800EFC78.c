#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl11.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"
#include "mmx5/system.h"

#include "shared/func_800EFC78_ovl11.c"

void func_800F03E0_ovl11(s32);
#include "shared/func_800EFE84_ovl11.c"

#define func_800F94C8_ovl07 func_800F03E0_ovl11

extern void func_800F94C8_ovl07(s32);
#define func_800F9088_ovl07 func_800EFFA0_ovl11
#include "shared/func_800F9088_ovl07.c"
#undef func_800F9088_ovl07
#undef func_800F94C8_ovl07

#include "shared/func_800F0120_ovl11.c"

#include "shared/func_800F018C_ovl11.c"

#define D_800EEBA0_ovl00 func_800F0228_ovl11
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800EFE84_ovl11)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F0248_ovl11.c"

#include "shared/func_800F0268_ovl11.c"

#include "shared/func_800F02C4_ovl11.c"

#include "shared/func_800F0330_ovl11.c"
