/* Shared body (DK-5), from the banked draft of func_800F3230_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D800(u8* a0);

void DEDUP_NAME(u8* obj) {
    u8* g = g_Player;

    if (g[0xF7] == 0) {
        animate_object(obj);
        apply_object_motion(obj);
    }
    if (func_800317B8(obj) != 0) {
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002E274(obj, g) != 0) {
        if (obj[2] & 0x40) {
            ((s32(*)())func_8004FD24)(obj);
        }
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (obj[2] & 0x40) {
        if (obj[0x70] == 0) {
            ((s32(*)())func_8002F8FC)(obj);
            if (obj[0x70] == 0) {
                goto tail; // !FAKE: goto kept for the matching branch layout
            }
        }
        ((s32(*)())func_8004FD24)(obj);
        obj[4]++;
        return;
    }
    if (obj[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj[0x70] == 0) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8004FC64(obj);
    obj[4] = 2;
    return;
tail:
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
        return;
    }
inc:
    obj[4]++;
}
