#include "types.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6644_ovl28(u8* obj) {
    D_1F80004C.bytes[0x8C] = 0;
    func_800F6A8C_ovl28(obj);
    func_80017248(obj);
    func_800171E8(obj, 1);
    obj[6]++;
}
