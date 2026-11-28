#include "types.h"
#include "addr.h"

extern u16 D_8009A11C;

void func_80023808(void) {
    if (D_801F6000 != 0xE10) {
        D_801F6384[D_801F6000] = D_8009A11C;
        D_801F6000++;
    }
}
