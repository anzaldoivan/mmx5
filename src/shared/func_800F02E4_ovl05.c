#include "types.h"
#include "mmx5/globals.h"

void func_800F02E4_ovl05(Ob5* o) {
    apply_object_motion(o);
    if (o->b45 == 1) {
        o->b6++;
    }
}
