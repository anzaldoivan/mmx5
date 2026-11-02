/* Shared body (DK-5), from the banked draft of func_800F16EC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A197;

void DEDUP_NAME(u8* obj) {
    u8* parent;
    s32 v;

    parent = *(u8**)(obj + 0x50);
    if (*(s8*)(parent + 4) != 1) {
        obj[4] = 2;
        obj[3] = 0;
    }
    if (D_8009A197 == 0 || *(s8*)(obj + 2) != 0) {
        func_80017248(obj);
        *(s32*)(obj + 8) = *(s32*)(parent + 8);
        *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
        obj[0x16] = parent[0x16];
        if (obj[0x15] != 0) {
            v = *(u16*)(obj + 0xA) + 3;
        } else {
            v = *(u16*)(obj + 0xA) - 3;
        }
        *(u16*)(obj + 0xA) = v;
    }
    if (*(s8*)(obj + 0x45) != 0) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x30, 0x30);
}
