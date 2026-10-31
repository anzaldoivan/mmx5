/* Shared body (DK-5), from the banked draft of func_800EFDE8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80030AE4(u8* obj, s16 x, s16 y);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    s32 r;
    s32 hit;

    func_80017248(obj);
    if (*(s16*)(obj + 0x7E) != 0) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            if (*(s8*)(obj + 0x45) != 0) {
                func_800171E8(obj, 2);
            } else {
                func_800171E8(obj, 1);
            }
        }
        return;
    }
    r = func_80030AE4(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE));
    if (r != 0x2D) {
        *(u8*)(obj + 5) = 1;
        *(u8*)(obj + 6) = 0;
        *(s16*)(obj + 0x7C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x10000;
        return;
    }
    hit = 0;
    if (*(s32*)(obj + 0x20) < 0) {
        hit = func_80030AE4(obj, *(s16*)(obj + 0xA) - 8, *(s16*)(obj + 0xE)) !=
              0x2D;
    } else if (func_80030AE4(obj, *(s16*)(obj + 0xA) + 8, *(s16*)(obj + 0xE)) !=
               r) {
        hit = 1;
    }
    if (hit != 0) {
        if (*(s8*)(obj + 0x45) != 0) {
            func_800171E8(obj, 4);
        } else {
            func_800171E8(obj, 3);
        }
        *(s16*)(obj + 0x7E) = 0x28;
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
    func_8002DF54(obj);
}
