/* Shared body (DK-5), from the banked draft of func_800FAE14_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(ObjFA284*);
extern void func_8002DED4(ObjFA284*);
extern s32 func_8002FB58(ObjFA284*);
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, void*);

void DEDUP_NAME(ObjFA284* o) {
    func_8002DED4(o);
    func_8002FB58(o);
    func_80017248(o);
    if (o->flags70 & 8) {
        func_8001296C(5);
        func_80016490(2, 7, o);
        o->timer = 0x14;
        o->step++;
    }
}
