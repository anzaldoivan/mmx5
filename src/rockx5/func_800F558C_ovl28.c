#include "types.h"

extern u8 D_80091C44;
extern void func_80017248(u8* obj);
extern void func_80044DD0(s32 a0);

void func_800F558C_ovl28(u8* obj) {
    func_80017248(obj);
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7E) = 10;
        obj[6]++;
    }
}
