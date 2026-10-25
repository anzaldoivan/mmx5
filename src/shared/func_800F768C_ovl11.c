/* Shared body (DK-5), from the banked draft of func_800F768C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);

void DEDUP_NAME(u8* obj) {
    u8 m;

    obj[0x60] = 4;
    obj[0x62] = 0;
    func_800171E8(obj, 1);
    func_80017248(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    m = (u32)func_8002DF78() % 3;
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
    *(s16*)(obj + 0x7C) = (0x70 - (m << 4)) >> 1;
}
