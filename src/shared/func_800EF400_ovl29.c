#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800EF400_ovl29(u8* arg0) {
    ((int*)arg0)[32] = 0;
    ((int*)arg0)[33] = 0;
    ((int*)arg0)[34] = 0;
    ((int*)arg0)[35] = 0;
    ((int*)arg0)[36] = 0;
    if (arg0[2] < 2) {
        func_8002D760(arg0);
    } else {
        clear_object_slot(arg0);
    }
}
