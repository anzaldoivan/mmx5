/* Shared body (DK-5), from the banked draft of func_800FAE88_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(ObjFA284*);
extern void func_800F9180_ovl06(ObjFA284*);

void DEDUP_NAME(ObjFA284* o) {
    func_80017248(o);
    if (--o->timer == -1) {
        *(s16*)(D_1F80004C.bytes + 0x8E) = 0x3C;
        D_1F80004C.bytes[0x8A] = 0;
        D_1F80004C.bytes[0x8B] = 0;
        func_800F9180_ovl06(o);
    }
}
