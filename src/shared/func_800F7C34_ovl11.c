/* Shared body (DK-5), from the banked draft of func_800F7C34_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern s16 D_800FA060_ovl11;

void DEDUP_NAME(u8* obj) {
    u32 r;

    func_8002DF54(obj);
    func_80017248(obj);
    if (*(s16*)(obj + 0xE) < D_800FA060_ovl11) {
        D_1F80004C.bytes[0x92] = 7;
        func_800171E8(obj, 2);
        *(s16*)(obj + 0x7C) = 0x5A;
        r = func_8002DF78();
        obj[6]++;
        *(s16*)(obj + 0x7E) = (u8)(r % 3) + 4;
    }
}
