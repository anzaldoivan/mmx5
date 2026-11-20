#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F56D8_ovl18(signed char* arg0) {
    if (--arg0[7] == 0) {
        clear_object_slot(arg0);
    } else {
        func_8002D89C(arg0);
    }
}
