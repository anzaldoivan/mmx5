/* Shared body (DK-5), from the banked draft of func_800F7A0C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x50) {
        *(s16*)(obj + 0xA) += 1;
        return;
    }
    if (D_800FA058_ovl11 + 0x50 < *(s16*)(obj + 0xA)) {
        *(s16*)(obj + 0xA) -= 1;
        return;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        func_800171E8(obj, 1);
    }
    func_80017248(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
        return;
    }
    func_8002DF54(obj);
    if (obj[0x70] & 8) {
        func_800171E8(obj, 0);
        *(s16*)(obj + 0x7C) = 30;
        obj[6]++;
    }
}
