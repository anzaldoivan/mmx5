#include "types.h"

extern int func_8002D760();
extern int func_8002D7A0();

void func_800F2528_ovl29(signed char* arg0) {
    arg0[0x7A] = 0;
    ((int*)arg0)[32] = 0;
    ((int*)arg0)[33] = 0;
    ((int*)arg0)[34] = 0;
    ((int*)arg0)[35] = 0;
    ((int*)arg0)[36] = 0;
    ((int*)arg0)[37] = 0;
    arg0[0x61] = 0;
    if (arg0[4] == 2) {
        func_8002D760(arg0);
    } else {
        func_8002D7A0(arg0);
    }
}
