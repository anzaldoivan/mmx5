/* Shared body (DK-5), from the banked draft of func_800F99C4_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_80044DE0();
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8003D2C4(void);
extern u8 D_8009A1F8[];

void DEDUP_NAME(u8* o) {
    u8* p;

    func_80017248(o);
    if (func_80044DE0() != 0) {
        return;
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        func_80016490(0, 0xE, 0);
        *(s16*)(o + 0x7C) = 2;
    }
    p = D_8009A1F8;
    *(s16*)(p + 0x26) = *(s16*)(o + 0x8C);
    if ((s8)++o[0x5C] == D_1F80004C.bytes[0x86]) {
        p[0x48] = o[0x90];
        *(s32*)(o + 0x8C) = 0;
        *(s32*)(o + 0x90) = 0;
        D_1F80004C.bytes[0x85] = 1;
        func_8003D2C4();
        o[5] = 3;
        o[6] = 0;
    }
}
