#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8003D29C(s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern u16 D_800D50DE;
extern u8 D_8009A0B5;

void func_800F5040_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    if (D_800D50DE == 0x1F) {
        func_8003D29C(0x48, D_8009A0B5);
        func_800171E8(obj, 0x17);
        obj[5] = 4;
    }
}
