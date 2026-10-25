#include "types.h"

extern s32 func_8002DF78(void);

void func_800F1784_ovl10(Obj* arg0) {
    arg0->timer = 0xB4;
    if ((func_8002DF78() & 3) == 0) {
        arg0->step = 1;
    } else {
        arg0->step = 2;
    }
}
