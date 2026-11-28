#include "types.h"

extern s32 TestEvent(s32);
extern s32 _card_clear(s32);
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

static inline s32 func_8001D90C_wait(void) {
    s32 timeout;

    timeout = 0x3D08F;
    do {
        if (TestEvent(D_800E81C8) != 0) {
            return 0;
        }
        if (TestEvent(D_800E81CC) != 0) {
            return 1;
        }
        if (TestEvent(D_800E81D0) != 0) {
            return 2;
        }
    } while (--timeout != 0);
    return 3;
}

s32 func_8001D90C(s32 arg0) {
    s32 retry;
    s32 result;

    retry = 10;
    result = 2;
    TestEvent(D_800E81C8);
    TestEvent(D_800E81CC);
    TestEvent(D_800E81D0);
    do {
        if (_card_clear(arg0 << 4) != 0) {
            result = func_8001D90C_wait();
            if (result == 0) {
                break;
            }
        }
    } while (--retry != 0);
    return result;
}
