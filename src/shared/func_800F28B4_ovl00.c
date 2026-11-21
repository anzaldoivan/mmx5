#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void func_800F2038_ovl00(void);

void func_800F28B4_ovl00(void) {
    if (G[0x8A] == 0) {
        func_800F2038_ovl00();
    }
}
