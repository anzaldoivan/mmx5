#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

#define D_8007BD4C D_800FDC50_ovl37

#define func_800532E0 func_800FD648_ovl37
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F864C_ovl11 func_800FD684_ovl37
#define D_800FA02C_ovl11 D_800FDC60_ovl37
#define func_800F869C_ovl11 func_800FD6D4_ovl37
#include "shared/func_800F864C_ovl11.c"
#undef func_800F864C_ovl11
#undef func_800F869C_ovl11
#undef D_800FA02C_ovl11

#define D_800EEBA0_ovl00 func_800FD75C_ovl37
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F7360_ovl28 func_800FD77C_ovl37
#define func_800F73C8_ovl28 func_800FD7E4_ovl37
#define func_800F7478_ovl28 func_800FD894_ovl37
#include "shared/func_800F7360_ovl28.c"
#undef func_800F7360_ovl28
#undef func_800F73C8_ovl28
#undef func_800F7478_ovl28
