#include "types.h"

extern void (*D_8007BD4C[])(u8*);

void func_800532E0(u8* arg0) {
    D_8007BD4C[*(signed char*)(arg0 + 6)](arg0);
}
