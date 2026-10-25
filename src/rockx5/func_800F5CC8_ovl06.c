#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];
extern u8 D_800FE924_ovl06[];

void func_800F5CC8_ovl06(u8* obj) {
    if (*(s8*)(obj + 6) == 0) {
        obj[6]++;
        func_800171E8(obj, 9);
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 2;
        obj[6] = 0;
        obj[0x88] = 0;
        obj[0x86] = 0;
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
        obj[0x87] = 0;
        return;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x50) = D_800FE924_ovl06;
        obj[0x60] = 6;
    } else if (*(s8*)(obj + 0x45) == 2) {
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
    }
    func_80017248(obj);
}
