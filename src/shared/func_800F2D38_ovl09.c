/* Shared body (DK-5), from the banked draft of func_800F2D38_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 D_800FB67C_ovl09;
extern u8 D_800FAD58_ovl09[][6];

void DEDUP_NAME(u8* obj) {
    u32 r;
    s32 lim;
    s32 c;
    u8 idx;

    r = random_byte();
    obj[0x97] = 0;
    lim = *(s8*)(obj + 0x5C);
    c = (s8)D_800D1CA2;
    r &= 0xF;
    if ((c * 2) / 3 < lim) {
        if (r < 6) {
            obj[0x96] = 0;
        } else {
            obj[0x96] = 1;
        }
    } else if ((s8)(c / 3) < lim) {
        if (r < 8) {
            obj[0x96] = 2;
        } else {
            obj[0x96] = 3;
        }
    } else {
        obj[0x96] = r < 4 ? 4 : r < 9 ? 5 : 6;
        D_800FB67C_ovl09 = 1;
    }
    idx = obj[0x97]++;
    obj[5] = D_800FAD58_ovl09[obj[0x96]][idx];
    obj[6] = 0;
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
