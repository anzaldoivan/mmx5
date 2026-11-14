/* Shared body (DK-5), from the banked draft of func_800F9BB0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800FCC54_ovl07(void);
extern void func_80024548(s32);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern u8 D_800C9310;
extern u8 D_800D1C00[];
extern s32 D_80093DD0[];
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void DEDUP_NAME(u8* obj) {
    s32 i;
    u16 x;
    u16 y;

    if (**(s8**)(D_1F80004C.bytes + 0x80) != 0) {
        return;
    }
    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    D_80093E68 = 0;
    D_8009A42E = 0;
    D_800D50DE = 0;
    for (i = 2; i < 16; i++) {
        D_80093DD0[i] = 0;
    }
    func_800FCC54_ovl07();
    D_800C9310 |= 1;
    D_800D1C00[0x24] = 1;
    D_800D1C00[0x25] = 0;
    *(u8**)(D_800D1C00 + 0x20) = obj;
    D_800D1C00[0xA2] = 0x30;
    if (*(s8*)(D_800D1C00 + 0xC) == 0xC) {
        func_80024548(-1);
    } else {
        func_80024548(1);
    }
    D_1F80004C.bytes[0x8A] = D_800D1C00[0xA2];
    obj[0x15] = 0;
    *(s32*)(obj + 0x2C) = 0x1000;
    ((Obj800F2688*)obj)->unk7C = 6;
    obj[3] = 1;
    ((Obj800F2688*)obj)->unk7E = 0;
    x = D_80102014_ovl07;
    y = D_80102016_ovl07;
    *(s16*)(obj + 0xA) = x + 0x22A0;
    *(s16*)(obj + 0xE) = y + 0x480;
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    obj[6]++;
}
