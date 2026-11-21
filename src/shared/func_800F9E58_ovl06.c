#include "types.h"
#include "mmx5/globals.h"

void func_800F9E58_ovl06(Obj* o) {
    animate_object(o);
    if (--o->timer == 0) {
        o->step++;
    }
}
