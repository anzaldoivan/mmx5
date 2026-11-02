/* Shared body (DK-5), from the banked draft of func_800F7F98_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_80047184(s32 arg0);
extern u16 D_80093E68;
extern u8 D_8009A197;
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;

void DEDUP_NAME(u8* obj) {
    if (*(u16*)(obj + 0x7C) & 1) {
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_800C9310 |= 1;
        D_80093E68 = 0x7C00;
    } else {
        D_800D50DE = 0;
        D_8009A42E = 0;
        D_80093E68 = 0;
        D_800C9310 |= 1;
    }
    if (++*(s16*)(obj + 0x7C) == 9) {
        func_800171E8(obj, 1);
        func_80047184(1);
        D_8009A197 = 1;
        *(u16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
