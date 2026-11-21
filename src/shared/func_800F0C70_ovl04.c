#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F0C70_ovl04(signed char* arg0) {
    if (arg0[2] == 0) {
        func_8002D760(arg0);
    } else {
        clear_object_slot(arg0);
    }
}
