#include "types.h"

void func_800470EC(u8* arg0) {
    u8* obj;

    obj = *(u8**)(arg0 + 0x7C);
    arg0[3] = 0;
    arg0[4]++;
    if (*(s8*)(obj + 2) == 0) {
        if (*(s8*)(obj + 5) != 0x26) {
            arg0[4] = 3;
        }
    } else {
        if (*(s8*)(obj + 5) != 0x3F) {
            arg0[4] = 3;
        }
    }
}
