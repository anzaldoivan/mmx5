#include "types.h"

extern void (*D_800FB5BC_ovl09[])(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);

void func_800F9724_ovl09(u8* obj) {
    if (((signed char*)*(u8**)(obj + 0x7C))[4] != 3) {
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    func_80017248(obj);
    D_800FB5BC_ovl09[(signed char)obj[5]](obj);
    func_800317B8(obj);
}
