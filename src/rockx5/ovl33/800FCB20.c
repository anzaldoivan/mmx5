#include "types.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define func_800FAEF8_ovl06 func_800FD4BC_ovl33
#define func_800FA55C_ovl06 func_800FCB20_ovl33
#define func_800FAF38_ovl06 func_800FD4FC_ovl33
#define func_800FA5C0_ovl06 func_800FCB84_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FA674_ovl06 func_800FCC38_ovl33
#include "shared/func_800FA55C_ovl06.c"
#undef func_800FA55C_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06
#undef func_800FAEF8_ovl06
#undef func_800FA5C0_ovl06
#undef func_800FA674_ovl06
