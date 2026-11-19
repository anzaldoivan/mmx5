/* Shared body (DK-5), from the banked draft of func_800FB840_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_8004FC64(u8* a0);

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    move_object(obj);
    func_800317B8(obj);
    if (func_8002E274(obj, g_Player) == 0) {
        if (*(s8*)(obj + 2) < 3 && (func_80031DD0(obj) < 0 || obj[0x70] != 0)) {
            func_8004FC64(obj);
            obj[4] = 2;
            return;
        }
        func_8002F8FC(obj);
        if (is_off_screen(obj, 0x60, 0x20) == 0) {
            func_8002D9EC(obj, 0x60, 0x20);
            return;
        }
    }
    obj[4] = 2;
}
