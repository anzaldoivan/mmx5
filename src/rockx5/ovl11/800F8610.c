#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

#define D_8007BD4C D_800FA01C_ovl11

#define func_800532E0 func_800F8610_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F864C_ovl11.c"

#define D_800EEBA0_ovl00 func_800F8724_ovl11
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F7360_ovl28 func_800F8744_ovl11
#define func_800F73C8_ovl28 func_800F87AC_ovl11
#define func_800F7478_ovl28 func_800F885C_ovl11
#include "shared/func_800F7360_ovl28.c"
#undef func_800F7360_ovl28
#undef func_800F73C8_ovl28
#undef func_800F7478_ovl28
