/* Shared body (DK-5), from the banked draft of func_800F9D38_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);
extern void func_80017248(u8* obj);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_800C9310;
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    u8* p;

    if (!(*(u16*)(obj + 0x7E) & 0xF)) {
        if (--*(s16*)(obj + 0x7C) == -1) {
            ((s16*)obj)[0x3E] = 6;
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
            D_800C9310 |= 1;
            if (D_800D50DE >= 0x1F) {
                *(u16*)(obj + 0x7E) |= 1;
            }
        }
    }
    if (!(*(u16*)(obj + 0x7E) & 0xF0)) {
        func_8002DED4(obj);
        if (D_1F80004C.bytes[0x91] & 8) {
            *(u16*)(obj + 0x7E) |= 0x10;
        }
    }
    if (*(s16*)(obj + 0x7E) == 0x11) {
        D_1F80004C.bytes[0x92] = 0;
        func_800171E8(obj, 2);
        D_1F80004C.bytes[0x92] = 1;
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
        obj[0x15] = 0;
        p = D_800D1C00;
        if (*(s8*)(p + 0xC) != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x2C, 0xFF, p[0x2E]);
            } else {
                func_8002385C(0x5E, 0xFF, p[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
        obj[6]++;
    }
    func_80017248(obj);
}
