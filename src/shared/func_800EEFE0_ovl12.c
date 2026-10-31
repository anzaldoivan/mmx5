/* Shared body (DK-5), from the banked draft of func_800EEFE0_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern s16 D_8009A0AA;

void DEDUP_NAME(u8* obj) {
    s16 d;

    func_800171E8(obj, 6);
    if (D_8009A0AA < 0xB8) {
        d = 0x130 - *(u16*)(obj + 0xA);
        obj[0x15] = 0;
        if ((d < 0 ? -d : d) < 0x20) {
            func_800171E8(obj, 7);
            func_80016490(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
            goto far; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        obj[0x15] = 0x40;
        d = 0x40 - *(u16*)(obj + 0xA);
        if ((d < 0 ? -d : d) < 0x20) {
            func_800171E8(obj, 7);
            func_80016490(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
        far:
            *(s32*)(obj + 0x24) = 0x30000;
            *(s32*)(obj + 0x2C) = 0x2666;
            func_80016490(2, 0x35, obj);
            obj[6] += 1;
        }
    }
}
