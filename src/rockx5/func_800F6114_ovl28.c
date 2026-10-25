#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6114_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        func_800171E8(obj, 5);
        *(s8*)(obj + 0x67) = -1;
        obj[6]++;
    }
}
