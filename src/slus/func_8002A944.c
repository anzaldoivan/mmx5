#include "types.h"

extern s16 D_8009A206;

void func_8002A944(u8* p) {
    *(s16*)(p + 0xE) = D_8009A206 + *(s16*)(p + 0x42);
}
