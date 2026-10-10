#include "types.h"

extern int func_8002D6FC();
extern signed char D_800D1C01;
extern void (*D_80070B10[])(signed char*);

void func_80019FD0(signed char* arg0) {
    if (D_800D1C01 == 0) {
        func_8002D6FC();
    } else {
        D_80070B10[arg0[4]](arg0);
    }
}
