/* Shared body (DK-5), from the banked draft of func_800F9F08_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern void func_800FC9E0_ovl07(u8* obj);
extern s8 D_800D1C44;
extern s16 D_8009A0AE;

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    *(u16*)(D_1F80004C.bytes + 0x84) = 0;
    func_800FC9E0_ovl07(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    if (D_800D1C44 == 0) {
        if (D_8009A0AE < *(s16*)(obj + 0xE)) {
            *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xE);
            D_1F80004C.bytes[0x8F] = 0;
            *(s32*)(obj + 0x24) = 0x2000;
            *(s32*)(obj + 0x2C) = -0x1000;
            obj[6] = 1;
            return;
        } else {
            *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xE);
            D_1F80004C.bytes[0x8F] = 1;
            *(s32*)(obj + 0x24) = -0x2000;
            *(s32*)(obj + 0x2C) = 0x1000;
            obj[6] = 1;
            return;
        }
    }
    if (obj[0x15] == 0) {
        *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xA);
        D_1F80004C.bytes[0x8F] = 0;
        *(s32*)(obj + 0x20) = -0x2000;
        *(s32*)(obj + 0x28) = 0x1000;
    } else {
        *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xA);
        D_1F80004C.bytes[0x8F] = 0x40;
        *(s32*)(obj + 0x20) = 0x2000;
        *(s32*)(obj + 0x28) = 0x1000;
    }
    obj[6] = 2;
}
