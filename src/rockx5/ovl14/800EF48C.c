#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F20BC_ovl12 D_800F2060_ovl14
#define D_800F20C0_ovl12 D_800F2064_ovl14
#define func_800EF48C_ovl12 func_800EF48C_ovl14
#define func_800EF5E8_ovl12 func_800EF5E8_ovl14
#define func_800EF7EC_ovl12 func_800EF7EC_ovl14
#include "shared/func_800EF48C_ovl12.c"
#undef func_800EF48C_ovl12
#undef D_800F20BC_ovl12
#undef D_800F20C0_ovl12
#undef func_800EF5E8_ovl12
#undef func_800EF7EC_ovl12

#define D_800F1FF4_ovl12 D_800F1F98_ovl14

#define func_800EF928_ovl12 func_800EF928_ovl14
#include "shared/func_800EF928_ovl12.c"
#undef func_800EF928_ovl12
