/* Shared body (DK-5), from the banked draft of func_800FA1C4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AA;

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 a;
    s32 b;
    s32 d;

    func_80017248(obj);
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
        func_8002DED4(obj);
    }
}
