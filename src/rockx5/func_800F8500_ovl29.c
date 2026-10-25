#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern s32 func_800171E8(u8* obj, s32 state);

void func_800F8500_ovl29(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(s32*)(obj + 0x8) = *(s32*)(parent + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
    func_80017248(obj);
    func_8002D89C(obj);
    if (*(s8*)(parent + 0x67) == 0) {
        func_800171E8(obj, 0x1A);
        obj[4] -= 2;
    } else {
        if (*(s8*)(obj + 0x46) < 0) {
            if (*(s8*)(obj + 0x2) != 0) {
                obj[4]--;
            }
        }
    }
}
