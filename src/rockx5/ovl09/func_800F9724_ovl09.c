#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FB5BC_ovl09[])(u8* obj);

void func_800F9724_ovl09(u8* obj) {
    if (((signed char*)*(u8**)(obj + 0x7C))[4] != 3) {
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    animate_object(obj);
    D_800FB5BC_ovl09[(signed char)obj[5]](obj);
    func_800317B8(obj);
}
