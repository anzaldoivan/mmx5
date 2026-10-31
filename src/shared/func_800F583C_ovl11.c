/* Shared body (DK-5), from the banked draft of func_800F583C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern void func_800171E8(u8* obj, s32 state);
extern s32 D_8009A420;
extern s16 D_8009A0AA;
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(u8* obj) {
    u16 x;
    s16 y;

    func_80017248(obj);
    func_8002DF54(obj);
    if (!(D_8009A420 & 1)) {
        x = *(u16*)(obj + 0xA);
        y = *(u16*)(obj + 0xE) + 0x28;
        func_80050650(0x11, x - 0x10, y, x + 0x10, y, 1);
    }
    if (*(s16*)(obj + 0x7C) != 0) {
        (*(s16*)(obj + 0x7C))--;
        return;
    }
    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x18 ||
            *(s16*)(obj + 0xA) + 0x28 < D_8009A0AA) {
            func_800171E8(obj, 6);
            obj[6]++;
        }
    } else {
        if (D_800FA058_ovl11 + 0x18 < *(s16*)(obj + 0xA) ||
            D_8009A0AA < *(s16*)(obj + 0xA) - 0x28) {
            func_800171E8(obj, 6);
            obj[6]++;
        }
    }
}
