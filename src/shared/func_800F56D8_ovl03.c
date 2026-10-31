/* Shared body (DK-5), from the banked draft of func_800F56D8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u8 D_800D1C10;
extern u16 D_800D50DE;

void DEDUP_NAME(u8* obj) {
    s16 t;

    t = *(s16*)(obj + 0x7C) % 60;
    if (t == 0) {
        func_80016490(2, 0x10, obj);
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_800C9310 |= 1;
        D_80093E68 = 0x7C00;
    } else if (t == 1) {
        D_800D50DE = 0;
        D_8009A42E = 0;
        D_80093E68 = 0;
        D_800C9310 |= 1;
    }
    if (++*(s16*)(obj + 0x7C) == 0xB6) {
        func_80016490(2, 0xD, obj);
        *(s32*)(obj + 0x54) = 0;
        D_800D1C10 = 2;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
