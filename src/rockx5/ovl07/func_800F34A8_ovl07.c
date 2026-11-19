#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void (*D_8010112C_ovl07[])(u8*);

void func_800F34A8_ovl07(u8* obj) {
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_8010112C_ovl07[*(signed char*)(obj + 5)](obj);
        animate_object(obj);
    }
    func_800317B8(obj);
    func_80031DD0(obj);
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}
