#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];

void func_800FDD58_ovl04(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        if (*(s8*)(obj + 0x5) == 2) {
            func_800171E8(obj, 0);
        }
        obj[0x6] = 0;
        D_800D1C00[0x28] &= obj[0x95];
        D_800D1C00[0x29] &= obj[0x96];
    }
}
