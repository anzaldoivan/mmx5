/* Shared body (DK-5), from the banked draft of func_80036E60 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003A9AC(void);
extern s32 func_800439A8(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8003D344(void* arg0);
extern void func_8003B33C(u8*, s32);

void DEDUP_NAME(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    if (func_800439A8(obj)) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[0x84] = 0;
        *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
        return;
    }
    func_8002DED4(obj);
    func_8003D344(obj);
    if (*(s8*)(obj + 0x46) < 0 || (*(u16*)(obj + 0x7C) & 3)) {
        func_8003B33C(obj, 0x14);
        obj[5] = 7;
        obj[6] = 0;
    }
}
