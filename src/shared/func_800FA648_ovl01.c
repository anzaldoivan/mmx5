/* Shared body (DK-5), from the banked draft of func_800FA648_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_800D1C0C;
extern u8 D_800FD60C_ovl01[];
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    s32 limit = 0x40;

    if (D_800D1C0C != 12) {
        limit = 0x120;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    if (limit < *(s16*)(obj + 0xE)) {
        *(u8**)(obj + 0x68) = D_800FD60C_ovl01;
        obj[6] = 4;
    }
}
