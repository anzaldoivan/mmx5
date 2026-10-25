#include "types.h"

extern void (*D_800FB3C4_ovl00[])(Obj6BD4*);
extern void func_8002FB58(Obj6BD4*);

void func_800F6BD4_ovl00(Obj6BD4* arg0) {
    arg0->prevX = arg0->x;
    arg0->prevY = arg0->y;
    func_8002FB58(arg0);
    D_800FB3C4_ovl00[arg0->state](arg0);
}
