/* Shared body (DK-5), from the banked draft of func_800FBCF8_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_80044DE0();
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8003D2C4(void);

void DEDUP_NAME(u8* obj) {
    u8* sc;
    s8 n;

    func_80017248(obj);
    if (func_80044DE0() != 0) {
        return;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_80016490(0, 0xE, 0);
        *(s16*)(obj + 0x7C) = 2;
    }
    n = ++*(s8*)(obj + 0x5C);
    sc = D_1F80004C.bytes;
    if (n == sc[0x8A]) {
        sc[0x89] = 1;
        *(s16*)(D_1F80004C.bytes + 0x84) = *(s16*)(obj + 0xE) - 0x50;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x2C) = 0;
        func_8003D2C4();
        obj[6]++;
    }
}
