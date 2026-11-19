#include "types.h"

extern void (*D_800FEC24_ovl39[])(Obj800FCE88*);

void func_800FCE88_ovl39(Obj800FCE88* arg0) {
    arg0->old_x = arg0->x;
    arg0->old_y = arg0->y;
    D_800FEC24_ovl39[arg0->state](arg0);
    if (((Obj800FCE88*)arg0->parent)->state == 2) {
        arg0->unk84 = 0;
        arg0->state = 2;
    }
}
