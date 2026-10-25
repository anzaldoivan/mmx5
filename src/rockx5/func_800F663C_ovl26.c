#include "types.h"

extern void (*D_800FA288_ovl26[])(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F663C_ovl26(u8* obj) {
    func_80031DD0(obj);
    func_800317B8(obj);
    D_800FA288_ovl26[(signed char)obj[5]](obj);
    func_8002D9EC(obj, 0x60, 0x60);
}
