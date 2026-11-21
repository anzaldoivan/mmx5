#include "types.h"
#include "mmx5/object.h"

extern void (*D_800F5028_ovl05[])(Entity800EF8CC*);

void func_800EF8CC_ovl05(Entity800EF8CC* e) {
    e->prevX = e->x;
    e->prevY = e->y;
    if (*e->unk50 != 0x41) {
        clear_object_slot(e);
    } else {
        D_800F5028_ovl05[e->state](e);
    }
}
