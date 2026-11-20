#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void func_800F558C_ovl28(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7E) = 10;
        obj[6]++;
    }
}
