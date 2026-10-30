#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800F90AC_ovl09(u8* obj);

void func_800F8B0C_ovl09(u8* obj) {
    func_800171E8(obj, 0xC);
    func_800F90AC_ovl09(obj);
    obj[6]++;
}
