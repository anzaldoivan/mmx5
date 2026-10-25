#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4DD4_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
        func_800171E8(obj, 0);
    }
    func_80017248(obj);
}
