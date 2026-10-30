#include "types.h"

extern void func_80017248(u8* obj);

void func_800F5E78_ovl26(u8* obj) {
    s8 state;

    func_80017248(obj);
    state = obj[0x45];
    if (state == 2) {
        obj[4] = state;
    }
}
