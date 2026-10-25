#include "types.h"

extern void func_800171E8(Obj5524*, s32);

void func_800F8FE0_ovl00(Obj5524* arg0) {
    func_800171E8(arg0, 1);
    arg0->timer7C = 10;
    arg0->timer7E = 0;
    arg0->state6++;
}
