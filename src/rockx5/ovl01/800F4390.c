#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/ovl01.h"
#include "mmx5/ovl00.h"
#include "mmx5/movement.h"
#include "mmx5/title.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

#define func_800F292C_ovl00 func_800F4390_ovl01
#define func_800F2E10_ovl00 func_800F4874_ovl01
#define func_800F2970_ovl00 func_800F43D4_ovl01
#include "shared/func_800F292C_ovl00.c"
#undef func_800F292C_ovl00
#undef func_800F2970_ovl00
#undef func_800F2E10_ovl00

#define D_800F75FC_ovl18 D_800FCD0C_ovl01
#define animate_object func_800F4A2C_ovl01
#define func_8002D89C func_800F4748_ovl01

#define func_800EF750_ovl18 func_800F447C_ovl01
#include "shared/func_800EF750_ovl18.c"
#undef func_800EF750_ovl18
#undef D_800F75FC_ovl18
#undef animate_object
#undef func_8002D89C

#define func_800F2A6C_ovl00 func_800F44D0_ovl01
#include "shared/func_800F2A6C_ovl00.c"
#undef func_800F2A6C_ovl00

#define func_800F28B4_ovl00 func_800F4514_ovl01
#define func_800F2038_ovl00 func_800F3A9C_ovl01
#include "shared/func_800F28B4_ovl00.c"
#undef func_800F28B4_ovl00
#undef func_800F2038_ovl00

#define D_8007BD4C D_800FCD14_ovl01

#define func_800532E0 func_800F4550_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F2B28_ovl00 func_800F458C_ovl01
#define func_800F2B5C_ovl00 func_800F45C0_ovl01
#define func_800F2EA4_ovl00 func_800F4908_ovl01
#define func_800F2BA4_ovl00 func_800F4608_ovl01
#define func_800F2BCC_ovl00 func_800F4630_ovl01
#include "shared/func_800F2B28_ovl00.c"
#undef func_800F2B28_ovl00
#undef func_800F2B5C_ovl00
#undef func_800F2EA4_ovl00
#undef func_800F2BA4_ovl00
#undef func_800F2BCC_ovl00

#define D_8007BD4C D_800FCD24_ovl01

#define func_800532E0 func_800F4694_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F2C6C_ovl00 func_800F46D0_ovl01
#include "shared/func_800F2C6C_ovl00.c"
#undef func_800F2C6C_ovl00

extern void func_800F3A9C_ovl01();
#define D_800EEBA0_ovl00 func_800F4728_ovl01
#define func_8002D720 func_800F3A9C_ovl01
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F2CE4_ovl00 func_800F4748_ovl01
#define func_800F2D24_ovl00 func_800F4788_ovl01
#define func_800F2D68_ovl00 func_800F47CC_ovl01
#define D_800FAC44_ovl00 D_800FCBD0_ovl01
#define func_800F2E10_ovl00 func_800F4874_ovl01
#define func_800F2EA4_ovl00 func_800F4908_ovl01
#define func_800F2F40_ovl00 func_800F49A4_ovl01
#define func_800F2FC8_ovl00 func_800F4A2C_ovl01
#define func_800F2038_ovl00 func_800F3A9C_ovl01
#define D_800FADA0_ovl00 D_800FCD2C_ovl01
#define D_800FADA8_ovl00 D_800FCD34_ovl01
#define D_800FADAC_ovl00 D_800FCD38_ovl01
#define D_800FADB0_ovl00 D_800FCD3C_ovl01
#define D_800FADB4_ovl00 D_800FCD40_ovl01
#define func_800F3014_ovl00 func_800F4A78_ovl01
#define D_800FADB8_ovl00 D_800FCD44_ovl01
#define D_800FADCC_ovl00 D_800FCD58_ovl01
#define func_800F3224_ovl00 func_800F4C88_ovl01
#define func_800F33B0_ovl00 func_800F4E14_ovl01
#include "shared/func_800F2CE4_ovl00.c"
#undef func_800F2CE4_ovl00
#undef func_800F2D24_ovl00
#undef func_800F2D68_ovl00
#undef func_800F2E10_ovl00
#undef D_800FAC44_ovl00
#undef func_800F2EA4_ovl00
#undef func_800F2F40_ovl00
#undef func_800F2FC8_ovl00
#undef func_800F2038_ovl00
#undef func_800F3014_ovl00
#undef D_800FADA0_ovl00
#undef D_800FADA8_ovl00
#undef D_800FADAC_ovl00
#undef D_800FADB0_ovl00
#undef D_800FADB4_ovl00
#undef func_800F3224_ovl00
#undef D_800FADB8_ovl00
#undef D_800FADCC_ovl00
#undef func_800F33B0_ovl00

#define D_800F4844_ovl05 D_800FCD48_ovl01

#define func_800EEA80_ovl05 func_800F4F88_ovl01
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800F3560_ovl00 func_800F4FC4_ovl01
#include "shared/func_800F3560_ovl00.c"
#undef func_800F3560_ovl00

#define D_800EEBA0_ovl00 func_800F5070_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
