/* Shared body (DK-5), from the banked draft of func_800F7268_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002DFB0(void);
extern void func_800F81F4_ovl11(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 1);
    func_80017248(obj);
    obj[0x60] = 8;
    obj[0x62] = 0;
    func_800F81F4_ovl11(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s16*)(obj + 0x7C) = (func_8002DFB0() % 32 + 0x50) / 2;
    if (*(s16*)(obj + 0x7C) > 0x100) {
        D_1F80004C.bytes[0x91] = 1;
    } else {
        D_1F80004C.bytes[0x91] = 0;
    }
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}
