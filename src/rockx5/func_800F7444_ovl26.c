#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FA4D8_ovl26[])(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);

void func_800F7444_ovl26(u8* obj) {
    if (((signed char*)*(u8**)(obj + 0x7C))[4] == 2) {
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    if (D_8009A197 == 0) {
        func_80017248(obj);
        D_800FA4D8_ovl26[(signed char)obj[5]](obj);
    }
    func_800317B8(obj);
    obj[3] = 1;
}
