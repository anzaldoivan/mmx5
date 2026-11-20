#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s8 D_8009A0A2;
extern void (*D_800FE1B8_ovl28[])(Obj6BD4*);

void func_800F4D7C_ovl28(Obj6BD4* obj) {
    if (D_8009A0A2 == 0) {
        clear_object_slot();
        return;
    }
    obj->prevX = obj->x;
    obj->prevY = obj->y;
    D_800FE1B8_ovl28[obj->state](obj);
    func_8002FB58(obj);
}
