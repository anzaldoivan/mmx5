#include "types.h"

extern void* D_80072E8C[];

void func_8002B4E4(s32 arg0) {
    ((s32(*)(void))D_80072E8C[arg0 & 0xF])();
}
