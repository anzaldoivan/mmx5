#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800F70CC_ovl28(u8* obj) {
    func_80017248(obj);
    if ((*(s8**)(obj + 0x50))[7] == 2) {
        *(s32*)(obj + 0x24) = 0x80000;
        func_800171E8(obj, 0x16);
        func_80016490(2, 0x75, obj);
        obj[6]++;
    }
}
