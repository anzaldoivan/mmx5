#include "types.h"

extern int func_8002D760();
extern int func_8002D6FC();

void func_800F0C70_ovl04(signed char* arg0) {
    if (arg0[2] == 0) {
        func_8002D760(arg0);
    } else {
        func_8002D6FC(arg0);
    }
}
