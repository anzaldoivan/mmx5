#include "types.h"
#include "mmx5/globals.h"

void func_800F5E78_ovl26(u8* obj) {
    s8 state;

    animate_object(obj);
    state = obj[0x45];
    if (state == 2) {
        obj[4] = state;
    }
}
