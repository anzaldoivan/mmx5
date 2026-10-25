#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2B6C_ovl01(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    func_800171E8(obj, 3);
    obj[5] = 5;
    obj[6] = 0;
    *(s32*)(obj + 0x2C) = 0x1800;
    *(s32*)(obj + 0x24) = 0x2E000;
    *(s32*)(obj + 0x28) = 0;
    obj[0x67] = 1;
}
