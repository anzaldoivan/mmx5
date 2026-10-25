#include "types.h"

s32 TestEvent(s32);
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

s32 func_8001DFB8(void) {
    s32 i = 0x3D08F;

    do {
        if (TestEvent(D_800E81C8)) {
            return 0;
        }
        if (TestEvent(D_800E81CC)) {
            return 1;
        }
        if (TestEvent(D_800E81D0)) {
            return 2;
        }
    } while (--i);
    return 3;
}
