#include "types.h"

extern void (*D_800FA214_ovl00[])(u8*);

void func_800EEB64_ovl00(u8* arg0) {
    D_800FA214_ovl00[*(signed char*)(arg0 + 5)](arg0);
}
