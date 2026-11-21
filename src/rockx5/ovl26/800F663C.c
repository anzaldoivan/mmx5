#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800FA288_ovl26[])(u8* obj);

void func_800F663C_ovl26(u8* obj) {
    func_80031DD0(obj);
    func_800317B8(obj);
    D_800FA288_ovl26[(signed char)obj[5]](obj);
    func_8002D9EC(obj, 0x60, 0x60);
}

#define D_800EEBA0_ovl00 func_800F669C_ovl26
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
