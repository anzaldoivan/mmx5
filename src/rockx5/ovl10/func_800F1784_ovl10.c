#include "types.h"
#include "mmx5/system.h"

void func_800F1784_ovl10(Obj* arg0) {
    arg0->timer = 0xB4;
    if ((random_byte() & 3) == 0) {
        arg0->step = 1;
    } else {
        arg0->step = 2;
    }
}
