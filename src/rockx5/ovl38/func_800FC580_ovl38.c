/* Standalone twin of func_800F28B4_ovl00 (src/shared/func_800F28B4_ovl00.c): flag byte 0x92. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void func_800FAC40_ovl38(void);

void func_800FC580_ovl38(void) {
    if (G[0x92] == 0) {
        func_800FAC40_ovl38();
    }
}
