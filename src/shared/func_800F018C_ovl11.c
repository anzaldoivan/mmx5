/* Shared body (DK-5), from the banked draft of func_800F018C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F0330_ovl11(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800F0414_ovl11(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    if (obj[0x87] != 0) {
        obj[0x87]--;
        *(s32*)(obj + 0x8) += *(s32*)(obj + 0x20);
        *(s32*)(obj + 0x20) += *(s32*)(obj + 0x28);
    } else {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
    }
    func_800F0330_ovl11(obj);
    func_80017248(obj);
    func_800F0414_ovl11(obj);
    if (*(signed char*)(obj + 0x2) == 0) {
        func_8002DED4(obj);
    }
    func_8002D9EC(obj, 0x30, 0x20);
}
