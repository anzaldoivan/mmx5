/* Shared body (DK-5), from the banked draft of func_800FB4BC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC(ObjFB4BC*, s32, s32);
extern void func_80017248(ObjFB4BC*);
extern s32 func_800317B8(ObjFB4BC*);
extern s32 func_80031DD0(ObjFB4BC*);
extern s32 func_8004FC64(ObjFB4BC*);
extern void (*D_800FF6C4_ovl06[])(ObjFB4BC*);

void DEDUP_NAME(ObjFB4BC* obj) {
    if (obj->parent->state == 2) {
        obj->b4 = 2;
        return;
    }
    obj->prev = obj->pos;
    func_8002D9EC(obj, 16, 16);
    func_80017248(obj);
    D_800FF6C4_ovl06[obj->b5](obj);
    func_800317B8(obj);
    if (obj->b2 < 4) {
        if (obj->b2 >= 0 && func_80031DD0(obj) < 0) {
            func_8004FC64(obj);
            obj->b4 = 2;
        }
    }
}
