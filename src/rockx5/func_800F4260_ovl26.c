#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800F9628_ovl26[];

void func_800F4260_ovl26(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[0x45] == 1) {
        *(s32*)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_800F9628_ovl26;
        func_800171E8(obj, 7);
        *(s32*)(obj + 0x24) = 0x40000;
        obj[6]++;
    }
}
