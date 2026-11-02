/* Shared body (DK-5), from the banked draft of func_800F6888_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x7C);
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    if (*(s8*)(obj + 5) == 0) {
        if (*(s32*)(p + 0x20) == 0) {
            func_800171E8(obj, 1);
            obj[5] = 1;
        }
    } else if (*(s32*)(p + 0x24) == 0) {
        func_800171E8(obj, 0);
        obj[5] = 0;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4]++;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    func_80017248(obj);
    func_8002DED4(obj);
}
