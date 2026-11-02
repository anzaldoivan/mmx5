/* Shared body (DK-5), from the banked draft of func_800FA928_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800FAF38_ovl06(u8*, s32, s32, s32);

void DEDUP_NAME(u8* obj) {
    s32 t;

    func_80017248(obj);
    t = *(s16*)(obj + 0x7C);
    if (t == 0) {
        func_800171E8(obj, 0x1D);
        obj[6]++;
        return;
    }
    t = *(u16*)(obj + 0x7C);
    if (!(t & 1)) {
        func_800FAF38_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE),
                            (u8)(obj[0x7E] + 0x20));
        if (D_1F80004C.bytes[0x8A] & 1) {
            (*(u16*)(obj + 0x7E))++;
        }
        D_1F80004C.bytes[0x8A]++;
    }
    (*(u16*)(obj + 0x7C))--;
}
