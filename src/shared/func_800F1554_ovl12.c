/* Shared body (DK-5), from the banked draft of func_800F1554_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_800F20CC_ovl12[];

void DEDUP_NAME(u8* obj) {
    u8* parent;

    func_800317B8(obj);
    if (*(s8*)(obj + 5) == 0) {
        if (*(s32*)(obj + 0x8C) == 0x14) {
            *(u8**)(obj + 0x50) = D_800F20CC_ovl12;
        }
        if (++*(s32*)(obj + 0x8C) == 0x3C) {
            obj[4] = 2;
        }
    }
    parent = *(u8**)(obj + 0x7C);
    if (*(s8*)(parent + 4) == 2 || *(s8*)(parent + 5) == 9) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x100);
    func_80017248(obj);
    func_8002DF54(obj);
}
