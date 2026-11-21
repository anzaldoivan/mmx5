#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s32 func_8004FC64(u8* a0);
extern s32 func_8002E274(u8* a0, u8* a1);

s32 func_800F9C5C_ovl00(u8* obj) {
    s32 r;

    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        r = func_8004FC64(obj);
        goto inc;
    }
    if (func_8002E274(obj, g_Player) == 0) {
        if (obj[0x70] != 0) {
            r = ((s32(*)())func_8004FD24)(obj);
        inc:
            obj[4]++;
            return r;
        }
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D9EC(obj, 0x10, 0x10);
            return;
        }
    }
    obj[4]++;
}

#define D_800EEBA0_ovl00 func_800F9D28_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F9D48_ovl00
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
