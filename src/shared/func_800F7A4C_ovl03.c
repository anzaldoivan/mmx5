/* Shared body (DK-5), from the banked draft of func_800F7A4C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* arg0) {
    u32 r;

    r = random_byte() & 0xF;
    arg0[0x93] = 0;
    if (D_800D1CA2 / 2 < (s8)arg0[0x5C]) {
        if (r < 12) {
            arg0[0x92] = 0;
        } else {
            arg0[0x92] = 1;
        }
    } else if (r < 6) {
        arg0[0x92] = 2;
    } else if (r < 12) {
        arg0[0x92] = 3;
    } else if (r >= 14) {
        arg0[0x92] = 5;
    } else {
        arg0[0x92] = 4;
    }
    arg0[5] = D_800FA0BC_ovl03[arg0[0x92]][arg0[0x93]++];
    arg0[6] = 0;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002D9EC(arg0, 0xFF, 0xFF);
}
