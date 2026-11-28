#include "types.h"

extern Ent800F43E8 D_800F43E8_ovl02[];

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800EFD5C_ovl02(Obj800EFA30* o) {
    if (D_800F43E8_ovl02[o->x85].a != 0) {
        o->x80 = ABS((s16)D_800F43E8_ovl02[o->x85].x -
                     (s16)D_800F43E8_ovl02[o->x85 + 1].x);
    } else {
        o->x80 = ABS((s16)D_800F43E8_ovl02[o->x85].y -
                     (s16)D_800F43E8_ovl02[o->x85 + 1].y);
    }
    o->x20 = D_800F43E8_ovl02[o->x85].a;
    o->x24 = D_800F43E8_ovl02[o->x85].b;
}
