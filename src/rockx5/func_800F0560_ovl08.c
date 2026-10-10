#include "types.h"

extern int func_8002D760();
extern int func_8002D7A0();

void func_800F0560_ovl08(signed char* arg0) {
    *(int*)(arg0 + 0x80) = 0;
    *(int*)(arg0 + 0x84) = 0;
    *(int*)(arg0 + 0x88) = 0;
    *(int*)(arg0 + 0x8C) = 0;
    *(int*)(arg0 + 0x94) = 0;
    if (arg0[4] == 4) {
        func_8002D7A0(arg0);
    } else {
        func_8002D760(arg0);
    }
}
