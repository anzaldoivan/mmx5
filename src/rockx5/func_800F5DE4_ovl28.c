#include "types.h"

extern void func_800F6A8C_ovl28(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F5DE4_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    func_80017248(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        func_800171E8(obj, 7);
        obj[6]++;
    }
}
