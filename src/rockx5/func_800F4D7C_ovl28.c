#include "types.h"

extern int func_8002D6FC();
extern s32 func_8002FB58(Obj6BD4*);
extern s8 D_8009A0A2;
extern void (*D_800FE1B8_ovl28[])(Obj6BD4*);

void func_800F4D7C_ovl28(Obj6BD4* obj) {
    if (D_8009A0A2 == 0) {
        func_8002D6FC();
        return;
    }
    obj->prevX = obj->x;
    obj->prevY = obj->y;
    D_800FE1B8_ovl28[obj->state](obj);
    func_8002FB58(obj);
}
