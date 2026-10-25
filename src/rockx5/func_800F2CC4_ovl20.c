#include "types.h"

extern s32 func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1C01;
extern u8 D_800F6DFB_ovl20;

void func_800F2CC4_ovl20(u8* obj) {
    func_80017248(obj);
    if (D_800D1C01 == 6 || D_800F6DFB_ovl20 == 1) {
        obj[3] = 0;
    } else {
        func_8002D9EC(obj, 0x80, 0x80);
    }
}
