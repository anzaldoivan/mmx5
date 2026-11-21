#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8002E274(u8* a0, u8* a1);

void func_800F2070_ovl01(u8* obj) {
    u8* g = g_Player;

    if (g[0xF7] == 0) {
        animate_object(obj);
        move_object(obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        goto dead;
    }
    if (func_8002E274(obj, g) == 0) {
        if (obj[0x70] != 0) {
        dead:
            ((s32(*)())func_8004FD24)(obj);
            obj[4]++;
            return;
        }
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D9EC(obj, 0x10, 0x10);
            return;
        }
    }
    obj[4]++;
}

#define D_800EEBA0_ovl00 func_800F2148_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F2168_ovl01
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
