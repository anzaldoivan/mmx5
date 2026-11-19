#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

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
