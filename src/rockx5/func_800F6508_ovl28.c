#include "types.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6508_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    func_80017248(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        D_1F80004C.bytes[0x8C] = 0;
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s16*)(obj + 0x7E) = 5;
        func_800171E8(obj, 9);
        obj[6]++;
    }
}
