#include "types.h"

extern int func_8002D6FC();
extern void func_8002D89C(u8*);

void func_800F56D8_ovl18(signed char* arg0) {
    if (--arg0[7] == 0) {
        func_8002D6FC(arg0);
    } else {
        func_8002D89C(arg0);
    }
}
