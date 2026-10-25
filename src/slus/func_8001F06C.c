#include "types.h"

void func_8001F06C(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 3) {
        arg0[1]++;
    }
}
