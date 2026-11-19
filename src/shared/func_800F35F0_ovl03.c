/* Shared body (DK-5), from the banked draft of func_800F35F0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8002DC14(void);
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    s8* p;

    if (*(s8*)(obj + 0x46) == 0) {
        p = (s8*)D_800D1C00;
        if (p[0xC] != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x6B, 0xFF, p[0x2E]);
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x30, 0xFF, p[0x2E]);
            } else {
                func_8002385C(0x62, 0xFF, p[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
        set_animation(obj, 1);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    if (*(s8*)(obj + 0x45) != 0 && *(s32*)(obj + 0x24) == 0) {
        *(s32*)(obj + 0x24) = 0xFFFF0000;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
