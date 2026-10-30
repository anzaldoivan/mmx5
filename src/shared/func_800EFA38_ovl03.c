/* Shared body (DK-5), from the banked draft of func_800EFA38_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x20000;
    func_8002DF54(obj);
    func_80017248(obj);
}
