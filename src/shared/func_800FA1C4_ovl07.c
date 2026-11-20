/* Shared body (DK-5), from the banked draft of func_800FA1C4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 a;
    s32 b;
    s32 d;

    animate_object(obj);
    p = D_1F80004C.bytes;
    if (p[0x8F] == 0) {
        a = *(s16*)(obj + 0xA);
        b = *(s16*)(p + 0x84);
        d = a - b;
        if (((d >= 0) ? (d >= 0x30) : (b - a >= 0x30)) &&
            D_8009A0AA + 0x10 > (s16) * (u16*)(obj + 0xA)) {
            obj[6] = 3;
            return;
        }
        p = D_1F80004C.bytes;
        d = p[0x91];
        d &= 2;
    } else {
        a = *(s16*)(obj + 0xA);
        b = *(s16*)(p + 0x84);
        d = a - b;
        if (((d >= 0) ? (d >= 0x30) : (b - a >= 0x30)) &&
            D_8009A0AA - 0x10 < (s16) * (u16*)(obj + 0xA)) {
            obj[6] = 3;
            return;
        }
        p = D_1F80004C.bytes;
        d = p[0x91];
        d &= 1;
    }
    if (d) {
        obj[6] = 3;
    } else {
        apply_object_motion(obj);
    }
}
