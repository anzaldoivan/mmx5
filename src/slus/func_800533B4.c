#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800533B4(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if (state == 1) {
        obj[6] = state;
        return;
    }
    func_800171E8(obj, 1);
    obj[6] = 2;
}
