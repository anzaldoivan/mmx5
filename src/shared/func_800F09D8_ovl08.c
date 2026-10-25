/* Shared body (DK-5), from the banked draft of func_800F09D8_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(void* obj);
extern void func_800171E8(void* obj, s32 anim);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if ((s8)obj[0x45] == 2) {
        obj[0x8B] = 0;
    }
    if ((s8)obj[0x45] == 1) {
        if (obj[2] & 0x10) {
            func_800171E8(obj, 0);
        } else {
            func_800171E8(obj, 1);
        }
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 5;
    }
}
