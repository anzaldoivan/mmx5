/* Shared body (DK-5), from the banked draft of func_800F1E04_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void func_80017248(Ent1E04*);
extern void func_8002D9EC(Ent1E04*, s32, s32);

void DEDUP_NAME(Ent1E04* obj) {
    Ent1E04* p;

    if (D_8009A197 == 0) {
        func_80017248(obj);
    }
    p = obj->parent;
    if (p->active == 0 || p->link != 0) {
        obj->state = 2;
    }
    obj->x = p->x;
    obj->y = p->y;
    func_8002D9EC(obj, 0x30, 0x30);
}
