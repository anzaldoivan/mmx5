#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_800FBE00_ovl10[];

void func_800F56C4_ovl10(u8* obj) {
    func_80017248(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        if (obj[0x8E] != 0) {
            obj[0x8E] = 0;
            obj[0x88] = 0;
            obj[5] = D_800FBE00_ovl10[(obj[0x8A] * 2 + obj[0x89]) * 5];
        } else {
            obj[5] =
                D_800FBE00_ovl10[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        }
        obj[6] = 0;
    }
}
