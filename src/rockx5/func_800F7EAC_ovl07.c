#include "types.h"

extern Ent800F43E8 D_801015E0_ovl07[];

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F7EAC_ovl07(Obj800EFA30* o) {
    if (D_801015E0_ovl07[o->x85].a != 0) {
        o->x80 = ABS((s16)D_801015E0_ovl07[o->x85].x -
                     (s16)D_801015E0_ovl07[o->x85 + 1].x);
    } else {
        o->x80 = ABS((s16)D_801015E0_ovl07[o->x85].y -
                     (s16)D_801015E0_ovl07[o->x85 + 1].y);
    }
    o->x20 = D_801015E0_ovl07[o->x85].a;
    o->x24 = D_801015E0_ovl07[o->x85].b;
}
