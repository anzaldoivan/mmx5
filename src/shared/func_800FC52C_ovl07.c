/* Shared body (DK-5), from the banked draft of func_800FC52C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);
extern u8 D_80101810_ovl07[];
extern u8 D_8010180C_ovl07[];

void DEDUP_NAME(u8* obj) {
    u8* scr = D_1F80004C.bytes;

    if (scr[0x91] & 8) {
        scr[0x92] = 0;
        func_800171E8(obj, 0xF);
        *(u8**)(obj + 0x54) = D_80101810_ovl07;
        *(u8**)(obj + 0x50) = D_8010180C_ovl07;
        obj[6]++;
    } else {
        func_8002DED4(obj);
    }
}
