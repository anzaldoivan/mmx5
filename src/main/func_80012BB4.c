#include "types.h"

#define SP(offset) (0x1F800000 + (offset))

int VSync(int mode);

void func_80012BB4(void) {
    *(s32*)SP(0x074) = VSync(1);
}
