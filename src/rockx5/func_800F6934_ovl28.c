#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6934_ovl28(u8* obj) {
    func_80017248(obj);
    if (D_1F80004C.bytes[0x8C] == 1) {
        func_800171E8(obj, 5);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[7] = 0;
        obj[6]++;
    }
}
