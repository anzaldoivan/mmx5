#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl26.h"
#include "mmx5/title.h"

#define D_800F8FB4_ovl29 D_800F936C_ovl26
#define D_800F8FB8_ovl29 D_800F9370_ovl26
#define D_800F8FBC_ovl29 D_800F9374_ovl26
#define D_800F9104_ovl29 D_800F94BC_ovl26

#define func_800EECF8_ovl29 func_800F0460_ovl26
#include "shared/func_800EECF8_ovl29.c"
#undef func_800EECF8_ovl29
#undef D_800F8FB4_ovl29
#undef D_800F8FB8_ovl29
#undef D_800F8FBC_ovl29
#undef D_800F9104_ovl29

#define D_800F9138_ovl29 D_800F94F0_ovl26
#define D_800F9150_ovl29 D_800F9508_ovl26
#define func_800EEF84_ovl29 func_800F06EC_ovl26
#define func_800EF190_ovl29 func_800F08F8_ovl26
#define func_800EF2B8_ovl29 func_800F0A20_ovl26
#define func_800EFC68_ovl29 func_800F13D0_ovl26
#define func_800EFCEC_ovl29 func_800F1454_ovl26

extern void func_800EF190_ovl29(u8* a0);
extern void func_800EF2B8_ovl29(u8* a0);
#define func_800EEE6C_ovl29 func_800F05D4_ovl26
#define func_800EEF84_ovl29 func_800F06EC_ovl26
#include "shared/func_800EEE6C_ovl29.c"
#undef func_800EEE6C_ovl29
#undef D_800F9138_ovl29
#undef D_800F9150_ovl29
#undef func_800EEF84_ovl29
#undef func_800EF190_ovl29
#undef func_800EF2B8_ovl29
#undef func_800EFC68_ovl29
#undef func_800EFCEC_ovl29
