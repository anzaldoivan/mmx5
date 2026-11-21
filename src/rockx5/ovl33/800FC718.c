#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FC718_ovl33
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define D_800FF1EC_ovl06 D_800FEAEC_ovl33
#define D_800FF1F0_ovl06 D_800FEAF0_ovl33
#define func_800FA198_ovl06 func_800FC75C_ovl33
#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define func_800FA284_ovl06 func_800FC848_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FA324_ovl06 func_800FC8E8_ovl33
#include "shared/func_800FA198_ovl06.c"
#undef func_800FA198_ovl06
#undef D_800FF1EC_ovl06
#undef D_800FF1F0_ovl06
#undef func_800FA284_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06
#undef func_800FA324_ovl06
#undef func_800F9180_ovl06

#define D_8007BD4C D_800FEF08_ovl33

#define func_800532E0 func_800FC938_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
