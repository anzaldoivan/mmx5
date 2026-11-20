#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800F7F74_ovl18[];
extern u8 D_800F7F78_ovl18[];

void func_800F5A4C_ovl18(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x68) = D_800F7F74_ovl18;
        *(u8**)(obj + 0x54) = D_800F7F78_ovl18;
        obj[0x7C] = 0x96;
        obj[6]++;
    }
}
