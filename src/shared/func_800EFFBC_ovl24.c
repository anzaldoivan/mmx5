#include "types.h"

extern void (*D_800F5024_ovl24[])(u8*);

void func_800EFFBC_ovl24(u8* arg0) {
    D_800F5024_ovl24[*(signed char*)(arg0 + 2)](arg0);
}
