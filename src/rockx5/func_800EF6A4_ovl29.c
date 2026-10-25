#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800EF6A4_ovl29(u8* obj) {
    func_800171E8(obj, 3);
    func_80017248(obj);
    obj[6] = 1;
}
