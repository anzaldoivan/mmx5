#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FA848_ovl28(u8* obj) {
    s8 v;

    func_800317B8(obj);
    func_80031DD0(obj);
    switch ((s8)obj[5]) {
    case 0:
        if (++*(s32*)(obj + 0x8C) == 10) {
            obj[0x16] = 1;
            obj[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(obj + 0x8C) == 100) {
            obj[4] = 2;
        }
        break;
    }
    v = (*(u8**)(obj + 0x7C))[4];
    if (v == 2) {
        obj[4] = v;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}

#define D_800EEBA0_ovl00 func_800FA914_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800FA934_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
