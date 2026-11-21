#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl30.h"
#include "mmx5/ovl01.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800FDCE4_ovl30

#define func_800532E0 func_800FBAE4_ovl30
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FD580_ovl01 D_800FD768_ovl30
#define D_800FD584_ovl01 D_800FD76C_ovl30
#define D_800FD588_ovl01 D_800FD770_ovl30
#define D_800FD58C_ovl01 D_800FD774_ovl30
#define D_800FD590_ovl01 D_800FD778_ovl30
#define D_800FD594_ovl01 D_800FD77C_ovl30

#define func_800F9EE8_ovl01 func_800FBB20_ovl30
#include "shared/func_800F9EE8_ovl01.c"
#undef func_800F9EE8_ovl01
#undef D_800FD580_ovl01
#undef D_800FD584_ovl01
#undef D_800FD588_ovl01
#undef D_800FD58C_ovl01
#undef D_800FD590_ovl01
#undef D_800FD594_ovl01

#define D_800FD578_ovl01 D_800FD760_ovl30
#define D_800FD57C_ovl01 D_800FD764_ovl30
#define func_800F9F8C_ovl01 func_800FBBC4_ovl30
#define func_800FB308_ovl01 func_800FCF40_ovl30
#define func_800F9FCC_ovl01 func_800FBC04_ovl30
#include "shared/func_800F9F8C_ovl01.c"
#undef func_800F9F8C_ovl01
#undef D_800FD578_ovl01
#undef D_800FD57C_ovl01
#undef func_800F9FCC_ovl01
