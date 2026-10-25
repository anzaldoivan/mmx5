#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 D_8009A420;
extern u8 D_800F47B8_ovl02[];
extern u8 D_800F47BC_ovl02[];
extern u8 D_800F47C0_ovl02[];

void func_800F3158_ovl02(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[0x46] == 0) {
        func_800171E8(obj, 1);
        obj[5] = 3;
        obj[6] = 0;
        func_8002D9EC(obj, 0x20, 0x20);
        *(u8**)(obj + 0x68) = D_800F47C0_ovl02;
        *(u8**)(obj + 0x54) = D_800F47BC_ovl02;
        *(u8**)(obj + 0x50) = D_800F47B8_ovl02;
    } else if (D_8009A420 & 1) {
        obj[3] = 0;
    } else {
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
