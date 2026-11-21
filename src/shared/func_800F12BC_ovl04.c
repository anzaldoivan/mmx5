#include "types.h"
#include "mmx5/object.h"

void func_800F12BC_ovl04(Ent12BC* self) {
    if (--self->timer == -1) {
        self->state = 8;
        self->sub = 0;
    }
    move_object(self);
}
