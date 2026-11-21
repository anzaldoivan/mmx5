#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F5008_ovl05[])(ObjF424*);

void func_800EF424_ovl05(ObjF424* o) {
    if (o->unk84 == 0 && o->unk70 == 0) {
        func_8002F8FC(o);
    }
    D_800F5008_ovl05[o->state](o);
}
