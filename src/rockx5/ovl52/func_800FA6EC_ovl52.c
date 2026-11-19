#include "types.h"

extern signed char D_8009A424;
extern void func_80013288(s32);

void func_800FA6EC_ovl52(Actor50* a) {
    if (D_8009A424 == 0) {
        func_80013288(8);
        a->step++;
    }
}
