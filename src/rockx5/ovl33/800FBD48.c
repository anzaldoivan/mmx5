#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"
#include "mmx5/movement.h"

#define func_800F3E90_ovl26 func_800FBD48_ovl33
#include "shared/func_800F3E90_ovl26.c"
#undef func_800F3E90_ovl26

#define func_800F97BC_ovl06 func_800FBD80_ovl33
#include "shared/func_800F97BC_ovl06.c"
#undef func_800F97BC_ovl06

#define func_800EFFE4_ovl04 func_800FBE1C_ovl33
#include "shared/func_800EFFE4_ovl04.c"
#undef func_800EFFE4_ovl04

#define func_800F986C_ovl06 func_800FBE30_ovl33
#define func_800F98B8_ovl06 func_800FBE7C_ovl33
#define func_800F9970_ovl06 func_800FBF34_ovl33
#define func_800F99C4_ovl06 func_800FBF88_ovl33
#include "shared/func_800F986C_ovl06.c"
#undef func_800F986C_ovl06
#undef func_800F98B8_ovl06
#undef func_800F9970_ovl06
#undef func_800F99C4_ovl06

#define D_8007BD4C D_800FEEAC_ovl33

#define func_800532E0 func_800FC060_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define func_800F9AD8_ovl06 func_800FC09C_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FAEF8_ovl06 func_800FD4BC_ovl33
#define func_800F9B2C_ovl06 func_800FC0F0_ovl33
#include "shared/func_800F9AD8_ovl06.c"
#undef func_800F9AD8_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06
#undef func_800F9B2C_ovl06
#undef func_800F9180_ovl06
#undef func_800FAEF8_ovl06

#define D_8007BD4C D_800FEEB4_ovl33

#define func_800532E0 func_800FC154_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FF1DC_ovl06 D_800FEADC_ovl33
#define D_800FF1E0_ovl06 D_800FEAE0_ovl33
#define func_800FAEF8_ovl06 func_800FD4BC_ovl33

#define func_800F9BCC_ovl06 func_800FC190_ovl33
#include "shared/func_800F9BCC_ovl06.c"
#undef func_800F9BCC_ovl06
#undef D_800FF1DC_ovl06
#undef D_800FF1E0_ovl06
#undef func_800FAEF8_ovl06

#define func_800F02E4_ovl05 func_800FC21C_ovl33
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9C9C_ovl06 func_800FC260_ovl33
#include "shared/func_800F9C9C_ovl06.c"
#undef func_800F9C9C_ovl06

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33

#define func_800F9CF8_ovl06 func_800FC2BC_ovl33
#include "shared/func_800F9CF8_ovl06.c"
#undef func_800F9CF8_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06

#define func_800F9180_ovl06 func_800FB744_ovl33

#define func_800F9D90_ovl06 func_800FC354_ovl33
#include "shared/func_800F9D90_ovl06.c"
#undef func_800F9D90_ovl06
