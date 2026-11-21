#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_800FD578_ovl01 D_800FD760_ovl30
#define D_800FD57C_ovl01 D_800FD764_ovl30
#define D_800FD5A8_ovl01 D_800FD790_ovl30
#define D_800FD5AC_ovl01 D_800FD794_ovl30
#define func_800FA0DC_ovl01 func_800FBD14_ovl30
#define func_800FA1B0_ovl01 func_800FBDE8_ovl30
#include "shared/func_800FA0DC_ovl01.c"
#undef func_800FA0DC_ovl01
#undef D_800FD578_ovl01
#undef D_800FD57C_ovl01
#undef D_800FD5A8_ovl01
#undef D_800FD5AC_ovl01
#undef func_800FA1B0_ovl01

#define D_8007BD4C D_800FDD08_ovl30

#define func_800532E0 func_800FBE3C_ovl30
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FD5A8_ovl01 D_800FD790_ovl30
#define D_800FD5AC_ovl01 D_800FD794_ovl30
#define func_800FA240_ovl01 func_800FBE78_ovl30
#define func_800FB348_ovl01 func_800FCF80_ovl30
#define func_800FA2CC_ovl01 func_800FBF04_ovl30
#include "shared/func_800FA240_ovl01.c"
#undef func_800FA240_ovl01
#undef D_800FD5A8_ovl01
#undef D_800FD5AC_ovl01
#undef func_800FA2CC_ovl01
