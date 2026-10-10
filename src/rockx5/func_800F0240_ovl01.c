#include "types.h"

extern int func_8002D760();
extern int func_8002D7A0();

void func_800F0240_ovl01(signed char* arg0) {
    if (arg0[4] == 3) {
        func_8002D7A0(arg0);
    } else {
        func_8002D760(arg0);
    }
}
