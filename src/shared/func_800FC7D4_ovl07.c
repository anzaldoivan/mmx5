/* Shared body (DK-5), from the banked draft of func_800FC7D4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* arg0) {
    if (((signed char*)arg0)[0x45] == 1) {
        func_800FB030_ovl07(arg0);
    } else {
        animate_object(arg0);
    }
}
