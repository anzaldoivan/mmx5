#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FA288_ovl26[])(u8* obj);

void func_800F663C_ovl26(u8* obj) {
    func_80031DD0(obj);
    func_800317B8(obj);
    D_800FA288_ovl26[(signed char)obj[5]](obj);
    func_8002D9EC(obj, 0x60, 0x60);
}
