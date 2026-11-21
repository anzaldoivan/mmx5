#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_8010111C_ovl07

#define func_800EEA80_ovl05 func_800F346C_ovl07
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

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

#define D_800EEBA0_ovl00 func_800F3554_ovl07
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F3574_ovl07
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
