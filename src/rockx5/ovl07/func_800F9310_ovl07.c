#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F9310_ovl07
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800F8F6C_ovl07)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
