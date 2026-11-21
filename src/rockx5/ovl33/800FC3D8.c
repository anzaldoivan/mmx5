#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FC3D8_ovl33
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9E58_ovl06 func_800FC41C_ovl33
#include "shared/func_800F9E58_ovl06.c"
#undef func_800F9E58_ovl06

#define D_800FF1E4_ovl06 D_800FEAE4_ovl33
#define D_800FF1E8_ovl06 D_800FEAE8_ovl33
#define func_800F9EA8_ovl06 func_800FC46C_ovl33
#define D_800FF1DC_ovl06 D_800FEADC_ovl33
#define D_800FF1E0_ovl06 D_800FEAE0_ovl33
#define func_800FAF38_ovl06 func_800FD4FC_ovl33
#define func_800F9F0C_ovl06 func_800FC4D0_ovl33
#include "shared/func_800F9EA8_ovl06.c"
#undef func_800F9EA8_ovl06
#undef D_800FF1E4_ovl06
#undef D_800FF1E8_ovl06
#undef func_800F9F0C_ovl06
#undef D_800FF1DC_ovl06
#undef D_800FF1E0_ovl06
#undef func_800FAF38_ovl06

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33

#define func_800F9FFC_ovl06 func_800FC5C0_ovl33
#include "shared/func_800F9FFC_ovl06.c"
#undef func_800F9FFC_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06

#define func_800FA08C_ovl06 func_800FC650_ovl33
#include "shared/func_800FA08C_ovl06.c"
#undef func_800FA08C_ovl06

#define func_800F9180_ovl06 func_800FB744_ovl33

#define func_800F9D90_ovl06 func_800FC694_ovl33
#include "shared/func_800F9D90_ovl06.c"
#undef func_800F9D90_ovl06
