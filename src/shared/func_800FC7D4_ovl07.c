/* Shared body (DK-5), from the banked draft of func_800FC7D4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

void func_800FB030_ovl07(u8* obj);
void func_80017248(u8* obj);

void DEDUP_NAME(u8* arg0) {
    if (((signed char*)arg0)[0x45] == 1) {
        func_800FB030_ovl07(arg0);
    } else {
        func_80017248(arg0);
    }
}
