/* Shared body (DK-5), from the banked draft of func_800EFE38_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_8002E058(void*, s32);

void DEDUP_NAME(u8* obj) {
    u8* child;

    func_80017248(obj);
    if (--*(s16*)(obj + 0x7E) == 0) {
        if (obj[0x80] == 0) {
            func_800171E8(obj, obj[0x88] + 2);
        } else {
            func_800171E8(obj, obj[0x88] + 7);
        }
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x1B;
            child[2] = obj[0x88] + obj[0x80] * 5;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            child[0x15] = obj[0x15];
            func_8002E058(child, obj[0x84]);
            child[4] = 0;
        }
        if (--*(s16*)(obj + 0x7C) == 0) {
            *(s16*)(obj + 0x7C) = 0x1E;
            obj[6] = 3;
            obj[0x8C] = 0;
            return;
        }
        *(s16*)(obj + 0x7E) = 0x10;
    }
}
