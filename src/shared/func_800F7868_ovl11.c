/* Shared body (DK-5), from the banked draft of func_800F7868_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();

void DEDUP_NAME(u8* obj) {
    s8 state;
    u8* child;

    if (*(s8*)(obj + 0x45) == 0x10) {
        func_80016490(2, 0x33, obj);
    }
    func_80017248(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 5;
            child[2] = state;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            child[0x15] = obj[0x15];
            if (obj[0x15] == 0) {
                *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                *(s32*)(child + 0x20) = 0xFFFE0000;
            } else {
                *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) + 0x30;
                *(s32*)(child + 0x20) = 0x20000;
            }
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE) + 0x40;
            *(s32*)(child + 0x28) = 0;
            *(s32*)(child + 0x24) = 0;
            *(s32*)(child + 0x2C) = 0x4000;
            *(u8**)(child + 0x7C) = obj;
        }
        obj[6]++;
    }
}
