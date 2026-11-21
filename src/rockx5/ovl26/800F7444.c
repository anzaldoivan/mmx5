#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_8009A197;
extern void (*D_800FA4D8_ovl26[])(u8* obj);

void func_800F7444_ovl26(u8* obj) {
    if (((signed char*)*(u8**)(obj + 0x7C))[4] == 2) {
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    if (D_8009A197 == 0) {
        animate_object(obj);
        D_800FA4D8_ovl26[(signed char)obj[5]](obj);
    }
    func_800317B8(obj);
    obj[3] = 1;
}

#define D_800EEBA0_ovl00 func_800F74D8_ovl26
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
