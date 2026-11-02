/* Shared body (DK-5), from the banked draft of func_800EFBFC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];
extern u8 D_800F52C8_ovl05[];

void DEDUP_NAME(u8* obj) {
    u8* p = D_8009A0A0;

    if (((*(s16*)(p + 0xA) - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA))
             : (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA))) >= 3) {
        u8* q = D_8009A0A0;

        if (*(s16*)(q + 0xA) < *(s16*)(obj + 0xA)) {
            *(s32*)(obj + 0x20) = 0xFFFF0000;
        } else {
            *(s32*)(obj + 0x20) = 0x10000;
        }
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        *(u8**)(obj + 0x54) = D_800F52C8_ovl05;
        func_800171E8(obj, 0xE);
        D_1F80004C.bytes[0x84] = 1;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}
