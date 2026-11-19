/* Shared body (DK-5), from the banked draft of func_800F6EEC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* p) {
    switch ((s8)p[5]) {
    case 0:
        p[7]--;
        if ((s8)p[7] == -1) {
            p[7] = 0;
            p[5]++;
        }
        func_8002D9EC(p, 0x20, 0x20);
        break;
    case 1:
        p[7]++;
        if ((s8)p[7] == 0x14) {
            p[4] = 2;
        }
        if (p[7] & 1) {
            func_8002D9EC(p, 0x20, 0x20);
        }
        break;
    }
    animate_object(p);
    apply_object_motion(p);
}
