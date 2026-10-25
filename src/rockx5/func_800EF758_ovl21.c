#include "types.h"

extern void func_8002D89C(u8*);
extern s8 D_800D1C01;

void func_800EF758_ovl21(u8* obj) {
    if (D_800D1C01 == 7) {
        obj[4] = 3;
        *(s16*)(obj + 0x42) = 0x7848;
    }
    func_8002D89C(obj);
}
