#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F52AC_ovl26(u8* obj) {
    func_80017248(obj);
    func_800171E8(obj, 0x11);
    obj[6]++;
}
