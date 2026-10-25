/* Shared body (DK-5), from the banked draft of func_800EF410_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

void func_800EF4FC_ovl11(void* arg0);
void func_800EF534_ovl11(void* arg0);

void DEDUP_NAME(signed char* arg0) {
    if (arg0[4] == 0) {
        func_800EF4FC_ovl11(arg0);
    } else {
        func_800EF534_ovl11(arg0);
    }
}
