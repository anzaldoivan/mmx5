#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800F7804_ovl18

#define func_800532E0 func_800F0760_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800EF7C0_ovl29 func_800F079C_ovl18
#define func_800EF82C_ovl29 func_800F0808_ovl18
#define func_800EF920_ovl29 func_800F08FC_ovl18
#define func_800EF9C8_ovl29 func_800F09A4_ovl18
#include "shared/func_800EF7C0_ovl29.c"
#undef func_800EF7C0_ovl29
#undef func_800EF82C_ovl29
#undef func_800EF920_ovl29
#undef func_800EF9C8_ovl29

#define D_8007BD4C D_800F7810_ovl18

#define func_800532E0 func_800F0A3C_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
