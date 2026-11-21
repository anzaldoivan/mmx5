#include "types.h"
#include "mmx5/ovl08.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F1574_ovl08
/* the callee takes a pointer, the body's call passes none */
#define func_8002D720 ((void (*)())func_800F11D0_ovl08)
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
