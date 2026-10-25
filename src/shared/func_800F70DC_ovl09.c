/* Shared body (DK-5), from the banked draft of func_800F70DC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    u8* p;

    func_800317B8(obj);
    if (--*(s32*)(obj + 0x8C) == 0) {
        obj[4] = 2;
    }
    p = *(u8**)(*(u8**)(obj + 0x7C) + 0x80);
    if (*(signed char*)(p + 5) == 11 || *(signed char*)(p + 4) == 2) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    func_80017248(obj);
    func_8002DF54(obj);
}
