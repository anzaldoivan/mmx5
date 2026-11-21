#include "types.h"
#include "mmx5/globals.h"

void func_800FA08C_ovl06(ObjFA284* o) {
    animate_object(o);
    if (((signed char*)o)[0x45] == 1) {
        o->timer = 0xF;
        o->step++;
    }
}
