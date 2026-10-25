#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);

void func_800FA700_ovl27(u8* obj) {
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x89] = 0;
    func_80016490(2, 0x67, obj);
    func_800171E8(obj, 0x12);
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    obj[5] = 3;
    obj[6] = 0;
}
