#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80091C44;

void func_800559A8(u8* obj) {
    if (D_80091C44 == 1) {
        func_800171E8(obj, 0xB);
        obj[6] = 0;
        obj[5]++;
    }
}
