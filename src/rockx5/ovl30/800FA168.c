#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/ovl30.h"
#include "mmx5/ovl01.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

#define D_800FD57C_ovl01 D_800FD764_ovl30
#define D_800FDA14_ovl01 D_800FDBFC_ovl30
#define D_800FDA98_ovl01 D_800FDC80_ovl30
#define D_800FDAA4_ovl01 D_800FDC8C_ovl30

#define func_800F8530_ovl01 func_800FA168_ovl30
#include "shared/func_800F8530_ovl01.c"
#undef func_800F8530_ovl01
#undef D_800FD57C_ovl01
#undef D_800FDA14_ovl01
#undef D_800FDA98_ovl01
#undef D_800FDAA4_ovl01

#define D_800FDA5C_ovl01 D_800FDC44_ovl30
#define D_800FDAC4_ovl01 D_800FDCAC_ovl30

#define func_800F86D8_ovl01 func_800FA310_ovl30
#include "shared/func_800F86D8_ovl01.c"
#undef func_800F86D8_ovl01
#undef D_800FDA5C_ovl01
#undef D_800FDAC4_ovl01

#define func_800F8948_ovl01 func_800FA580_ovl30
#include "shared/func_800F8948_ovl01.c"
#undef func_800F8948_ovl01

#define D_800FD590_ovl01 D_800FD778_ovl30
#define D_800FD594_ovl01 D_800FD77C_ovl30
#define D_800FD598_ovl01 D_800FD780_ovl30
#define D_800FD59C_ovl01 D_800FD784_ovl30
#define D_800FD5A0_ovl01 D_800FD788_ovl30
#define D_800FD5A4_ovl01 D_800FD78C_ovl30
#define func_800FB308_ovl01 func_800FCF40_ovl30

#define func_800F8A40_ovl01 func_800FA678_ovl30
#include "shared/func_800F8A40_ovl01.c"
#undef func_800F8A40_ovl01
