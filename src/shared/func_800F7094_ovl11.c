/* Shared body (DK-5), from the banked draft of func_800F7094_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 D_8009A420;
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

#define S16(p, o) (*(s16*)((p) + (o)))
#define S32(p, o) (*(s32*)((p) + (o)))
void DEDUP_NAME(u8* obj) {
    if (!(D_8009A420 & 1)) {
        func_80050650(0x11, S16(obj, 0xA) - 0x10, S16(obj, 0xE) + 0x28,
                      S16(obj, 0xA) + 0x10, S16(obj, 0xE) + 0x28, 1);
    }
    func_8002DED4(obj);
    func_80017248(obj);
    if ((S32(obj, 0x20) < 0 ? -S32(obj, 0x20) : S32(obj, 0x20)) < 0x4000) {
        func_800171E8(obj, 0);
        obj[0x62] = 0;
        S16(obj, 0x7C) = 0x1E;
        obj[6]++;
    }
}
