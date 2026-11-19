#include "types.h"

extern void func_8002C1C8(void);

void func_800EEFB4_ovl21(u8* o) {
    if (++*(s16*)(o + 4) >= 3) {
        func_8002C1C8();
        *(s16*)(o + 4) = 0;
        o[1]++;
    }
}
